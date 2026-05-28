#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QButtonGroup>
#include <QTimer>
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
    // 1、内嵌窗口和独立窗口
    void onAlignClicked(int id);
    void onStyleChanged(bool bold, bool italic, bool underline);
    void onColorChanged(int id);

    // 2、窗口的位置和大小
    void on_pBtnGetWindow_clicked();
    void on_pBtnSetWindow_clicked();
    void on_pBtnMoveWindow_clicked();

    // 3、设置窗口标题和图标
    void on_pBtnSetTitle_clicked();
    void on_pBtnUpdateIcon_clicked();

    // 4、换行
    void on_pushButtonAllowWrap_clicked();
    void on_pushButtonDisableWrap_clicked();

    // 定时器
    void OnTimeOut();

private:
    Ui::MyWidget *ui;
    QButtonGroup *alignGroup;
    QTimer *timer;
};
#endif // MY_WIDGET_H
