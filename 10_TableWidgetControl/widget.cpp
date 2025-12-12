#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // TableWidget控件
    // 设置列数
    ui->tableWidget->setColumnCount(3);

    // 设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");

    // 设置行数
    ui->tableWidget->setRowCount(5);

    // 设置正文
    // ui->tableWidget->setItem(0, 0, new QTableWidgetItem("亚瑟"));

    // 姓名列
    QStringList name;
    name << "A" << "B" << "C" << "D" << "E";

    // 性别列
    QList<QString> gender;
    gender << "1" << "2" << "3" << "4" << "5";

    for (int i = 0; i < 5; i++) {
        int column = 0;
        ui->tableWidget->setItem(i, column++, new QTableWidgetItem(name[i]));
        ui->tableWidget->setItem(i, column++, new QTableWidgetItem(gender[i]));
        ui->tableWidget->setItem(i, column++, new QTableWidgetItem(QString::number(18)));
    }
}

Widget::~Widget()
{
    delete ui;
}
