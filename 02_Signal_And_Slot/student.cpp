#include "student.h"
#include <QDebug>

Student::Student(QObject *parent)
    : QObject{parent}
{}

void Student::Treat()
{
    qDebug() << "请老师吃饭";
}

void Student::Treat(QString foodName)
{
    // QString -> char *
    // 先用 toUtf8() 转成 QByteArray，再用 data() 转成 char *
    qDebug() << "请老师吃饭：" << foodName.toUtf8().data();
}
