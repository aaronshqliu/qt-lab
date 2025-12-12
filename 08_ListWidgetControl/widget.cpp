#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 利用listWideget写一首诗
    // 方式1
    // QListWidgetItem *item1 = new QListWidgetItem("床前明月光");
    // QListWidgetItem *item2 = new QListWidgetItem("疑是地上霜");
    // QListWidgetItem *item3 = new QListWidgetItem("举头望明月");
    // QListWidgetItem *item4 = new QListWidgetItem("低头思故乡");
    // // 放到ListWidget控件中
    // ui->listWidget->addItem(item1);
    // ui->listWidget->addItem(item2);
    // ui->listWidget->addItem(item3);
    // ui->listWidget->addItem(item4);
    // // 设置水平居中
    // item1->setTextAlignment(Qt::AlignCenter);
    // item2->setTextAlignment(Qt::AlignCenter);
    // item3->setTextAlignment(Qt::AlignCenter);
    // item4->setTextAlignment(Qt::AlignCenter);

    // 方式2
    QStringList labels;
    labels << "床前明月光" << "疑是地上霜" << "举头望明月" << "低头思故乡";
    ui->listWidget->addItems(labels);
}

Widget::~Widget()
{
    delete ui;
}
