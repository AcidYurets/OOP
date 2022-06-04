#include <QDebug>
#include "door.h"


Door::Door()
{
    connect(this, &Door::startForcedOpening, this, &Door::opening);
    connect(this, &Door::doorsAlreadyOpend, this, &Door::open);
}

void Door::opening()
{
    if (state == State::CLOSED || state == State::CLOSING || state == State::FORCED_OPENING)
    {
        qDebug() << "door is opening...";
        state = State::OPENING;
        emit openingSignal();
    }
}

void Door::closing()
{
    if (state == State::OPENED)
    {
        qDebug() << "door is closing...";
        state = State::CLOSING;
        emit closingSignal();
    }
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
