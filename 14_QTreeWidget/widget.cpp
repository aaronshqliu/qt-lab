#include "widget.h"
#include <QDebug>
#include "./ui_widget.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    initData();
    // traverseItems(ui->treeInfo);
    ui->chkHeader->toggle();
    ui->chkColor->toggle();
    connect(ui->chkHeader, &QCheckBox::toggled, ui->treeInfo->header(), &QHeaderView::setVisible);
    connect(ui->chkColor, &QCheckBox::toggled, ui->treeInfo, &QTreeWidget::setAlternatingRowColors);
    connect(ui->chkEditable, &QCheckBox::toggled, this, &Widget::onEditableToggled);

    group = new QButtonGroup(this);
    group->addButton(ui->rdoCell, 0);
    group->addButton(ui->rdoRow, 1);
    group->addButton(ui->rdoColumn, 2);
    ui->rdoRow->toggle();
    connect(group, &QButtonGroup::idClicked, this, [this](int id) {
        static const QAbstractItemView::SelectionBehavior behaviors[]
            = {QAbstractItemView::SelectItems,
               QAbstractItemView::SelectRows,
               QAbstractItemView::SelectColumns};
        ui->treeInfo->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->treeInfo->setSelectionBehavior(behaviors[id]);
    });

    connect(ui->treeInfo, &QTreeWidget::itemClicked, this, [this](QTreeWidgetItem *item) {
        ui->edtCity->setText(item->text(0));
        ui->edtArea->setText(item->text(1));
        ui->edtPopulation->setText(item->text(2));
        ui->edtGdp->setText(item->text(3));

        ui->btnModify->setEnabled(true);
        ui->btnDelete->setEnabled(true);
    });

    connect(ui->btnAppend, &QPushButton::clicked, this, &Widget::onAppendClicked);
    connect(ui->btnInsert, &QPushButton::clicked, this, &Widget::onInsertClicked);
    connect(ui->btnChild, &QPushButton::clicked, this, &Widget::onChildClicked);
    connect(ui->btnModify, &QPushButton::clicked, this, &Widget::onModifyClicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &Widget::onDeleteClicked);

    ui->btnModify->setEnabled(false);
    ui->btnDelete->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onEditableToggled(bool checked)
{
    int topCount = ui->treeInfo->topLevelItemCount();

    for (int i = 0; i < topCount; ++i) {
        QTreeWidgetItem *topItem = ui->treeInfo->topLevelItem(i);
        setRowEditable(topItem, checked);

        int childCount = topItem->childCount();
        for (int j = 0; j < childCount; ++j) {
            setRowEditable(topItem->child(j), checked);
        }
    }
}

void Widget::onAppendClicked()
{
    QTreeWidgetItem *currentItem = ui->treeInfo->currentItem();
    if (!currentItem) {
        return;
    }

    QTreeWidgetItem *newItem = createItemFromInput();
    if (QTreeWidgetItem *parent = currentItem->parent()) {
        parent->addChild(newItem);
    } else {
        ui->treeInfo->addTopLevelItem(newItem);
    }
}

void Widget::onInsertClicked()
{
    QTreeWidgetItem *currentItem = ui->treeInfo->currentItem();
    if (!currentItem) {
        return;
    }

    QTreeWidgetItem *newItem = createItemFromInput();
    if (QTreeWidgetItem *parent = currentItem->parent()) {
        parent->insertChild(parent->indexOfChild(currentItem), newItem);
    } else {
        ui->treeInfo->insertTopLevelItem(ui->treeInfo->indexOfTopLevelItem(currentItem), newItem);
    }
}

void Widget::onChildClicked()
{
    if (QTreeWidgetItem *currentItem = ui->treeInfo->currentItem()) {
        currentItem->addChild(createItemFromInput());
        currentItem->setExpanded(true);
    }
}

void Widget::onModifyClicked()
{
    QTreeWidgetItem *currentItem = ui->treeInfo->currentItem();
    if (!currentItem) {
        return;
    }

    QStringList data = getInputData();
    for (int i = 0; i < data.size(); ++i) {
        currentItem->setText(i, data.at(i));
    }
}

