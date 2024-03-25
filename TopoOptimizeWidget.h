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
#include "ui_VectorDieldDriven_PathPara.h"
#include "ui_VectorDieldDriven_SurfaceMesh.h"
#include "ui_VectorDieldDriven_VecField.h"
#include "ui_OffsetPath_SurfaceMesh.h"
#include "ui_OffsetPath_PathPara.h"
#include "ui_GradientFilling_SurfaceMesh.h"
#include "ui_GradientFilling_PathPara.h"
#include "ui_RefSurfBasedSlice_ModMesh.h"
#include "ui_RefSurfBasedSlice_PrinZone.h"
#include "ui_RefSurfBasedSlice_RefPlane.h"
#include "ui_RefSurfBasedSlice_SurfSlice.h"
#include "ui_RefSurfBasedSlice_PathPlan.h"
#include "ui_VecFieldBasedSlice_ModMesh.h"
#include "ui_VecFieldBasedSlice_PathPlan.h"
#include "ui_VecFieldBasedSlice_PrinZone.h"
#include "ui_VecFieldBasedSlice_SurfSlice.h"
#include "ui_VecFieldBasedSlice_VecField.h"

#include "Global.h"

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
#include <QTimer>
#include <QApplication>
#include <QGridLayout>

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
#include <osg/Light>
#include <osg/LightSource>
#include <osg/LineWidth>
#include <osg/PositionAttitudeTransform>

#include <osgManipulator/Selection>
#include <osgManipulator/TrackballDragger>

#include <osgViewer/CompositeViewer>
#include <osgViewer/ViewerEventHandlers>

#include <osgGA/MultiTouchTrackballManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/FirstPersonManipulator>

#include <osgDB/ReadFile>

#include <osgQt/GraphicsWindowQt>

#include <iostream>

#include "Global.h"

typedef Eigen::Vector2d Point2D;
typedef Eigen::Vector3d Point3D;
typedef std::vector<Eigen::Vector3d> CoorSet;
typedef Eigen::MatrixXd V;
typedef Eigen::MatrixXi C;

class HUDAxis :public osg::Camera
{
public:
	HUDAxis();
	HUDAxis(HUDAxis const& copy, osg::CopyOp copyOp = osg::CopyOp::SHALLOW_COPY);
	META_Node(osg, HUDAxis);
	inline void setMainCamera(Camera* camera) { _mainCamera = camera; }
	virtual void traverse(osg::NodeVisitor& nv);
protected:
	virtual ~HUDAxis();
	osg::observer_ptr<Camera> _mainCamera;
};

class OsgWidget : public QWidget, public osgViewer::CompositeViewer
{
public:
	OsgWidget(QWidget* parent = 0, Qt::WindowFlags f = 0, osgViewer::ViewerBase::ThreadingModel threadingModel = osgViewer::CompositeViewer::SingleThreaded);

	QWidget* addViewWidget(osgQt::GraphicsWindowQt* gw);

	osgQt::GraphicsWindowQt* createGraphicsWindow(int x, int y, int w, int h, const std::string& name = "", bool windowDecoration = false);

	virtual void paintEvent(QPaintEvent* event);

	osgViewer::Viewer* view;

protected:
	QTimer _timer;
};

/***********************************�ṹ�Ż���������************************************/

//�����
class DesignZoneWidget : public QWidget
{

	Q_OBJECT

public:
	DesignZoneWidget();
	~DesignZoneWidget();
	Ui::DesignZoneWidget* uiDesignZone;
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
	Ui::DesignZoneWidget_3D* uiDesignZone_3d;
};

//��������
class MaterialSetWidget : public QWidget
{

	Q_OBJECT

public:
	MaterialSetWidget();
	~MaterialSetWidget();
	Ui::MeterialSetWidget* uiMaterialSet;
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
	Ui::BoundaryCasesWidget* uiBoundaryCases;
};

//3D�߽���������
class BoundaryCases_3D : public QWidget
{
public:
	BoundaryCases_3D();
	~BoundaryCases_3D();
	Ui::BoundaryCasesWidget_3D* uiBoundaryCases_3D;
	
};


