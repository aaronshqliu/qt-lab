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
    void on_pBtnStart_clicked();
    void on_pBtnStop_clicked();
    void on_pBtnUp_clicked();
    void on_pBtnDown_clicked();
    void on_pBtnLeft_clicked();
    void on_pBtnRight_clicked();
    void on_pBtnReset_clicked();

private:
    void moveLabelBy(int dx, int dy);

    Ui::MyWidget *ui;
    static const int MOVE_STEP = 10;
};
#endif // MY_WIDGET_H
