#include "my_widget.h"

void RegionManager::loadData()
{
	provinces.reserve(34);

	// 模拟数据插入
	provinces.push_back({ "110000", "北京市" });
	provinces.push_back({ "440000", "广东省" });

	cities["110000"] = { {"110100", "北京市"} };
	districts["110100"] = { {"110105", "朝阳区"}, {"110108", "海淀区"} };

	cities["440000"] = { {"440100", "广州市"}, {"440300", "深圳市"} };
	districts["440100"] = { {"440106", "天河区"}, {"440111", "白云区"} };
	districts["440300"] = { {"440305", "南山区"}, {"440304", "福田区"} };
}

MyWidget::MyWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::MyWidgetClass())
{
	ui->setupUi(this);

	// QCheckBox

	// 初始化水果列表
	fruitList << ui->chkApple << ui->chkBanana << ui->chkOrange << ui->chkGrape;
	ui->edtSelectedFruit->setReadOnly(true);
	// 开启三态支持
	ui->chkAll->setTristate(true);
	// 绑定全选框
	connect(ui->chkAll, &QCheckBox::clicked, this, &MyWidget::onSelectAllClicked);
	// 批量绑定水果框
	for (QCheckBox* fruitBox : fruitList) {
		connect(fruitBox, &QCheckBox::clicked, this, &MyWidget::onFruitClicked);
	}
	// 初始化显示状态
	updateSelectAllState();
	updateFruitDisplay();


	// QComboBox
	RegionManager::instance().loadData();
	ui->edtSelectedRegion->setReadOnly(true);

	connect(ui->cmbProvince, qOverload<int>(&QComboBox::currentIndexChanged), this, [this](int index) {
		if (index <= 0) {
			ui->cmbCity->clear();
			ui->cmbDistrict->clear();
			updateSelectedRegion();
			return;
		}

		QString provCode = ui->cmbProvince->itemData(index).toString();
		ui->cmbCity->blockSignals(true);
		ui->cmbCity->clear();
		ui->cmbCity->addItem("请选择城市", "");

		const auto& cities = RegionManager::instance().cities.value(provCode);
		for (const auto& city : cities) {
			ui->cmbCity->addItem(city.name, city.code);
		}
		ui->cmbCity->blockSignals(false);
		ui->cmbDistrict->clear();
		updateSelectedRegion();
		});

	connect(ui->cmbCity, qOverload<int>(&QComboBox::currentIndexChanged), this, [this](int index) {
		if (index <= 0) {
			ui->cmbDistrict->clear();
			updateSelectedRegion();
			return;
		}

		QString cityCode = ui->cmbCity->itemData(index).toString();
		ui->cmbDistrict->blockSignals(true);
		ui->cmbDistrict->clear();
		ui->cmbDistrict->addItem("请选择区县", "");

		const auto& districts = RegionManager::instance().districts.value(cityCode);
		for (const auto& dist : districts) {
			ui->cmbDistrict->addItem(dist.name, dist.code);
		}
		ui->cmbDistrict->blockSignals(false);
		updateSelectedRegion();
		});

	connect(ui->cmbDistrict, qOverload<int>(&QComboBox::currentIndexChanged), this, [this](int index) {
		Q_UNUSED(index);
		updateSelectedRegion();
		});

	initComboBoxes();


	// QSpinBox
	ui->dspnUnitPrice->setRange(1.00, 100.00);  // 设置最小最大值
	ui->dspnUnitPrice->setPrefix("$"); // 设置前缀
	ui->dspnUnitPrice->setSingleStep(0.01); // 设置步长
	ui->dspnUnitPrice->setAccelerated(true); // 设置加速
	ui->dspnUnitPrice->setWrapping(true);  // 设置循环

	ui->spnWeight->setRange(100, 300);  // 设置最小最大值
	ui->spnWeight->setSuffix("KG"); // 设置后缀
	ui->spnWeight->setSingleStep(1); // 设置步长
	ui->spnWeight->setAccelerated(true); // 设置加速
	ui->spnWeight->setWrapping(true);  // 设置循环

	ui->edtTotalPrice->setReadOnly(true);

	connect(ui->dspnUnitPrice, qOverload<double>(&QDoubleSpinBox::valueChanged), this, [this](double value) {
		ui->edtTotalPrice->setText(QString::number(value * ui->spnWeight->value()));
		});
	connect(ui->spnWeight, qOverload<int>(&QSpinBox::valueChanged), this, [this](int value) {
		ui->edtTotalPrice->setText(QString::number(value * ui->dspnUnitPrice->value()));
		});
	ui->edtTotalPrice->setText(QString::number(ui->dspnUnitPrice->value() * ui->spnWeight->value()));
}

