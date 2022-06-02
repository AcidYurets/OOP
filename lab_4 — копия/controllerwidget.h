#ifndef CONTROLLERWIDGET_H
#define CONTROLLERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLCDNumber>
#include "common.h"
#include "controller.h"
#include "controllerbuttonwidget.h"
#include "ui_controllerwidget.h"


namespace Ui {
class Controller;
}

class ControllerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControllerWidget(Controller* controller);
    ~ControllerWidget();

public slots:
    void floorVisited(int floor);

private:
    void addButton(int floor, QVBoxLayout* buttonsLayout);

    Ui::Controller *ui;
    Controller* controller;

    QLCDNumber *floorLCD;
    std::vector<ControllerButton*> buttons;
    std::vector<ControllerButtonWidget*> buttonWidgets;
};

#endif // CONTROLLERWIDGET_H
