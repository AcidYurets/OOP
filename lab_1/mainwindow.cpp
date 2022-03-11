#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task_manager.h"
#include "error_handler.h"
#include "operations.h"
#include "defines.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    request req;
    req.t = INIT;
    task_manager(req);
}

MainWindow::~MainWindow()
{
    delete ui;
}

errors draw_action(Ui::MainWindow* ui)
{
    draw dr;

    dr.gV = ui->graphicsView;
    dr.h = ui->graphicsView->height();
    dr.w = ui->graphicsView->width();

    request req;
    req.t = DRAW;
    req.dr = dr;

    errors err = (errors) task_manager(req);
    return err;
}

errors transform_and_show(request req, Ui::MainWindow* ui)
{
    errors err = (errors) task_manager(req);
    if (err)
        return err;
    else
        err = draw_action(ui);

    return err;
}

// Load figure
void MainWindow::on_openFile_triggered()
{
    request req;
    req.t = LOAD_FILE;
    req.load_f.filename = "cube.txt";

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

// Transformation
void MainWindow::on_downButton_clicked()
{
    request req;
    req.t = MOVE;

    req.mo.dx = 0;
    req.mo.dy = MOVE_VALUE;
    req.mo.dz = 0;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_rightButton_clicked()
{
    request req;
    req.t = MOVE;

    req.mo.dx = MOVE_VALUE;
    req.mo.dy = 0;
    req.mo.dz = 0;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_leftButton_clicked()
{
    request req;
    req.t = MOVE;

    req.mo.dx = -MOVE_VALUE;
    req.mo.dy = 0;
    req.mo.dz = 0;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_upButton_clicked()
{
    request req;
    req.t = MOVE;

    req.mo.dx = 0;
    req.mo.dy = -MOVE_VALUE;
    req.mo.dz = 0;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_plusButton_clicked()
{
    request req;
    req.t = SCALE;

    req.sc.kx = SCALE_VALUE;
    req.sc.ky = SCALE_VALUE;
    req.sc.kz = SCALE_VALUE;
    req.sc.cx = ui->graphicsView->width() / 2;
    req.sc.cy = ui->graphicsView->height() / 2;
    req.sc.cz = 0;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_minusButton_clicked()
{
    request req;
    req.t = SCALE;

    req.sc.kx = 1 / SCALE_VALUE;
    req.sc.ky = 1 / SCALE_VALUE;
    req.sc.kz = 1 / SCALE_VALUE;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_rotateXLeftButton_clicked()
{
    request req;
    req.t = TURN;

    req.tu.ox = -ROTATE_VALUE;
    req.tu.oy = 0;
    req.tu.oz = 0;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_rotateXRightButton_clicked()
{
    request req;
    req.t = TURN;

    req.tu.ox = ROTATE_VALUE;
    req.tu.oy = 0;
    req.tu.oz = 0;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_rotateYLeftButton_clicked()
{
    request req;
    req.t = TURN;

    req.tu.ox = 0;
    req.tu.oy = -ROTATE_VALUE;
    req.tu.oz = 0;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_rotateYRightButton_clicked()
{
    request req;
    req.t = TURN;

    req.tu.ox = 0;
    req.tu.oy = ROTATE_VALUE;
    req.tu.oz = 0;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_rotateZLeftButton_clicked()
{
    request req;
    req.t = TURN;

    req.tu.ox = 0;
    req.tu.oy = 0;
    req.tu.oz = ROTATE_VALUE;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_rotateZRightButton_clicked()
{
    request req;
    req.t = TURN;

    req.tu.ox = 0;
    req.tu.oy = 0;
    req.tu.oz = -ROTATE_VALUE;

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

