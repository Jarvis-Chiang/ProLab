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
#include "ui_Finite2D_BoundaryCondition.h"
#include "ui_Finite2D_ComputePara.h"
#include "ui_Finite2D_ImportModelGrid.h"
#include "ui_Finite2D_LoadSet.h"
#include "ui_Finite2D_MaterialProperties.h"
#include "ui_Finite2D_ResultView.h"
#include "ui_Finite3D_BoundaryCondition.h"
#include "ui_Finite3D_ComputePara.h"
#include "ui_Finite3D_ImportModelGrid.h"
#include "ui_Finite3D_LoadSet.h"
#include "ui_Finite3D_MaterialProperties.h"
#include "ui_Finite3D_ResultView.h"

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
#include <QMessageBox>
#include <QTimer>
#include <QApplication>
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QFormLayout>

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
#include <osg/NodeVisitor>

#include <osgFX/Scribe>
#include <osgFX/Outline>

#include <osgManipulator/TrackballDragger>
#include <osgManipulator/Selection>

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


class ArrowShape : public osg::Group//保存箭头的基本数据结构（里边包含了拖拽器）!!!!!!!!!!!!!!!!!!!!!!!关联新方法
{
public:
	ArrowShape(osg::Vec3 direction, osg::Vec3 strtPnt);
	~ArrowShape(void);

	void UpdateDragger(osg::Quat attitude, osg::Vec3 position);
	void setData(osg::Vec3 position, osg::Quat rotation);

	void EnableHighLight();
	void DisableHighLight();
	void EnableDragger();
	void DisableDragger();

	double length;

	std::array <double, 6> vector_Data;

	bool isHighLighted = false;
private:
	osg::ref_ptr<osg::Node> mShape;
	osg::ref_ptr<osgManipulator::Dragger> mDragger;
	osg::ref_ptr<osg::PositionAttitudeTransform> mTrans;
	osg::ref_ptr<osgManipulator::Selection> mSelection;//拖拽器
	osg::ref_ptr<osgFX::Outline> ot;
	QTreeWidgetItem* treeLabel;
};

/**************************以下为访问器函数********************************/

class FindDelNodeVisitor : public osg::NodeVisitor
{
	//节点访问器函数本身并完全完成，最终想要达到的效果是：
	//根据节点名称和节点类型对根节点的不同子节点应用不同的apply()函数。
public:
	FindDelNodeVisitor() : osg::NodeVisitor(TRAVERSE_PARENTS), searchForeName() {};
	FindDelNodeVisitor(std::string& searchName) : osg::NodeVisitor(TRAVERSE_PARENTS), searchForeName(searchName) {};
	virtual void apply(osgManipulator::Selection& searchNode)
	{
		osg::Quat rotation;
		searchNode.getMatrix().get(rotation);
		rotation_Global *= rotation;//传递出姿态信息
		searchNode.setMatrix(osg::Matrix::identity());//注意：removeChild实际上移除的是子节点的地址！！！！！
		traverse(searchNode);
	}
	//virtual void apply(osgManipulator::TrackballDragger& searchTrackballDragger)
	//{
	//	arrow->removeChild(&searchTrackballDragger);//
	//	traverse(searchTrackballDragger);
	//}
private:
	std::string searchForeName;
};

/*******************以下为交互事件函数***********************/
class AddLinePointHandler : public QObject, public osgGA::GUIEventHandler
{
	Q_OBJECT

public:
	AddLinePointHandler() { };
	~AddLinePointHandler() { };

	osg::ref_ptr<osg::PositionAttitudeTransform> picked;
	osg::ref_ptr<osgManipulator::Selection> selection;
	ArrowShape* arrowShape;

	bool PickedObject = false;
	bool isModel = false;
	bool m_ctrlKeyPressed = false;//用来监测ctrl是否按下的变量

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
		//获得model节点下的模型表面点
		osgUtil::LineSegmentIntersector::Intersections intersections;
		std::vector<osg::Vec3> pointsToChoose;//用来保存model上的所有点
		viewer->getCamera()->getViewMatrixAsLookAt(position, center_1, up);

