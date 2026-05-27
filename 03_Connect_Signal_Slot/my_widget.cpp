#include "my_widget.h"
#include "./ui_my_widget.h"
#include <QDateTime>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 1、使用SIGNAL/SLOT的方式连接信号槽
    // SIGNAL/SLOT是两个宏，它们会将函数名以及对应的参数，转换为字符串。
    // 这种方式，编译器不会做错误检查，即使函数名或者参数写错了，也可以编译通过，这样就把问题留在了运行阶段。
    // 而我们编程开发的一个原则是尽可能早地发现并规避问题，因此这种方式不被推荐。
    connect(ui->btnMax, SIGNAL(clicked(bool)), this, SLOT(showMaximized()));

    // 2、使用函数地址的方式
    // 使用这种方式，由于无法指定函数的参数，因此如果有重载的信号和槽时，编译器会产生二义性。
    // 解决方法：使用QOverload
    connect(ui->btnNormal, &QPushButton::clicked, this, &QWidget::showNormal);

    // 5、使用lamdba表达式
    connect(ui->btnModifyTitle, &QPushButton::clicked, this, [this]() {
        QString title = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
        this->setWindowTitle(title);
    });
}

MyWidget::~MyWidget()
{
    delete ui;
}

// 3. 设计师界面-转到槽的方式
// 致命缺陷：静默失效（Silent Breakage）
// 必须极其符合特定格式的函数名，规则是：on_ + 对象名 + _ + 信号名。
void MyWidget::on_btnMini_clicked()
{
    showMinimized();
}

