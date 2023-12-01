#pragma once
#pragma execution_character_set("utf-8")

#include "ui_DesignZoneWidget.h"
#include "ui_MaterialSetWidget.h"

#include <QWidget>
#include <QStackedWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QSharedPointer>
#include <QGridLayout>
#include <QFileDialog>


//设计域
class DesignZoneWidget : public QWidget
{

	Q_OBJECT

public:
	DesignZoneWidget(QWidget* parent = 0);
	~DesignZoneWidget();
	Ui_DesignZone::DesignZoneWidget* uiDesignZone;

	//	//元对象系统自动生成的信号：条件是保持同名
	//public slots:
	//	void on_importDesignGridBotton_clicked();//必须写定义
	//	void on_generateBotton_clicked();
	//需要测试！！！！！！！！！！！！！！！！！！！！！！！！！！命名规范为什么不管用？？？？？？？？？

};

//材料设置
class MaterialSetWidget : public QWidget
{

	Q_OBJECT

public:
	MaterialSetWidget(QWidget* parent = 0);
	~MaterialSetWidget();
	Ui_Material::MeterialSetWidget* uiMaterialSet;
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
	QTreeWidget* treeWidget; //左侧树状结构窗口
	QString fileRoute;//外部文件路径接口，需要选择的路径可以直接用这个QString类字符串
private:
	DesignZoneWidget* designZoneWidget;
	MaterialSetWidget* materialSetWidget;
	QSharedPointer<QGridLayout> gridLayout;


public slots:
	void stackedWidgetPageChange(QTreeWidgetItem* item, int column);
	void importDesignGridFile();
};



