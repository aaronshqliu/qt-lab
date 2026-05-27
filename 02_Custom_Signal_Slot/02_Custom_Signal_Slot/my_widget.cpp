#include "my_widget.h"
#include "stdafx.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MyWidgetClass()) {
    ui->setupUi(this);

    // 创建两个类的实例
    commander = new Commander(this);
    soldier = new Soldier(this);

#if 0
    // 1、 使用宏 SIGNAL/SLOT
    connect(commander, SIGNAL(go()), soldier, SLOT(fight()));
    connect(commander, SIGNAL(go(QString, int)), soldier, SLOT(fight(QString)));
#endif

#if 0
    // 2、使用自定义函数指针的写法
    void (Commander::*pFuncGo1)() = &Commander::go;
    void (Soldier::*pFuncFight1)() = &Soldier::fight;
    connect(commander, pFuncGo1, soldier, pFuncFight1);

    void (Commander::*pFuncGo2)(QString, int) = &Commander::go;
    void (Soldier::*pFuncFight2)(QString) = &Soldier::fight;
    connect(commander, pFuncGo2, soldier, pFuncFight2);
#endif

#if 0
    // 3、信号槽重载时的精简写法：
    // 建立信号和槽的连接，没有重载可以这样写
    // connect(commander, &Commander::go, soldier, &Soldier::fight);

    // 解决方法：QOverload
    // 它是 Qt5.7 引入的一个模板类，用于解决信号和槽重载时的连接歧义问题，让代码更简洁、可读
    // 基本形式-类模板：QOverload<参数类型列表>::of(&类名::函数名)
    // connect(commander, QOverload<>::of(&Commander::go), soldier, QOverload<>::of(&Soldier::fight));
    // connect(commander, QOverload<QString, int>::of(&Commander::go), soldier, QOverload<QString>::of(&Soldier::fight));

    // 或者使用函数模板 - qOverload
    connect(commander, qOverload<>(&Commander::go), soldier, qOverload<>(&Soldier::fight));
    connect(commander, qOverload<QString, int>(&Commander::go), soldier, qOverload<QString>(&Soldier::fight));

    // 发送信号
    // emit 可省略
    /*emit*/ commander->go();
    commander->go("freedom", 1);
    // 信号参数数量可以多于槽
    // 槽参数数量不能多于信号，
    // 如果槽函数定义的参数比信号传递过来的多，
    // 那么多出来的参数将无法获得有效值，这会导致未定义行为或编译/运行时错误。因此，这条规则是强制性的。
#endif

#if 0
    // 4、一个信号连接多个槽函数
    soldier2 = new Soldier(this);
    connect(commander, qOverload<>(&Commander::go), soldier, qOverload<>(&Soldier::fight));
    connect(commander, qOverload<>(&Commander::go), soldier2, qOverload<>(&Soldier::escape));
    emit commander->go();
#endif

#if 0
    // 5、多个信号连接一个槽
    connect(commander, qOverload<>(&Commander::go), soldier, qOverload<>(&Soldier::fight));
    connect(commander, &Commander::move, soldier, qOverload<>(&Soldier::fight));
    emit commander->go();
    emit commander->move();
#endif

#if 0
    // 6、信号连接信号
    connect(ui->btnSignal2Signal, &QPushButton::clicked, commander, &Commander::move);
    connect(commander, &Commander::move, soldier, &Soldier::escape);
#endif

#if 0
    // 7、取消连接信号
    connect(commander, qOverload<>(&Commander::go), soldier, qOverload<>(&Soldier::fight));
    connect(commander, qOverload<QString, int>(&Commander::go), soldier, qOverload<QString>(&Soldier::fight));
    emit commander->go();

    commander->disconnect();
    emit commander->go("freedom", 1);
#endif

#if 1
    // 8、获取发送信号的对象
    connect(ui->btnStart, &QPushButton::clicked, this, &MyWidget::onBtnClick);
    connect(ui->btnStop, &QPushButton::clicked, this, &MyWidget::onBtnClick);
#endif

}

MyWidget::~MyWidget() { delete ui; }

void MyWidget::onBtnClick()
{
    // qDebug() << "onBtnClick";

    //获取发送信号的对象指针
    QObject *senderObj = sender();
    QPushButton *btn = qobject_cast<QPushButton*>(senderObj);
    if (btn) {
        if (btn == ui->btnStart) {
            qDebug() << "Start";
        } else {
            qDebug() << "Stop";
        }
    }
}
