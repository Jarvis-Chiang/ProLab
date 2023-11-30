#pragma once
#include <qwidget.h>
#include <qstackedwidget.h>
#include <qtreewidget.h>
#include <qsharedpointer.h>
#include "ui_DesignZoneWidget.h"
class TopoOptimizeWidget : public QWidget
{

	Q_OBJECT

public:
    explicit TopoOptimizeWidget(QWidget* parent = 0);
    virtual ~TopoOptimizeWidget();

	void init();

public:
	QSharedPointer<QStackedWidget> oprStackWidget; //�Ҳ��������ջ����
	QSharedPointer<QTreeWidget> treeWidget; //�����״�ṹ����
private:
	//DesignZoneWidget* designZoneWidget;
	//QSharedPointer<DesignZoneWidget> designZoneWidget;
	QSharedPointer<QGridLayout> gridLayout;
	//QSharedPointer<QLabel> label;
	//QLabel* label;

};


class DesignZoneWidget : public QWidget
{
	Q_OBJECT

public:
	DesignZoneWidget(QWidget* parent = 0);
	~DesignZoneWidget();

private:
	Ui::DesignZoneWidget* uiDesignZone;
};
