#include <QDebug>
#include "cabin.h"

constexpr auto timeout = 1000;


Cabin::Cabin()
{
    timer.setSingleShot(false);
    connect(&timer, &QTimer::timeout, this, &Cabin::timerTimeout);
    connect(this, &Cabin::timerTimeoutSignal, this, &Cabin::move);
    connect(this, &Cabin::startMovingSignal, this, &Cabin::move);
}


Direction Cabin::getDirection() const
{
    return direction;
}

void timerTimeout()
{
    emit timerTimeoutSignal();
}

void Cabin::startMove(int targetFloor, int &currFloor)
{
    if (state == State::STOPPED)
    {
        state = State::STARTED_MOVING;
        qDebug() << "Cabin: started moving to floor " << targetFloor;
        emit startMovingSignal(targetFloor, currFloor);
    }
}

void Cabin::move(int targetFloor, int &currFloor)
{
    if (state == State::STARTED_MOVING)
    {
        timer.start(timeout);
        state = State::MOVING;
        return;
    }
    else if (state == State::MOVING)
    {
        qDebug() << "Cabin: at " << currFloor;
    }
    else
        return;

    state = State::MOVING;

    if (currFloor < targetFloor)
    {
        direction = Direction::UP;
        emit movingSignal(++currFloor);
    }
    else if (targetFloor < currFloor)
    {
        direction = Direction::DOWN;
        emit movingSignal(--currFloor);
    }
}

void Cabin::stop(int currFloor)
{
    if (state == State::MOVING || state == State::STARTED_MOVING)
    {
        state = State::STOPPED;
        qDebug() << "stopped moving.";
        timer.stop();
        emit stoppedSignal(currFloor);
    }
}

