#pragma once

#include <QtWidgets/QWidget>
#include "ui_my_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidgetClass; };
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private:
    Ui::MyWidgetClass *ui;
};

