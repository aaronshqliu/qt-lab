#include "official_widget.h"
#include "ui_official_widget.h"

OfficialWidget::OfficialWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OfficialWidget)
{
    ui->setupUi(this);
}

OfficialWidget::~OfficialWidget()
{
    delete ui;
}
