/********************************************************************************
** Form generated from reading UI file 'controllerwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLERWIDGET_H
#define UI_CONTROLLERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Controller
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *buttonsLayout;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *buttonsLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Controller)
    {
        if (Controller->objectName().isEmpty())
            Controller->setObjectName(QString::fromUtf8("Controller"));
        Controller->resize(262, 466);
        QPalette palette;
        Controller->setPalette(palette);
        gridLayout = new QGridLayout(Controller);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(4, 4, 4, 4);
        label_2 = new QLabel(Controller);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic UI Light")});
        font.setPointSize(20);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(Controller);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Yu Gothic UI Light")});
        font1.setPointSize(14);
        label->setFont(font1);
        label->setTextFormat(Qt::PlainText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 2);

        lcdNumber = new QLCDNumber(Controller);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(lcdNumber, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        buttonsLayout = new QVBoxLayout();
        buttonsLayout->setSpacing(25);
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));

        horizontalLayout->addLayout(buttonsLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        buttonsLayout_2 = new QVBoxLayout();
        buttonsLayout_2->setSpacing(25);
        buttonsLayout_2->setObjectName(QString::fromUtf8("buttonsLayout_2"));

        horizontalLayout->addLayout(buttonsLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 5, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 2);


        retranslateUi(Controller);

        QMetaObject::connectSlotsByName(Controller);
    } // setupUi

    void retranslateUi(QWidget *Controller)
    {
        Controller->setWindowTitle(QCoreApplication::translate("Controller", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Controller", "\320\255\321\202\320\260\320\266:", nullptr));
        label->setText(QCoreApplication::translate("Controller", "\320\237\320\260\320\275\320\265\320\273\321\214 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Controller: public Ui_Controller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLERWIDGET_H