void Widget::onDeleteClicked()
{
    // Qt 机制：直接 delete QTreeWidgetItem，它会自动安全地将自己从父节点或 QTreeWidget 中摘除！
    // 根本不需要判断它是不是 topLevelItem，也不需要手动 remove。
    delete ui->treeInfo->currentItem();
}

void Widget::initData()
{
    // 设置表头，共有4列，添加列的名称
    ui->treeInfo->setColumnCount(4);
    ui->treeInfo->setHeaderLabels(QStringList() << "城市" << "面积(平方公里)" << "人口(万人)"
                                                << "GDP(亿元)"); // 设置列标题

    // 设置所有列的宽度模式为拉伸
    ui->treeInfo->header()->setSectionResizeMode(QHeaderView::Stretch);

    // 设置样式表
    ui->treeInfo->setStyleSheet(R"(
        QTreeView {
            color: #222222;
            font: 16px "微软雅黑";
        }
    )");
    ui->treeInfo->header()->setStyleSheet(R"(
        QHeaderView::section {
            color: #222222;
            font: bold 16px "微软雅黑";
            border: 0px solid #c8c8c8;
        }
    )");

    QList<RegionData> regions = {{{"北京市", "16807", "2186", "43800"}, {}},
                                 {{"上海市", "6340", "2487", "47200"}, {}},
                                 {{"天津市", "11966", "1363", "16737"}, {}},
                                 {{"广东省"},
                                  {{"广州市", "7434", "1882", "30355"},
                                   {"深圳市", "1997", "1779", "34606"}}},
                                 {{"浙江省"},
                                  {{"杭州市", "16850", "1252", "20059"},
                                   {"温州市", "11784", "976", "8730"},
                                   {"宁波市", "9816", "969", "16452"}}},
                                 {{"江苏省"},
                                  {{"苏州市", "8657", "1295", "24653"},
                                   {"无锡市", "4627", "749", "15456"},
                                   {"南京市", "6587", "954", "17421"}}}};

    for (const RegionData &region : regions) {
        // 创建顶级节点 (QTreeWidgetItem 有一个直接接受 QStringList 的构造函数，非常方便)
        QTreeWidgetItem *topItem = new QTreeWidgetItem(region.info);
        ui->treeInfo->addTopLevelItem(topItem);
        // 如果这个顶级节点有子城市，遍历添加
        for (const QStringList &childInfo : region.children) {
            QTreeWidgetItem *childItem = new QTreeWidgetItem(childInfo);
            topItem->addChild(childItem);
        }
    }
    // 默认展开所有节点，方便查看效果
    ui->treeInfo->expandAll();
}

void Widget::traverseItem(QTreeWidgetItem *item, int depth)
{
    if (!item) {
        return;
    }

    QString indent = QString(" ").repeated(depth * 4);

    // 获取当前节点数据
    QString s = indent + item->text(0);
    int childCount = item->childCount();

    // 如果是叶子节点（比如城市，没有子节点），追加后续列的数据
    if (childCount == 0) {
        s += "|" + item->text(1) + "|" + item->text(2) + "|" + item->text(3);
    }

    // 打印当前节点，去掉引号
    qDebug().noquote() << s;

    // 递归遍历所有子节点，深度直接 +1
    for (int i = 0; i < childCount; ++i) {
        traverseItem(item->child(i), depth + 1);
    }
}

void Widget::traverseItems(QTreeWidget *treeWidget)
{
    int topLevelItemCount = treeWidget->topLevelItemCount();
    for (int i = 0; i < topLevelItemCount; ++i) {
        // 从顶级节点开始遍历，初始深度设为 0
        traverseItem(treeWidget->topLevelItem(i), 0);
    }
}

void Widget::setRowEditable(QTreeWidgetItem *item, bool editable)
{
    if (!item) {
        return;
    }

    if (editable) {
        // 使用位元或運算（|）加上可編輯屬性
        item->setFlags(item->flags() | Qt::ItemIsEditable);
    } else {
        // 使用位元與非運算（& ~）移除可編輯屬性
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
    }
}

QStringList Widget::getInputData() const
{
    return {ui->edtCity->text().trimmed(),
            ui->edtArea->text().trimmed(),
            ui->edtPopulation->text().trimmed(),
            ui->edtGdp->text().trimmed()};
}

QTreeWidgetItem *Widget::createItemFromInput() const
{
    return new QTreeWidgetItem(getInputData());
}
