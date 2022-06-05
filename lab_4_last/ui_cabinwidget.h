/********************************************************************************
** Form generated from reading UI file 'cabinwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CABINWIDGET_H
#define UI_CABINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Elevator
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *leftDoor;
    QSpacerItem *spacer;
    QFrame *rightDoor;

    void setupUi(QWidget *Elevator)
    {
        if (Elevator->objectName().isEmpty())
            Elevator->setObjectName(QString::fromUtf8("Elevator"));
        Elevator->resize(260, 450);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Elevator->sizePolicy().hasHeightForWidth());
        Elevator->setSizePolicy(sizePolicy);
        Elevator->setMinimumSize(QSize(260, 450));
        Elevator->setMaximumSize(QSize(260, 450));
        Elevator->setBaseSize(QSize(260, 450));
        horizontalLayout_2 = new QHBoxLayout(Elevator);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        leftDoor = new QFrame(Elevator);
        leftDoor->setObjectName(QString::fromUtf8("leftDoor"));
        QPalette palette;
        QBrush brush(QColor(129, 129, 129, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        leftDoor->setPalette(palette);
        leftDoor->setAutoFillBackground(true);
        leftDoor->setFrameShape(QFrame::StyledPanel);
        leftDoor->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(leftDoor);

        spacer = new QSpacerItem(0, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(spacer);

        rightDoor = new QFrame(Elevator);
        rightDoor->setObjectName(QString::fromUtf8("rightDoor"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        rightDoor->setPalette(palette1);
        rightDoor->setAutoFillBackground(true);
        rightDoor->setFrameShape(QFrame::StyledPanel);
        rightDoor->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(rightDoor);


        retranslateUi(Elevator);

        QMetaObject::connectSlotsByName(Elevator);
    } // setupUi

    void retranslateUi(QWidget *Elevator)
    {
        Elevator->setWindowTitle(QCoreApplication::translate("Elevator", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Elevator: public Ui_Elevator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CABINWIDGET_H
