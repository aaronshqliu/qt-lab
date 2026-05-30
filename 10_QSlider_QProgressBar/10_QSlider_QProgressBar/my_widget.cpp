#include "my_widget.h"

#include <QSlider>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidgetClass())
    , downloadTimer(new QTimer(this))
    , currentProgress(PROGRESS_MIN)
{
	ui->setupUi(this);

	// 滑动条 - QSlider
	initUi();
	initConnections();
	onRgbValueChanged();
}

MyWidget::~MyWidget()
{
	delete ui;
}

void MyWidget::initUi()
{
	for (QSlider* slider : { ui->sldRed, ui->sldGreen, ui->sldBlue }) {
		slider->setRange(COLOR_MIN, COLOR_MAX);
		slider->setSingleStep(5);
		slider->setPageStep(5);
		slider->setTickPosition(QSlider::TicksAbove);
		slider->setTickInterval(50);
	}
	for (QLineEdit* edit : { ui->edtRed, ui->edtGreen, ui->edtBlue }) {
		edit->setReadOnly(true);
	}
	ui->txtColor->setReadOnly(true);

	ui->prgDownload->setRange(PROGRESS_MIN, PROGRESS_MAX);
	ui->prgDownload->setValue(PROGRESS_MIN);
	// %p% 是 Qt 内置占位符（代表百分比），后面追加上下文状态，方便操作员审阅
	ui->prgDownload->setFormat(QStringLiteral("%p% (等待握手...)"));
	ui->prgDownload->setAlignment(Qt::AlignCenter);
}

void MyWidget::initConnections()
{
	connect(ui->sldRed, &QSlider::valueChanged, this, &MyWidget::onRgbValueChanged);
	connect(ui->sldGreen, &QSlider::valueChanged, this, &MyWidget::onRgbValueChanged);
	connect(ui->sldBlue, &QSlider::valueChanged, this, &MyWidget::onRgbValueChanged);

	connect(ui->btnDownload, &QPushButton::clicked, this, &MyWidget::onBtnDownloadClicked);
	connect(downloadTimer, &QTimer::timeout, this, &MyWidget::onDownloadTimerTimeout);
}

void MyWidget::onRgbValueChanged()
{

	const int r = ui->sldRed->value();
	const int g = ui->sldGreen->value();
	const int b = ui->sldBlue->value();
	updateColorDisplay(r, g, b);
}

void MyWidget::updateColorDisplay(int r, int g, int b)
{
	ui->edtRed->setText(QString::number(r));
	ui->edtGreen->setText(QString::number(g));
	ui->edtBlue->setText(QString::number(b));

	// 使用 QStringLiteral 宏处理不变的字符串模板。
	// 在编译期就生成了字符串数据，避免了运行时的堆内存分配，提升渲染高频触发时的性能。
	const QString qss = QStringLiteral("background-color: rgb(%1, %2, %3);")
		.arg(r).arg(g).arg(b);
	ui->txtColor->setStyleSheet(qss);
}

void MyWidget::updateUiState(TaskState state)
{
	switch (state) {
	case TaskState::Idle:
		ui->btnDownload->setEnabled(true);
		ui->btnDownload->setText(QStringLiteral("开始下载"));
		ui->prgDownload->setValue(PROGRESS_MIN);
		ui->prgDownload->setFormat(QStringLiteral("就绪，等待下发指令..."));
		break;

	case TaskState::Executing:
		ui->btnDownload->setEnabled(false);
		ui->btnDownload->setText(QStringLiteral("下载中..."));
		ui->prgDownload->setFormat(QStringLiteral("正在写入数据区块... %p%"));
		break;

	case TaskState::Success:
		ui->btnDownload->setEnabled(true);
		ui->btnDownload->setText(QStringLiteral("重新下载"));
		ui->prgDownload->setFormat(QStringLiteral("数据校验通过，下载成功！"));
		break;

	case TaskState::Fault:
		ui->btnDownload->setEnabled(true);
		ui->btnDownload->setText(QStringLiteral("清除错误并重试"));
		ui->prgDownload->setFormat(QStringLiteral("下载终止：帧校验失败(CRC)"));
		break;
	}
}

void MyWidget::onBtnDownloadClicked()
{
	currentProgress = PROGRESS_MIN;
	updateUiState(TaskState::Executing);
	downloadTimer->start(TIMER_INTERVAL_MS);
}
void MyWidget::onDownloadTimerTimeout()
{
	currentProgress += PROGRESS_STEP;
	// 绝不能仅用 == 判断，必须用 >= 防止步进值改变时越界
	if (currentProgress >= PROGRESS_MAX) {
		downloadTimer->stop();  // 必须先关闭定时器停止触发
		ui->prgDownload->setValue(PROGRESS_MAX); // 强制归正边界值
		updateUiState(TaskState::Success);  // 状态机流转至成功
	}
	else {
		ui->prgDownload->setValue(currentProgress);
	}
}
