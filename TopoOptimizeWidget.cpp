#include "TopoOptimizeWidget.h"

TopoOptimizeWidget::TopoOptimizeWidget(QWidget* parent) :
	oprStackWidget(QSharedPointer<QStackedWidget>(new QStackedWidget(this))),
	designZoneWidget(new DesignZoneWidget),
	gridLayout(QSharedPointer<QGridLayout>(new QGridLayout(this))),
	materialSetWidget(new MaterialSetWidget)
{
	init();
}

TopoOptimizeWidget :: ~TopoOptimizeWidget()
{

}

void TopoOptimizeWidget :: init()
{
	oprStackWidget->addWidget(designZoneWidget);//QStackedWidget����addWidget������ֻ�����ڱ�׼ָ�룬Qt����ָ�벻��
	oprStackWidget->addWidget(materialSetWidget);
	gridLayout->addWidget(oprStackWidget.data(),0, 0, 0, 0);
	setLayout(gridLayout.data());
}


//���������ui
TopoOptimizeWidget::DesignZoneWidget::DesignZoneWidget(QWidget* parent) :
	uiDesignZone(new Ui_DesignZone::DesignZoneWidget)
{
	uiDesignZone->setupUi(this);
}

TopoOptimizeWidget::DesignZoneWidget :: ~DesignZoneWidget()
{
	delete uiDesignZone;
}

//���ز�����������ui
TopoOptimizeWidget::MaterialSetWidget::MaterialSetWidget(QWidget* parent):
	uiMaterialSet(new Ui_Material::MeterialSetWidget)
{
	uiMaterialSet->setupUi(this);
}

TopoOptimizeWidget::MaterialSetWidget::~MaterialSetWidget()
{
	delete uiMaterialSet;
}
