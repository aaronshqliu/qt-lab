#include "style_form.h"
#include "ui_style_form.h"

StyleForm::StyleForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StyleForm)
{
    ui->setupUi(this);

    connect(ui->cBoxBold, &QCheckBox::clicked, this, &StyleForm::onStyleClicked);
    connect(ui->cBoxItalic, &QCheckBox::clicked, this, &StyleForm::onStyleClicked);
    connect(ui->cBoxUnderline, &QCheckBox::clicked, this, &StyleForm::onStyleClicked);
}

StyleForm::~StyleForm()
{
    delete ui;
}

void StyleForm::onStyleClicked()
{
    emit styleChanged(ui->cBoxBold->isChecked(), ui->cBoxItalic->isChecked(), ui->cBoxUnderline->isChecked());
}
