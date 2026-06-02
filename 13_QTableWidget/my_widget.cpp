#include "my_widget.h"
#include <QDebug>
#include "./ui_my_widget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 1. 设置行列表头
    // 共有4列，并添加列的名称
    ui->tblPerson->setColumnCount(4);
    QStringList rowHeader;
    rowHeader << "姓名" << "性别" << "年龄" << "籍贯";
    ui->tblPerson->setHorizontalHeaderLabels(rowHeader);

    // 设置列的宽度
    // 设置所有列的宽度模式为拉伸
    ui->tblPerson->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 2. 添加几行初始化数据
    QList<Person> persons{{"张三", "男", 18, "北京市"},
                          {"李四", "男", 20, "上海市"},
                          {"王五", "女", 19, "广东省"}};

    for (const auto &p : persons) {
        appendOneRow(p);
    }

    insertOneRow(0, {"Aaron", "男", 25, "山东省"});

    // 3、复选框
    // 行表头
    connect(ui->chkRowHeader,
            &QCheckBox::toggled,
            ui->tblPerson->horizontalHeader(),
            &QHeaderView::setVisible);
    // 列表头
    connect(ui->chkColumnHeader,
            &QCheckBox::toggled,
            ui->tblPerson->verticalHeader(),
            &QHeaderView::setVisible);
    // 交替背景色
    connect(ui->chkColor,
            &QCheckBox::toggled,
            ui->tblPerson,
            &QTableWidget::setAlternatingRowColors);
    // 单元格可编辑
    connect(ui->chkCellEditable, &QCheckBox::toggled, this, [this](bool checked) {
        ui->tblPerson->setEditTriggers(checked ? (QAbstractItemView::DoubleClicked
                                                  | QAbstractItemView::SelectedClicked
                                                  | QAbstractItemView::EditKeyPressed)
                                               : QAbstractItemView::NoEditTriggers);
    });
    // 设置复选框的默认状态
    ui->chkRowHeader->toggle();
    ui->chkColumnHeader->toggle();
    ui->chkColor->toggle();
    // ui->chkCellEditable->toggle();
    ui->tblPerson->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 4、单选按钮
    selectedGroup = new QButtonGroup(this);
    selectedGroup->addButton(ui->rdoSelectCell, 0);
    selectedGroup->addButton(ui->rdoSelectRow, 1);
    selectedGroup->addButton(ui->rdoSelectColumn, 2);
    connect(selectedGroup, &QButtonGroup::idClicked, this, [this](int id) {
        static const QAbstractItemView::SelectionBehavior behaviors[]
            = {QAbstractItemView::SelectItems,
               QAbstractItemView::SelectRows,
               QAbstractItemView::SelectColumns};
        ui->tblPerson->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tblPerson->setSelectionBehavior(behaviors[id]);
    });
    // 设置单选按钮的默认状态
    ui->rdoSelectCell->toggle();

    // 5、增删改
    connect(ui->tblPerson, &QTableWidget::itemClicked, this, [this](QTableWidgetItem *item) {
        int row = item->row();
        ui->edtName->setText(ui->tblPerson->item(row, 0)->text());
        ui->edtGender->setText(ui->tblPerson->item(row, 1)->text());
        ui->edtAge->setText(ui->tblPerson->item(row, 2)->text());
        ui->edtHometown->setText(ui->tblPerson->item(row, 3)->text());
    });
    connect(ui->btnAdd, &QPushButton::clicked, this, &MyWidget::addPerson);
    connect(ui->btnInsert, &QPushButton::clicked, this, &MyWidget::insertPerson);
    connect(ui->btnModify, &QPushButton::clicked, this, &MyWidget::modifyPerson);
    connect(ui->btnDelete, &QPushButton::clicked, this, &MyWidget::deletePerson);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::setPersonRow(int row, const Person &person)
{
    QStringList values{person.name, person.gender, QString::number(person.age), person.homedown};
    for (int col = 0; col < values.size(); ++col) {
        auto *item = new QTableWidgetItem(values[col]);
        item->setTextAlignment(Qt::AlignCenter);
        ui->tblPerson->setItem(row, col, item);
    }
}

void MyWidget::appendOneRow(const Person &person)
{
    // 获取当前行数
    int row = ui->tblPerson->rowCount();
    qDebug() << "当前行数：" << row;

    // 设置当前行数
    ui->tblPerson->setRowCount(row + 1);

    setPersonRow(row, person);
}

void MyWidget::insertOneRow(int row, const Person &person)
{
    ui->tblPerson->insertRow(row);
    setPersonRow(row, person);
}

void MyWidget::addPerson()
{
    appendOneRow({ui->edtName->text(),
                  ui->edtGender->text(),
                  ui->edtAge->text().toInt(),
                  ui->edtHometown->text()});
}

void MyWidget::insertPerson()
{
    insertOneRow(ui->tblPerson->currentRow(),
                 {ui->edtName->text(),
                  ui->edtGender->text(),
                  ui->edtAge->text().toInt(),
                  ui->edtHometown->text()});
}

void MyWidget::modifyPerson()
{
    setPersonRow(ui->tblPerson->currentRow(),
                 {ui->edtName->text(),
                  ui->edtGender->text(),
                  ui->edtAge->text().toInt(),
                  ui->edtHometown->text()});
}

void MyWidget::deletePerson()
{
    ui->tblPerson->removeRow(ui->tblPerson->currentRow());
}
