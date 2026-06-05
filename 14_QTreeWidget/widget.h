#ifndef WIDGET_H
#define WIDGET_H

#include <QButtonGroup>
#include <QTreeWidget>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

#include <QList>
#include <QString>

struct RegionData
{
    QStringList info;            // 包含: 名称, 面积, 人口, GDP
    QList<QStringList> children; // 下属城市的列表 (如果没有就不填)
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private slots:
    void onEditableToggled(bool checked);
    void onAppendClicked();
    void onInsertClicked();
    void onChildClicked();
    void onModifyClicked();
    void onDeleteClicked();

private:
    void initData();
    void traverseItem(QTreeWidgetItem *item, int depth); // 递归遍历函数
    void traverseItems(QTreeWidget *treeWidget);

    void setRowEditable(QTreeWidgetItem *item, bool editable);

    QStringList getInputData() const;
    QTreeWidgetItem *createItemFromInput() const;

private:
    Ui::Widget *ui;
    QButtonGroup *group;
};
#endif // WIDGET_H
