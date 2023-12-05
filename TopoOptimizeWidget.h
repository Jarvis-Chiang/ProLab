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

//3D�����
class DesignZone_3D : public QWidget
{
public:
	DesignZone_3D();
	~DesignZone_3D();
	Ui_DesignZone_3D::DesignZoneWidget* uiDesignZone_3d;


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

//3D�߽���������
class BoundaryCases_3D : public QWidget
{
public:
	BoundaryCases_3D();
	~BoundaryCases_3D();
	Ui_BoundaryCases_3D::BoundaryCasesWidget_3D* uiBoundaryCases_3D;
	
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

//3D�غ�����
class LoadSet_3D : public QWidget
{
public:
	LoadSet_3D();
	~LoadSet_3D();
	Ui_LoadSet_3D::LoadSetWidget_3D* uiLoadSet_3D;
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

//3D�Ż���������
class OptimizePara_3D : public QWidget
{
public:
	OptimizePara_3D();
	~OptimizePara_3D();
	Ui_OptimizePara_3D::OptimizeParaWidget_3D* uiOptimizePara_3D;
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
	QStackedWidget* treeStackWidget;//�����״�ṹ��ջ����
	QString fileRoute;//�ⲿ�ļ�·���ӿڣ���Ҫѡ���·������ֱ�������QString���ַ���
private:
	QTreeWidget* treeWidget1; //�����״�ṹ����1
	QTreeWidget* treeWidget2; //�����״�ṹ����2
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



