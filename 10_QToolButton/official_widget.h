#ifndef OFFICIAL_WIDGET_H
#define OFFICIAL_WIDGET_H

#include <QWidget>

namespace Ui {
class OfficialWidget;
}

class OfficialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OfficialWidget(QWidget *parent = nullptr);
    ~OfficialWidget();

private:
    Ui::OfficialWidget *ui;
};

#endif // OFFICIAL_WIDGET_H