//�غ�����
class LoadSetWidget : public QWidget
{

	Q_OBJECT

public:
	LoadSetWidget();
	~LoadSetWidget();
	Ui::LoadSetWidget* uiLoadSet;

};

//3D�غ�����
class LoadSet_3D : public QWidget
{
public:
	LoadSet_3D();
	~LoadSet_3D();
	Ui::LoadSetWidget_3D* uiLoadSet_3D;
};



//�Ż���������
class OptimizeParaWidget : public QWidget
{
	Q_OBJECT

public:
	OptimizeParaWidget();
	~OptimizeParaWidget();
	Ui::OptimizeParaWidget* uiOptimizePara;
};

//3D�Ż���������
class OptimizePara_3D : public QWidget
{
public:
	OptimizePara_3D();
	~OptimizePara_3D();
	Ui::OptimizeParaWidget_3D* uiOptimizePara_3D;
};

//����鿴
class ResultCheckWidget : public QWidget
{

	Q_OBJECT

public:
	ResultCheckWidget();
	~ResultCheckWidget();
	Ui::ResultCheckWidget* uiRecultCheck;

};

/***************************************���չ滮��������***********************************/

//��������·��UI
	//·������UI
class VectorDieldDriven_PathPara : public QWidget
{
	Q_OBJECT
public:
	VectorDieldDriven_PathPara() : uiPathPara(new Ui::VectorDieldDriven_PathPara){uiPathPara->setupUi(this);};
	~VectorDieldDriven_PathPara(){delete uiPathPara;};
	Ui::VectorDieldDriven_PathPara* uiPathPara;
};

	//��������UI
class VectorDieldDriven_SurfaceMesh : public QWidget
{
	Q_OBJECT
public:
	VectorDieldDriven_SurfaceMesh() : uiSurfaceMesh(new Ui::VectorFieldDriven_SurfaceMesh) { uiSurfaceMesh->setupUi(this); };
	~VectorDieldDriven_SurfaceMesh() { delete uiSurfaceMesh; };
	Ui::VectorFieldDriven_SurfaceMesh* uiSurfaceMesh;
};

	//����UI
class VectorDieldDriven_VecField : public QWidget
{
	Q_OBJECT
public:
	VectorDieldDriven_VecField() : uiVecField(new Ui::VectorDieldDriven_VecField) { uiVecField->setupUi(this); };
	~VectorDieldDriven_VecField() { delete uiVecField; };
	Ui::VectorDieldDriven_VecField* uiVecField;
};

//ƫ��·��UI
	//��������UI
class OffsetPath_SurfaceMesh : public QWidget
{
	Q_OBJECT
public:
	OffsetPath_SurfaceMesh() : uiSurfaceMesh(new Ui::OffsetPath_SurfaceMesh) { uiSurfaceMesh->setupUi(this); };
	~OffsetPath_SurfaceMesh() { delete uiSurfaceMesh; };
	Ui::OffsetPath_SurfaceMesh* uiSurfaceMesh;
};

	//·������UI
class OffsetPath_PathPara : public QWidget
{
	Q_OBJECT
public:
	OffsetPath_PathPara() : uiPathPara(new Ui::OffsetPath_PathPara) { uiPathPara->setupUi(this); };
	~OffsetPath_PathPara() { delete uiPathPara; };
	Ui::OffsetPath_PathPara* uiPathPara;
};

//�ݶ����·��UI
	//��������UI
class GradientFilling_SurfaceMesh : public QWidget
{
	Q_OBJECT
public:
	GradientFilling_SurfaceMesh() : uiSurfaceMesh(new Ui::GradientFilling_SurfaceMesh) { uiSurfaceMesh->setupUi(this); };
	~GradientFilling_SurfaceMesh() { delete uiSurfaceMesh; };
	Ui::GradientFilling_SurfaceMesh* uiSurfaceMesh;
};

