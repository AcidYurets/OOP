#include "controllerwidget.h"
#include "ui_controllerwidget.h"

ControllerWidget::ControllerWidget(Controller *controller)
    : QWidget(nullptr), ui(new Ui::Controller), controller(controller)
{
    ui->setupUi(this);

    for (int i = FLOORS_COUNT; i > 0; i--)
        addFloorButton(i);

    floorLCD = ui->lcdNumber;
    floorLCD->setSegmentStyle(QLCDNumber::Flat);
    floorLCD->display(1);

    connect(controller->getCabin(), &Cabin::movingSignal, this, &ControllerWidget::floorVisited);
}

ControllerWidget::~ControllerWidget()
{
    delete ui;
}

void ControllerWidget::floorVisited(int floor)
{
    floorLCD->display(floor);
}

void ControllerWidget::addFloorButton(int floor)
{
    ControllerButton* button = new ControllerButton(floor);
    ControllerButtonWidget* buttonWidget = new ControllerButtonWidget(button);

    buttons.insert(buttons.begin(), button);
    buttonWidgets.insert(buttonWidgets.begin(), buttonWidget);

    ui->buttonsLayout->addWidget(buttonWidget);
    controller->connectButton(button);
}
