#include "TopoOptimizeWidget.h"
#pragma execution_character_set("utf-8")

TopoOptimizeWidget::TopoOptimizeWidget(QWidget* parent) :
	oprStackWidget(new  QStackedWidget(this)),
	designZoneWidget(new DesignZoneWidget),
	materialSetWidget(new MaterialSetWidget),
	optimizeParaWidget(new OptimizeParaWidget),
	resultCheckWidget(new ResultCheckWidget),
	boundaryCasesWidget(new BoundaryCasesWidget),
	loadSetWidget(new LoadSetWidget),
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
	//�Ҳ��������ջ����
	oprStackWidget->addWidget(designZoneWidget);//QStackedWidget����addWidget������ֻ�����ڱ�׼ָ�룬Qt����ָ�벻��
	oprStackWidget->addWidget(materialSetWidget);
	oprStackWidget->addWidget(boundaryCasesWidget);
	oprStackWidget->addWidget(loadSetWidget);
	oprStackWidget->addWidget(optimizeParaWidget);
	oprStackWidget->addWidget(resultCheckWidget);

	//�����״�ṹ����
	treeWidget->setColumnCount(1); //��������
	treeWidget->setHeaderHidden(true);

	QTreeWidgetItem* tree0 = new QTreeWidgetItem(treeWidget, QStringList(QString("�����")));
	QTreeWidgetItem* tree1 = new QTreeWidgetItem(treeWidget, QStringList(QString("��������")));
	QTreeWidgetItem* tree2 = new QTreeWidgetItem(treeWidget, QStringList(QString("�߽�����")));
	QTreeWidgetItem* tree3 = new QTreeWidgetItem(treeWidget, QStringList(QString("�غ�����")));
	QTreeWidgetItem* tree4 = new QTreeWidgetItem(treeWidget, QStringList(QString("�Ż�����")));
	QTreeWidgetItem* tree5 = new QTreeWidgetItem(treeWidget, QStringList(QString("����鿴")));

	treeWidget->expandAll();
}

void TopoOptimizeWidget::creatAction()
{
	//���ṹ�Ͷ�ջ���ڹ���
	connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));

	//�ļ���ȡ�Ի���
	connect(designZoneWidget->uiDesignZone->importDesignGridButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));
	connect(materialSetWidget->uiMaterialSet->pushButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));
}


//���������ui
DesignZoneWidget::DesignZoneWidget() :
	uiDesignZone(new Ui_DesignZone::DesignZoneWidget)
{
	uiDesignZone->setupUi(this);
}

DesignZoneWidget :: ~DesignZoneWidget()
{
	delete uiDesignZone;
}

//���ز�����������ui
MaterialSetWidget::MaterialSetWidget():
	uiMaterialSet(new Ui_Material::MeterialSetWidget)
{
	uiMaterialSet->setupUi(this);
}

MaterialSetWidget::~MaterialSetWidget()
{
	delete uiMaterialSet;
}

//���ر߽�����ui

BoundaryCasesWidget::BoundaryCasesWidget():
	uiBoundaryCases(new Ui_BoundaryCases::BoundaryCasesWidget)
{
	uiBoundaryCases->setupUi(this);
}

BoundaryCasesWidget::~BoundaryCasesWidget()
{
	delete uiBoundaryCases;
}

//�����غ�����ui
LoadSetWidget::LoadSetWidget():
	uiLoadSet(new Ui_LoadSet::LoadSetWidget)
{
	uiLoadSet->setupUi(this);
}

LoadSetWidget::~LoadSetWidget()
{
	delete uiLoadSet;
}

//���ز����Ż�ui
OptimizeParaWidget::OptimizeParaWidget():
	uiOptimizePara(new Ui_OptimizePara::OptimizeParaWidget)
{
	uiOptimizePara->setupUi(this);
}

OptimizeParaWidget::~OptimizeParaWidget()
{
	delete uiOptimizePara;
}

//���ؽ���鿴ui
ResultCheckWidget::ResultCheckWidget():
	uiRecultCheck(new Ui_Result:: ResultCheckWidget)
{
	uiRecultCheck->setupUi(this);
}

ResultCheckWidget::~ResultCheckWidget()
{
	delete uiRecultCheck;
}




//****************����Ϊ�ۺ���*********************//

void TopoOptimizeWidget::stackedWidgetPageChange(QTreeWidgetItem* item, int column)
{
	if (item->text(column) == "�����")//?????????????
	{
		oprStackWidget->setCurrentIndex(0);
	}

	if (item->text(column) == "��������")
	{
		oprStackWidget->setCurrentIndex(1);
	}

	if (item->text(column) == "�߽�����")
	{
		oprStackWidget->setCurrentIndex(2);
	}

	if (item->text(column) == "�غ�����")
	{
		oprStackWidget->setCurrentIndex(3);
	}

	if (item->text(column) == "�Ż�����")
	{
		oprStackWidget->setCurrentIndex(4);
	}

	if (item->text(column) == "����鿴")
	{
		oprStackWidget->setCurrentIndex(5);
	}
}

//������е�������������ļ���Ӧ��ѡ���ļ�·���Ի���
void TopoOptimizeWidget::importDesignGridFile()
{
	fileRoute = QFileDialog::getOpenFileName(this, QStringLiteral("Please Select File"), "F:", QStringLiteral("textfile(*txt)"));
}
