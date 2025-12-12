#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // treeWidget控件的使用
    // 设置水平头（这里使用了QStringList的匿名对象）
    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "英雄介绍");

    // 加载顶层节点
    QTreeWidgetItem *powerItem = new QTreeWidgetItem(QStringList() << "力量");
    QTreeWidgetItem *speedItem = new QTreeWidgetItem(QStringList() << "敏捷");
    QTreeWidgetItem *intelligenceItem = new QTreeWidgetItem(QStringList() << "智力");
    ui->treeWidget->addTopLevelItem(powerItem);
    ui->treeWidget->addTopLevelItem(speedItem);
    ui->treeWidget->addTopLevelItem(intelligenceItem);

    // 追加子节点
    QTreeWidgetItem *powerHero1 = new QTreeWidgetItem(QStringList() << "A" << "abcd");
    powerItem->addChild(powerHero1);
    QTreeWidgetItem *powerHero2= new QTreeWidgetItem(QStringList() << "B" << "abcd");
    powerItem->addChild(powerHero2);
}

Widget::~Widget()
{
    delete ui;
}
