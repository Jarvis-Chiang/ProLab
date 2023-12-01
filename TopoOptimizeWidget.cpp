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
	//�Ҳ��������ջ����
	oprStackWidget->addWidget(designZoneWidget);//QStackedWidget����addWidget������ֻ�����ڱ�׼ָ�룬Qt����ָ�벻��
	oprStackWidget->addWidget(materialSetWidget);
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
	connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(designZoneWidget->uiDesignZone->importDesignGridButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));
	connect(materialSetWidget->uiMaterialSet->pushButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));
}


//���������ui
DesignZoneWidget::DesignZoneWidget(QWidget* parent) :
	uiDesignZone(new Ui_DesignZone::DesignZoneWidget)
{
	uiDesignZone->setupUi(this);
}

DesignZoneWidget :: ~DesignZoneWidget()
{
	delete uiDesignZone;
}

//���ز�����������ui
MaterialSetWidget::MaterialSetWidget(QWidget* parent):
	uiMaterialSet(new Ui_Material::MeterialSetWidget)
{
	uiMaterialSet->setupUi(this);
}

MaterialSetWidget::~MaterialSetWidget()
{
	delete uiMaterialSet;
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
}

//������е�������������ļ���Ӧ��ѡ���ļ�·���Ի���
void TopoOptimizeWidget::importDesignGridFile()
{
	fileRoute = QFileDialog::getOpenFileName(this, QStringLiteral("Please Select File"), "F:", QStringLiteral("textfile(*txt)"));
}
