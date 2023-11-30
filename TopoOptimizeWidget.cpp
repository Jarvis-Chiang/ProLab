#include "TopoOptimizeWidget.h"

TopoOptimizeWidget::TopoOptimizeWidget(QWidget* parent) :
	oprStackWidget(QSharedPointer<QStackedWidget>(new QStackedWidget(this))),
	//designZoneWidget(new DesignZoneWidget),
	//designZoneWidget(QSharedPointer<DesignZoneWidget>(new DesignZoneWidget)),
	gridLayout(QSharedPointer<QGridLayout>(new QGridLayout(this)))
	//label(new QLabel)
{
	init();
}

TopoOptimizeWidget :: ~TopoOptimizeWidget()
{

}

void TopoOptimizeWidget :: init()
{
	//oprStackWidget->addWidget(designZoneWidget);//QStackedWidget类适addWidget函数适只适用于标准指针，Qt智能指针不行
	//label->setText("dsfadfas");
	//oprStackWidget->addWidget(label);
	gridLayout->addWidget(oprStackWidget.data(),0, 0, 0, 0);
	setLayout(gridLayout.data());
}

//TopoOptimizeWidget内部控件
DesignZoneWidget::DesignZoneWidget(QWidget* parent) :
	uiDesignZone(new Ui::DesignZoneWidget)
{
	uiDesignZone->setupUi(this);
}

DesignZoneWidget :: ~DesignZoneWidget()
{
	delete uiDesignZone;
}