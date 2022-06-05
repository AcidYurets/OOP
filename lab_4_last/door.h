#ifndef DOOR_H
#define DOOR_H

#include <QObject>


class Door : public QObject
{
    Q_OBJECT

public:
    enum class State
    {
        CLOSED,
        CLOSING,
        OPENED,
        OPENING
    };

    Door() = default;
    virtual ~Door() = default;

signals:
    void openedSignal();
    void openingSignal();
    void closingSignal();
    void closedSignal();

public slots:
    void opening();
    void closing();
    void open();
    void close();

public:
    State state = State::CLOSED;
};

#endif // DOOR_H
