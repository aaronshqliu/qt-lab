#include "my_widget.h"
#include "./ui_my_widget.h"

#include "color_form.h"
#include "style_form.h"

#include <QDateTime>
#include <QMovie>
#include <QPixmap>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 对齐方式
    alignGroup = new QButtonGroup(this);
    alignGroup->addButton(ui->rBtnLeftAlign, 0);
    alignGroup->addButton(ui->rBtnCenterAlign, 1);
    alignGroup->addButton(ui->rBtnRightAlign, 2);

    connect(alignGroup, &QButtonGroup::idClicked, this, &MyWidget::onAlignClicked);
    ui->rBtnCenterAlign->click();

    // 字体设置
    StyleForm *styleForm = new StyleForm();
    ui->widgetSet->layout()->addWidget(styleForm);
    styleForm->setWindowTitle("字体设置");

    connect(styleForm, &StyleForm::styleChanged, this, &MyWidget::onStyleChanged);

    // 颜色设置
    QPushButton *btnSetColor = new QPushButton("颜色设置");
    btnSetColor->setStyleSheet("QPushButton { font-size: 12pt; }");
    ui->widgetSet->layout()->addWidget(btnSetColor);

    ColorForm *colorForm = new ColorForm();
    colorForm->setWindowTitle("颜色设置");
    colorForm->setFixedWidth(300);

    connect(btnSetColor, &QPushButton::clicked, this, [=]() { colorForm->show(); });
    connect(colorForm, &ColorForm::colorChanged, this, &MyWidget::onColorChanged);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MyWidget::OnTimeOut);
    timer->start(500);

    // 换行
    ui->labelWrap->setWordWrap(true);
    ui->labelWrap->setText(
        "Qt is a powerful and versatile cross-platform application and UI framework that enables "
        "developers to create sophisticated and responsive graphical "
        "user interfaces (GUIs) for desktop, mobile, and embedded systems.");

    // 加载静态图片
    QPixmap p1;
    p1.load(":/icon/avatar.png");
    ui->labelPixmap->setPixmap(p1);
    ui->labelPixmap->setScaledContents(true);

    // 加载动态图片
    QMovie *movie = new QMovie(":/icon/angry.gif");
    ui->labelMovie->setMovie(movie);
    ui->labelMovie->setScaledContents(true);
    movie->start();
}

MyWidget::~MyWidget() { delete ui; }

void MyWidget::onAlignClicked(int id)
{
    if (id == 0) {
        ui->labelTime->setAlignment(Qt::AlignLeft);
    } else if (id == 1) {
        ui->labelTime->setAlignment(Qt::AlignCenter);
    } else if (id == 2) {
        ui->labelTime->setAlignment(Qt::AlignRight);
    }
}

void MyWidget::onStyleChanged(bool bold, bool italic, bool underline)
{
    QFont font = ui->labelTime->font();
    font.setBold(bold);
    font.setItalic(italic);
    font.setUnderline(underline);

    ui->labelTime->setFont(font);
}

void MyWidget::onColorChanged(int id)
{
    if (id == 0) {
        ui->labelTime->setStyleSheet("QLabel { color: red };");
    } else if (id == 1) {
        ui->labelTime->setStyleSheet("QLabel { color: green };");
    } else if (id == 2) {
        ui->labelTime->setStyleSheet("QLabel { color: blue };");
    }
}

void MyWidget::on_pBtnGetWindow_clicked()
{
    QRect rect = this->geometry();
    QPoint topLeft = rect.topLeft();
    int width = rect.width();
    int height = rect.height();

    QString s = QString("左上角(%1, %2), 宽高(%3, %4)")
                    .arg(topLeft.x())
                    .arg(topLeft.y())
                    .arg(width)
                    .arg(height);

    ui->lineEditWindowSize->setText(s);
}

void MyWidget::on_pBtnSetWindow_clicked() { this->resize(400, 400); }

void MyWidget::on_pBtnMoveWindow_clicked() { this->move(100, 100); }

void MyWidget::on_pBtnSetTitle_clicked()
{
    this->setWindowTitle(ui->lineEditWindowTitle->text().trimmed());
}

void MyWidget::on_pBtnUpdateIcon_clicked()
{
    QStringList icons = {":/icon/black.png",
                         ":/icon/blue.png",
                         ":/icon/green.png",
                         ":/icon/red.png"};
    static int i = 0;
    this->setWindowIcon(QIcon(icons[i++ % 4]));
}

void MyWidget::OnTimeOut()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    ui->labelTime->setText(currentTime.toString("yyyy/MM/dd hh:mm::ss"));
}

void MyWidget::on_pushButtonAllowWrap_clicked()
{
    ui->labelWrap->setWordWrap(true);
}

void MyWidget::on_pushButtonDisableWrap_clicked()
{
    ui->labelWrap->setWordWrap(false);
}
