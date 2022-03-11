#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "error_handler.h"
#include "task_manager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_downButton_clicked();
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_upButton_clicked();

    void on_plusButton_clicked();
    void on_minusButton_clicked();

    void on_rotateXLeftButton_clicked();
    void on_rotateXRightButton_clicked();
    void on_rotateYLeftButton_clicked();
    void on_rotateYRightButton_clicked();
    void on_rotateZLeftButton_clicked();
    void on_rotateZRightButton_clicked();

    void on_openFile_triggered();

private:
    Ui::MainWindow *ui;
};

errors draw_action(Ui::MainWindow* ui);
errors transform_and_show(request req, Ui::MainWindow* ui);

#endif // MAINWINDOW_H
