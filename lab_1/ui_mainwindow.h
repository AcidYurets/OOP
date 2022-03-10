/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QGroupBox *group_Move;
    QLineEdit *lineEdit_MoveX;
    QLineEdit *lineEdit_MoveY;
    QLineEdit *lineEdit_MoveZ;
    QPushButton *button_Move;
    QLabel *label_MoveX;
    QLabel *label_MoveY;
    QLabel *label_MoveZ;
    QGroupBox *group_Move_2;
    QLineEdit *lineEdit_ScaleX;
    QLineEdit *lineEdit_ScaleY;
    QLineEdit *lineEdit_ScaleZ;
    QPushButton *button_Scale;
    QLabel *label_ScaleX;
    QLabel *label_ScaleY;
    QLabel *label_ScaleZ;
    QGroupBox *group_Move_3;
    QLineEdit *lineEdit_TurnX;
    QLineEdit *lineEdit_TurnY;
    QLineEdit *lineEdit_TurnZ;
    QPushButton *button_Turn;
    QLabel *label_TurnX;
    QLabel *label_TurnY;
    QLabel *label_TurnZ;
    QMenuBar *menuBar;
    QMenu *menuOOP_Lab1_Obergan;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 500);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 10, 600, 450));
        group_Move = new QGroupBox(centralWidget);
        group_Move->setObjectName(QString::fromUtf8("group_Move"));
        group_Move->setGeometry(QRect(650, 30, 300, 120));
        lineEdit_MoveX = new QLineEdit(group_Move);
        lineEdit_MoveX->setObjectName(QString::fromUtf8("lineEdit_MoveX"));
        lineEdit_MoveX->setGeometry(QRect(20, 60, 70, 20));
        lineEdit_MoveY = new QLineEdit(group_Move);
        lineEdit_MoveY->setObjectName(QString::fromUtf8("lineEdit_MoveY"));
        lineEdit_MoveY->setGeometry(QRect(115, 60, 70, 20));
        lineEdit_MoveZ = new QLineEdit(group_Move);
        lineEdit_MoveZ->setObjectName(QString::fromUtf8("lineEdit_MoveZ"));
        lineEdit_MoveZ->setGeometry(QRect(210, 60, 70, 20));
        button_Move = new QPushButton(group_Move);
        button_Move->setObjectName(QString::fromUtf8("button_Move"));
        button_Move->setGeometry(QRect(20, 90, 260, 23));
        label_MoveX = new QLabel(group_Move);
        label_MoveX->setObjectName(QString::fromUtf8("label_MoveX"));
        label_MoveX->setGeometry(QRect(20, 30, 45, 13));
        QFont font;
        font.setPointSize(10);
        label_MoveX->setFont(font);
        label_MoveY = new QLabel(group_Move);
        label_MoveY->setObjectName(QString::fromUtf8("label_MoveY"));
        label_MoveY->setGeometry(QRect(120, 30, 45, 13));
        label_MoveY->setFont(font);
        label_MoveZ = new QLabel(group_Move);
        label_MoveZ->setObjectName(QString::fromUtf8("label_MoveZ"));
        label_MoveZ->setGeometry(QRect(210, 30, 45, 13));
        label_MoveZ->setFont(font);
        group_Move_2 = new QGroupBox(centralWidget);
        group_Move_2->setObjectName(QString::fromUtf8("group_Move_2"));
        group_Move_2->setGeometry(QRect(650, 180, 300, 120));
        lineEdit_ScaleX = new QLineEdit(group_Move_2);
        lineEdit_ScaleX->setObjectName(QString::fromUtf8("lineEdit_ScaleX"));
        lineEdit_ScaleX->setGeometry(QRect(20, 60, 70, 20));
        lineEdit_ScaleY = new QLineEdit(group_Move_2);
        lineEdit_ScaleY->setObjectName(QString::fromUtf8("lineEdit_ScaleY"));
        lineEdit_ScaleY->setGeometry(QRect(115, 60, 70, 20));
        lineEdit_ScaleZ = new QLineEdit(group_Move_2);
        lineEdit_ScaleZ->setObjectName(QString::fromUtf8("lineEdit_ScaleZ"));
        lineEdit_ScaleZ->setGeometry(QRect(210, 60, 70, 20));
        button_Scale = new QPushButton(group_Move_2);
        button_Scale->setObjectName(QString::fromUtf8("button_Scale"));
        button_Scale->setGeometry(QRect(20, 90, 260, 23));
        label_ScaleX = new QLabel(group_Move_2);
        label_ScaleX->setObjectName(QString::fromUtf8("label_ScaleX"));
        label_ScaleX->setGeometry(QRect(20, 30, 45, 13));
        label_ScaleX->setFont(font);
        label_ScaleY = new QLabel(group_Move_2);
        label_ScaleY->setObjectName(QString::fromUtf8("label_ScaleY"));
        label_ScaleY->setGeometry(QRect(120, 30, 45, 13));
        label_ScaleY->setFont(font);
        label_ScaleZ = new QLabel(group_Move_2);
        label_ScaleZ->setObjectName(QString::fromUtf8("label_ScaleZ"));
        label_ScaleZ->setGeometry(QRect(210, 30, 45, 13));
        label_ScaleZ->setFont(font);
        group_Move_3 = new QGroupBox(centralWidget);
        group_Move_3->setObjectName(QString::fromUtf8("group_Move_3"));
        group_Move_3->setGeometry(QRect(650, 330, 300, 120));
        lineEdit_TurnX = new QLineEdit(group_Move_3);
        lineEdit_TurnX->setObjectName(QString::fromUtf8("lineEdit_TurnX"));
        lineEdit_TurnX->setGeometry(QRect(20, 60, 70, 20));
        lineEdit_TurnY = new QLineEdit(group_Move_3);
        lineEdit_TurnY->setObjectName(QString::fromUtf8("lineEdit_TurnY"));
        lineEdit_TurnY->setGeometry(QRect(115, 60, 70, 20));
        lineEdit_TurnZ = new QLineEdit(group_Move_3);
        lineEdit_TurnZ->setObjectName(QString::fromUtf8("lineEdit_TurnZ"));
        lineEdit_TurnZ->setGeometry(QRect(210, 60, 70, 20));
        button_Turn = new QPushButton(group_Move_3);
        button_Turn->setObjectName(QString::fromUtf8("button_Turn"));
        button_Turn->setGeometry(QRect(20, 90, 260, 23));
        label_TurnX = new QLabel(group_Move_3);
        label_TurnX->setObjectName(QString::fromUtf8("label_TurnX"));
        label_TurnX->setGeometry(QRect(20, 30, 45, 13));
        label_TurnX->setFont(font);
        label_TurnY = new QLabel(group_Move_3);
        label_TurnY->setObjectName(QString::fromUtf8("label_TurnY"));
        label_TurnY->setGeometry(QRect(120, 30, 45, 13));
        label_TurnY->setFont(font);
        label_TurnZ = new QLabel(group_Move_3);
        label_TurnZ->setObjectName(QString::fromUtf8("label_TurnZ"));
        label_TurnZ->setGeometry(QRect(210, 30, 45, 13));
        label_TurnZ->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        menuOOP_Lab1_Obergan = new QMenu(menuBar);
        menuOOP_Lab1_Obergan->setObjectName(QString::fromUtf8("menuOOP_Lab1_Obergan"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOOP_Lab1_Obergan->menuAction());
        menuOOP_Lab1_Obergan->addSeparator();
        menuOOP_Lab1_Obergan->addAction(actionOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "OOP Lab1 Winterpuma", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        group_Move->setTitle(QCoreApplication::translate("MainWindow", "Move", nullptr));
        lineEdit_MoveX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_MoveY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_MoveZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        button_Move->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        label_MoveX->setText(QCoreApplication::translate("MainWindow", "dx:", nullptr));
        label_MoveY->setText(QCoreApplication::translate("MainWindow", "dy:", nullptr));
        label_MoveZ->setText(QCoreApplication::translate("MainWindow", "dz:", nullptr));
        group_Move_2->setTitle(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        lineEdit_ScaleX->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        lineEdit_ScaleY->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        lineEdit_ScaleZ->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        button_Scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label_ScaleX->setText(QCoreApplication::translate("MainWindow", "kx:", nullptr));
        label_ScaleY->setText(QCoreApplication::translate("MainWindow", "ky:", nullptr));
        label_ScaleZ->setText(QCoreApplication::translate("MainWindow", "kz:", nullptr));
        group_Move_3->setTitle(QCoreApplication::translate("MainWindow", "Turn", nullptr));
        lineEdit_TurnX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_TurnY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineEdit_TurnZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        button_Turn->setText(QCoreApplication::translate("MainWindow", "Turn", nullptr));
        label_TurnX->setText(QCoreApplication::translate("MainWindow", "ox:", nullptr));
        label_TurnY->setText(QCoreApplication::translate("MainWindow", "oy:", nullptr));
        label_TurnZ->setText(QCoreApplication::translate("MainWindow", "oz:", nullptr));
        menuOOP_Lab1_Obergan->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
