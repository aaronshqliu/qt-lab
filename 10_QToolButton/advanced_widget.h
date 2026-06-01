#ifndef ADVANCED_WIDGET_H
#define ADVANCED_WIDGET_H

#include <QWidget>

namespace Ui {
class AdvancedWidget;
}

class AdvancedWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AdvancedWidget(QWidget *parent = nullptr);
    ~AdvancedWidget();

private:
    Ui::AdvancedWidget *ui;
};

#endif // ADVANCED_WIDGET_H
