#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // QSpinBox改变，QSlider移动
    void(QSpinBox::*spainBoxSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spainBoxSignal, ui->horizontalSlider, &QSlider::setValue);

    // QSlider移动，QSpinBox改变
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->spinBox, &QSpinBox::setValue);

    // 获取当前值
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        qDebug() << getNumber();
    });

    // 滑动到一半
    connect(ui->pushButton_2, &QPushButton::clicked, [=](){
        setNumber(50);
    });
}

void Widget::setNumber(int number)
{
    ui->spinBox->setValue(number);
}

int Widget::getNumber()
{
    return ui->spinBox->value();
}

Widget::~Widget()
{
    delete ui;
}
