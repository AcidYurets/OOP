#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include "common.h"
#include "cabin.h"
#include "door.h"
#include "controllerbutton.h"


class Controller : public QObject
{
    Q_OBJECT

public:
    enum class State
    {
        NOT_ACTIVE,
        DOORS_OPENING,
        WAITING_PASSENGERS,
        DOORS_CLOSING,
        ELEVATOR_IN_MOVE
    };

    Controller(Cabin* cabin, Door* door);
    virtual ~Controller() = default;

    void connectButton(ControllerButton* button);
    Cabin* getCabin();

signals:
    void releaseButton(int floor);

    void startOpeningDoors(int floor);
    void doorsOpeningSignal();
    void doorsClosingSignal();

    void cabinMoveSignal(int targetFloor);
    void cabinStopSignal();

    void controllerNotActiveSignal();

public slots:
    void controllerIsNotActive();                 // NOT_ACTIVE
    void cabinIsMoving();                         // ELEVATOR_IN_MOVE
    void cabinStopped(int floor);                 // OPENING_DOORS
    void doorOpened();                            // WAITING_PASSENGERS
    void waitingTimeout();                        // CLOSING_DOORS

    void buttonPressed(ControllerButton* button);

private:
    bool hasRequests() const;
    int getNextTargetFloor() const;
    int getNextTargetFloor(int currFloor, Direction dir) const;

    State state = State::NOT_ACTIVE;
    bool floorRequested[FLOORS_COUNT] = { false };

    Cabin* cabin;
    Door* door;
    QTimer timer;
};

#endif // CONTROLLER_H
