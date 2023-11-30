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
	oprStackWidget->addWidget(designZoneWidget);//QStackedWidget类适addWidget函数适只适用于标准指针，Qt智能指针不行
	oprStackWidget->addWidget(materialSetWidget);
	gridLayout->addWidget(oprStackWidget.data(),0, 0, 0, 0);
	setLayout(gridLayout.data());
}


//加载设计域ui
TopoOptimizeWidget::DesignZoneWidget::DesignZoneWidget(QWidget* parent) :
	uiDesignZone(new Ui_DesignZone::DesignZoneWidget)
{
	uiDesignZone->setupUi(this);
}

TopoOptimizeWidget::DesignZoneWidget :: ~DesignZoneWidget()
{
	delete uiDesignZone;
}

//加载材料属性设置ui
TopoOptimizeWidget::MaterialSetWidget::MaterialSetWidget(QWidget* parent):
	uiMaterialSet(new Ui_Material::MeterialSetWidget)
{
	uiMaterialSet->setupUi(this);
}

TopoOptimizeWidget::MaterialSetWidget::~MaterialSetWidget()
{
	delete uiMaterialSet;
}
