#include <QDebug>
#include "door.h"


void Door::opening()
{
    if (state == State::CLOSED || state == State::CLOSING || state == State::OPENED)
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
    if (state == State::OPENING)
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
