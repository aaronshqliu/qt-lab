#ifndef THIRD_WIDGET_H
#define THIRD_WIDGET_H

#include <QWidget>

namespace Ui {
class ThirdWidget;
}

class ThirdWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ThirdWidget(QWidget *parent = nullptr);
    ~ThirdWidget();

private:
    Ui::ThirdWidget *ui;
};

#endif // THIRD_WIDGET_H
