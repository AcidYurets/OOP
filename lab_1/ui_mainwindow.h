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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *openFile;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QPushButton *upButton;
    QPushButton *leftButton;
    QPushButton *downButton;
    QPushButton *rightButton;
    QGroupBox *groupBox_2;
    QPushButton *rotateYRightButton;
    QPushButton *rotateYLeftButton;
    QPushButton *rotateXRightButton;
    QPushButton *rotateXLeftButton;
    QPushButton *rotateZRightButton;
    QPushButton *rotateZLeftButton;
    QGroupBox *groupBox_3;
    QPushButton *plusButton;
    QPushButton *minusButton;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(815, 661);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        openFile = new QAction(MainWindow);
        openFile->setObjectName(QString::fromUtf8("openFile"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(191, 91));
        groupBox->setMaximumSize(QSize(191, 91));
        upButton = new QPushButton(groupBox);
        upButton->setObjectName(QString::fromUtf8("upButton"));
        upButton->setGeometry(QRect(70, 20, 50, 31));
        upButton->setAutoRepeatDelay(10);
        upButton->setAutoRepeatInterval(0);
        upButton->setAutoDefault(true);
        upButton->setFlat(false);
        leftButton = new QPushButton(groupBox);
        leftButton->setObjectName(QString::fromUtf8("leftButton"));
        leftButton->setGeometry(QRect(20, 50, 50, 31));
        leftButton->setAutoExclusive(false);
        leftButton->setAutoRepeatDelay(10);
        leftButton->setAutoRepeatInterval(0);
        leftButton->setAutoDefault(true);
        downButton = new QPushButton(groupBox);
        downButton->setObjectName(QString::fromUtf8("downButton"));
        downButton->setGeometry(QRect(70, 50, 50, 31));
        downButton->setAutoRepeatDelay(10);
        downButton->setAutoRepeatInterval(0);
        downButton->setAutoDefault(true);
        rightButton = new QPushButton(groupBox);
        rightButton->setObjectName(QString::fromUtf8("rightButton"));
        rightButton->setGeometry(QRect(120, 50, 50, 31));
        rightButton->setAutoRepeatDelay(10);
        rightButton->setAutoRepeatInterval(0);
        rightButton->setAutoDefault(true);

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(191, 101));
        groupBox_2->setMaximumSize(QSize(191, 101));
        rotateYRightButton = new QPushButton(groupBox_2);
        rotateYRightButton->setObjectName(QString::fromUtf8("rotateYRightButton"));
        rotateYRightButton->setGeometry(QRect(50, 50, 31, 31));
        rotateYRightButton->setAutoRepeatDelay(10);
        rotateYLeftButton = new QPushButton(groupBox_2);
        rotateYLeftButton->setObjectName(QString::fromUtf8("rotateYLeftButton"));
        rotateYLeftButton->setGeometry(QRect(110, 50, 31, 31));
        rotateYLeftButton->setAutoRepeatDelay(10);
        rotateXRightButton = new QPushButton(groupBox_2);
        rotateXRightButton->setObjectName(QString::fromUtf8("rotateXRightButton"));
        rotateXRightButton->setGeometry(QRect(80, 30, 31, 31));
        rotateXRightButton->setAutoRepeatDelay(10);
        rotateXLeftButton = new QPushButton(groupBox_2);
        rotateXLeftButton->setObjectName(QString::fromUtf8("rotateXLeftButton"));
        rotateXLeftButton->setGeometry(QRect(80, 60, 31, 31));
        rotateXLeftButton->setAutoRepeatDelay(10);
        rotateZRightButton = new QPushButton(groupBox_2);
        rotateZRightButton->setObjectName(QString::fromUtf8("rotateZRightButton"));
        rotateZRightButton->setGeometry(QRect(40, 20, 41, 31));
        rotateZRightButton->setAutoRepeatDelay(10);
        rotateZLeftButton = new QPushButton(groupBox_2);
        rotateZLeftButton->setObjectName(QString::fromUtf8("rotateZLeftButton"));
        rotateZLeftButton->setGeometry(QRect(110, 20, 41, 31));
        rotateZLeftButton->setAutoRepeatDelay(10);

        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(191, 71));
        groupBox_3->setMaximumSize(QSize(191, 71));
        plusButton = new QPushButton(groupBox_3);
        plusButton->setObjectName(QString::fromUtf8("plusButton"));
        plusButton->setGeometry(QRect(100, 20, 40, 40));
        plusButton->setMaximumSize(QSize(40, 40));
        plusButton->setAutoRepeatDelay(10);
        minusButton = new QPushButton(groupBox_3);
        minusButton->setObjectName(QString::fromUtf8("minusButton"));
        minusButton->setGeometry(QRect(50, 20, 40, 40));
        minusButton->setMaximumSize(QSize(40, 40));
        minusButton->setAutoRepeatDelay(10);

        gridLayout->addWidget(groupBox_3, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(600, 600));

        gridLayout->addWidget(graphicsView, 0, 1, 4, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 815, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(openFile);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "lab_1", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        openFile->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
        upButton->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
#if QT_CONFIG(shortcut)
        upButton->setShortcut(QCoreApplication::translate("MainWindow", "Up", nullptr));
#endif // QT_CONFIG(shortcut)
        leftButton->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
#if QT_CONFIG(shortcut)
        leftButton->setShortcut(QCoreApplication::translate("MainWindow", "Left", nullptr));
#endif // QT_CONFIG(shortcut)
        downButton->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
#if QT_CONFIG(shortcut)
        downButton->setShortcut(QCoreApplication::translate("MainWindow", "Down", nullptr));
#endif // QT_CONFIG(shortcut)
        rightButton->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
#if QT_CONFIG(shortcut)
        rightButton->setShortcut(QCoreApplication::translate("MainWindow", "Right", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        rotateYRightButton->setText(QCoreApplication::translate("MainWindow", "\342\206\252", nullptr));
#if QT_CONFIG(shortcut)
        rotateYRightButton->setShortcut(QCoreApplication::translate("MainWindow", "6", nullptr));
#endif // QT_CONFIG(shortcut)
        rotateYLeftButton->setText(QCoreApplication::translate("MainWindow", "\342\206\251", nullptr));
#if QT_CONFIG(shortcut)
        rotateYLeftButton->setShortcut(QCoreApplication::translate("MainWindow", "4", nullptr));
#endif // QT_CONFIG(shortcut)
        rotateXRightButton->setText(QCoreApplication::translate("MainWindow", "\342\244\265", nullptr));
#if QT_CONFIG(shortcut)
        rotateXRightButton->setShortcut(QCoreApplication::translate("MainWindow", "5", nullptr));
#endif // QT_CONFIG(shortcut)
        rotateXLeftButton->setText(QCoreApplication::translate("MainWindow", "\342\244\264", nullptr));
#if QT_CONFIG(shortcut)
        rotateXLeftButton->setShortcut(QCoreApplication::translate("MainWindow", "8", nullptr));
#endif // QT_CONFIG(shortcut)
        rotateZRightButton->setText(QCoreApplication::translate("MainWindow", "\342\206\273", nullptr));
#if QT_CONFIG(shortcut)
        rotateZRightButton->setShortcut(QCoreApplication::translate("MainWindow", "7", nullptr));
#endif // QT_CONFIG(shortcut)
        rotateZLeftButton->setText(QCoreApplication::translate("MainWindow", "\342\206\272", nullptr));
#if QT_CONFIG(shortcut)
        rotateZLeftButton->setShortcut(QCoreApplication::translate("MainWindow", "9", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        plusButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
#if QT_CONFIG(shortcut)
        plusButton->setShortcut(QCoreApplication::translate("MainWindow", "1", nullptr));
#endif // QT_CONFIG(shortcut)
        minusButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
#if QT_CONFIG(shortcut)
        minusButton->setShortcut(QCoreApplication::translate("MainWindow", "3", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