		if (viewer->computeIntersections(x, y, intersections))//有选中物体
		{
			for (osgUtil::LineSegmentIntersector::Intersections::iterator hitr = intersections.begin();
				hitr != intersections.end();
				++hitr)//遍历和所有节点的所有交点
			{
				osg::NodePath getNodePath = hitr->nodePath;
				for (int i = getNodePath.size() - 1; i >= 0; --i)//遍历节点路径，当是model上点 isModel = true 否则 isModel = false；
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
			if (pointsToChoose.empty())//如果所有的交点全不是model上的
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
					continue;
				else
				{
					PickedObject = true;
					picked = mt;
					osg::Node* grandParent = picked->getParent(0)->getParent(0);
					arrowShape = dynamic_cast<ArrowShape*> (grandParent);
					arrowShape->EnableHighLight();
					startPoint = mt->getPosition();
					emit HavePicked();
				}

			}
		}
		else
		{
			PickedObject = false;
		}

	}

	void removeTraceBallTracker()
	{
		FindDelNodeVisitor delVisitor;
		picked->accept(delVisitor);
		picked->setAttitude(rotation_Global);
		arrowShape->setData(picked->getPosition(), rotation_Global);
	}

	bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
	{
		//获取要响应的viewer
		osg::ref_ptr<osgViewer::Viewer> viewer = dynamic_cast<osgViewer::Viewer*>(&aa);

		if (viewer == NULL)
			return false;

		//判断事件类型
		switch (ea.getEventType())
		{
		case osgGA::GUIEventAdapter::DOUBLECLICK://双击鼠标添加顶点
			if (ea.getButton() == 1)
			{

				//创建一个线段交集检测对象
				float x = ea.getX();
				float y = ea.getY();
				pick(x, y, viewer);
				startPoint = getSurfPoint(x, y, viewer);
				emit SurfPicked(startPoint.x(), startPoint.y(), startPoint.z());
			}
			break;

		case osgGA::GUIEventAdapter::PUSH://单机鼠标选中拖动物体
			if (ea.getButton() == 1)
			{
				float x = ea.getX();
				float y = ea.getY();
				pick(x, y, viewer);
			}
			break;

		case osgGA::GUIEventAdapter::DRAG://拖动物体移动
			if (PickedObject)//如果选中物体进行了拖动
			{
				float x = ea.getX();
				float y = ea.getY();
				osg::Vec3 lastPoint = getSurfPoint(x, y, viewer);
				picked->setPosition(lastPoint);
				arrowShape->UpdateDragger(picked->getAttitude(), lastPoint);
				arrowShape->setData(lastPoint, picked->getAttitude());
				emit DragEnd(lastPoint.x(), lastPoint.y(), lastPoint.z());
				return true;//表示使用自定的事件处理器进行了处理，无需使用默认事件处理器进行处理了
			}
			else
				break;

		case osgGA::GUIEventAdapter::RELEASE:
			PickedObject = false;
			
			break;

		case osgGA::GUIEventAdapter::KEYDOWN:
			if ((osgGA::GUIEventAdapter::KEY_Control_L == ea.getKey())
				|| (osgGA::GUIEventAdapter::KEY_Control_R == ea.getKey())) // Ctrl键被按下
			{
				if (arrowShape != NULL)
				{
					rotation_Global = picked->getAttitude();
					arrowShape->EnableDragger();
				}
				m_ctrlKeyPressed = true;
			}
			break;

		case osgGA::GUIEventAdapter::KEYUP:
			if ((osgGA::GUIEventAdapter::KEY_Control_L == ea.getKey())
				|| (osgGA::GUIEventAdapter::KEY_Control_R == ea.getKey())) // Ctrl键被释放
			{
				if (arrowShape != NULL)
				{
					removeTraceBallTracker();
					arrowShape->DisableDragger();
				}
				m_ctrlKeyPressed = false;
			}
			break;

		default:
			break;
		}

		return false;
	}