//·������UI
class GradientFilling_PathPara : public QWidget
{
	Q_OBJECT
public:
	GradientFilling_PathPara() : uiPathPara(new Ui::GradientFilling_PathPara) { uiPathPara->setupUi(this); };
	~GradientFilling_PathPara() { delete uiPathPara; };
	Ui::GradientFilling_PathPara* uiPathPara;
};

//��׼�淨������ƬUI
	//ģ������UI
class RefSurfBasedSlice_ModMesh : public QWidget
{
	Q_OBJECT
public:
	RefSurfBasedSlice_ModMesh() : uiModMesh(new Ui::RefSurfBasedSlice_ModMesh) { uiModMesh->setupUi(this); };
	~RefSurfBasedSlice_ModMesh() { delete uiModMesh; };
	Ui::RefSurfBasedSlice_ModMesh* uiModMesh;
};

  //��ӡ��UI
class RefSurfBasedSlice_PrinZone : public QWidget
{
	Q_OBJECT
public:
	RefSurfBasedSlice_PrinZone() : uiPrinZone(new Ui::RefSurfBasedSlice_PrinZone) { uiPrinZone->setupUi(this); };
	~RefSurfBasedSlice_PrinZone() { delete uiPrinZone; };
	Ui::RefSurfBasedSlice_PrinZone* uiPrinZone;
};

	//��׼��UI
class RefSurfBasedSlice_RefPlane : public QWidget
{
	Q_OBJECT
public:
	RefSurfBasedSlice_RefPlane() : uiRefPlane(new Ui::RefSurfBasedSlice_RefPlane) { uiRefPlane->setupUi(this); };
	~RefSurfBasedSlice_RefPlane() { delete uiRefPlane; };
	Ui::RefSurfBasedSlice_RefPlane* uiRefPlane;
};

//������ƬUI
class RefSurfBasedSlice_SurfSlice : public QWidget
{
	Q_OBJECT
public:
	RefSurfBasedSlice_SurfSlice() : uiSurfSlice(new Ui::RefSurfBasedSlice_SurfSlice) { uiSurfSlice->setupUi(this); };
	~RefSurfBasedSlice_SurfSlice() { delete uiSurfSlice; };
	Ui::RefSurfBasedSlice_SurfSlice* uiSurfSlice;
};

//·���滮UI
class RefSurfBasedSlice_PathPlan : public QWidget
{
	Q_OBJECT
public:
	RefSurfBasedSlice_PathPlan() : uiPathPlan(new Ui::RefSurfBasedSlice_PathPlan) { uiPathPlan->setupUi(this); };
	~RefSurfBasedSlice_PathPlan() { delete uiPathPlan; };
	Ui::RefSurfBasedSlice_PathPlan* uiPathPlan;
};

//���򳡷�������ƬUI
	//ģ������UI
class VecFieldBasedSlice_ModMesh : public QWidget
{
	Q_OBJECT
public:
	VecFieldBasedSlice_ModMesh() : uiModMesh(new Ui::VecFieldBasedSlice_ModMesh) { uiModMesh->setupUi(this); };
	~VecFieldBasedSlice_ModMesh() { delete uiModMesh; };
	Ui::VecFieldBasedSlice_ModMesh* uiModMesh;
};

//��ӡ��UI
class VecFieldBasedSlice_PrinZone : public QWidget
{
	Q_OBJECT
public:
	VecFieldBasedSlice_PrinZone() : uiPrinZone(new Ui::VecFieldBasedSlice_PrinZone) { uiPrinZone->setupUi(this); };
	~VecFieldBasedSlice_PrinZone() { delete uiPrinZone; };
	Ui::VecFieldBasedSlice_PrinZone* uiPrinZone;
};

//����UI
class VecFieldBasedSlice_VecField : public QWidget
{
	Q_OBJECT
public:
	VecFieldBasedSlice_VecField() : uiVecField(new Ui::VecFieldBasedSlice_VecField) { uiVecField->setupUi(this); };
	~VecFieldBasedSlice_VecField() { delete uiVecField; };
	Ui::VecFieldBasedSlice_VecField* uiVecField;
};

