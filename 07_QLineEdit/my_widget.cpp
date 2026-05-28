#include "my_widget.h"
#include <QIntValidator>
#include <QMessageBox>
#include "./ui_my_widget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    // 对齐方式
    ui->lineEditSetFontStyle->setText("0123456789");
    ui->lineEditSetFontStyle->setPlaceholderText("请输入...");

    alignGroup = new QButtonGroup(this);
    alignGroup->addButton(ui->radioButtonAlignLeft, 0);
    alignGroup->addButton(ui->radioButtonAlignCenter, 1);
    alignGroup->addButton(ui->radioButtonAlignRight, 2);
    connect(alignGroup, &QButtonGroup::idClicked, this, &MyWidget::onPushButtonGroupAlignClicked);
    ui->radioButtonAlignCenter->click();

    // 字体样式
    connect(ui->checkBoxBold, &QCheckBox::toggled, this, &MyWidget::onFontStyleClicked);
    connect(ui->checkBoxItalic, &QCheckBox::toggled, this, &MyWidget::onFontStyleClicked);
    connect(ui->checkBoxUnderline, &QCheckBox::toggled, this, &MyWidget::onFontStyleClicked);

    // 回显模式
    ui->lineEditEchoMode->setPlaceholderText("请输入密码...");
    echoModeGroup = new QButtonGroup(this);
    echoModeGroup->addButton(ui->radioButtonNormal, 0);
    echoModeGroup->addButton(ui->radioButtonPwd, 1);
    echoModeGroup->addButton(ui->radioButtonNoEcho, 2);
    echoModeGroup->addButton(ui->radioButtonLoseFocus, 3);
    connect(echoModeGroup, &QButtonGroup::idClicked, this, &MyWidget::onEchoModeClicked);
    connect(ui->pushButtonShow, &QPushButton::clicked, this, &MyWidget::on_pushButtonShow_clicked);
    ui->radioButtonNormal->click();

    // 格式控制
    styleCtrlGroup = new QButtonGroup(this);
    styleCtrlGroup->addButton(ui->radioButtonNone, 0);
    styleCtrlGroup->addButton(ui->radioButtonPhoneNumber, 1);
    styleCtrlGroup->addButton(ui->radioButtonSecretKey, 2);
    connect(styleCtrlGroup,
            &QButtonGroup::idClicked,
            this,
            &MyWidget::onPushButtonGroupStyleCtrlClicked);
    ui->radioButtonNone->click();

    // 信号槽
    // textChanged
    ui->lineEditAdd1->setValidator(new QIntValidator(this)); // 用于设置校验,只允许文本框中输入整数
    ui->lineEditAdd2->setValidator(new QIntValidator(this));

    // editingFinished
    ui->lineEditSub1->setValidator(new QIntValidator(this));
    ui->lineEditSub2->setValidator(new QIntValidator(this));
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::onPushButtonGroupAlignClicked(int id) {
    if (id == 0) {
        ui->lineEditSetFontStyle->setAlignment(Qt::AlignLeft);
    }
    else if (id == 1) {
        ui->lineEditSetFontStyle->setAlignment(Qt::AlignCenter);
    }
    else if (id == 2) {
        ui->lineEditSetFontStyle->setAlignment(Qt::AlignRight);
    }
}

void MyWidget::onFontStyleClicked()
{
    QFont font = ui->lineEditSetFontStyle->font();
    font.setBold(ui->checkBoxBold->isChecked());
    font.setItalic(ui->checkBoxItalic->isChecked());
    font.setUnderline(ui->checkBoxUnderline->isChecked());
    ui->lineEditSetFontStyle->setFont(font);
}

void MyWidget::on_pushButtonRw_clicked()
{
    ui->lineEditRwControl->setReadOnly(false);
}

void MyWidget::on_pushButtonReadOnly_clicked()
{
    ui->lineEditRwControl->setReadOnly(true);
}

void MyWidget::on_pushButtonDisable_clicked()
{
    ui->lineEditRwControl->setDisabled(true);
}

void MyWidget::on_pushButtonEnable_clicked()
{
    ui->lineEditRwControl->setEnabled(true);
}

void MyWidget::onEchoModeClicked(int id)
{
    ui->lineEditEchoMode->clear();

    if (id == 0) {
        ui->lineEditEchoMode->setEchoMode(QLineEdit::Normal);
    } else if (id == 1) {
        ui->lineEditEchoMode->setEchoMode(QLineEdit::Password);
    } else if (id == 2) {
        ui->lineEditEchoMode->setEchoMode(QLineEdit::NoEcho);
    } else if (id == 3) {
        ui->lineEditEchoMode->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    }
}

void MyWidget::on_pushButtonShow_clicked()
{
    QMessageBox::information(this, "回显模式", ui->lineEditEchoMode->text());
}

void MyWidget::onPushButtonGroupStyleCtrlClicked(int id)
{
    if (id == 0) {
        ui->lineEditStyleControl->setInputMask("");
    } else if (id == 1) {
        // 9 - 表示要求输入0-9的数字
        // ;# - 表示格式字符串结束，并且未输入时显示#
        ui->lineEditStyleControl->setInputMask("99999999999;#");
    } else if (id == 2) {
        // > - 表示后边的英文字符都转为大写
        // A - 表示要求输入英文字符A-Z或者a-z
        // ;* - 表示格式字符串结束，并且未输入时显示*
        ui->lineEditStyleControl->setInputMask(">AAAAA-AAAAA-AAAAA-AAAAA;*");
    }
}

void MyWidget::on_lineEditAdd1_textChanged(const QString &arg1)
{
    int res = arg1.toInt() + ui->lineEditAdd2->text().toInt();
    ui->lineEditAddRes->setText(QString::number(res));
}

void MyWidget::on_lineEditAdd2_textChanged(const QString &arg1)
{
    int res = arg1.toInt() + ui->lineEditAdd1->text().toInt();
    ui->lineEditAddRes->setText(QString::number(res));
}

void MyWidget::on_lineEditSub1_editingFinished()
{
    int res = ui->lineEditSub1->text().toInt() - ui->lineEditSub2->text().toInt();
    ui->lineEditSubRes->setText(QString::number(res));
}

void MyWidget::on_lineEditSub2_editingFinished()
{
    int res = ui->lineEditSub1->text().toInt() - ui->lineEditSub2->text().toInt();
    ui->lineEditSubRes->setText(QString::number(res));
}
