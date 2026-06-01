#include "font_widget.h"
#include "ui_font_widget.h"

FontWidget::FontWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FontWidget)
{
    ui->setupUi(this);
}

FontWidget::~FontWidget()
{
    delete ui;
}
