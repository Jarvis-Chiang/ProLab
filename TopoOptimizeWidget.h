#pragma once

#include "ui_DesignZoneWidget.h"
#include "ui_MaterialSetWidget.h"

#include <qwidget.h>
#include <qstackedwidget.h>
#include <qtreewidget.h>
#include <qsharedpointer.h>
#include <qgridlayout.h>

class TopoOptimizeWidget : public QWidget
{

	Q_OBJECT

public:
    explicit TopoOptimizeWidget(QWidget* parent = 0);
    virtual ~TopoOptimizeWidget();

	void init();

private:

	//设计域
	class DesignZoneWidget : public QWidget
	{
	public:
		DesignZoneWidget(QWidget* parent = 0);
		~DesignZoneWidget();

	private:
		Ui_DesignZone::DesignZoneWidget* uiDesignZone;
	};

	//材料设置
	class MaterialSetWidget : public QWidget
	{
	public:
		MaterialSetWidget(QWidget* parent = 0);
		~MaterialSetWidget();

	private:
		Ui_Material::MeterialSetWidget* uiMaterialSet;
	};

public:
	QSharedPointer<QStackedWidget> oprStackWidget; //右侧操作栏堆栈窗口
	QSharedPointer<QTreeWidget> treeWidget; //左侧树状结构窗口
private:
	DesignZoneWidget* designZoneWidget;
	MaterialSetWidget* materialSetWidget;
	QSharedPointer<QGridLayout> gridLayout;
};



