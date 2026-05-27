#include "soldier.h"
#include <QDebug>

Soldier::Soldier(QObject *parent)
    : QObject{parent}
{}

void Soldier::fight()
{
    qDebug() << "fight";
}

void Soldier::fight(QString s)
{
    // qDebug() << "fight for " << s;  // fight for  "freedom"

    // 禁用字符串输出的自动引号包裹
    qDebug().noquote() << "fight for" << s;
}

void Soldier::escape()
{
    qDebug() << "escape";
}
