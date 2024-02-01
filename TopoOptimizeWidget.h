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
#include "OsgWidget.h"

#include <set>
#include <vector>
#include <algorithm>

#include <QWidget>
#include <QStackedWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QSharedPointer>
#include <QGridLayout>
#include <QFileDialog>
#include <QButtonGroup>
#include <Eigen/Dense>
#include <QMessageBox>

#include <osg/Geometry>
#include <osg/Geode>
#include <osgUtil/SmoothingVisitor>
#include <osgViewer/Viewer>
#include <osg/Group>
#include <osg/MatrixTransform>
#include <osg/Light>
#include <osg/LightSource>
#include <osg/StateSet>
#include <osg/CullFace>
#include <osg/StateAttribute>
#include <osg/ShapeDrawable>
//#include <osg/PolygonOffset>
//#include <osgUtil/Optimizer>
//#include <osg/PolygonMode>
//#include <osg/Material>
//#include <osg/Array>



typedef Eigen::Vector2d Point2D;
typedef Eigen::Vector3d Point3D;
typedef std::vector<Eigen::Vector3d> CoorSet;
typedef Eigen::MatrixXd V;
typedef Eigen::MatrixXi C;

//�����
class DesignZoneWidget : public QWidget
{

	Q_OBJECT

public:
	DesignZoneWidget();
	~DesignZoneWidget();
	Ui_DesignZone::DesignZoneWidget* uiDesignZone;
private:
	void aabbSplit2D(const Point2D& left, const Point2D& right, double resolution, V& vers, C& cells);

	//	//Ԫ����ϵͳ�Զ����ɵ��źţ������Ǳ���ͬ��
	//public slots:
	//	void on_importDesignGridBotton_clicked();//����д����
	//	void on_generateBotton_clicked();
	//��Ҫ���ԣ��������������������������������������������������������淶Ϊʲô�����ã�����������������

};

//3D�����
class DesignZone_3D : public QWidget
{
	Q_OBJECT
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
private:
	QButtonGroup* radioButtons;

private slots:
	void sameButton(int state);
	void diffButton(int state);
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

	OsgWidget* osgWidget;

	osg::ref_ptr<osg::Node> createLightSource(unsigned int num, const osg::Vec3d& trans, const osg::Vec3d& vecDir);

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

	void aabbSplit3D(const Point3D& left, const Point3D& right, float resolution, V& vers, C& cells);

	osg::ref_ptr<osg::Group> group = new osg::Group;//���ص�Ԫ��ڵ�
	osg::Vec3 getnormal(osg::Vec3 v1, osg::Vec3 v2, osg::Vec3 v3, osg::Vec3 v4);//���ƽ�淨����
	void getShellVoxel(V v, C c, CoorSet& finalCoors);
	//�����������㷨
	static bool cmpAixsX(Point3D x, Point3D y);

	static bool cmpAixsY(Point3D x, Point3D y);

	static bool cmpAixsZ(Point3D x, Point3D y);

	void pickSurfaceCoors(CoorSet unPickedCoors, CoorSet& PickCoors);

	
	//osg::ref_ptr<osg::Group> decorator = new osg::Group;//������������ڵ�
	//osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
	//osg::ref_ptr<osg::PolygonOffset> polyoffset = new osg::PolygonOffset;//�ʵ��趨ƫ�� 
	//osg::ref_ptr<osg::PolygonMode> polymode = new osg::PolygonMode;

	//osgUtil::Optimizer optimzer;//�Ż���


public slots:
	void stackedWidgetPageChange(QTreeWidgetItem* item, int column);
	void importDesignGridFile();
private slots:
	void generate3dDesignZone();
	void addTangentPlane();
	void addArrow0();
	void addArrow();
	void add2DArrow();
	void delArrow();
	void del2DArrow();
};



