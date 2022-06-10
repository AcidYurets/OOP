#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QTimer>


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

    Door();
    virtual ~Door() = default;

signals:
    void openedSignal();
    void doorsAnimationSignal(int openingValue);
    void closedSignal();

    void doorsAlreadyOpend();

    void openingAnimationEnd();
    void closingAnimationEnd();

public slots:
    void opening();
    void closing();
    void open();
    void close();

    void openingProcess();
    void closingProcess();

public:
    State state = State::CLOSED;
    int openingValue = 0;
    QTimer timer;
};

#endif // DOOR_H
