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

	//�����
	class DesignZoneWidget : public QWidget
	{
	public:
		DesignZoneWidget(QWidget* parent = 0);
		~DesignZoneWidget();

	private:
		Ui_DesignZone::DesignZoneWidget* uiDesignZone;
	};

	//��������
	class MaterialSetWidget : public QWidget
	{
	public:
		MaterialSetWidget(QWidget* parent = 0);
		~MaterialSetWidget();

	private:
		Ui_Material::MeterialSetWidget* uiMaterialSet;
	};

public:
	QSharedPointer<QStackedWidget> oprStackWidget; //�Ҳ��������ջ����
	QSharedPointer<QTreeWidget> treeWidget; //�����״�ṹ����
private:
	DesignZoneWidget* designZoneWidget;
	MaterialSetWidget* materialSetWidget;
	QSharedPointer<QGridLayout> gridLayout;
};



