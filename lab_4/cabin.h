#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include <QTimer>
#include "common.h"


class Cabin : public QObject
{
    Q_OBJECT

public:
    enum class State
    {
        STOPPED,
        STARTED_MOVING,
        MOVING
    };

    Cabin();
    virtual ~Cabin() = default;

    int getCurrFloor() const;
    Direction getDirection() const;

signals:
    void movingSignal(int floor);
    void startMovingSignal(int targetFloor, int &currFloor);
    void stoppedSignal(int floor);

    void timerTimeoutSignal();

public slots:
    void startMove(int targetFloor, int &currFloor);
    void move(int targetFloor, int &currFloor);
    void stop(int currFloor);

    void timerTimeout();
private:
    //int currFloor = 1;
    //int targetFloor = 1;
    Direction direction = Direction::NONE;
    State state = State::STOPPED;
    QTimer timer;
};

#endif // CABIN_H
