#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置单选按钮 默认男选中
    ui->radioButton->setChecked(true);
    // 选中 女 后，打印信息
    connect(ui->radioButton_2, &QRadioButton::clicked, [=](){
        qDebug() << "选中 女";
    });


    // 多选按钮  2是选中 0是未选中
    // tristate 开启半选中状态后，state返回1
    connect(ui->checkBox, &QCheckBox::stateChanged, [=](int state){
        qDebug() << state;
    });
}

Widget::~Widget()
{
    delete ui;
}
