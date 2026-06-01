#ifndef CONTINUE_WIDGET_H
#define CONTINUE_WIDGET_H

#include <QWidget>

namespace Ui {
class ContinueWidget;
}

class ContinueWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ContinueWidget(QWidget *parent = nullptr);
    ~ContinueWidget();

private:
    Ui::ContinueWidget *ui;
};

#endif // CONTINUE_WIDGET_H
