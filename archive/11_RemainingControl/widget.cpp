#include "widget.h"
#include "ui_widget.h"

#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 栈控件的使用
    // 设置默认第一页
    ui->stackedWidget->setCurrentIndex(2);

    connect(ui->btn_p1, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    connect(ui->btn_p2, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->btn_p3, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });


    // comboBox的使用
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("奥迪");

    // 点击按钮选中奔驰
    connect(ui->btn_benz, &QPushButton::clicked, this, [=](){
        ui->comboBox->setCurrentIndex(0);
    });


    // 利用label组件显示图片
    ui->label->setPixmap(QPixmap(":/resources/open.png"));

    // 利用label组件显示动态图片（gif格式）
    QMovie *movie = new QMovie(":/resources/loading.gif");
    ui->label_movie->setMovie(movie);
    // 播放动图
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}
