/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QKeySequenceEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_4;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_2;
    QWidget *page_3;
    QWidget *page_6;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QWidget *tab_2;
    QWidget *tab;
    QWidget *page_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_30;
    QPushButton *pushButton_29;
    QPushButton *pushButton_28;
    QPushButton *pushButton_27;
    QPushButton *pushButton_26;
    QPushButton *pushButton_25;
    QPushButton *pushButton_24;
    QPushButton *pushButton_23;
    QPushButton *pushButton_22;
    QPushButton *pushButton_21;
    QPushButton *pushButton_20;
    QPushButton *pushButton_19;
    QPushButton *pushButton_18;
    QPushButton *pushButton_17;
    QPushButton *pushButton_16;
    QPushButton *pushButton_15;
    QPushButton *pushButton_14;
    QPushButton *pushButton_13;
    QPushButton *pushButton_12;
    QPushButton *pushButton_11;
    QPushButton *pushButton_31;
    QPushButton *pushButton_32;
    QPushButton *pushButton_37;
    QPushButton *pushButton_36;
    QPushButton *pushButton_35;
    QPushButton *pushButton_34;
    QPushButton *pushButton_33;
    QPushButton *btn_p1;
    QPushButton *btn_p2;
    QPushButton *btn_p3;
    QComboBox *comboBox;
    QPushButton *btn_benz;
    QSpinBox *spinBox;
    QDoubleSpinBox *doubleSpinBox;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QDateTimeEdit *dateTimeEdit;
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;
    QSlider *horizontalSlider;
    QSlider *verticalSlider;
    QKeySequenceEdit *keySequenceEdit;
    QLabel *label;
    QLabel *label_movie;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(938, 600);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(90, 60, 241, 501));
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        toolBox = new QToolBox(page_4);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(20, 20, 181, 441));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 181, 339));
        toolBox->addItem(page, QString::fromUtf8("\345\256\266\344\272\272"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 181, 339));
        toolBox->addItem(page_2, QString::fromUtf8("\346\234\213\345\217\213"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        toolBox->addItem(page_3, QString::fromUtf8("\351\273\221\345\220\215\345\215\225"));
        stackedWidget->addWidget(page_4);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        tabWidget = new QTabWidget(page_6);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 30, 231, 151));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        stackedWidget->addWidget(page_6);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        scrollArea = new QScrollArea(page_5);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(20, 10, 161, 451));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 142, 1310));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        verticalLayout->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(scrollAreaWidgetContents);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(scrollAreaWidgetContents);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        verticalLayout->addWidget(pushButton_10);

        pushButton_30 = new QPushButton(scrollAreaWidgetContents);
        pushButton_30->setObjectName(QString::fromUtf8("pushButton_30"));

        verticalLayout->addWidget(pushButton_30);

        pushButton_29 = new QPushButton(scrollAreaWidgetContents);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));

        verticalLayout->addWidget(pushButton_29);

        pushButton_28 = new QPushButton(scrollAreaWidgetContents);
        pushButton_28->setObjectName(QString::fromUtf8("pushButton_28"));

        verticalLayout->addWidget(pushButton_28);

        pushButton_27 = new QPushButton(scrollAreaWidgetContents);
        pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));

        verticalLayout->addWidget(pushButton_27);

        pushButton_26 = new QPushButton(scrollAreaWidgetContents);
        pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));

        verticalLayout->addWidget(pushButton_26);

        pushButton_25 = new QPushButton(scrollAreaWidgetContents);
        pushButton_25->setObjectName(QString::fromUtf8("pushButton_25"));

        verticalLayout->addWidget(pushButton_25);

        pushButton_24 = new QPushButton(scrollAreaWidgetContents);
        pushButton_24->setObjectName(QString::fromUtf8("pushButton_24"));

        verticalLayout->addWidget(pushButton_24);

        pushButton_23 = new QPushButton(scrollAreaWidgetContents);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));

        verticalLayout->addWidget(pushButton_23);

        pushButton_22 = new QPushButton(scrollAreaWidgetContents);
        pushButton_22->setObjectName(QString::fromUtf8("pushButton_22"));

        verticalLayout->addWidget(pushButton_22);

        pushButton_21 = new QPushButton(scrollAreaWidgetContents);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));

        verticalLayout->addWidget(pushButton_21);

        pushButton_20 = new QPushButton(scrollAreaWidgetContents);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));

        verticalLayout->addWidget(pushButton_20);

        pushButton_19 = new QPushButton(scrollAreaWidgetContents);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));

        verticalLayout->addWidget(pushButton_19);

        pushButton_18 = new QPushButton(scrollAreaWidgetContents);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));

        verticalLayout->addWidget(pushButton_18);

        pushButton_17 = new QPushButton(scrollAreaWidgetContents);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));

        verticalLayout->addWidget(pushButton_17);

        pushButton_16 = new QPushButton(scrollAreaWidgetContents);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));

        verticalLayout->addWidget(pushButton_16);

        pushButton_15 = new QPushButton(scrollAreaWidgetContents);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        verticalLayout->addWidget(pushButton_15);

        pushButton_14 = new QPushButton(scrollAreaWidgetContents);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        verticalLayout->addWidget(pushButton_14);

        pushButton_13 = new QPushButton(scrollAreaWidgetContents);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        verticalLayout->addWidget(pushButton_13);

        pushButton_12 = new QPushButton(scrollAreaWidgetContents);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        verticalLayout->addWidget(pushButton_12);

        pushButton_11 = new QPushButton(scrollAreaWidgetContents);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        verticalLayout->addWidget(pushButton_11);

        pushButton_31 = new QPushButton(scrollAreaWidgetContents);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));

        verticalLayout->addWidget(pushButton_31);

        pushButton_32 = new QPushButton(scrollAreaWidgetContents);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));

        verticalLayout->addWidget(pushButton_32);

        pushButton_37 = new QPushButton(scrollAreaWidgetContents);
        pushButton_37->setObjectName(QString::fromUtf8("pushButton_37"));

        verticalLayout->addWidget(pushButton_37);

        pushButton_36 = new QPushButton(scrollAreaWidgetContents);
        pushButton_36->setObjectName(QString::fromUtf8("pushButton_36"));

        verticalLayout->addWidget(pushButton_36);

        pushButton_35 = new QPushButton(scrollAreaWidgetContents);
        pushButton_35->setObjectName(QString::fromUtf8("pushButton_35"));

        verticalLayout->addWidget(pushButton_35);

        pushButton_34 = new QPushButton(scrollAreaWidgetContents);
        pushButton_34->setObjectName(QString::fromUtf8("pushButton_34"));

        verticalLayout->addWidget(pushButton_34);

        pushButton_33 = new QPushButton(scrollAreaWidgetContents);
        pushButton_33->setObjectName(QString::fromUtf8("pushButton_33"));

        verticalLayout->addWidget(pushButton_33);

        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(page_5);
        btn_p1 = new QPushButton(Widget);
        btn_p1->setObjectName(QString::fromUtf8("btn_p1"));
        btn_p1->setGeometry(QRect(370, 80, 92, 28));
        btn_p2 = new QPushButton(Widget);
        btn_p2->setObjectName(QString::fromUtf8("btn_p2"));
        btn_p2->setGeometry(QRect(370, 130, 92, 28));
        btn_p3 = new QPushButton(Widget);
        btn_p3->setObjectName(QString::fromUtf8("btn_p3"));
        btn_p3->setGeometry(QRect(370, 190, 92, 28));
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(500, 80, 89, 27));
        btn_benz = new QPushButton(Widget);
        btn_benz->setObjectName(QString::fromUtf8("btn_benz"));
        btn_benz->setGeometry(QRect(500, 140, 92, 28));
        spinBox = new QSpinBox(Widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(510, 200, 50, 28));
        doubleSpinBox = new QDoubleSpinBox(Widget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(520, 260, 72, 28));
        timeEdit = new QTimeEdit(Widget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(370, 260, 118, 28));
        dateEdit = new QDateEdit(Widget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(370, 330, 116, 28));
        dateTimeEdit = new QDateTimeEdit(Widget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(510, 330, 194, 28));
        horizontalScrollBar = new QScrollBar(Widget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(440, 490, 160, 16));
        horizontalScrollBar->setOrientation(Qt::Orientation::Horizontal);
        verticalScrollBar = new QScrollBar(Widget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(380, 390, 16, 160));
        verticalScrollBar->setOrientation(Qt::Orientation::Vertical);
        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(590, 200, 160, 18));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        verticalSlider = new QSlider(Widget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(630, 380, 18, 160));
        verticalSlider->setOrientation(Qt::Orientation::Vertical);
        keySequenceEdit = new QKeySequenceEdit(Widget);
        keySequenceEdit->setObjectName(QString::fromUtf8("keySequenceEdit"));
        keySequenceEdit->setGeometry(QRect(470, 420, 113, 27));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(680, 400, 111, 101));
        label_movie = new QLabel(Widget);
        label_movie->setObjectName(QString::fromUtf8("label_movie"));
        label_movie->setGeometry(QRect(640, 30, 271, 131));

        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(1);
        toolBox->setCurrentIndex(2);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("Widget", "\345\256\266\344\272\272", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("Widget", "\346\234\213\345\217\213", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("Widget", "\351\273\221\345\220\215\345\215\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("Widget", "\347\231\276\345\272\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Widget", "\350\260\267\346\255\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Widget", "\345\277\205\345\272\224", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_30->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_29->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_28->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_27->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_26->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_25->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_24->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_23->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_22->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_21->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_20->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_19->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_18->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_17->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_16->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_15->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_14->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_13->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_12->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_31->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_32->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_37->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_36->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_35->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_34->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        pushButton_33->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        btn_p1->setText(QCoreApplication::translate("Widget", "\347\254\254\344\270\200\351\241\265", nullptr));
        btn_p2->setText(QCoreApplication::translate("Widget", "\347\254\254\344\272\214\351\241\265", nullptr));
        btn_p3->setText(QCoreApplication::translate("Widget", "\347\254\254\344\270\211\351\241\265", nullptr));
        btn_benz->setText(QCoreApplication::translate("Widget", "\347\202\271\345\207\273\351\200\211\344\270\255\345\245\224\351\251\260", nullptr));
        label->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        label_movie->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
