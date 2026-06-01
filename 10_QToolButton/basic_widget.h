#ifndef BASIC_WIDGET_H
#define BASIC_WIDGET_H

#include <QWidget>

namespace Ui {
class BasicWidget;
}

class BasicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BasicWidget(QWidget *parent = nullptr);
    ~BasicWidget();

private:
    Ui::BasicWidget *ui;
};

#endif // BASIC_WIDGET_H
