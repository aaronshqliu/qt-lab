#include "widget.h"
// 包含应用程序类头文件
#include <QApplication>

int main(int argc, char *argv[])
{
    // a -> 应用程序对象，在QT中，应用程序对象有且仅有一个
    QApplication a(argc, argv);
    // 窗口对象
    Widget w;
    // 窗口对象默认不会显示，必须调用show()
    w.show();
    // 让应用程序对象进入消息循环
    return a.exec();
}
