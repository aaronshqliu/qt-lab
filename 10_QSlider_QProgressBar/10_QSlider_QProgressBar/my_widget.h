#pragma once

#include "ui_my_widget.h"
#include <QTimer>
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
	void onRgbValueChanged();

	void onBtnDownloadClicked();
	void onDownloadTimerTimeout();

private:
	void initUi();
	void initConnections();
	void updateColorDisplay(int r, int g, int b);

	enum class TaskState {
		Idle,        // 空间就绪/等待指令
		Executing,   // 执行中/下载中
		Success,     // 执行成功/下载完成
		Fault        // 链路异常/下载失败（预留扩展）
	};
	void updateUiState(TaskState state);

private:
	Ui::MyWidgetClass* ui;

	static constexpr int COLOR_MIN = 0;
	static constexpr int COLOR_MAX = 255;

	QTimer* downloadTimer;
	int currentProgress; // 当前进度缓存
	static constexpr int PROGRESS_MIN = 0;
	static constexpr int PROGRESS_MAX = 100;
	static constexpr int TIMER_INTERVAL_MS = 50; // 50ms 刷新率，保证高频刷新时的视觉平滑度
	static constexpr int PROGRESS_STEP = 1;      // 单次步进增量
};

