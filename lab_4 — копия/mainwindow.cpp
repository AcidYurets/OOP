#include <QLayout>
#include "controllerwidget.h"
#include "cabinwidget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    door = new Door();
    cabin = new Cabin();
    controller = new Controller(cabin, door);

    CabinWidget* cabinWidget = new CabinWidget(cabin, door);
    ui->centralwidget->layout()->addWidget(cabinWidget);

    ControllerWidget* controllerWidget = new ControllerWidget(controller);
    controllerWidget->setMinimumSize(262, 450);
    controllerWidget->setMaximumSize(262, 450);
    ui->centralwidget->layout()->addWidget(controllerWidget);

    ui->centralwidget->setMinimumSize(600, 450);
    ui->centralwidget->setMaximumSize(600, 450);
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete controller;
    //delete cabin;
    //delete door;
}
