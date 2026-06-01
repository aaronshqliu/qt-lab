#include "highlight_widget.h"
#include "ui_highlight_widget.h"

HighlightWidget::HighlightWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HighlightWidget)
{
    ui->setupUi(this);
}

HighlightWidget::~HighlightWidget()
{
    delete ui;
}
