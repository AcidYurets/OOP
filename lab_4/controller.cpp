#include "controller.h" 
#include <QDebug> 

constexpr auto wait_timeout = 2000;


Controller::Controller(Cabin *cabin, Door *door)
    : cabin(cabin), door(door)
{
    connect(this, &Controller::startOpeningDoors, this, &Controller::cabinStopped);

    connect(this, &Controller::doorsOpeningSignal, door, &Door::opening);
    connect(this, &Controller::doorsClosingSignal, door, &Door::closing);
    connect(door, &Door::openedSignal, this, &Controller::doorOpened);
    connect(door, &Door::closedSignal, this, &Controller::cabinIsMoving);
    
    
    connect(this, &Controller::cabinMoveSignal, cabin, &Cabin::startMove);
    connect(this, &Controller::cabinStopSignal, cabin, &Cabin::stop);
    connect(cabin, &Cabin::movingSignal, this, &Controller::cabinIsMoving);
    connect(cabin, &Cabin::stoppedSignal, this, &Controller::cabinStopped);

    connect(this, &Controller::controllerNotActiveSignal, this, &Controller::controllerIsNotActive);
    connect(&timer, &QTimer::timeout, this, &Controller::waitingTimeout);
}

void Controller::connectButton(ControllerButton *button)
{
    connect(button, &ControllerButton::pressedSignal, this, &Controller::buttonPressed);
    connect(this, &Controller::releaseButton, [button](int floor)
    {
        if (floor == button->getFloorNumber())
            button->release();
    });
}

void Controller::connectOpenButton(QPushButton* button)
{
    connect(button, &QPushButton::pressed, this, &Controller::openButtonPressed);
}

Cabin *Controller::getCabin()
{
    return cabin;
}

void Controller::cabinStopped()
{
    if (state == State::ELEVATOR_IN_MOVE || state == State::DOORS_CLOSING || state == State::WAITING_PASSENGERS || state == State::NOT_ACTIVE)
    {
        state = State::DOORS_OPENING;
        qDebug() << "cabin stopped";
        emit doorsOpeningSignal();
    }
}

void Controller::doorOpened()
{
    if (state == State::DOORS_OPENING)
    {
        state = State::WAITING_PASSENGERS;
        qDebug() << "waiting passengers...";

        floorRequested[currFloor - 1] = false;

        emit releaseButton(currFloor);
        timer.start(wait_timeout);
    }
}

void Controller::waitingTimeout()
{
    if (state == State::WAITING_PASSENGERS)
    {
        state = State::DOORS_CLOSING;
        qDebug() << "end waiting";
        timer.stop();
        emit doorsClosingSignal();
    }
}

void Controller::cabinIsMoving()
{
    if (state == State::ELEVATOR_IN_MOVE || state == State::DOORS_CLOSING)
    {
        state = State::ELEVATOR_IN_MOVE;

        if (floorRequested[currFloor - 1]) // Приехали куда надо
            emit cabinStopSignal(currFloor);
        else if (getNextTargetFloor() != 0)            // Едем к цели         
            emit cabinMoveSignal(getNextTargetFloor(), currFloor);
        else                                           // Ехать некуда
            emit controllerNotActiveSignal();
    }
}

void Controller::controllerIsNotActive()
{
    state = State::NOT_ACTIVE;
    qDebug() << "elevator not active!";
}


void Controller::buttonPressed(ControllerButton* button)
{
    int floor = button->getFloorNumber();
    floorRequested[floor - 1] = true;

    if (state == State::NOT_ACTIVE) // Если лифт не активен
        emit startOpeningDoors();
    else if ((state == State::DOORS_CLOSING || state == State::WAITING_PASSENGERS)
        && (floor == currFloor)) // Если нажали кнопку этажа, на котором лифт и так находится
        emit startOpeningDoors();
}

void Controller::openButtonPressed()
{
    // qDebug() << "STATE: " << (int)state;
    if (state == State::DOORS_CLOSING || state == State::WAITING_PASSENGERS || state == State::NOT_ACTIVE)
        emit startOpeningDoors();
}


bool Controller::hasRequests() const
{
    for (int i = 0; i < FLOORS_COUNT; i++)
        if (floorRequested[i])
            return true;

    return false;
}

int Controller::getNextTargetFloor() const
{
    Direction dir = cabin->getDirection();

    return getNextTargetFloor(currFloor, dir);
}

int Controller::getNextTargetFloor(int currFloor, Direction dir) const
{
    if (dir == Direction::DOWN)
    {
        for (int i = currFloor - 1; i >= 0; i--)
            if (floorRequested[i])
                return i + 1;

        for (int i = currFloor - 1; i < FLOORS_COUNT; i++)
            if (floorRequested[i])
                return i + 1;
    }
    else
    {
        for (int i = currFloor - 1; i < FLOORS_COUNT; i++)
            if (floorRequested[i])
                return i + 1;

        for (int i = currFloor - 1; i >= 0; i--)
            if (floorRequested[i])
                return i + 1;
    }
    return 0;
}
