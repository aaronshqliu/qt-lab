#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QButtonGroup>
#include <QTableWidgetItem>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyWidget;
}
QT_END_NAMESPACE

struct Person
{
    QString name;
    QString gender;
    int age;
    QString homedown;
};

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget() override;

    void appendOneRow(const Person &person);
    void insertOneRow(int row, const Person &person);

private slots:
    void addPerson();
    void insertPerson();
    void modifyPerson();
    void deletePerson();

private:
    void setPersonRow(int row, const Person &person);

private:
    Ui::MyWidget *ui;
    QButtonGroup *selectedGroup;
};
#endif // MY_WIDGET_H