signals:
	void HavePicked();
	void DragEnd(double x, double y, double z);
	void SurfPicked(double x, double y, double z);
};

class OsgWidget : public QWidget, public osgViewer::CompositeViewer
{
public:
	OsgWidget(QWidget* parent = 0, Qt::WindowFlags f = 0, osgViewer::ViewerBase::ThreadingModel threadingModel = osgViewer::CompositeViewer::SingleThreaded);

	QWidget* addViewWidget(osgQt::GraphicsWindowQt* gw);

	osgQt::GraphicsWindowQt* createGraphicsWindow(int x, int y, int w, int h, const std::string& name = "", bool windowDecoration = false);

	virtual void paintEvent(QPaintEvent* event);

	osgViewer::Viewer* view;

	void getBestView()
	{
		//获得最佳的场景角度
		view->getCameraManipulator()->computeHomePosition();
		view->getCameraManipulator()->home(0.0);
	}

	AddLinePointHandler* addLinePointHandler;

protected:
	QTimer _timer;
};

/***********************************结构优化操作窗口************************************/

//设计域
class DesignZoneWidget : public QWidget
{

	Q_OBJECT

public:
	DesignZoneWidget();
	~DesignZoneWidget();
	Ui::DesignZoneWidget* uiDesignZone;
	//	//元对象系统自动生成的信号：条件是保持同名
	//public slots:
	//	void on_importDesignGridBotton_clicked();//必须写定义
	//	void on_generateBotton_clicked();
	//需要测试！！！！！！！！！！！！！！！！！！！！！！！！！！命名规范为什么不管用？？？？？？？？？

};

//3D设计域
class DesignZone_3D : public QWidget
{
	Q_OBJECT
public:
	DesignZone_3D();
	~DesignZone_3D();
	Ui::DesignZoneWidget_3D* uiDesignZone_3d;
};

//材料设置
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

//边界条件设置
class BoundaryCasesWidget : public QWidget
{

	Q_OBJECT

public:
	BoundaryCasesWidget();
	~BoundaryCasesWidget();
	Ui::BoundaryCasesWidget* uiBoundaryCases;
};

//3D边界条件设置
class BoundaryCases_3D : public QWidget
{
public:
	BoundaryCases_3D();
	~BoundaryCases_3D();
	Ui::BoundaryCasesWidget_3D* uiBoundaryCases_3D;
	
};


//载荷设置
class LoadSetWidget : public QWidget
{

	Q_OBJECT

public:
	LoadSetWidget();
	~LoadSetWidget();
	Ui::LoadSetWidget* uiLoadSet;

};

//3D载荷设置
class LoadSet_3D : public QWidget
{
public:
	LoadSet_3D();
	~LoadSet_3D();
	Ui::LoadSetWidget_3D* uiLoadSet_3D;
};



//优化参数设置
class OptimizeParaWidget : public QWidget
{
	Q_OBJECT

public:
	OptimizeParaWidget();
	~OptimizeParaWidget();
	Ui::OptimizeParaWidget* uiOptimizePara;
};

//3D优化参数设置
class OptimizePara_3D : public QWidget
{
public:
	OptimizePara_3D();
	~OptimizePara_3D();
	Ui::OptimizeParaWidget_3D* uiOptimizePara_3D;
};

//结果查看
class ResultCheckWidget : public QWidget
{

	Q_OBJECT

public:
	ResultCheckWidget();
	~ResultCheckWidget();
	Ui::ResultCheckWidget* uiRecultCheck;

};

//2D有限元分析模块
	//模型网格UI
class Finite2D_ImportModelGrid : public QWidget
{
	Q_OBJECT
public:
	Finite2D_ImportModelGrid() : uiImportModelGrid(new Ui::Finite2D_ImportModelGrid) { uiImportModelGrid->setupUi(this); };
	~Finite2D_ImportModelGrid() { delete uiImportModelGrid; };
	Ui::Finite2D_ImportModelGrid* uiImportModelGrid;
};

	//材料属性UI
