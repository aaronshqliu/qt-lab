#ifndef PANEL_WIDGET_H
#define PANEL_WIDGET_H

#include <QWidget>

namespace Ui {
class PanelWidget;
}

class PanelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PanelWidget(QWidget *parent = nullptr);
    ~PanelWidget();

private:
    Ui::PanelWidget *ui;
};

#endif // PANEL_WIDGET_H
