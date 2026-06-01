#include "basic_widget.h"
#include "ui_basic_widget.h"

BasicWidget::BasicWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BasicWidget)
{
    ui->setupUi(this);
}

BasicWidget::~BasicWidget()
{
    delete ui;
}
