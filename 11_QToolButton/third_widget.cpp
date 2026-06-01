#include "third_widget.h"
#include "ui_third_widget.h"

ThirdWidget::ThirdWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ThirdWidget)
{
    ui->setupUi(this);
}

ThirdWidget::~ThirdWidget()
{
    delete ui;
}
