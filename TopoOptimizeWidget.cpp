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
	//oprStackWidget->addWidget(designZoneWidget);//QStackedWidget����addWidget������ֻ�����ڱ�׼ָ�룬Qt����ָ�벻��
	//label->setText("dsfadfas");
	//oprStackWidget->addWidget(label);
	gridLayout->addWidget(oprStackWidget.data(),0, 0, 0, 0);
	setLayout(gridLayout.data());
}

//TopoOptimizeWidget�ڲ��ؼ�
DesignZoneWidget::DesignZoneWidget(QWidget* parent) :
	uiDesignZone(new Ui::DesignZoneWidget)
{
	uiDesignZone->setupUi(this);
}

DesignZoneWidget :: ~DesignZoneWidget()
{
	delete uiDesignZone;
}