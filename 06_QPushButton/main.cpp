#include "my_widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MYWidget w;
    w.show();
    return QApplication::exec();
}
