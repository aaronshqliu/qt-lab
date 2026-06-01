#include "weather_widget.h"
#include "ui_weather_widget.h"

WeatherWidget::WeatherWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WeatherWidget)
{
    ui->setupUi(this);
}

WeatherWidget::~WeatherWidget()
{
    delete ui;
}
