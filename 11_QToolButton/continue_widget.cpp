#include "continue_widget.h"
#include "ui_continue_widget.h"

ContinueWidget::ContinueWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ContinueWidget)
{
    ui->setupUi(this);
}

ContinueWidget::~ContinueWidget()
{
    delete ui;
}
