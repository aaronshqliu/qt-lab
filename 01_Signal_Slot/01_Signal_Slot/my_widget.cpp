#include "my_widget.h"

#include <QPushButton>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidgetClass())
{
    ui->setupUi(this);

    // 关联信号槽
    connect(ui->btnMax, &QPushButton::clicked, this, &QWidget::showMaximized);
    connect(ui->btnMini, &QPushButton::clicked, this, &QWidget::showMinimized);
    connect(ui->btnNormal, &QPushButton::clicked, this, &QWidget::showNormal);
    connect(ui->btnClose, &QPushButton::clicked, this, &QWidget::close);
}

MyWidget::~MyWidget()
{
    delete ui;
}
