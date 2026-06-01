#ifndef WEATHER_WIDGET_H
#define WEATHER_WIDGET_H

#include <QWidget>

namespace Ui {
class WeatherWidget;
}

class WeatherWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherWidget(QWidget *parent = nullptr);
    ~WeatherWidget();

private:
    Ui::WeatherWidget *ui;
};

#endif // WEATHER_WIDGET_H
