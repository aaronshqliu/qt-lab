#include "stdafx.h"
#include "my_widget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MyWidget window;
    window.show();
    return app.exec();
}
