#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

    // 自定义槽函数
    // 早期Qt版本，槽函数必须写到public slots下，高级版本可以写到public或者全局下
    // 返回值void；需要声明，也需要实现；可以有参数，可以发生重载
    void Treat();

    void Treat(QString foodName);

signals:
};

#endif // STUDENT_H