class Finite2D_MaterialProperties : public QWidget
{
	Q_OBJECT
public:
	Finite2D_MaterialProperties() : uiMaterialProperties(new Ui::Finite2D_MaterialProperties) { uiMaterialProperties->setupUi(this); };
	~Finite2D_MaterialProperties() { delete uiMaterialProperties; };
	Ui::Finite2D_MaterialProperties* uiMaterialProperties;
};

	//边界条件UI
class Finite2D_BoundaryCondition : public QWidget
{
	Q_OBJECT
public:
	Finite2D_BoundaryCondition() : uiBoundaryCondition(new Ui::Finite2D_BoundaryCondition) { uiBoundaryCondition->setupUi(this); };
	~Finite2D_BoundaryCondition() { delete uiBoundaryCondition; };
	Ui::Finite2D_BoundaryCondition* uiBoundaryCondition;
};

	//载荷设置UI
class Finite2D_LoadSet : public QWidget
{
	Q_OBJECT
public:
	Finite2D_LoadSet() : uiLoadSet(new Ui::Finite2D_LoadSet) { uiLoadSet->setupUi(this); };
	~Finite2D_LoadSet() { delete uiLoadSet; };
	Ui::Finite2D_LoadSet* uiLoadSet;
};

	//计算参数UI
class Finite2D_ComputePara : public QWidget
{
	Q_OBJECT
public:
	Finite2D_ComputePara() : uiComputePara(new Ui::Finite2D_ComputePara) { uiComputePara->setupUi(this); };
	~Finite2D_ComputePara() { delete uiComputePara; };
	Ui::Finite2D_ComputePara* uiComputePara;
};

	//结果查看UI
class Finite2D_ResultView : public QWidget
{
	Q_OBJECT
public:
	Finite2D_ResultView() : uiResultView(new Ui::Finite2D_ResultView) { uiResultView->setupUi(this); };
	~Finite2D_ResultView() { delete uiResultView; };
	Ui::Finite2D_ResultView* uiResultView;
};

//3D有限元分析模块
class Finite3D_ImportModelGrid : public QWidget
{
	Q_OBJECT
public:
	Finite3D_ImportModelGrid() : uiImportModelGrid(new Ui::Finite3D_ImportModelGrid) { uiImportModelGrid->setupUi(this); };
	~Finite3D_ImportModelGrid() { delete uiImportModelGrid; };
	Ui::Finite3D_ImportModelGrid* uiImportModelGrid;
};

	//材料属性UI
class Finite3D_MaterialProperties : public QWidget
{
	Q_OBJECT
public:
	Finite3D_MaterialProperties() : uiMaterialProperties(new Ui::Finite3D_MaterialProperties) { uiMaterialProperties->setupUi(this); };
	~Finite3D_MaterialProperties() { delete uiMaterialProperties; };
	Ui::Finite3D_MaterialProperties* uiMaterialProperties;
};

	//边界条件UI
class Finite3D_BoundaryCondition : public QWidget
{
	Q_OBJECT
public:
	Finite3D_BoundaryCondition() : uiBoundaryCondition(new Ui::Finite3D_BoundaryCondition) { uiBoundaryCondition->setupUi(this); };
	~Finite3D_BoundaryCondition() { delete uiBoundaryCondition; };
	Ui::Finite3D_BoundaryCondition* uiBoundaryCondition;
};

	//载荷设置UI
class Finite3D_LoadSet : public QWidget
{
	Q_OBJECT
public:
	Finite3D_LoadSet() : uiLoadSet(new Ui::Finite3D_LoadSet) { uiLoadSet->setupUi(this); };
	~Finite3D_LoadSet() { delete uiLoadSet; };
	Ui::Finite3D_LoadSet* uiLoadSet;
};

	//计算参数UI
class Finite3D_ComputePara : public QWidget
{
	Q_OBJECT
public:
	Finite3D_ComputePara() : uiComputePara(new Ui::Finite3D_ComputePara) { uiComputePara->setupUi(this); };
	~Finite3D_ComputePara() { delete uiComputePara; };
	Ui::Finite3D_ComputePara* uiComputePara;
};

	//结果查看UI
