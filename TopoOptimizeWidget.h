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
	QSharedPointer<QStackedWidget> oprStackWidget; //ÓÒ²à²Ù×÷À¸¶ÑÕ»´°¿Ú
	QSharedPointer<QTreeWidget> treeWidget; //×ó²àÊ÷×´½á¹¹´°¿Ú
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
