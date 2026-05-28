#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#include <QButtonGroup>
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
    // 字体设置
    void onPushButtonGroupAlignClicked(int id);
    void onFontStyleClicked();

    // 读写控制
    void on_pushButtonRw_clicked();
    void on_pushButtonReadOnly_clicked();
    void on_pushButtonDisable_clicked();
    void on_pushButtonEnable_clicked();

    // 回显模式
    void onEchoModeClicked(int id);
    void on_pushButtonShow_clicked();

    // 格式控制
    void onPushButtonGroupStyleCtrlClicked(int id);

    // 信号槽
    void on_lineEditAdd1_textChanged(const QString &arg1);
    void on_lineEditAdd2_textChanged(const QString &arg1);
    void on_lineEditSub1_editingFinished();
    void on_lineEditSub2_editingFinished();

private:
    Ui::MyWidget *ui;
    QButtonGroup *alignGroup;
    QButtonGroup *echoModeGroup;
    QButtonGroup *styleCtrlGroup;
};
#endif // MY_WIDGET_H