class Finite3D_ResultView : public QWidget
{
	Q_OBJECT
public:
	Finite3D_ResultView() : uiResultView(new Ui::Finite3D_ResultView) { uiResultView->setupUi(this); };
	~Finite3D_ResultView() { delete uiResultView; };
	Ui::Finite3D_ResultView* uiResultView;
};

/***************************************工艺规划操作窗口***********************************/

//方向场驱动路径UI
	//路径参数UI
class VectorDieldDriven_PathPara : public QWidget
{
	Q_OBJECT
public:
	VectorDieldDriven_PathPara() : uiPathPara(new Ui::VectorDieldDriven_PathPara){uiPathPara->setupUi(this);};
	~VectorDieldDriven_PathPara(){delete uiPathPara;};
	Ui::VectorDieldDriven_PathPara* uiPathPara;
};

	//曲面网格UI
class VectorDieldDriven_SurfaceMesh : public QWidget
{
	Q_OBJECT
public:
	VectorDieldDriven_SurfaceMesh() : uiSurfaceMesh(new Ui::VectorFieldDriven_SurfaceMesh) { uiSurfaceMesh->setupUi(this); };
	~VectorDieldDriven_SurfaceMesh() { delete uiSurfaceMesh; };
	Ui::VectorFieldDriven_SurfaceMesh* uiSurfaceMesh;
};

	//方向场UI
class VectorDieldDriven_VecField : public QWidget
{
	Q_OBJECT
public:
	VectorDieldDriven_VecField() : uiVecField(new Ui::VectorDieldDriven_VecField) {
		uiVecField->setupUi(this); 
		QButtonGroup* buttonBox = new QButtonGroup;
		buttonBox->setExclusive(true);
		buttonBox->addButton(uiVecField->radioButton);
		buttonBox->addButton(uiVecField->radioButton_2);
	};
	~VectorDieldDriven_VecField() { delete uiVecField; };
	Ui::VectorDieldDriven_VecField* uiVecField;
};

//偏移路径UI
	//曲面网格UI
class OffsetPath_SurfaceMesh : public QWidget
{
	Q_OBJECT
public:
	OffsetPath_SurfaceMesh() : uiSurfaceMesh(new Ui::OffsetPath_SurfaceMesh) { uiSurfaceMesh->setupUi(this); };
	~OffsetPath_SurfaceMesh() { delete uiSurfaceMesh; };
	Ui::OffsetPath_SurfaceMesh* uiSurfaceMesh;
};

	//路径参数UI
class OffsetPath_PathPara : public QWidget
{
	Q_OBJECT
public:
	OffsetPath_PathPara() : uiPathPara(new Ui::OffsetPath_PathPara) { uiPathPara->setupUi(this); };
	~OffsetPath_PathPara() { delete uiPathPara; };
	Ui::OffsetPath_PathPara* uiPathPara;
};

//梯度填充路径UI
	//曲面网格UI
class GradientFilling_SurfaceMesh : public QWidget
{
	Q_OBJECT
public:
	GradientFilling_SurfaceMesh() : uiSurfaceMesh(new Ui::GradientFilling_SurfaceMesh) { uiSurfaceMesh->setupUi(this); };
	~GradientFilling_SurfaceMesh() { delete uiSurfaceMesh; };
	Ui::GradientFilling_SurfaceMesh* uiSurfaceMesh;
};

//路径参数UI
class GradientFilling_PathPara : public QWidget
{
	Q_OBJECT
public:
	GradientFilling_PathPara() : uiPathPara(new Ui::GradientFilling_PathPara) { uiPathPara->setupUi(this); };
	~GradientFilling_PathPara() { delete uiPathPara; };
	Ui::GradientFilling_PathPara* uiPathPara;
};

//基准面法曲面切片UI
	//模型网格UI
