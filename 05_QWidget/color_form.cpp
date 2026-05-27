#include "color_form.h"
#include "ui_color_form.h"

ColorForm::ColorForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ColorForm)
{
    ui->setupUi(this);

    colorGroup = new QButtonGroup(this);
    colorGroup->addButton(ui->rBtnRed, 0);
    colorGroup->addButton(ui->rBtnGreen, 1);
    colorGroup->addButton(ui->rBtnBlue, 2);

    connect(colorGroup, &QButtonGroup::idClicked, this, &ColorForm::onColorClicked);
}

ColorForm::~ColorForm()
{
    delete ui;
}

void ColorForm::onColorClicked(int id)
{
    emit colorChanged(id);
}
