#pragma once

#include "ui_my_widget.h"
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidgetClass; };
QT_END_NAMESPACE

class MyWidget : public QWidget
{
	Q_OBJECT

public:
	MyWidget(QWidget* parent = nullptr);
	~MyWidget();

private slots:
	void moveToRight();
	void moveToLeft();
	void moveAllToRight();
	void moveAllToLeft();
	void checkButtonStates();

private:
	Ui::MyWidgetClass* ui;
};