MyWidget::~MyWidget()
{
	delete ui;
}

void MyWidget::onSelectAllClicked()
{
	// isChecked() 只要不是 Unchecked（包括了全选和部分选中），都返回true
	bool toCheck = ui->chkAll->isChecked();

	// 屏蔽全选框自身的信号，防止 setCheckState 再次触发不必要的信号
	// 并且强制用户点击时，全选框只能在“全选”和“不选”之间切换，跳过“部分选中”状态
	{
		QSignalBlocker blocker(ui->chkAll);
		ui->chkAll->setCheckState(toCheck ? Qt::Checked : Qt::Unchecked);
	}

	// 遍历更新子项，并屏蔽子项的信号，防止它们反向触发 updateSelectAllState
	for (QCheckBox* fruitBox : fruitList) {
		QSignalBlocker blocker(fruitBox);
		fruitBox->setChecked(toCheck);
	}

	updateFruitDisplay();
}

void MyWidget::onFruitClicked()
{
	updateSelectAllState();
	updateFruitDisplay();
}

void MyWidget::updateSelectAllState()
{
	int checkedCount = 0;
	for (QCheckBox* fruitBox : fruitList) {
		if (fruitBox->isChecked()) {
			checkedCount++;
		}
	}

	// 屏蔽信号防止死循环
	QSignalBlocker blocker(ui->chkAll);
	if (checkedCount == fruitList.size()) {
		// 全选
		ui->chkAll->setCheckState(Qt::Checked);
	}
	else if (checkedCount == 0) {
		// 全不选
		ui->chkAll->setCheckState(Qt::Unchecked);
	}
	else {
		// 部分选中
		ui->chkAll->setCheckState(Qt::PartiallyChecked);
	}
}

void MyWidget::updateFruitDisplay()
{
	QStringList selected;
	for (QCheckBox* fruitBox : fruitList) {
		if (fruitBox->isChecked()) {
			selected << fruitBox->text();
		}
	}
	ui->edtSelectedFruit->setText(selected.join(", "));
}

void MyWidget::initComboBoxes()
{
	// 操作UI前阻断信号，防止清空/添加时触发不必要的级联计算
	ui->cmbProvince->blockSignals(true);
	ui->cmbProvince->clear();

	const auto& provinces = RegionManager::instance().provinces;
	ui->cmbProvince->addItem("请选择省份", "");

	for (const auto& prov : provinces) {
		// addItem的第二个参数是userData。
		// 将行政代码Code存入userData，保证唯一性，不依赖显示文本
		ui->cmbProvince->addItem(prov.name, prov.code);
	}

	ui->cmbProvince->blockSignals(false);
	ui->cmbProvince->setCurrentIndex(0);
}

void MyWidget::updateSelectedRegion()
{
	QString address;
	if (ui->cmbProvince->currentIndex() > 0) {
		address += ui->cmbProvince->currentText();
	}
	if (ui->cmbCity->currentIndex() > 0) {
		address += ui->cmbCity->currentText();
	}
	if (ui->cmbDistrict->currentIndex() > 0) {
		address += ui->cmbDistrict->currentText();
	}
	ui->edtSelectedRegion->setText(address);
}