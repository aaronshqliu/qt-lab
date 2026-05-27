#include "my_widget.h"
#include "./ui_my_widget.h"

MYWidget::MYWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MYWidget)
{
    ui->setupUi(this);

    // 1、文本、图标、使能
    ui->pBtnOk->setText("确定");
    ui->pBtnOk->setFont(QFont("黑体", 12));
    ui->pBtnOk->setIcon(QIcon(":/icon/ok.png"));
    ui->pBtnOk->setIconSize(QSize(20, 20));

    ui->pBtnCancel->setText("取消");
    ui->pBtnCancel->setFont(QFont("黑体", 12));
    ui->pBtnCancel->setIcon(QIcon(":/icon/cancel.png"));
    ui->pBtnCancel->setIconSize(QSize(20, 20));

    ui->pBtnStart->setText("开始");
    ui->pBtnStart->setFont(QFont("黑体", 12));
    ui->pBtnStart->setIcon(QIcon(":/icon/start.png"));
    ui->pBtnStart->setIconSize(QSize(20, 20));

    ui->pBtnStop->setText("停止");
    ui->pBtnStop->setFont(QFont("黑体", 12));
    ui->pBtnStop->setIcon(QIcon(":/icon/stop.png"));
    ui->pBtnStop->setIconSize(QSize(20, 20));

    ui->pBtnStart->setEnabled(true);
    ui->pBtnStop->setDisabled(true);

    // 2、标签样式
    ui->pBtnUp->setText("");
    ui->pBtnUp->setStyleSheet(R"(
QPushButton {
    border-image: url(:/icon/up_normal.png);
}

QPushButton:hover {
    border-image: url(:/icon/up_hover.png);
}

QPushButton:pressed {
    border-image: url(:/icon/up_pressed.png);
}
    )");

    ui->pBtnDown->setText("");
    ui->pBtnDown->setStyleSheet(R"(
QPushButton {
    border-image: url(:/icon/down_normal.png);
}

QPushButton:hover {
    border-image: url(:/icon/down_hover.png);
}

QPushButton:pressed {
    border-image: url(:/icon/down_pressed.png);
}
    )");

    ui->pBtnLeft->setText("");
    ui->pBtnLeft->setStyleSheet(R"(
QPushButton {
    border-image: url(:/icon/left_normal.png);
}

QPushButton:hover {
    border-image: url(:/icon/left_hover.png);
}

QPushButton:pressed {
    border-image: url(:/icon/left_pressed.png);
}
    )");

    ui->pBtnRight->setText("");
    ui->pBtnRight->setStyleSheet(R"(
QPushButton {
    border-image: url(:/icon/right_normal.png);
}

QPushButton:hover {
    border-image: url(:/icon/right_hover.png);
}

QPushButton:pressed {
    border-image: url(:/icon/right_pressed.png);
}
    )");

    ui->pBtnReset->setText("");
    ui->pBtnReset->setStyleSheet(R"(
QPushButton {
    border-image: url(:/icon/reset_normal.png);
}

QPushButton:hover {
    border-image: url(:/icon/reset_hover.png);
}

QPushButton:pressed {
    border-image: url(:/icon/reset_pressed.png);
}
    )");

    // 3、自动连发
    ui->pBtnUp->setAutoRepeat(true);     // 開啟自動連發
    ui->pBtnUp->setAutoRepeatDelay(500); // 設定長按多長時間後開始連發（單位：毫秒，500ms = 0.5秒）
    ui->pBtnUp->setAutoRepeatInterval(
        50); // 設定連發的時間間隔（單位：毫秒，50ms 代表每秒觸發 20 次）

    ui->pBtnDown->setAutoRepeat(true);
    ui->pBtnDown->setAutoRepeatDelay(500);
    ui->pBtnDown->setAutoRepeatInterval(50);

    ui->pBtnLeft->setAutoRepeat(true);
    ui->pBtnLeft->setAutoRepeatDelay(500);
    ui->pBtnLeft->setAutoRepeatInterval(50);

    ui->pBtnRight->setAutoRepeat(true);
    ui->pBtnRight->setAutoRepeatDelay(500);
    ui->pBtnRight->setAutoRepeatInterval(50);

    // 4、设置快捷键
    ui->pBtnUp->setShortcut(QKeySequence(Qt::Key_Up));
    ui->pBtnDown->setShortcut(QKeySequence(Qt::Key_Down));
    ui->pBtnLeft->setShortcut(QKeySequence(Qt::Key_Left));
    ui->pBtnRight->setShortcut(QKeySequence(Qt::Key_Right));
    ui->pBtnReset->setShortcut(QKeySequence(Qt::Key_Home));
}

MYWidget::~MYWidget()
{
    delete ui;
}

void MYWidget::on_pBtnStart_clicked()
{
    ui->pBtnStart->setDisabled(true);
    ui->pBtnStop->setEnabled(true);
}

void MYWidget::on_pBtnStop_clicked()
{
    ui->pBtnStart->setEnabled(true);
    ui->pBtnStop->setDisabled(true);
}

void MYWidget::on_pBtnUp_clicked()
{
    moveLabelBy(0, -MOVE_STEP);
}

void MYWidget::on_pBtnDown_clicked()
{
    moveLabelBy(0, MOVE_STEP);
}

void MYWidget::on_pBtnLeft_clicked()
{
    moveLabelBy(-MOVE_STEP, 0);
}

void MYWidget::on_pBtnRight_clicked()
{
    moveLabelBy(MOVE_STEP, 0);
}

void MYWidget::on_pBtnReset_clicked()
{
    // 获取父控件的大小
    QWidget *parentWidget = ui->labelMove->parentWidget();
    QRect parentRect = parentWidget->rect();
    QRect lableRect = ui->labelMove->rect();

    // 计算子控件应该位于父控件中心位置
    int x = parentRect.center().x() - lableRect.width() / 2;
    int y = parentRect.center().y() - lableRect.height() / 2;
    ui->labelMove->move(x, y);
}

void MYWidget::moveLabelBy(int dx, int dy)
{
    // 1、计算预期目标坐标
    QPoint targetPos = ui->labelMove->pos() + QPoint(dx, dy);

    // 2、获取参数边界
    int parentWidth = ui->labelMove->parentWidget()->width();
    int parentHeight = ui->labelMove->parentWidget()->height();
    int labelWidth = ui->labelMove->width();
    int labelHeight = ui->labelMove->height();

    // 3、X轴边界环绕逻辑
    if (targetPos.x() <= -labelWidth) {
        targetPos.setX(parentWidth);
    } else if (targetPos.x() >= parentWidth) {
        targetPos.setX(-labelWidth);
    }

    // 4、Y轴边界环绕逻辑
    if (targetPos.y() <= -labelHeight) {
        targetPos.setY(parentHeight);
    } else if (targetPos.y() >= parentHeight) {
        targetPos.setY(-labelHeight);
    }

    // 5、统一执行一次移动操作
    ui->labelMove->move(targetPos);
}
