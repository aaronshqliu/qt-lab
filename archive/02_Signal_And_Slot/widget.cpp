#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建一个老师对象
    this->teacher = new Teacher(this);

    // 创建一个学生对象
    this->student = new Student(this);

    // // 老师饿了，学生请客的连接
    // connect(teacher, &Teacher::Hungry, student, &Student::Treat);

    // // 调用下课函数
    // ClassIsOver();

    // 当信号函数发生重载时，要这么写，否则编译报错。
    // 成员函数的函数地址，要把成员函数的作用域加到函数指针前面
    void (Teacher::*teacherSignal)(QString) = &Teacher::Hungry;
    void (Student::*studentSignal)(QString) = &Student::Treat;
    connect(teacher, teacherSignal, student, studentSignal);

    QPushButton *btn = new QPushButton("下课", this);
    this->resize(600, 400);

    // 点击按钮，触发下课
    // connect(btn, &QPushButton::clicked, this, &Widget::ClassIsOver);

    // 无参信号和槽的连接
    void (Teacher::*teacherSignal2)(void) = &Teacher::Hungry;
    void (Student::*studentSignal2)(void) = &Student::Treat;
    connect(teacher, teacherSignal2, student, studentSignal2);

    // 信号连接信号
    connect(btn, &QPushButton::clicked, teacher, teacherSignal2);

    // 断开信号
    // disconnect(teacher, teacherSignal2, student, studentSignal2);

    /**
     * 拓展：
     * 1、信号可以连接信号
     * 2、一个信号可以连接多个槽函数
     * 3、多个信号可以连接同一个槽函数
     * 4、信号和槽函数的参数类型必须一一对应
     * 5、信号的参数个数可以多于槽函数的参数个数
     */

    // lambda表达式
    // [=](){
    //     btn->setText("aaa");
    // }();

    // QPushButton *myBtn = new QPushButton(this);
    // QPushButton *myBtn2 = new QPushButton(this);
    // myBtn2->move(100, 100);

    // int m = 100;
    // // 值传递数据 m 是只读状态，加上 mutable 修饰后，可以修改按值传递进来的拷贝（注意修改的是拷贝，而不是值本身）
    // connect(myBtn, &QPushButton::clicked, this, [m]()mutable { m += 10; qDebug() << m; });
    // connect(myBtn2, &QPushButton::clicked, this, [=](){ qDebug() << m; });


    // 利用 lambda 表达式，实现点击按钮，关闭窗口
    QPushButton *btn2 = new QPushButton;
    btn2->setParent(this);
    btn2->setText("关闭");
    btn2->move(200, 0);
    connect(btn2, &QPushButton::clicked, this, [=](){
        emit teacher->Hungry("宫保鸡丁");
        this->close();
    });

}

void Widget::ClassIsOver()
{
    // 下课函数，调用后，触发老师饿了的信号
    emit teacher->Hungry("宫保鸡丁");
}


Widget::~Widget()
{
    delete ui;
}
