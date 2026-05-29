#pragma once

#include <QtWidgets/QWidget>
#include <QVector>
#include "ui_my_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidgetClass; };
QT_END_NAMESPACE


struct Region {
    QString code;  // 行政代码
    QString name;  // 名称
};

class RegionManager {
public:
    static RegionManager& instance() {
        static RegionManager instance;
        return instance;
    }

    void loadData();

    QVector<Region> provinces;
    QHash<QString, QVector<Region>> cities;
    QHash<QString, QVector<Region>> districts;

private:
    RegionManager() = default;
};

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    // QCheckBox
    void onSelectAllClicked();  // 全选框被点击
    void onFruitClicked();  // 任何一个水果框被点击


private:
    void updateSelectAllState();
    void updateFruitDisplay();

    void initComboBoxes();
    void updateSelectedRegion();

    Ui::MyWidgetClass *ui;
    QList<QCheckBox*> fruitList;

};

