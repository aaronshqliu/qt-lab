#include "my_widget.h"
#include <QListWidgetItem>

MyWidget::MyWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::MyWidgetClass())
{
	ui->setupUi(this);

	// 初始化左侧“待选参数”列表
	QStringList sensorParams = {
		"低压转子转速 (N1)",
		"高压转子转速 (N2)",
		"排气温度 (EGT)",
		"燃油流量 (FF)",
		"滑油压力 (OP)",
		"风扇叶片振动幅值",
		"机匣温度"
	};

	// 遍历字符串列表，为每一个字符串创建一个 QListWidgetItem 并加入左侧列表
	for (const QString& paramName : sensorParams) {
		QListWidgetItem* item = new QListWidgetItem(paramName);
		QIcon icon(":/icons/sensor.png");
		item->setIcon(icon);
		ui->lstAvailable->addItem(item);
	}

	// 初始状态下，禁用左移和右移按钮 (防呆设计：因为现在什么都没选中)
	ui->btnMoveToRight->setEnabled(false);
	ui->btnMoveToLeft->setEnabled(false);

	connect(ui->btnMoveToRight, &QPushButton::clicked, this, &MyWidget::moveToRight);
	connect(ui->btnMoveToLeft, &QPushButton::clicked, this, &MyWidget::moveToLeft);
	connect(ui->btnMoveAllToRight, &QPushButton::clicked, this, &MyWidget::moveAllToRight);
	connect(ui->btnMoveAllToLeft, &QPushButton::clicked, this, &MyWidget::moveAllToLeft);

	connect(ui->lstAvailable, &QListWidget::itemSelectionChanged, this, &MyWidget::checkButtonStates);
	connect(ui->lstSelected, &QListWidget::itemSelectionChanged, this, &MyWidget::checkButtonStates);

	checkButtonStates();
}

MyWidget::~MyWidget()
{
	delete ui;
}

void MyWidget::moveToRight()
{
	QList<QListWidgetItem*> selectedItems = ui->lstAvailable->selectedItems();

	for (QListWidgetItem* item : selectedItems) {
		// 1. 必须先获取这个 item 在原列表中的行号
		int row = ui->lstAvailable->row(item);

		// 2. 使用 takeItem 将它从原列表中“拔”出来。
		// 注意：takeItem 只是把它从 UI 界面上剥离，并没有 delete 它的内存！
		ui->lstAvailable->takeItem(row);

		// 3. 将这块内存重新插入到右侧列表中。完美实现了转移，且没有内存泄漏。
		ui->lstSelected->addItem(item);
	}
	checkButtonStates();
}

void MyWidget::moveToLeft()
{
	QList<QListWidgetItem*> selectedItems = ui->lstSelected->selectedItems();

	for (QListWidgetItem* item : selectedItems) {
		int row = ui->lstSelected->row(item);
		ui->lstSelected->takeItem(row);
		ui->lstAvailable->addItem(item);
	}
	checkButtonStates();
}

void MyWidget::moveAllToRight()
{
	// 只要左边还有东西，就一直拔出第 0 行，塞到右边
	while (ui->lstAvailable->count() > 0)
	{
		QListWidgetItem* item = ui->lstAvailable->takeItem(0);
		ui->lstSelected->addItem(item);
	}
	checkButtonStates();
}

void MyWidget::moveAllToLeft()
{
	while (ui->lstSelected->count() > 0)
	{
		QListWidgetItem* item = ui->lstSelected->takeItem(0);
		ui->lstAvailable->addItem(item);
	}
	checkButtonStates();
}

void MyWidget::checkButtonStates()
{
	// 如果左侧有选中项，才允许点击 ">"
	bool hasAvailableSelected = (ui->lstAvailable->selectedItems().count() > 0);
	ui->btnMoveToRight->setEnabled(hasAvailableSelected);

	// 如果右侧有选中项，才允许点击 "<"
	bool hasSelectedSelected = (ui->lstSelected->selectedItems().count() > 0);
	ui->btnMoveToLeft->setEnabled(hasSelectedSelected);

	// 如果左侧/右侧完全空了，对应的 ">>" 和 "<<" 也应该置灰
	ui->btnMoveAllToRight->setEnabled(ui->lstAvailable->count() > 0);
	ui->btnMoveAllToLeft->setEnabled(ui->lstSelected->count() > 0);
}
