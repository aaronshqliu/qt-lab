#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    // 鼠标进入事件
    void enterEvent(QEvent *ev);
    // 鼠标离开事件
    void leaveEvent(QEvent *ev);
    // 鼠标按下事件
    virtual void mousePressEvent(QMouseEvent *ev);
    // 鼠标释放事件
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    // 鼠标移动事件
    virtual void mouseMoveEvent(QMouseEvent *ev);

signals:
};

#endif // MYLABEL_H
