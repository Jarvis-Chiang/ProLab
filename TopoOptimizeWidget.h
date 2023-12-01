#pragma once
#pragma execution_character_set("utf-8")

#include "ui_DesignZoneWidget.h"
#include "ui_MaterialSetWidget.h"
#include "ui_OptimizeParaWidget.h"
#include "ui_ResultCheckWidget.h"
#include "ui_BoundaryCasesWidget.h"
#include "ui_LoadSetWidget.h"

#include <QWidget>
#include <QStackedWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QSharedPointer>
#include <QGridLayout>
#include <QFileDialog>


//�����
class DesignZoneWidget : public QWidget
{

	Q_OBJECT

public:
	DesignZoneWidget();
	~DesignZoneWidget();
	Ui_DesignZone::DesignZoneWidget* uiDesignZone;

	//	//Ԫ����ϵͳ�Զ����ɵ��źţ������Ǳ���ͬ��
	//public slots:
	//	void on_importDesignGridBotton_clicked();//����д����
	//	void on_generateBotton_clicked();
	//��Ҫ���ԣ��������������������������������������������������������淶Ϊʲô�����ã�����������������

};

//��������
class MaterialSetWidget : public QWidget
{

	Q_OBJECT

public:
	MaterialSetWidget();
	~MaterialSetWidget();
	Ui_Material::MeterialSetWidget* uiMaterialSet;
};

//�߽���������
class BoundaryCasesWidget : public QWidget
{

	Q_OBJECT

public:
	BoundaryCasesWidget();
	~BoundaryCasesWidget();
	Ui_BoundaryCases::BoundaryCasesWidget* uiBoundaryCases;
};

//�غ�����
class LoadSetWidget : public QWidget
{

	Q_OBJECT

public:
	LoadSetWidget();
	~LoadSetWidget();
	Ui_LoadSet::LoadSetWidget* uiLoadSet;

};




//�Ż���������
class OptimizeParaWidget : public QWidget
{
	Q_OBJECT

public:
	OptimizeParaWidget();
	~OptimizeParaWidget();
	Ui_OptimizePara::OptimizeParaWidget* uiOptimizePara;
};

//����鿴
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
	QStackedWidget* oprStackWidget; //�Ҳ��������ջ����
	QTreeWidget* treeWidget; //�����״�ṹ����
	QString fileRoute;//�ⲿ�ļ�·���ӿڣ���Ҫѡ���·������ֱ�������QString���ַ���
private:
	DesignZoneWidget* designZoneWidget;
	MaterialSetWidget* materialSetWidget;
	OptimizeParaWidget* optimizeParaWidget;
	ResultCheckWidget* resultCheckWidget;
	BoundaryCasesWidget* boundaryCasesWidget;
	LoadSetWidget* loadSetWidget;


public slots:
	void stackedWidgetPageChange(QTreeWidgetItem* item, int column);
	void importDesignGridFile();
};



