#ifndef WIDGET_H
#define WIDGET_H

#include <QButtonGroup>
#include <QToolButton>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private:
    Ui::Widget *ui;
    QButtonGroup *tbtnGroup;
    struct PageMapping
    {
        QToolButton *tbtn;
        QWidget *page;
    };
};
#endif // WIDGET_H
