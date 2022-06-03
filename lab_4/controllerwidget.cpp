#include "controllerwidget.h"

ControllerWidget::ControllerWidget(Controller* controller)
    : QWidget(nullptr), ui(new Ui::Controller), controller(controller)
{
    ui->setupUi(this);

    for (int i = FLOORS_COUNT / 2 + 1; i > 0; i--)
        addButton(i, ui->buttonsLayout);

    for (int i = FLOORS_COUNT; i > FLOORS_COUNT / 2 + 1; i--)
        addButton(i, ui->buttonsLayout_2);

    addOpenButton(ui->buttonsLayout_2);

    floorLCD = ui->lcdNumber;
    floorLCD->setSegmentStyle(QLCDNumber::Flat);
    setStyleSheet("QLCDNumber {"
        "border-style: solid;"
        "border-width: 2px;"
        "border-color: grey;"
        "border-radius: 5px;"
        "background-color: rgb(0, 0, 204);"
        "color: rgb(182, 182, 182);"
        "}");
    floorLCD->display(1);

    connect(controller->getCabin(), &Cabin::movingSignal, this, &ControllerWidget::floorVisited);
}

ControllerWidget::~ControllerWidget()
{
    delete ui;
}

void ControllerWidget::floorVisited(int floor)
{
    int target = controller->getNextTargetFloor();
    if (floor == target)

    {
        setStyleSheet("QLCDNumber {"
            "border-style: solid;"
            "border-width: 2px;"
            "border-color: rgb(0, 230, 0);"
            "border-radius: 5px;"
            "background-color: rgb(0, 0, 204);"
            "color: rgb(0, 230, 0);"
            "}");
    }
    else
    {
        setStyleSheet("QLCDNumber {"
            "border-style: solid;"
            "border-width: 2px;"
            "border-color: grey;"
            "border-radius: 5px;"
            "background-color: rgb(0, 0, 204);"
            "color: rgb(182, 182, 182);"
            "}");
    }
    floorLCD->display(floor);
}


void ControllerWidget::addButton(int floor, QVBoxLayout* buttonsLayout)
{
    ControllerButton* button = new ControllerButton(floor);
    ControllerButtonWidget* buttonWidget = new ControllerButtonWidget(button);

    buttons.insert(buttons.begin(), button);
    buttonWidgets.insert(buttonWidgets.begin(), buttonWidget);

    buttonsLayout->addWidget(buttonWidget);
    controller->connectButton(button);
}


void ControllerWidget::addOpenButton(QVBoxLayout* buttonsLayout)
{
    QPushButton* button = new QPushButton("<>");
    openButton = button;

    buttonsLayout->addWidget(button);
    controller->connectOpenButton(button);
}
