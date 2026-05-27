#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600, 400);

    // 创建菜单栏（最多只能有一个）
    QMenuBar *menubar = menuBar();
    // 将菜单栏放入窗口中
    setMenuBar(menubar);
    // 创建菜单
    QMenu *fileMenu = menubar->addMenu("文件");
    QMenu *editMenu = menubar->addMenu("编辑");
    // 创建菜单项
    QAction *newFile = fileMenu->addAction("新建文件");
    // 添加分隔线
    fileMenu->addSeparator();
    QAction *openFile = fileMenu->addAction("打开文件");


    // 创建工具栏（可以有多个）
    QToolBar *toolbar = new QToolBar(this);
    // 默认在左侧
    addToolBar(Qt::LeftToolBarArea, toolbar);
    // 只允许左右停靠
    toolbar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    // 设置不允许浮动
    toolbar->setFloatable(false);
    // 设置不允许移动（总开关）
    // toolbar->setMovable(false);
    // 工具栏设置内容
    toolbar->addAction(newFile);
    toolbar->addSeparator();
    toolbar->addAction(openFile);
    // 工具栏中添加空间
    QPushButton *btn = new QPushButton("按钮", this);
    toolbar->addWidget(btn);


    // 创建状态栏 （最多只能有一个）
    QStatusBar *statusbar = statusBar();
    // 将状态栏添加到窗口中
    setStatusBar(statusbar);
    // 放一些标签控件
    QLabel *label = new QLabel("左侧提示信息", this);
    statusbar->addWidget(label);
    QLabel *label2 = new QLabel("右侧提示信息", this);
    statusbar->addPermanentWidget(label2);


    // 创建铆接部件（浮动窗口）（可以有多个）
    QDockWidget *dockWidget = new QDockWidget("浮动", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
    // 设置后期停靠区域（只允许上下）
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);


    // 创建中心部件（最多只能有一个）
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);






}

MainWindow::~MainWindow() {}
