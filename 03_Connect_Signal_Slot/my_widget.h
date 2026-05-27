#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyWidget;
}
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget() override;

private slots:
    void on_btnMini_clicked();

private:
    Ui::MyWidget *ui;
};
#endif // MY_WIDGET_H
