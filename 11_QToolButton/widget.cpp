#include "./ui_widget.h"
#include "advanced_widget.h"
#include "basic_widget.h"
#include "continue_widget.h"
#include "font_widget.h"
#include "highlight_widget.h"
#include "official_widget.h"
#include "panel_widget.h"
#include "skin_widget.h"
#include "third_widget.h"
#include "weather_widget.h"
#include "widget.h"

Widget::Widget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::Widget)
{
	ui->setupUi(this);

	tbtnGroup = new QButtonGroup(this);
	QList<PageMapping> mappings = { {ui->tbtnBasic, new BasicWidget(this)},
								   {ui->tbtnFont, new FontWidget(this)},
								   {ui->tbtnAdvanced, new AdvancedWidget(this)},
								   {ui->tbtnOfficialChat, new OfficialWidget(this)},
								   {ui->tbtnThirdChat, new ThirdWidget(this)},
								   {ui->tbtnPanel, new PanelWidget(this)},
								   {ui->tbtnHighlight, new HighlightWidget(this)},
								   {ui->tbtnWeather, new WeatherWidget(this)},
								   {ui->tbtnSkin, new SkinWidget(this)},
								   {ui->tbtnContinue, new ContinueWidget(this)} };

	for (const PageMapping& item : mappings) {
		ui->stackedWidget->addWidget(item.page);
		tbtnGroup->addButton(item.tbtn);
		connect(item.tbtn, &QToolButton::clicked, this, [=]() {
			ui->stackedWidget->setCurrentWidget(item.page);
			});
	}
	ui->tbtnBasic->click();
}

Widget::~Widget()
{
	delete ui;
}
