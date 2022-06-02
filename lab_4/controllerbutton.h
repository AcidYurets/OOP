#ifndef CONTROLLERBUTTON_H
#define CONTROLLERBUTTON_H

#include <QObject>


class ControllerButton : public QObject
{
    Q_OBJECT

public:
    enum class State
    {
        PRESSED,
        RELEASED
    };

    explicit ControllerButton(int floor);
    virtual ~ControllerButton() = default;

    int getFloorNumber() const;

signals:
    void pressedSignal(ControllerButton* button);
    void releasedSignal(ControllerButton* button);

public slots:
    void press();
    void release();

private:
    int floorNumber;
    State state = State::RELEASED;
};

class ControllerOpenButton : public ControllerButton
{
    Q_OBJECT

public:
    enum class State
    {
        PRESSED,
        RELEASED
    };

    explicit ControllerOpenButton() = default;
    virtual ~ControllerOpenButton() = default;
};
#endif // CONTROLLERBUTTON_H
