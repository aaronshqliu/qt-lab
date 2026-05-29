#include "my_widget.h"
#include <QDebug>
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidgetClass())
{
    ui->setupUi(this);

    // 不同 widget 分组中的 radioButton 不互斥
    ui->rdoMale1->setChecked(true);
    ui->rdoDoctor1->setChecked(true);

    // 不同 GroupBox 分组中的 radioButton 不互斥
    ui->rdoMale2->setChecked(true);
    ui->rdoDoctor2->setChecked(true);

    // 打印选择结果
    connect(ui->btnShow, &QPushButton::clicked, this, &MyWidget::handleShow);

    // 不同 ButtonGroup 中的 radioButton
    bgGender = new QButtonGroup(this);
    bgGender->addButton(ui->rdoMale3, 0);
    bgGender->addButton(ui->rdoFemale3, 1);

    bgEducation = new QButtonGroup(this);
    bgEducation->addButton(ui->rdoDoctor3, 10);
    bgEducation->addButton(ui->rdoMaster3, 11);
    bgEducation->addButton(ui->rdoBachelor3, 12);
    bgEducation->addButton(ui->rdoOther3, 13);

    connect(bgGender, &QButtonGroup::idClicked, this, &MyWidget::handleChecked);
    connect(bgEducation, &QButtonGroup::idClicked, this, &MyWidget::handleChecked);
    connect(ui->rdoMale3, &QRadioButton::toggled, this, &MyWidget::handleMale3Toggled);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::handleShow()
{
    QString res;
    if (ui->rdoMale2->isChecked()) {
        res += ui->rdoMale2->text();
    }
    else if (ui->rdoFemale2->isChecked()) {
        res += ui->rdoFemale2->text();
    }

    if (ui->rdoDoctor2->isChecked()) {
        res += ui->rdoDoctor2->text();
    }
    else if (ui->rdoMaster2->isChecked()) {
        res += ui->rdoMaster2->text();
    }
    else if (ui->rdoBachelor2->isChecked()) {
        res += ui->rdoBachelor2->text();
    }
    else if (ui->rdoOther2->isChecked()) {
        res += ui->rdoOther2->text();
    }
    ui->edt2->setText(res);
}

void MyWidget::handleChecked()
{
    QString res;

    QAbstractButton *checkedGender =  bgGender->checkedButton();
    if (checkedGender != nullptr) {
        res += checkedGender->text();
    }

    QAbstractButton* checkedEducation = bgEducation->checkedButton();
    if (checkedEducation != nullptr) {
        res += checkedEducation->text();
    }
   
    ui->edt3->setText(res);
}

void MyWidget::handleMale3Toggled(bool checked)
{
    qDebug() << "Male4: " << checked;
}
