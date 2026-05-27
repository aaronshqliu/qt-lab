#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ui->actionNew->setIcon(QIcon("C:\\Users\\qiang\\Downloads\\XXX.png"));

    // 使用 Qt 资源文件，格式 ":+前缀名+文件名"
    ui->actionNew->setIcon(QIcon(":/resources/new.png"));
    ui->actionOpen->setIcon(QIcon(":/resources/open.png"));


}

MainWindow::~MainWindow()
{
    delete ui;
}
