#ifndef FONT_WIDGET_H
#define FONT_WIDGET_H

#include <QWidget>

namespace Ui {
class FontWidget;
}

class FontWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FontWidget(QWidget *parent = nullptr);
    ~FontWidget();

private:
    Ui::FontWidget *ui;
};

#endif // FONT_WIDGET_H
