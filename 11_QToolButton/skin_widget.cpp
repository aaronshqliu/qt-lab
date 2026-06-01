#include "skin_widget.h"
#include "ui_skin_widget.h"

SkinWidget::SkinWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SkinWidget)
{
    ui->setupUi(this);
}

SkinWidget::~SkinWidget()
{
    delete ui;
}
