#pragma once

#include <QObject>

class Commander  : public QObject
{
	Q_OBJECT

public:
	Commander(QObject *parent);
	~Commander();

signals:
    // 信号只需声明，无需实现
    // 信号返回 void
    void go();
    void go(QString s, int a);

    void move();
};

