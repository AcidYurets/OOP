#include "qtypeinfo.h"
#include "controllerwidget.h"

ControllerWidget::ControllerWidget(Controller *controller)
    : QWidget(nullptr), ui(new Ui::Controller), controller(controller)
{
    ui->setupUi(this);

    for (int i = FLOORS_COUNT / 2 + 1; i > 0; i--)
        addButton(i, ui->buttonsLayout);
     
    for (int i = FLOORS_COUNT; i > FLOORS_COUNT / 2 + 1; i--)
        addButton(i, ui->buttonsLayout_2);
    
    addButton(-1, ui->buttonsLayout_2);

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

void ControllerWidget::addButton(int floor, QVBoxLayout* buttonsLayout)
{
    ControllerButton* button; ;
    ControllerButtonWidget* buttonWidget;
    if (floor != -1)
    {
        button = new ControllerButton(floor);
        buttonWidget = new ControllerButtonWidget(button);
    }
    else
    {
        button = new ControllerOpenButton();
        buttonWidget = new ControllerOpenButtonWidget(button);
    }


    buttons.insert(buttons.begin(), button);
    buttonWidgets.insert(buttonWidgets.begin(), buttonWidget);

    buttonsLayout->addWidget(buttonWidget);
        controller->connectOpenButton(button);
        controller->connectButton(button);
}