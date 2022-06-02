#include "controllerbuttonwidget.h"
#include "qfile"

ControllerButtonWidget::ControllerButtonWidget(ControllerButton* button)
    : button(button)
{
    QFile file("./buttonStyle.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);

    auto f = font();
    f.setPointSize(16);
    setFont(f);
    setText(QString::number(button->getFloorNumber()));

    connect(this, &QPushButton::pressed, this, &ControllerButtonWidget::buttonPressed);
    connect(button, &ControllerButton::releasedSignal, this, &ControllerButtonWidget::buttonReleased);
}

ControllerOpenButtonWidget::ControllerOpenButtonWidget(ControllerOpenButton* openButton)
    : openButton(openButton)
{
    QFile file("./buttonStyle.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);

    auto f = font();
    f.setPointSize(16);
    setFont(f);
    setText("<>");

    connect(this, &QPushButton::pressed, this, &ControllerButtonWidget::buttonPressed);
    //connect(openButton, &ControllerButton::releasedSignal, this, &ControllerButtonWidget::buttonReleased);
}

ControllerButton *ControllerButtonWidget::getControllerButton()
{
    return button;
}

void ControllerButtonWidget::buttonPressed()
{
    setDisabled(true);
    button->press();
}

void ControllerButtonWidget::buttonReleased(ControllerButton *button)
{
    setDisabled(false);
}
