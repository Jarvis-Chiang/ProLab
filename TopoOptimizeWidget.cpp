#include "TopoOptimizeWidget.h"
#pragma execution_character_set("utf-8")

TopoOptimizeWidget::TopoOptimizeWidget(QWidget* parent) :
	oprStackWidget(new  QStackedWidget(this)),
	designZoneWidget(new DesignZoneWidget),
	materialSetWidget(new MaterialSetWidget),
	treeWidget(new QTreeWidget(this))
{
	init();
	creatAction();
}

TopoOptimizeWidget :: ~TopoOptimizeWidget()
{

}

void TopoOptimizeWidget :: init()
{
	//右侧操作栏堆栈窗口
	oprStackWidget->addWidget(designZoneWidget);//QStackedWidget类适addWidget函数适只适用于标准指针，Qt智能指针不行
	oprStackWidget->addWidget(materialSetWidget);
	//左侧树状结构窗口
	treeWidget->setColumnCount(1); //设置列数
	treeWidget->setHeaderHidden(true);

	QTreeWidgetItem* tree0 = new QTreeWidgetItem(treeWidget, QStringList(QString("设计域")));
	QTreeWidgetItem* tree1 = new QTreeWidgetItem(treeWidget, QStringList(QString("材料属性")));
	QTreeWidgetItem* tree2 = new QTreeWidgetItem(treeWidget, QStringList(QString("边界条件")));
	QTreeWidgetItem* tree3 = new QTreeWidgetItem(treeWidget, QStringList(QString("载荷设置")));
	QTreeWidgetItem* tree4 = new QTreeWidgetItem(treeWidget, QStringList(QString("优化参数")));
	QTreeWidgetItem* tree5 = new QTreeWidgetItem(treeWidget, QStringList(QString("结果查看")));

	treeWidget->expandAll();
}

void TopoOptimizeWidget::creatAction()
{
	connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(designZoneWidget->uiDesignZone->importDesignGridButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));
	connect(materialSetWidget->uiMaterialSet->pushButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));
}


//加载设计域ui
DesignZoneWidget::DesignZoneWidget(QWidget* parent) :
	uiDesignZone(new Ui_DesignZone::DesignZoneWidget)
{
	uiDesignZone->setupUi(this);
}

DesignZoneWidget :: ~DesignZoneWidget()
{
	delete uiDesignZone;
}

//加载材料属性设置ui
MaterialSetWidget::MaterialSetWidget(QWidget* parent):
	uiMaterialSet(new Ui_Material::MeterialSetWidget)
{
	uiMaterialSet->setupUi(this);
}

MaterialSetWidget::~MaterialSetWidget()
{
	delete uiMaterialSet;
}


//****************以下为槽函数*********************//

void TopoOptimizeWidget::stackedWidgetPageChange(QTreeWidgetItem* item, int column)
{
	if (item->text(column) == "设计域")//?????????????
	{
		oprStackWidget->setCurrentIndex(0);
	}
	if (item->text(column) == "材料属性")
	{
		oprStackWidget->setCurrentIndex(1);
	}
}

//设计域中导入设计域网格文件对应的选择文件路径对话框
void TopoOptimizeWidget::importDesignGridFile()
{
	fileRoute = QFileDialog::getOpenFileName(this, QStringLiteral("Please Select File"), "F:", QStringLiteral("textfile(*txt)"));
}
