#ifndef CONTROLLERBUTTONWIDGET_H
#define CONTROLLERBUTTONWIDGET_H

#include <QPushButton>
#include "controllerbutton.h"


class ControllerButtonWidget : public QPushButton
{
    Q_OBJECT

public:
    explicit ControllerButtonWidget(ControllerButton* button);
    virtual ~ControllerButtonWidget() = default;

    ControllerButton* getControllerButton();

protected slots:
    void buttonPressed();
    void buttonReleased(ControllerButton* button);

private:
    ControllerButton* button;
};

class ControllerOpenButtonWidget : ControllerButtonWidget
{
    Q_OBJECT

public:
    explicit ControllerOpenButtonWidget(ControllerOpenButton* openButton);
    virtual ~ControllerOpenButtonWidget() = default;

private:
    ControllerOpenButton* openButton;
};

#endif // CONTROLLERBUTTONWIDGET_H