#include "advanced_widget.h"
#include "ui_advanced_widget.h"

AdvancedWidget::AdvancedWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdvancedWidget)
{
    ui->setupUi(this);
}

AdvancedWidget::~AdvancedWidget()
{
    delete ui;
}
