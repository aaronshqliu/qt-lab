#include "my_widget.h"
#include "./ui_my_widget.h"

#include "color_form.h"
#include "style_form.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MyWidget) {
    ui->setupUi(this);

    // 对齐方式
    ui->lineEditTime->setText("2026/5/26 2:12");
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

    connect(btnSetColor, &QPushButton::clicked, this,
            [=]() { colorForm->show(); });
    connect(colorForm, &ColorForm::colorChanged, this, &MyWidget::onColorChanged);
}

MyWidget::~MyWidget() { delete ui; }

void MyWidget::onAlignClicked(int id) {
    if (id == 0) {
        ui->lineEditTime->setAlignment(Qt::AlignLeft);
    } else if (id == 1) {
        ui->lineEditTime->setAlignment(Qt::AlignCenter);
    } else if (id == 2) {
        ui->lineEditTime->setAlignment(Qt::AlignRight);
    }
}

void MyWidget::onStyleChanged(bool bold, bool italic, bool underline) {
    QFont font = ui->lineEditTime->font();
    font.setBold(bold);
    font.setItalic(italic);
    font.setUnderline(underline);

    ui->lineEditTime->setFont(font);
}

void MyWidget::onColorChanged(int id) {
    if (id == 0) {
        ui->lineEditTime->setStyleSheet("QLineEdit { color: red };");
    } else if (id == 1) {
        ui->lineEditTime->setStyleSheet("QLineEdit { color: green };");
    } else if (id == 2) {
        ui->lineEditTime->setStyleSheet("QLineEdit { color: blue };");
    }
}

void MyWidget::on_pBtnGetWindow_clicked() {
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

void MyWidget::on_pBtnSetTitle_clicked() {
    this->setWindowTitle(ui->lineEditWindowTitle->text().trimmed());
}

void MyWidget::on_pBtnUpdateIcon_clicked() {
    QStringList icons = {":/icon/black.png", ":/icon/blue.png",
                         ":/icon/green.png", ":/icon/red.png"};
    static int i = 0;
    this->setWindowIcon(QIcon(icons[i++ % 4]));
}
