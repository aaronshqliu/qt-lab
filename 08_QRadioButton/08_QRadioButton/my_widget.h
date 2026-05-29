#pragma once

#include <QtWidgets/QWidget>
#include "ui_my_widget.h"
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidgetClass; };
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void handleShow();
    void handleChecked();
    void handleMale3Toggled(bool checked);

private:
    Ui::MyWidgetClass *ui;
    QButtonGroup* bgGender;
    QButtonGroup* bgEducation;
};

