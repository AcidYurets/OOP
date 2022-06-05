#include <QDebug>
#include "door.h"

constexpr auto tick_value = 10;
constexpr auto max_open_value = 260 - 50;

Door::Door()
{
    connect(this, &Door::startForcedOpening, this, &Door::opening);
    connect(this, &Door::doorsAlreadyOpend, this, &Door::open);

    connect(this, &Door::openingAnimationEnd, this, &Door::open);
    connect(this, &Door::closingAnimationEnd, this, &Door::close);
}

void Door::opening()
{
    if (state == State::CLOSED || state == State::CLOSING || state == State::FORCED_OPENING)
    {
        qDebug() << "door is opening...";
        state = State::OPENING;

        timer.stop();
        timer.disconnect();
        connect(&timer, &QTimer::timeout, this, &Door::openingProcess);
        timer.start(tick_value);
    }
}

void Door::openingProcess()
{
    openingValue += 2;
    if (openingValue >= max_open_value)
    {
        openingValue = max_open_value;
        timer.stop();
        timer.disconnect();
        emit openingAnimationEnd();
    }
    else
        emit doorsAnimationSignal(openingValue);
}

void Door::closing()
{
    if (state == State::OPENED)
    {
        qDebug() << "door is closing...";
        state = State::CLOSING;
        
        timer.stop();
        timer.disconnect();
        connect(&timer, &QTimer::timeout, this, &Door::closingProcess);
        timer.start(tick_value);
    }
}

void Door::closingProcess()
{
    openingValue -= 2;
    if (openingValue <= 0)
    {
        openingValue = 0;
        timer.stop();
        timer.disconnect();
        emit closingAnimationEnd();
    }
    else
        emit doorsAnimationSignal(openingValue);
}

void Door::open()
{
    if (state == State::OPENING || state == State::FORCED_OPENING)
    {
        qDebug() << "door opened.";
        state = State::OPENED;
        emit openedSignal();
    }
}

void Door::close()
{
    if (state == State::CLOSING)
    {
        qDebug() << "door closed.";
        state = State::CLOSED;
        emit closedSignal();
    }
}

void Door::forcedOpening()
{
    State lastState = state;
    if (state != State::OPENING)
    {
        qDebug() << "forced doors opening!";
        state = State::FORCED_OPENING;
        if (lastState == State::CLOSED || lastState == State::CLOSING)
            emit startForcedOpening();
        else if (lastState == State::OPENED)
            emit doorsAlreadyOpend();
    }
}
