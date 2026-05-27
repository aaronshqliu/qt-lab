#include "my_widget.h"
#include "./ui_my_widget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MyWidget) {
    ui->setupUi(this);
}

MyWidget::~MyWidget() { delete ui; }

void MyWidget::resizeEvent(QResizeEvent *event) {
    static int index = 1;
    int lineCount = ui->textEdit->document()->lineCount();
    if (lineCount > 100 * 6) {
        ui->textEdit->clear();
        index = 1;
    }

    QString strIndex = QString("[%1]--------------------------------------").arg(index++);
    ui->textEdit->append(strIndex);

    QString width = QString("按钮宽度: \t\t%1, %2, %3, %4")
                        .arg(ui->btnAddRecord->width())
                        .arg(ui->btnDeleteRecord->width())
                        .arg(ui->btnModifyRecord->width())
                        .arg(ui->btnQueryRecord->width());
    ui->textEdit->append(width);

    QMargins margins = ui->widget->layout()->contentsMargins();
    QString strMargins = QString("边距(左上右下): \t%1, %2, %3, %4")
                             .arg(margins.left())
                             .arg(margins.top())
                             .arg(margins.right())
                             .arg(margins.bottom());
    ui->textEdit->append(strMargins);

    int spacing = ui->widget->layout()->spacing();
    QString strSpacing = QString("间距: \t\t\t%1").arg(spacing);
    ui->textEdit->append(strSpacing);

    ui->textEdit->append("------------------------------------------\n");

    // 移动光标到最后一行
    ui->textEdit->moveCursor(QTextCursor::End);
}
