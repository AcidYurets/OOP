#include "cabinwidget.h"
#include "ui_cabinwidget.h"


CabinWidget::CabinWidget(Cabin* cabin, Door* door)
    : ui(new Ui::Elevator), cabin(cabin), door(door)
{
    ui->setupUi(this);

    connect(door, &Door::doorsAnimationSignal, this, &CabinWidget::changeDoorsOpeningState);
}

CabinWidget::~CabinWidget()
{
    delete ui;
}


void CabinWidget::changeDoorsOpeningState(int openingValue)
{
    int h = ui->spacer->sizeHint().height();
    ui->spacer->changeSize(openingValue, h);
    layout()->invalidate();
}
