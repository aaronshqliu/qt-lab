#include "widget.h"
#include <QPushButton>  // 按钮空间的头文件
#include <QDebug>
#include "mypushbutton.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 第一种方式创建按钮
    QPushButton *btn1 = new QPushButton;
    // btn->show();  // show是以顶层的方式弹出窗口控件
    // 让btn对象依赖在widget窗口中
    btn1->setParent(this);
    // 设置文本
    btn1->setText("按钮1");

    // 第二种方式创建按钮 按照控件的大小创建窗口
    QPushButton *btn2 = new QPushButton("按钮2", this);
    //移动btn2按钮
    btn2->move(100, 100);
    // 重置窗口的大小
    resize(600, 400);
    // 固定窗口大小
    setFixedSize(600, 400);
    //设置窗口标题
    setWindowTitle("第一个窗口");

    // 创建一个我的按钮的对象
    MyPushButton *myPushButton = new MyPushButton;
    myPushButton->setText("我的按钮");
    myPushButton->move(200, 200);
    myPushButton->setParent(this);  // 设置到对象树中
/*
 * 对象树
 * 1、当创建的对象在堆区的时候，如果指定的父亲是QObject派生下来的类或者QObject子类派生下来的类，
 * 可以不用管理释放的操作，将对象会放入到对象树中
 * 2、一定程度上简化了内存回收机制
*/
/*
 * Qt的坐标系
 * 左上角为(0, 0)点，x以右方向为正，y以下方向为正
 */

    // 需求 点击“我的按钮”，关闭窗口
    /*
     * 参数1：信号的发送者
     * 参数2：发送的信号(函数的地址)
     * 参数3：信号的接受者
     * 参数4：处理的槽函数
     */
    //connect(myPushButton, &MyPushButton::clicked, this, &Widget::close);
    connect(myPushButton, &QPushButton::clicked, this, &QWidget::close);

}

Widget::~Widget()
{
    qDebug() << "widget的析构函数调用";
}