class RefSurfBasedSlice_ModMesh : public QWidget
{
	Q_OBJECT
public:
	RefSurfBasedSlice_ModMesh() : uiModMesh(new Ui::RefSurfBasedSlice_ModMesh) { uiModMesh->setupUi(this); };
	~RefSurfBasedSlice_ModMesh() { delete uiModMesh; };
	Ui::RefSurfBasedSlice_ModMesh* uiModMesh;
};

  //打印域UI
class RefSurfBasedSlice_PrinZone : public QWidget
{
	Q_OBJECT
public:
	RefSurfBasedSlice_PrinZone() : uiPrinZone(new Ui::RefSurfBasedSlice_PrinZone) { uiPrinZone->setupUi(this); };
	~RefSurfBasedSlice_PrinZone() { delete uiPrinZone; };
	Ui::RefSurfBasedSlice_PrinZone* uiPrinZone;
};

	//基准面UI
class RefSurfBasedSlice_RefPlane : public QWidget
{
	Q_OBJECT
public:
	RefSurfBasedSlice_RefPlane() : uiRefPlane(new Ui::RefSurfBasedSlice_RefPlane) { uiRefPlane->setupUi(this); };
	~RefSurfBasedSlice_RefPlane() { delete uiRefPlane; };
	Ui::RefSurfBasedSlice_RefPlane* uiRefPlane;
};

//曲面切片UI
class RefSurfBasedSlice_SurfSlice : public QWidget
{
	Q_OBJECT
public:
	RefSurfBasedSlice_SurfSlice() : uiSurfSlice(new Ui::RefSurfBasedSlice_SurfSlice) { uiSurfSlice->setupUi(this); };
	~RefSurfBasedSlice_SurfSlice() { delete uiSurfSlice; };
	Ui::RefSurfBasedSlice_SurfSlice* uiSurfSlice;
};

//路径规划UI
class RefSurfBasedSlice_PathPlan : public QWidget
{
	Q_OBJECT
public:
	RefSurfBasedSlice_PathPlan() : uiPathPlan(new Ui::RefSurfBasedSlice_PathPlan) { uiPathPlan->setupUi(this); };
	~RefSurfBasedSlice_PathPlan() { delete uiPathPlan; };
	Ui::RefSurfBasedSlice_PathPlan* uiPathPlan;
};

//方向场法曲面切片UI
	//模型网格UI
class VecFieldBasedSlice_ModMesh : public QWidget
{
	Q_OBJECT
public:
	VecFieldBasedSlice_ModMesh() : uiModMesh(new Ui::VecFieldBasedSlice_ModMesh) { uiModMesh->setupUi(this); };
	~VecFieldBasedSlice_ModMesh() { delete uiModMesh; };
	Ui::VecFieldBasedSlice_ModMesh* uiModMesh;
};

//打印域UI
class VecFieldBasedSlice_PrinZone : public QWidget
{
	Q_OBJECT
public:
	VecFieldBasedSlice_PrinZone() : uiPrinZone(new Ui::VecFieldBasedSlice_PrinZone) { uiPrinZone->setupUi(this); };
	~VecFieldBasedSlice_PrinZone() { delete uiPrinZone; };
	Ui::VecFieldBasedSlice_PrinZone* uiPrinZone;
};

//方向场UI
class VecFieldBasedSlice_VecField : public QWidget
{
	Q_OBJECT
public:
	VecFieldBasedSlice_VecField() : uiVecField(new Ui::VecFieldBasedSlice_VecField) { uiVecField->setupUi(this); };
	~VecFieldBasedSlice_VecField() { delete uiVecField; };
	Ui::VecFieldBasedSlice_VecField* uiVecField;
};

//曲面切片UI
class VecFieldBasedSlice_SurfSlice : public QWidget
{
	Q_OBJECT
public:
	VecFieldBasedSlice_SurfSlice() : uiSurfSlice(new Ui::VecFieldBasedSlice_SurfSlice) { uiSurfSlice->setupUi(this); };
	~VecFieldBasedSlice_SurfSlice() { delete uiSurfSlice; };
	Ui::VecFieldBasedSlice_SurfSlice* uiSurfSlice;
};

