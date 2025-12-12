#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent)
    : QLabel{parent}
{
    // 设置鼠标的追踪状态
    setMouseTracking(true);
}

// 鼠标进入事件
void MyLabel::enterEvent(QEvent *ev)
{
    qDebug() << "鼠标进入";
}

// 鼠标离开事件
void MyLabel::leaveEvent(QEvent *ev)
{
    qDebug() << "鼠标离开";
}

// 鼠标按下事件
void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    // 当鼠标左键按下时打印信息
    //if (ev->button() == Qt::LeftButton) {
        QString str = QString("鼠标按下 x: %1, y: %2, globalX: %3, globalY: %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    //}
}

// 鼠标释放事件
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    // 当鼠标左键按下时打印信息
    //if (ev->button() == Qt::LeftButton) {
        qDebug() << "鼠标释放";
    //}
}

// 鼠标移动事件
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    // 当鼠标左键按下时打印信息
    //if (ev->buttons() & Qt::LeftButton) {
        QString str = QString("鼠标移动 x: %1, y: %2, globalX: %3, globalY: %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    //}
}
