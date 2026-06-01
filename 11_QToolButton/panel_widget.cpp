#include "panel_widget.h"
#include "ui_panel_widget.h"

PanelWidget::PanelWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PanelWidget)
{
    ui->setupUi(this);
}

PanelWidget::~PanelWidget()
{
    delete ui;
}