//路径规划UI
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
	friend class AddLinePointHandler;

    explicit TopoOptimizeWidget(QWidget* parent = 0);
    virtual ~TopoOptimizeWidget();

	void init();
	void creatAction();
	osg::ref_ptr<osg::Geode> makeCoordinate();
	void creatHUD();


	void CreatArrow(osg::ref_ptr<osg::Group> root_t, const osg::Vec3& startPoint, const osg::Vec3& direction);

public:
	QStackedWidget* oprStackWidget; //右侧操作栏堆栈窗口
	QStackedWidget* treeStackWidget;//左侧树状结构堆栈窗口
	QString fileRoute;//外部文件路径接口，需要选择的路径可以直接用这个QString类字符串

	OsgWidget* osgWidget;

	QPlainTextEdit* LogText = new QPlainTextEdit;

	osg::ref_ptr<osg::Node> createLightSource(unsigned int num, const osg::Vec3d& trans, const osg::Vec3d& vecDir);

private:
	QTreeWidget* treeWidget1; //左侧树状结构窗口1
	QTreeWidget* treeWidget2; //左侧树状结构窗口2
	QTreeWidget* treeWidget3; //左侧树状结构窗口3
	QTreeWidget* treeWidget4; //左侧树状结构窗口4
	QTreeWidget* treeWidget5; //左侧树状结构窗口5
	QTreeWidget* treeWidget6; //左侧树状结构窗口6
	QTreeWidget* treeWidget7; //左侧树状结构窗口7
	QTreeWidget* treeWidget8; //左侧树状结构窗口8
	QTreeWidget* treeWidget9; //左侧树状结构窗口9

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
	Finite2D_BoundaryCondition* finite2D_BoundaryCondition;
	Finite2D_ComputePara* finite2D_ComputePara;
	Finite2D_ImportModelGrid* finite2D_ImportModelGrid;
	Finite2D_LoadSet* finite2D_LoadSet;
	Finite2D_MaterialProperties* finite2D_MaterialProperties;
	Finite2D_ResultView* finite2D_ResultView;
	Finite3D_BoundaryCondition* finite3D_BoundaryCondition;
	Finite3D_ComputePara* finite3D_ComputePara;
	Finite3D_ImportModelGrid* finite3D_ImportModelGrid;
	Finite3D_LoadSet* finite3D_LoadSet;
	Finite3D_MaterialProperties* finite3D_MaterialProperties;
	Finite3D_ResultView* finite3D_ResultView;



	void aabbSplit3D(const Point3D& left, const Point3D& right, float resolution, V& vers, C& cells);
	void aabbSplit2D(const Point2D& left, const Point2D& right, float resolution, V& vers, C& cells);

	osg::Vec3 getnormal(osg::Vec3 v1, osg::Vec3 v2, osg::Vec3 v3, osg::Vec3 v4);//获得平面法向量
	void getShellVoxel(V v, C c, CoorSet& finalCoors);//体素网格抽壳算法
	static bool cmpAixsX(Point3D x, Point3D y);

	static bool cmpAixsY(Point3D x, Point3D y);

	static bool cmpAixsZ(Point3D x, Point3D y);

	void pickSurfaceCoors(CoorSet unPickedCoors, CoorSet& PickCoors);

public slots:
	void stackedWidgetPageChange(QTreeWidgetItem* item, int column);
	void importDesignGridFile();

	void VectorDieldDriven_SurfaceMesh_on_ImportTriMesh_push();
	void VectorDieldDriven_VectorField_on_ImportVectorField_push();
	void VectorDieldDriven_VectorField_on_AddCtrlPnt_push();
	void VectorDieldDriven_VectorField_on_ExprtVecField_push();
	void VectorDieldDriven_VectorField_on_ClearMesh_push();
	void VectorDieldDriven_VectorField_on_ClearVec_push();
	void on_HavePicked();
	void on_DragEnd(double x, double y, double z);
	void on_SurfPicked(double x, double y, double z);
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






 