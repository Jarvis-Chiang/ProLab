#pragma once
#pragma execution_character_set("utf-8")

#include "ui_DesignZoneWidget.h"
#include "ui_MaterialSetWidget.h"
#include "ui_OptimizeParaWidget.h"
#include "ui_ResultCheckWidget.h"
#include "ui_BoundaryCasesWidget.h"
#include "ui_LoadSetWidget.h"
#include "ui_DesignZoneWidget _3D.h"
#include "ui_BoundaryCasesWidget_3D.h"
#include "ui_LoadSetWidget_3D.h"
#include "ui_OptimizeParaWidget_3D.h"

#include <QWidget>
#include <QStackedWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QSharedPointer>
#include <QGridLayout>
#include <QFileDialog>
#include <QButtonGroup>


//设计域
class DesignZoneWidget : public QWidget
{

	Q_OBJECT

public:
	DesignZoneWidget();
	~DesignZoneWidget();
	Ui_DesignZone::DesignZoneWidget* uiDesignZone;

	//	//元对象系统自动生成的信号：条件是保持同名
	//public slots:
	//	void on_importDesignGridBotton_clicked();//必须写定义
	//	void on_generateBotton_clicked();
	//需要测试！！！！！！！！！！！！！！！！！！！！！！！！！！命名规范为什么不管用？？？？？？？？？

};

//3D设计域
class DesignZone_3D : public QWidget
{
public:
	DesignZone_3D();
	~DesignZone_3D();
	Ui_DesignZone_3D::DesignZoneWidget* uiDesignZone_3d;


};

//材料设置
class MaterialSetWidget : public QWidget
{

	Q_OBJECT

public:
	MaterialSetWidget();
	~MaterialSetWidget();
	Ui_Material::MeterialSetWidget* uiMaterialSet;
private:
	QButtonGroup* radioButtons;

private slots:
	void sameButton(int state);
	void diffButton(int state);
};

//边界条件设置
class BoundaryCasesWidget : public QWidget
{

	Q_OBJECT

public:
	BoundaryCasesWidget();
	~BoundaryCasesWidget();
	Ui_BoundaryCases::BoundaryCasesWidget* uiBoundaryCases;
};

//3D边界条件设置
class BoundaryCases_3D : public QWidget
{
public:
	BoundaryCases_3D();
	~BoundaryCases_3D();
	Ui_BoundaryCases_3D::BoundaryCasesWidget_3D* uiBoundaryCases_3D;
	
};


//载荷设置
class LoadSetWidget : public QWidget
{

	Q_OBJECT

public:
	LoadSetWidget();
	~LoadSetWidget();
	Ui_LoadSet::LoadSetWidget* uiLoadSet;

};

//3D载荷设置
class LoadSet_3D : public QWidget
{
public:
	LoadSet_3D();
	~LoadSet_3D();
	Ui_LoadSet_3D::LoadSetWidget_3D* uiLoadSet_3D;
};



//优化参数设置
class OptimizeParaWidget : public QWidget
{
	Q_OBJECT

public:
	OptimizeParaWidget();
	~OptimizeParaWidget();
	Ui_OptimizePara::OptimizeParaWidget* uiOptimizePara;
};

//3D优化参数设置
class OptimizePara_3D : public QWidget
{
public:
	OptimizePara_3D();
	~OptimizePara_3D();
	Ui_OptimizePara_3D::OptimizeParaWidget_3D* uiOptimizePara_3D;
};

//结果查看
class ResultCheckWidget : public QWidget
{

	Q_OBJECT

public:
	ResultCheckWidget();
	~ResultCheckWidget();
	Ui_Result::ResultCheckWidget* uiRecultCheck;

};

class TopoOptimizeWidget : public QWidget
{

	Q_OBJECT

public:
    explicit TopoOptimizeWidget(QWidget* parent = 0);
    virtual ~TopoOptimizeWidget();

	void init();
	void creatAction();

public:
	QStackedWidget* oprStackWidget; //右侧操作栏堆栈窗口
	QStackedWidget* treeStackWidget;//左侧树状结构堆栈窗口
	QString fileRoute;//外部文件路径接口，需要选择的路径可以直接用这个QString类字符串
private:
	QTreeWidget* treeWidget1; //左侧树状结构窗口1
	QTreeWidget* treeWidget2; //左侧树状结构窗口2
	DesignZoneWidget* designZoneWidget;
	DesignZone_3D* designZone_3D;
	MaterialSetWidget* materialSetWidget;
	OptimizeParaWidget* optimizeParaWidget;
	ResultCheckWidget* resultCheckWidget;
	BoundaryCasesWidget* boundaryCasesWidget;
	LoadSetWidget* loadSetWidget;
	BoundaryCases_3D* boundaryCases_3D;
	LoadSet_3D* loadSet_3D;
	OptimizePara_3D* optimizePara_3D;


public slots:
	void stackedWidgetPageChange(QTreeWidgetItem* item, int column);
	void importDesignGridFile();
};



