#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 点击新建按钮，弹出一个对话框
    connect(ui->actionNew, &QAction::triggered, [=](){
        /**
         * 对话框分类：
         * 模态对话框（不可以对其他窗口进行操作）
         * 非模态对话框（可以对其他窗口进行操作）
         */
        // 创建模态对话框
        // QDialog dialog(this);
        // dialog.resize(200, 100);
        // dialog.exec();
        // qDebug() << "模态对话框弹出了";


        // 创建非模态对话框
        // 为了防止一闪而过，QDialog要创建在堆区使其一直存活
        // QDialog *dialog2 = new QDialog(this);
        // dialog2->resize(200, 100);
        // dialog2->show();
        // // 如果Qdialog无限的创建，然后关闭，会造成内存泄露。需要设置如下属性，让QDialog在关闭时释放掉。
        // // Make Qt delete this wideget when this wideget has accepted the close event
        // dialog2->setAttribute(Qt::WA_DeleteOnClose);
        // qDebug() << "非模态对话框弹出了";


        // 创建消息对话框
        // 错误对话框
        // QMessageBox::critical(this, "critical", "出错了");


        // 信息对话框
        // QMessageBox::information(this, "information", "这是帮助信息");


        // 提问对话框
        // if (QMessageBox::question(this, "question", "请回答这个问题", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Save) {
        //     qDebug() << "save";
        // } else {
        //     qDebug() << "cancel";
        // }


        // 创建警告对话框
        // QMessageBox::warning(this, "warning", "这是一个警告信息");


        // 选择颜色对话框（手动设置默认红色）
        // QColor color = QColorDialog::getColor(QColor(255, 0, 0));
        // qDebug() << "r = " << color.red() << "g = " << color.green() << "b = " << color.blue();


        // 文件对话框
        /**
         * 打开文件对话框
         * 返回值：选择文件的路径
         * 参数1：parent
         * 参数2：标题
         * 参数3：默认打开文件的路径
         * 参数4：过滤文件的格式
         */
        // QString str = QFileDialog::getOpenFileName(this, "打开文件", "C:\\Users\\qiang\\Desktop", "(*.txt)");
        // qDebug() << str;


        // 选择字体对话框
        bool flag;
        QFont font = QFontDialog::getFont(&flag, QFont("微软雅黑", 36));
        qDebug() << "字体：" << font.family().toUtf8().data() << "字号：" << font.pointSize() << "是否加粗：" << font.bold() << "是否倾斜：" << font.italic();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
