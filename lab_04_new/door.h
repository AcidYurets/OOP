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
        OPENING,
        FORCED_OPENING
    };

    Door();
    virtual ~Door() = default;

signals:
    void openedSignal();
    void openingSignal();
    void closingSignal();
    void closedSignal();

    void startForcedOpening();
    void doorsAlreadyOpend();

public slots:
    void opening();
    void closing();
    void open();
    void close();

    void forcedOpening();

public:
    State state = State::CLOSED;
};

#endif // DOOR_H
