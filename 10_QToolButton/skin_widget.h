#ifndef SKIN_WIDGET_H
#define SKIN_WIDGET_H

#include <QWidget>

namespace Ui {
class SkinWidget;
}

class SkinWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SkinWidget(QWidget *parent = nullptr);
    ~SkinWidget();

private:
    Ui::SkinWidget *ui;
};

#endif // SKIN_WIDGET_H
