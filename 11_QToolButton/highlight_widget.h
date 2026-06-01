#ifndef HIGHLIGHT_WIDGET_H
#define HIGHLIGHT_WIDGET_H

#include <QWidget>

namespace Ui {
class HighlightWidget;
}

class HighlightWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HighlightWidget(QWidget *parent = nullptr);
    ~HighlightWidget();

private:
    Ui::HighlightWidget *ui;
};

#endif // HIGHLIGHT_WIDGET_H
