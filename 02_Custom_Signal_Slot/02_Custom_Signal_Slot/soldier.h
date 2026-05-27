#ifndef SOLDIER_H
#define SOLDIER_H

#include <QObject>

class Soldier : public QObject
{
    Q_OBJECT
public:
    explicit Soldier(QObject *parent = nullptr);

signals:

// 通常将槽函数添加到slots后面
// 这个slots也可以不写。不过建议写上，以指明这是一个槽函数
// pulic表示槽函数既可以在当前类及其子类的成员函数中调用，也可以在类外部的其它函数（比如`main()`函数）中调用
public slots:
    void fight();
    void fight(QString s);

    void escape();
};

#endif // SOLDIER_H