//������ƬUI
class VecFieldBasedSlice_SurfSlice : public QWidget
{
	Q_OBJECT
public:
	VecFieldBasedSlice_SurfSlice() : uiSurfSlice(new Ui::VecFieldBasedSlice_SurfSlice) { uiSurfSlice->setupUi(this); };
	~VecFieldBasedSlice_SurfSlice() { delete uiSurfSlice; };
	Ui::VecFieldBasedSlice_SurfSlice* uiSurfSlice;
};

//·���滮UI
class VecFieldBasedSlice_PathPlan : public QWidget
{
	Q_OBJECT
public:
	VecFieldBasedSlice_PathPlan() : uiPathPlan(new Ui::VecFieldBasedSlice_PathPlan) { uiPathPlan->setupUi(this); };
	~VecFieldBasedSlice_PathPlan() { delete uiPathPlan; };
	Ui::VecFieldBasedSlice_PathPlan* uiPathPlan;
};


class TopoOptimizeWidget : public QWidget
{

	Q_OBJECT

public:
    explicit TopoOptimizeWidget(QWidget* parent = 0);
    virtual ~TopoOptimizeWidget();

	void init();
	void creatAction();
	osg::ref_ptr<osg::Geode> makeCoordinate();
	void creatHUD();


	void CreatArrow(osg::ref_ptr<osg::Group> root_t, const osg::Vec3& startPoint, const osg::Vec3& direction);

public:
	QStackedWidget* oprStackWidget; //�Ҳ��������ջ����
	QStackedWidget* treeStackWidget;//�����״�ṹ��ջ����
	QString fileRoute;//�ⲿ�ļ�·���ӿڣ���Ҫѡ���·������ֱ�������QString���ַ���

	OsgWidget* osgWidget;

	osg::ref_ptr<osg::Node> createLightSource(unsigned int num, const osg::Vec3d& trans, const osg::Vec3d& vecDir);

private:
	QTreeWidget* treeWidget1; //�����״�ṹ����1
	QTreeWidget* treeWidget2; //�����״�ṹ����2
	QTreeWidget* treeWidget3; //�����״�ṹ����3
	QTreeWidget* treeWidget4; //�����״�ṹ����4
	QTreeWidget* treeWidget5; //�����״�ṹ����5
	QTreeWidget* treeWidget6; //�����״�ṹ����6
	QTreeWidget* treeWidget7; //�����״�ṹ����7

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
	VectorDieldDriven_PathPara* vectorFieldDriven_PathPara;
	VectorDieldDriven_SurfaceMesh* vectorDieldDriven_SurfaceMesh;
	VectorDieldDriven_VecField* vectorDieldDriven_VecField;
	OffsetPath_SurfaceMesh* offsetPath_SurfaceMesh;
	OffsetPath_PathPara* offsetPath_PathPara;
	GradientFilling_SurfaceMesh* gradientFilling_SurfaceMesh;
	GradientFilling_PathPara* gradientFilling_PathPara;
	RefSurfBasedSlice_ModMesh* refSurfBasedSlice_ModMesh;
	RefSurfBasedSlice_PathPlan* refSurfBasedSlice_PathPlan;
	RefSurfBasedSlice_PrinZone* refSurfBasedSlice_PrinZone;
	RefSurfBasedSlice_RefPlane* refSurfBasedSlice_RefPlane;
	RefSurfBasedSlice_SurfSlice* refSurfBasedSlice_SurfSlice;
	VecFieldBasedSlice_ModMesh* vecFieldBasedSlice_ModMesh;
	VecFieldBasedSlice_PathPlan* vecFieldBasedSlice_PathPlan;
	VecFieldBasedSlice_PrinZone* vecFieldBasedSlice_PrinZone;
	VecFieldBasedSlice_SurfSlice* vecFieldBasedSlice_SurfSlice;
	VecFieldBasedSlice_VecField* vecFieldBasedSlice_VecField;

	void aabbSplit3D(const Point3D& left, const Point3D& right, float resolution, V& vers, C& cells);
	void aabbSplit2D(const Point2D& left, const Point2D& right, float resolution, V& vers, C& cells);

	osg::Vec3 getnormal(osg::Vec3 v1, osg::Vec3 v2, osg::Vec3 v3, osg::Vec3 v4);//���ƽ�淨����
	void getShellVoxel(V v, C c, CoorSet& finalCoors);//�����������㷨
	static bool cmpAixsX(Point3D x, Point3D y);

	static bool cmpAixsY(Point3D x, Point3D y);

	static bool cmpAixsZ(Point3D x, Point3D y);

	void pickSurfaceCoors(CoorSet unPickedCoors, CoorSet& PickCoors);

public slots:
	void stackedWidgetPageChange(QTreeWidgetItem* item, int column);
	void importDesignGridFile();
private slots:
	void generate3dDesignZone();
	void generate2dDesignZone();

	//void addTangentPlane();
	//void addArrow0();
	void addArrow0();
	//void add2DArrow();
	//void delArrow();
	//void del2DArrow();
};


/*******************����Ϊ�����¼�����***********************/
class AddLinePointHandler : public osgGA::GUIEventHandler
{
public:
	AddLinePointHandler() { };
	~AddLinePointHandler() { };

	osg::ref_ptr<osg::PositionAttitudeTransform> picked;

	bool PickedObject = false;
	bool isModel = false;
	bool m_ctrlKeyPressed = false;//�������ctrl�Ƿ��µı���

	osg::Vec3f firstPoint;
	osg::Vec3f lastPoint;

	static bool cmp(const osg::Vec3f& v1, const osg::Vec3f& v2)
	{
		float distance_v1 = (v1 - position).length();
		float distance_v2 = (v2 - position).length();
		return distance_v1 < distance_v2;
	}

	osg::Vec3 getSurfPoint(float x, float y, osg::ref_ptr<osgViewer::Viewer> viewer)
	{
		//���model�ڵ��µ�ģ�ͱ����
		osgUtil::LineSegmentIntersector::Intersections intersections;
		std::vector<osg::Vec3> pointsToChoose;//��������model�ϵ����е�
		viewer->getCamera()->getViewMatrixAsLookAt(position, center_1, up);

		if (viewer->computeIntersections(x, y, intersections))//��ѡ������
		{
			for (osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin();
				hitr != intersections.end();
				++hitr)//���������нڵ�����н���
			{
				osg::NodePath getNodePath = hitr->nodePath;
				for (int i = getNodePath.size() - 1; i >= 0; --i)//�����ڵ�·��������model�ϵ� isModel = true ���� isModel = false��
				{
					if (getNodePath[i] == model)
					{
						isModel = true;
						break;
					}
				}
				if (isModel)
				{
					float x_Point = float(hitr->getWorldIntersectPoint().x());
					float y_Point = float(hitr->getWorldIntersectPoint().y());
					float z_Point = float(hitr->getWorldIntersectPoint().z());

					pointsToChoose.push_back(osg::Vec3(x_Point, y_Point, z_Point));

				}
				isModel = false;
			}
			if (pointsToChoose.empty())//������еĽ���ȫ����model�ϵ�
				return osg::Vec3(0, 0, 0);
			else
			{
				std::sort(pointsToChoose.begin(), pointsToChoose.end(), cmp);
				return pointsToChoose[0];
			}
		}
		else
			return osg::Vec3(0, 0, 0);
	}

	void pick(float x, float y, osg::ref_ptr<osgViewer::Viewer> view)
	{

		osgUtil::LineSegmentIntersector::Intersections intersections;

		if (view->computeIntersections(x, y, intersections))
		{
			osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin();
			osg::NodePath getNodePath = hitr->nodePath;
			for (int i = getNodePath.size() - 1; i >= 0; --i)
			{
				osg::PositionAttitudeTransform* mt = dynamic_cast<osg::PositionAttitudeTransform*>(getNodePath[i]);
				if (mt == NULL)
				{
					continue;
				}
				else
				{
					PickedObject = true;
					picked = mt;
					firstPoint = { float(hitr->getWorldIntersectPoint().x()), float(hitr->getWorldIntersectPoint().y()), float(hitr->getWorldIntersectPoint().z()) };
				}

			}
		}
		else
		{
			PickedObject = false;
		}

	}

	void addTraceBallTracker(float x, float y, osg::ref_ptr<osgViewer::Viewer> viewer)
	{
		osgManipulator::TrackballDragger* dragger = new osgManipulator::TrackballDragger;
		dragger->setupDefaultGeometry();

		osgUtil::LineSegmentIntersector::Intersections intersections;//���������ж���
		if (viewer->computeIntersections(x, y, intersections))//����ɹ�ѡ��������
		{
			osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin();
			osg::NodePath getNodePath = hitr->nodePath;
			for (int i = getNodePath.size() - 1; i >= 0; --i)
			{
				osgManipulator::Selection* slt = dynamic_cast<osgManipulator::Selection*>(getNodePath[i]);
				osg::PositionAttitudeTransform* mt = dynamic_cast<osg::PositionAttitudeTransform*>(getNodePath[i]);
				if (slt == NULL && mt == NULL)
					continue;
				else
				{
					if (mt != NULL)
						dragger->setMatrix(osg::Matrix::scale(0.5, 0.5, 0.5) * osg::Matrix::translate(mt->getBound().center()));
					if (slt != NULL)
						dragger->addTransformUpdating(slt);
				}
			}
		}
		dragger->setHandleEvents(true);
		arrow->addChild(dragger);
	}

	bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
	{
		//��ȡҪ��Ӧ��viewer
		osg::ref_ptr<osgViewer::Viewer> viewer = dynamic_cast<osgViewer::Viewer*>(&aa);

		if (viewer == NULL)
			return false;

		//�ж��¼�����
		switch (ea.getEventType())
		{
		case osgGA::GUIEventAdapter::DOUBLECLICK://˫�������Ӷ���
			if (ea.getButton() == 1)
			{
				//����һ���߶ν���������
				float x = ea.getX();
				float y = ea.getY();

				startPoint = getSurfPoint(x, y, viewer);
			}
			break;

		case osgGA::GUIEventAdapter::PUSH://�������ѡ���϶�����
			if (ea.getButton() == 1)
			{
				if (m_ctrlKeyPressed)
				{
					float x = ea.getX();
					float y = ea.getY();
					addTraceBallTracker(x, y, viewer);
				}
				else
				{
					float x = ea.getX();
					float y = ea.getY();
					pick(x, y, viewer);
				}
			}
			break;

		case osgGA::GUIEventAdapter::DRAG://�϶������ƶ�
			if (PickedObject)//���ѡ������������϶�
			{
				float x = ea.getX();
				float y = ea.getY();
				osg::Vec3 lastPoint = getSurfPoint(x, y, viewer);
				picked->setPosition(lastPoint);
				return true;//��ʾʹ���Զ����¼������������˴�������ʹ��Ĭ���¼����������д�����
			}
			else
				break;

		case osgGA::GUIEventAdapter::RELEASE:
			PickedObject = false;
			break;

		case osgGA::GUIEventAdapter::KEYDOWN:
			if ((osgGA::GUIEventAdapter::KEY_Control_L == ea.getKey())
				|| (osgGA::GUIEventAdapter::KEY_Control_R == ea.getKey())) // Ctrl��������
			{
				m_ctrlKeyPressed = true;
			}
		break;

		case osgGA::GUIEventAdapter::KEYUP:
			if ((osgGA::GUIEventAdapter::KEY_Control_L == ea.getKey())
				|| (osgGA::GUIEventAdapter::KEY_Control_R == ea.getKey())) // Ctrl�����ͷ�
			{
				m_ctrlKeyPressed = false;
			}
		break;

		default:
			break;
		}

		////�ж��¼����ͣ�new��
		//if (ea.getEventType() == osgGA::GUIEventAdapter::PUSH&&ea.getEventType() == osgGA::GUIEventAdapter::KEYDOWN )

		return false;
	}


	
};


 