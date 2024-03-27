#include "TopoOptimizeWidget.h"
#pragma execution_character_set("utf-8")

TopoOptimizeWidget::TopoOptimizeWidget(QWidget* parent) :
	oprStackWidget(new  QStackedWidget(this)),
	designZoneWidget(new DesignZoneWidget),
	materialSetWidget(new MaterialSetWidget),
	optimizeParaWidget(new OptimizeParaWidget),
	resultCheckWidget(new ResultCheckWidget),
	boundaryCasesWidget(new BoundaryCasesWidget),
	loadSetWidget(new LoadSetWidget),
	treeWidget1(new QTreeWidget(this)),
	treeWidget2(new QTreeWidget(this)),
	treeWidget3(new QTreeWidget(this)),
	treeWidget4(new QTreeWidget(this)),
	treeWidget5(new QTreeWidget(this)),
	treeWidget6(new QTreeWidget(this)),
	treeWidget7(new QTreeWidget(this)),
	treeWidget8(new QTreeWidget(this)),
	treeWidget9(new QTreeWidget(this)),
	designZone_3D(new DesignZone_3D),
	treeStackWidget(new QStackedWidget),
	boundaryCases_3D(new BoundaryCases_3D),
	loadSet_3D(new LoadSet_3D),
	optimizePara_3D(new OptimizePara_3D),
	vectorFieldDriven_PathPara(new VectorDieldDriven_PathPara),
	vectorDieldDriven_SurfaceMesh(new VectorDieldDriven_SurfaceMesh),
	vectorDieldDriven_VecField(new VectorDieldDriven_VecField),
	offsetPath_SurfaceMesh(new OffsetPath_SurfaceMesh),
	offsetPath_PathPara(new OffsetPath_PathPara),
	gradientFilling_SurfaceMesh(new GradientFilling_SurfaceMesh),
	gradientFilling_PathPara(new GradientFilling_PathPara),
	refSurfBasedSlice_ModMesh(new RefSurfBasedSlice_ModMesh),
	refSurfBasedSlice_PathPlan(new RefSurfBasedSlice_PathPlan),
	refSurfBasedSlice_PrinZone(new RefSurfBasedSlice_PrinZone),
	refSurfBasedSlice_RefPlane(new RefSurfBasedSlice_RefPlane),
	refSurfBasedSlice_SurfSlice(new RefSurfBasedSlice_SurfSlice),
	vecFieldBasedSlice_ModMesh(new VecFieldBasedSlice_ModMesh),
	vecFieldBasedSlice_PathPlan(new VecFieldBasedSlice_PathPlan),
	vecFieldBasedSlice_PrinZone(new VecFieldBasedSlice_PrinZone),
	vecFieldBasedSlice_SurfSlice(new VecFieldBasedSlice_SurfSlice),
	vecFieldBasedSlice_VecField(new VecFieldBasedSlice_VecField),
	finite2D_BoundaryCondition(new Finite2D_BoundaryCondition),
	finite2D_ComputePara(new Finite2D_ComputePara),
	finite2D_ImportModelGrid(new Finite2D_ImportModelGrid),
	finite2D_LoadSet(new Finite2D_LoadSet),
	finite2D_MaterialProperties(new Finite2D_MaterialProperties),
	finite2D_ResultView(new Finite2D_ResultView),
	finite3D_BoundaryCondition(new Finite3D_BoundaryCondition),
	finite3D_ComputePara(new Finite3D_ComputePara),
	finite3D_ImportModelGrid(new Finite3D_ImportModelGrid),
	finite3D_LoadSet(new Finite3D_LoadSet),
	finite3D_MaterialProperties(new Finite3D_MaterialProperties),
	finite3D_ResultView(new Finite3D_ResultView),
	osgWidget(new OsgWidget(0, Qt::Widget, osgViewer::ViewerBase::SingleThreaded))
{
	creatHUD();
	init();
	creatAction();
}

TopoOptimizeWidget :: ~TopoOptimizeWidget()
{

}

void TopoOptimizeWidget :: init()
{
	//右侧操作栏堆栈窗口
	/********************************结构优化右侧操作************************************/
	oprStackWidget->addWidget(designZoneWidget);//QStackedWidget类适addWidget函数适只适用于标准指针，Qt智能指针不行//0
	oprStackWidget->addWidget(materialSetWidget);//1
	oprStackWidget->addWidget(boundaryCasesWidget);//2
	oprStackWidget->addWidget(loadSetWidget);//3
	oprStackWidget->addWidget(optimizeParaWidget);//4
	oprStackWidget->addWidget(resultCheckWidget);//5
	oprStackWidget->addWidget(designZone_3D);//6
	oprStackWidget->addWidget(boundaryCases_3D);//7
	oprStackWidget->addWidget(loadSet_3D);//8
	oprStackWidget->addWidget(optimizePara_3D);//9

	oprStackWidget->addWidget(vectorFieldDriven_PathPara);//10
	oprStackWidget->addWidget(vectorDieldDriven_SurfaceMesh);//11
	oprStackWidget->addWidget(vectorDieldDriven_VecField);//12

	oprStackWidget->addWidget(offsetPath_SurfaceMesh);//13
	oprStackWidget->addWidget(offsetPath_PathPara);//14

	oprStackWidget->addWidget(gradientFilling_SurfaceMesh);//15
	oprStackWidget->addWidget(gradientFilling_PathPara);//16

	oprStackWidget->addWidget(refSurfBasedSlice_ModMesh);//17
	oprStackWidget->addWidget(refSurfBasedSlice_PrinZone);//18
	oprStackWidget->addWidget(refSurfBasedSlice_RefPlane);//19
	oprStackWidget->addWidget(refSurfBasedSlice_SurfSlice);//20
	oprStackWidget->addWidget(refSurfBasedSlice_PathPlan);//21

	oprStackWidget->addWidget(vecFieldBasedSlice_ModMesh);//22
	oprStackWidget->addWidget(vecFieldBasedSlice_PrinZone);//23
	oprStackWidget->addWidget(vecFieldBasedSlice_VecField);//24
	oprStackWidget->addWidget(vecFieldBasedSlice_SurfSlice);//25
	oprStackWidget->addWidget(vecFieldBasedSlice_PathPlan);//26

	oprStackWidget->addWidget(finite2D_ImportModelGrid);//27
	oprStackWidget->addWidget(finite2D_MaterialProperties);//28
	oprStackWidget->addWidget(finite2D_BoundaryCondition);//29
	oprStackWidget->addWidget(finite2D_LoadSet);//30
	oprStackWidget->addWidget(finite2D_ComputePara);//31
	oprStackWidget->addWidget(finite2D_ResultView);//32

	oprStackWidget->addWidget(finite3D_ImportModelGrid);//33
	oprStackWidget->addWidget(finite3D_MaterialProperties);//34
	oprStackWidget->addWidget(finite3D_BoundaryCondition);//35
	oprStackWidget->addWidget(finite3D_LoadSet);//36
	oprStackWidget->addWidget(finite3D_ComputePara);//37
	oprStackWidget->addWidget(finite3D_ResultView);//38

	//左侧树状结构窗口1
	treeWidget1->setColumnCount(1); //设置列数
	treeWidget1->setHeaderLabel(QString("2D拓扑结构树"));

	QTreeWidgetItem* tree1_0 = new QTreeWidgetItem(treeWidget1, QStringList(QString("2D设计域")));
	QTreeWidgetItem* tree1_1 = new QTreeWidgetItem(treeWidget1, QStringList(QString("材料属性")));
	QTreeWidgetItem* tree1_2 = new QTreeWidgetItem(treeWidget1, QStringList(QString("2D边界条件")));
	QTreeWidgetItem* tree1_3 = new QTreeWidgetItem(treeWidget1, QStringList(QString("2D载荷设置")));
	QTreeWidgetItem* tree1_4 = new QTreeWidgetItem(treeWidget1, QStringList(QString("2D优化参数")));
	QTreeWidgetItem* tree1_5 = new QTreeWidgetItem(treeWidget1, QStringList(QString("结果查看")));
	treeWidget1->expandAll();

	//左侧树状结构窗口2
	treeWidget2->setColumnCount(1); //设置列数
	treeWidget2->setHeaderLabel(QString("3D拓扑结构树"));

	QTreeWidgetItem* tree2_0 = new QTreeWidgetItem(treeWidget2, QStringList(QString("3D设计域")));
	QTreeWidgetItem* tree2_1 = new QTreeWidgetItem(treeWidget2, QStringList(QString("材料属性")));
	QTreeWidgetItem* tree2_2 = new QTreeWidgetItem(treeWidget2, QStringList(QString("3D边界条件")));
	QTreeWidgetItem* tree2_3 = new QTreeWidgetItem(treeWidget2, QStringList(QString("3D载荷设置")));
	QTreeWidgetItem* tree2_4 = new QTreeWidgetItem(treeWidget2, QStringList(QString("3D优化参数")));
	QTreeWidgetItem* tree2_5 = new QTreeWidgetItem(treeWidget2, QStringList(QString("结果查看")));
	treeWidget2->expandAll();

	//左侧树状结构窗口3（方向场驱动路径）
	treeWidget3->setColumnCount(1); //设置列数
	treeWidget3->setHeaderLabel(QString("方向场驱动路径结构树"));
	QTreeWidgetItem* tree3_0 = new QTreeWidgetItem(treeWidget3, QStringList(QString("曲面网格(方向场驱动路径)")));
	QTreeWidgetItem* tree3_1 = new QTreeWidgetItem(treeWidget3, QStringList(QString("方向场(方向场驱动路径)")));
	QTreeWidgetItem* tree3_2 = new QTreeWidgetItem(treeWidget3, QStringList(QString("路径参数(方向场驱动路径)")));
	treeWidget3->expandAll();

	//树状结构窗口4（偏移路径）
	treeWidget4->setColumnCount(1); //设置列数
	treeWidget4->setHeaderLabel(QString("偏移路径结构树"));
	QTreeWidgetItem* tree4_0 = new QTreeWidgetItem(treeWidget4, QStringList(QString("曲面网格(偏移路径)")));
	QTreeWidgetItem* tree4_1 = new QTreeWidgetItem(treeWidget4, QStringList(QString("路径参数(偏移路径)")));
	treeWidget4->expandAll();

	//树状结构窗口5（梯度填充路径）
	treeWidget5->setColumnCount(1); //设置列数
	treeWidget5->setHeaderLabel(QString("梯度填充路径结构树"));
	QTreeWidgetItem* tree5_0 = new QTreeWidgetItem(treeWidget5, QStringList(QString("曲面网格(梯度填充路径)")));
	QTreeWidgetItem* tree5_1 = new QTreeWidgetItem(treeWidget5, QStringList(QString("路径参数(梯度填充路径)")));
	treeWidget5->expandAll();

	//树状结构窗口6（基准面法曲面切片）
	treeWidget6->setColumnCount(1); //设置列数
	treeWidget6->setHeaderLabel(QString("基准面法曲面切片结构树"));
	QTreeWidgetItem* tree6_0 = new QTreeWidgetItem(treeWidget6, QStringList(QString("模型网格(基准面法)")));
	QTreeWidgetItem* tree6_1 = new QTreeWidgetItem(treeWidget6, QStringList(QString("打印域(基准面法)")));
	QTreeWidgetItem* tree6_2 = new QTreeWidgetItem(treeWidget6, QStringList(QString("基准面")));
	QTreeWidgetItem* tree6_3 = new QTreeWidgetItem(treeWidget6, QStringList(QString("曲面切片(基准面法)")));
	QTreeWidgetItem* tree6_4 = new QTreeWidgetItem(treeWidget6, QStringList(QString("路径规划(基准面法)")));
	treeWidget6->expandAll();

	//树状结构窗口7（方向场法曲面切片）
	treeWidget7->setColumnCount(1); //设置列数
	treeWidget7->setHeaderLabel(QString("方向场法曲面切片结构树"));
	QTreeWidgetItem* tree7_0 = new QTreeWidgetItem(treeWidget7, QStringList(QString("模型网格(方向场法)")));
	QTreeWidgetItem* tree7_1 = new QTreeWidgetItem(treeWidget7, QStringList(QString("打印域(方向场法)")));
	QTreeWidgetItem* tree7_2 = new QTreeWidgetItem(treeWidget7, QStringList(QString("方向场")));
	QTreeWidgetItem* tree7_3 = new QTreeWidgetItem(treeWidget7, QStringList(QString("曲面切片(方向场法)")));
	QTreeWidgetItem* tree7_4 = new QTreeWidgetItem(treeWidget7, QStringList(QString("路径规划(方向场法)")));
	treeWidget7->expandAll();

	//左侧树状结构窗口8(有限元2D分析)
	treeWidget8->setColumnCount(1); //设置列数
	treeWidget8->setHeaderLabel(QString("2D有限元分析"));

	QTreeWidgetItem* tree8_0 = new QTreeWidgetItem(treeWidget8, QStringList(QString("2D模型网格")));
	QTreeWidgetItem* tree8_1 = new QTreeWidgetItem(treeWidget8, QStringList(QString("2D材料属性")));
	QTreeWidgetItem* tree8_2 = new QTreeWidgetItem(treeWidget8, QStringList(QString("2D边界条件（有限元）")));
	QTreeWidgetItem* tree8_3 = new QTreeWidgetItem(treeWidget8, QStringList(QString("2D载荷设置（有限元）")));
	QTreeWidgetItem* tree8_4 = new QTreeWidgetItem(treeWidget8, QStringList(QString("2D计算参数")));
	QTreeWidgetItem* tree8_5 = new QTreeWidgetItem(treeWidget8, QStringList(QString("2D结果查看（有限元）")));
	treeWidget8->expandAll();

	//左侧树状结构窗口9（3D有限元分析）
	treeWidget9->setColumnCount(1); //设置列数
	treeWidget9->setHeaderLabel(QString("2D拓扑结构树"));

	QTreeWidgetItem* tree9_0 = new QTreeWidgetItem(treeWidget9, QStringList(QString("3D模型网格")));
	QTreeWidgetItem* tree9_1 = new QTreeWidgetItem(treeWidget9, QStringList(QString("3D材料属性")));
	QTreeWidgetItem* tree9_2 = new QTreeWidgetItem(treeWidget9, QStringList(QString("3D边界条件（有限元）")));
	QTreeWidgetItem* tree9_3 = new QTreeWidgetItem(treeWidget9, QStringList(QString("3D载荷设置（有限元）")));
	QTreeWidgetItem* tree9_4 = new QTreeWidgetItem(treeWidget9, QStringList(QString("3D计算参数")));
	QTreeWidgetItem* tree9_5 = new QTreeWidgetItem(treeWidget9, QStringList(QString("3D结果查看（有限元）")));
	treeWidget9->expandAll();

	//左侧树状结构堆栈窗口
	treeStackWidget->addWidget(treeWidget1);
	treeStackWidget->addWidget(treeWidget2);
	treeStackWidget->addWidget(treeWidget3);
	treeStackWidget->addWidget(treeWidget4);
	treeStackWidget->addWidget(treeWidget5);
	treeStackWidget->addWidget(treeWidget6);
	treeStackWidget->addWidget(treeWidget7);
	treeStackWidget->addWidget(treeWidget8);
	treeStackWidget->addWidget(treeWidget9);

	//显示结构初始化
	root->addChild(model.get());
	root->addChild(arrow.get());
	root->addChild(slicePlane.get());

	model->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);//模型始终发亮，故关闭模型节点的光照设置

}

void TopoOptimizeWidget::creatAction()
{
	//树结构和堆栈窗口关联
	connect(treeWidget1, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget2, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget3, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget4, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget5, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget6, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget7, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget8, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget9, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));

	//文件读取对话框
	connect(designZoneWidget->uiDesignZone->importDesignGridButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));
	connect(materialSetWidget->uiMaterialSet->importElasticityMatrixButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));

	connect(vectorDieldDriven_SurfaceMesh->uiSurfaceMesh->pushButton_ImportTriMesh, SIGNAL(clicked()), this, SLOT(VectorDieldDriven_SurfaceMesh_on_ImportTriMesh_push()));

	connect(designZone_3D->uiDesignZone_3d->generateButton, SIGNAL(clicked()), this, SLOT(generate3dDesignZone()));
	connect(designZoneWidget->uiDesignZone->generateButton, SIGNAL(clicked()), this, SLOT(generate2dDesignZone()));
	connect(loadSet_3D->uiLoadSet_3D->pushButton_add, SIGNAL(clicked()), this, SLOT(addArrow0()));

}
//osgwidget
OsgWidget::OsgWidget(QWidget* parent, Qt::WindowFlags f, osgViewer::ViewerBase::ThreadingModel threadingModel) :
	view(new osgViewer::Viewer)
{
	setThreadingModel(threadingModel);

	// disable the default setting of viewer.done() by pressing Escape.
	setKeyEventSetsDone(0);

	QWidget* popupWidget = addViewWidget(createGraphicsWindow(900, 100, 800, 600, "Popup window", true));
	popupWidget->setMouseTracking(true);
	QGridLayout* grid = new QGridLayout;
	grid->addWidget(popupWidget, 0, 0);
	setLayout(grid);

	connect(&_timer, SIGNAL(timeout()), this, SLOT(update()));
	_timer.start(5);
}

QWidget* OsgWidget::addViewWidget(osgQt::GraphicsWindowQt* gw)
{
	addView(view);

	osg::Camera* camera = view->getCamera();
	camera->setGraphicsContext(gw);

	const osg::GraphicsContext::Traits* traits = gw->getTraits();

	camera->setClearColor(osg::Vec4(1, 1, 1, 1));
	camera->setViewport(new osg::Viewport(0, 0, traits->width, traits->height));
	camera->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(traits->width) / static_cast<double>(traits->height), 1.0f, 10000.0f);

	view->setSceneData(root);
	view->addEventHandler(new osgViewer::StatsHandler);
	//view->addEventHandler(new osgGA::StateSetManipulator(view->getCamera()->getOrCreateStateSet()));
	view->addEventHandler(new AddLinePointHandler);
	view->setCameraManipulator(new osgGA::MultiTouchTrackballManipulator);
	gw->setTouchEventsEnabled(true);
	return gw->getGLWidget();
}

osgQt::GraphicsWindowQt* OsgWidget::createGraphicsWindow(int x, int y, int w, int h, const std::string& name, bool windowDecoration)
{
	osg::DisplaySettings* ds = osg::DisplaySettings::instance().get();
	osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	traits->windowName = name;
	traits->windowDecoration = windowDecoration;
	traits->x = x;
	traits->y = y;
	traits->width = w;
	traits->height = h;
	traits->doubleBuffer = true;
	traits->alpha = ds->getMinimumNumAlphaBits();
	traits->stencil = ds->getMinimumNumStencilBits();
	traits->sampleBuffers = ds->getMultiSamples();
	traits->samples = ds->getNumMultiSamples();

	return new osgQt::GraphicsWindowQt(traits.get());
}

void OsgWidget::paintEvent(QPaintEvent* event)
{
	frame();
}


//加载设计域ui
DesignZoneWidget::DesignZoneWidget() :
	uiDesignZone(new Ui::DesignZoneWidget)
{
	uiDesignZone->setupUi(this);
}

DesignZoneWidget :: ~DesignZoneWidget()
{
	delete uiDesignZone;
}

//加载3D设计域
DesignZone_3D::DesignZone_3D():
	uiDesignZone_3d(new Ui::DesignZoneWidget_3D)
{
	uiDesignZone_3d->setupUi(this);
}

DesignZone_3D::~DesignZone_3D()
{
	delete uiDesignZone_3d;
}

//加载材料属性设置ui
MaterialSetWidget::MaterialSetWidget():
	uiMaterialSet(new Ui::MeterialSetWidget),
	radioButtons(new QButtonGroup)
{
	uiMaterialSet->setupUi(this);

	//设置各向同性/各项异性按钮互斥
	radioButtons->addButton(uiMaterialSet->sameButton);
	radioButtons->addButton(uiMaterialSet->differentButton);
	radioButtons->setExclusive(true);
	//设置默认
	uiMaterialSet->sameButton->setChecked(true);

	//设置链接
	//材料各向同性/各向异性选择
	connect(uiMaterialSet->sameButton, SIGNAL(stateChanged(int)), this, SLOT(sameButton(int)));
	connect(uiMaterialSet->differentButton, SIGNAL(stateChanged(int)), this, SLOT(diffButton(int)));
	
}

MaterialSetWidget::~MaterialSetWidget()
{
	delete uiMaterialSet;
}

//加载边界条件ui

BoundaryCasesWidget::BoundaryCasesWidget():
	uiBoundaryCases(new Ui::BoundaryCasesWidget)
{
	uiBoundaryCases->setupUi(this);
}

BoundaryCasesWidget::~BoundaryCasesWidget()
{
	delete uiBoundaryCases;
}

//加载3D边界条件ui
BoundaryCases_3D::BoundaryCases_3D() :
	uiBoundaryCases_3D(new Ui::BoundaryCasesWidget_3D)
{
	uiBoundaryCases_3D->setupUi(this);
}

BoundaryCases_3D::~BoundaryCases_3D()
{
	delete uiBoundaryCases_3D;
}

//加载载荷设置ui
LoadSetWidget::LoadSetWidget():
	uiLoadSet(new Ui::LoadSetWidget)
{
	uiLoadSet->setupUi(this);
}

LoadSetWidget::~LoadSetWidget()
{
	delete uiLoadSet;
}

//加载3D载荷设置ui
LoadSet_3D::LoadSet_3D() :
	uiLoadSet_3D(new Ui::LoadSetWidget_3D)
{
	uiLoadSet_3D->setupUi(this);
}

LoadSet_3D::~LoadSet_3D()
{
	delete uiLoadSet_3D;
}

//加载参数优化ui
OptimizeParaWidget::OptimizeParaWidget():
	uiOptimizePara(new Ui::OptimizeParaWidget)
{
	uiOptimizePara->setupUi(this);
}

OptimizeParaWidget::~OptimizeParaWidget()
{
	delete uiOptimizePara;
}

//加载3D参数优化ui
OptimizePara_3D::OptimizePara_3D() :
	uiOptimizePara_3D(new Ui::OptimizeParaWidget_3D)
{
	uiOptimizePara_3D->setupUi(this);
}

OptimizePara_3D::~OptimizePara_3D()
{
	delete uiOptimizePara_3D;
}

//加载结果查看ui
ResultCheckWidget::ResultCheckWidget():
	uiRecultCheck(new Ui:: ResultCheckWidget)
{
	uiRecultCheck->setupUi(this);
}

ResultCheckWidget::~ResultCheckWidget()
{
	delete uiRecultCheck;
}

//2D设计域生成函数
void TopoOptimizeWidget::aabbSplit2D(const Point2D& left, const Point2D& right, float resolution, V& vers, C& cells)
{
	Eigen::Vector2d bound = right - left;
	double aabbLength = bound.row(0).norm();
	double aabbWidth = bound.row(1).norm();

	auto Xnums = int((aabbLength - 1e-10) / resolution) + 1;
	auto Ynums = int((aabbWidth - 1e-10) / resolution) + 1;

	// Eigen::matrixXd Vertexes;
	vers.resize((Xnums + 1) * (Ynums + 1), 2);
	double startX = left.row(0).norm();
	double startY = left.row(1).norm();
	for (int i = 0; i < Ynums + 1; i++)
	{
		for (int j = 0; j < Xnums + 1; j++)
		{
			vers.row(i * (Xnums + 1) + j) << startX + resolution * j,
				startY + resolution * i;
		}
	}
	int crows = 0;
	cells.resize((Xnums) * (Ynums), 4);
	cells.setZero();
	for (int i = 0; i < Ynums; i++)
	{
		for (int j = 0; j < Xnums; j++)
		{
			int start = i * (Xnums + 1) + j;
			cells.row(crows) << start,
				start + 1,
				start + 1 + (Xnums + 1),
				start + Xnums + 1;
			crows++;
		}
	}
}

//3D设计域生成函数
void TopoOptimizeWidget::aabbSplit3D(const Point3D& left, const Point3D& right, float resolution, V& vers, C& cells)
{
	Eigen::Vector3d bound = right - left;
	double aabbLength = bound.row(0).norm();
	double aabbWidth = bound.row(1).norm();
	double aabbHeight = bound.row(2).norm();

	auto Xnums = int((aabbLength - 1e-10) / resolution) + 1;
	auto Ynums = int((aabbWidth - 1e-10) / resolution) + 1;
	auto Znums = int((aabbHeight - 1e-10) / resolution) + 1;

	// Eigen::MatrixXd Vertexes;
	vers.resize((Xnums + 1) * (Ynums + 1) * (Znums + 1), 3);
	double startX = left.row(0).norm();
	double startY = left.row(1).norm();
	double startZ = left.row(2).norm();
	for (int i = 0; i < Znums + 1; i++)
	{
		for (int j = 0; j < Ynums + 1; j++)
		{
			for (int k = 0; k < Xnums + 1; k++)
			{
				vers.row(i * (Xnums + 1) * (Ynums + 1) + j * (Xnums + 1) + k) << startX + resolution * k,
					startY + resolution * j,
					startZ + resolution * i;
			}
		}
	}
	int crows = 0;
	cells.resize((Xnums) * (Ynums) * (Znums), 8);
	cells.setZero();
	for (int i = 0; i < Znums; i++)
	{
		for (int j = 0; j < Ynums; j++)
		{
			for (int k = 0; k < Xnums; k++)
			{
				int start = i * (Xnums + 1) * (Ynums + 1) + j * (Xnums + 1) + k;
				cells.row(crows) << start,
					start + 1,
					start + 1 + Xnums + 1,
					start + Xnums + 1,
					start + (Xnums + 1) * (Ynums + 1),
					start + 1 + (Xnums + 1) * (Ynums + 1),
					start + 1 + Xnums + 1 + (Xnums + 1) * (Ynums + 1),
					start + Xnums + 1 + (Xnums + 1) * (Ynums + 1);
				crows++;
			}
		}
	}
}


void TopoOptimizeWidget::CreatArrow(osg::ref_ptr<osg::Group> root_t, const osg::Vec3& startPoint, const osg::Vec3& direction)
{
	double radius = 0.3;
	double height = direction.length() * 2;
	double coneRadius = 0.5;
	double coneHeight = 2;

	osg::ref_ptr<osg::Cone> cone = new osg::Cone(osg::Vec3(0.0f, 0.0f, height), coneRadius, coneHeight);
	osg::ref_ptr<osg::ShapeDrawable> coneDrawable = new osg::ShapeDrawable(cone.get());
	coneDrawable->setColor(osg::Vec4(1, 0, 0, 1));

	osg::ref_ptr<osg::Cylinder> cylinder = new osg::Cylinder(osg::Vec3(0.0f, 0.0f, 0.5 * height), radius, height);
	osg::ref_ptr<osg::ShapeDrawable> cylinderDrawable = new osg::ShapeDrawable(cylinder.get());
	cylinderDrawable->setColor(osg::Vec4(1, 0, 0, 1));
	//添加组节点来保存拖拽器
	osg::ref_ptr<osg::Group> group = new osg::Group;

	//为添加球式拖拽器的节点
	osg::ref_ptr<osgManipulator::Selection> selection = new osgManipulator::Selection;
	// 创建变换节点，并将圆柱和圆锥的几何体添加到变换节点中
	osg::ref_ptr<osg::PositionAttitudeTransform> arrowTransform = new osg::PositionAttitudeTransform;
	group->addChild(selection);//0
	selection->addChild(arrowTransform);
	arrowTransform->addChild(coneDrawable.get());
	arrowTransform->addChild(cylinderDrawable.get());

	// 设置变换节点的位置和方向
	arrowTransform->setPosition(startPoint);
	osg::Vec3 normalizedDirection = direction;
	normalizedDirection.normalize();
	osg::Quat rotation;
	rotation.makeRotate(osg::Vec3(0, 0, 1), normalizedDirection);
	rotation_Global = rotation;//初始姿态
	arrowTransform->setAttitude(rotation);

	// 将变换节点添加到箭头的根节点中
	root_t->addChild(group);

}

HUDAxis::HUDAxis()
{
	//可以在这直接读取axes.osgt;
	// this->addChild(osgDB::readNodeFile("axes.osgt"));
}
HUDAxis::HUDAxis(HUDAxis const& copy, osg::CopyOp copyOp /* = CopyOp::SHALLOW_COPY */) :Camera(copy, copyOp),
_mainCamera(copy._mainCamera)
{
}
void HUDAxis::traverse(osg::NodeVisitor& nv)
{
	double fovy, aspectRatio, vNear, vFar;
	_mainCamera->getProjectionMatrixAsPerspective(fovy, aspectRatio, vNear, vFar);
	//this->setProjectionMatrixAsOrtho(-10.0*aspectRatio, 10.0*aspectRatio, -10.0, 10.0, 2.0, -2.0); //设置投影矩阵，使缩放不起效果
	this->setProjectionMatrixAsOrtho2D(-10.0 * aspectRatio, 10.0 * aspectRatio, -10.0, 10.0);
	osg::Vec3 trans(8.5 * aspectRatio, -8.5, -8.0);
	if (_mainCamera.valid() && nv.getVisitorType() == osg::NodeVisitor::CULL_VISITOR)
	{
		osg::Matrix matrix = _mainCamera->getViewMatrix();//改变视图矩阵，让移动位置固定
		matrix.setTrans(trans);
		this->setViewMatrix(matrix);
	}//if
	osg::Camera::traverse(nv);
}
HUDAxis::~HUDAxis()
{
}

void TopoOptimizeWidget::creatHUD()
{
	osg::ref_ptr<HUDAxis> hudAxes = new HUDAxis;
	hudAxes->addChild(makeCoordinate());
	hudAxes->setMainCamera(osgWidget->view->getCamera());
	hudAxes->setRenderOrder(osg::Camera::POST_RENDER);
	hudAxes->setClearMask(GL_DEPTH_BUFFER_BIT);
	hudAxes->setAllowEventFocus(false);
	hudAxes->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	hudAxes->setName("hudAxes");
	hudAxes->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);//模型始终发亮，故关闭模型节点的光照设置
	root->addChild(hudAxes);//子节点2
}

osg::ref_ptr<osg::Geode> TopoOptimizeWidget::makeCoordinate()
{
	osg::ref_ptr<osg::Sphere> pSphereShape = new osg::Sphere(osg::Vec3(0, 0, 0), 0.1f);
	osg::ref_ptr<osg::ShapeDrawable> pShapeDrawable = new osg::ShapeDrawable(pSphereShape.get());
	pShapeDrawable->setColor(osg::Vec4(0.0, 0.0, 0.0, 1.0));

	//创建保存几何信息的对象
	osg::ref_ptr<osg::Geometry> geom = new osg::Geometry();

	//创建四个顶点
	osg::ref_ptr<osg::Vec3Array> v = new osg::Vec3Array();
	v->push_back(osg::Vec3(0.0f, 0.0f, 0.0f));
	v->push_back(osg::Vec3(1.0f, 0.0f, 0.0f));
	v->push_back(osg::Vec3(0.0f, 0.0f, 0.0f));
	v->push_back(osg::Vec3(0.0f, 1.0f, 0.0f));
	v->push_back(osg::Vec3(0.0f, 0.0f, 0.0f));
	v->push_back(osg::Vec3(0.0f, 0.0f, 1.0f));
	geom->setVertexArray(v.get());


	//为每个顶点指定一种颜色
	osg::ref_ptr<osg::Vec4Array> c = new osg::Vec4Array();
	c->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f)); //坐标原点为红色
	c->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f)); //x red
	c->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f)); //坐标原点为绿色
	c->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f)); //y green
	c->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f)); //坐标原点为蓝色
	c->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f)); //z blue
	//如果没指定颜色则会变为黑色
	geom->setColorArray(c.get());
	geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

	//三个轴
	geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINES, 0, 2)); //X
	geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINES, 2, 2)); //Y
	geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINES, 4, 2)); //Z

	osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	//geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setAttribute(new osg::LineWidth(3.0), osg::StateAttribute::ON);

	geode->addDrawable(pShapeDrawable.get());
	geode->addDrawable(geom.get());


	return geode.release();
}


//****************以下为槽函数*********************//

void TopoOptimizeWidget::stackedWidgetPageChange(QTreeWidgetItem* item, int column)
{
	if (item->text(column) == "2D设计域")//?????????????
		oprStackWidget->setCurrentIndex(0);

	if (item->text(column) == "材料属性")
		oprStackWidget->setCurrentIndex(1);

	if (item->text(column) == "2D边界条件")
		oprStackWidget->setCurrentIndex(2);

	if (item->text(column) == "2D载荷设置")
		oprStackWidget->setCurrentIndex(3);

	if (item->text(column) == "2D优化参数")
		oprStackWidget->setCurrentIndex(4);

	if (item->text(column) == "结果查看")
		oprStackWidget->setCurrentIndex(5);

	if (item->text(column) == "3D设计域")
		oprStackWidget->setCurrentIndex(6);

	if (item->text(column) == "3D边界条件")
		oprStackWidget->setCurrentIndex(7);

	if (item->text(column) == "3D载荷设置")
		oprStackWidget->setCurrentIndex(8);

	if (item->text(column) == "3D优化参数")
		oprStackWidget->setCurrentIndex(9);

	if (item->text(column) == "曲面网格(方向场驱动路径)")
		oprStackWidget->setCurrentIndex(11);

	if (item->text(column) == "方向场(方向场驱动路径)")
		oprStackWidget->setCurrentIndex(12);

	if (item->text(column) == "路径参数(方向场驱动路径)")
		oprStackWidget->setCurrentIndex(10);

	if (item->text(column) == "曲面网格(偏移路径)")
		oprStackWidget->setCurrentIndex(13);

	if (item->text(column) == "路径参数(偏移路径)")
		oprStackWidget->setCurrentIndex(14);

	if (item->text(column) == "曲面网格(梯度填充路径)")
		oprStackWidget->setCurrentIndex(15);

	if (item->text(column) == "路径参数(梯度填充路径)")
		oprStackWidget->setCurrentIndex(16);

	if (item->text(column) == "模型网格(基准面法)")
		oprStackWidget->setCurrentIndex(17);

	if (item->text(column) == "打印域(基准面法)")
		oprStackWidget->setCurrentIndex(18);

	if (item->text(column) == "基准面")
		oprStackWidget->setCurrentIndex(19);

	if (item->text(column) == "曲面切片(基准面法)")
		oprStackWidget->setCurrentIndex(20);

	if (item->text(column) == "路径规划(基准面法)")
		oprStackWidget->setCurrentIndex(21);

	if (item->text(column) == "模型网格(方向场法)")
		oprStackWidget->setCurrentIndex(22);

	if (item->text(column) == "打印域(方向场法)")
		oprStackWidget->setCurrentIndex(23);

	if (item->text(column) == "方向场")
		oprStackWidget->setCurrentIndex(24);

	if (item->text(column) == "曲面切片(方向场法)")
		oprStackWidget->setCurrentIndex(25);

	if (item->text(column) == "路径规划(方向场法)")
		oprStackWidget->setCurrentIndex(26);

	if (item->text(column) == "2D模型网格")
		oprStackWidget->setCurrentIndex(27);

	if (item->text(column) == "2D材料属性")
		oprStackWidget->setCurrentIndex(28);

	if (item->text(column) == "2D边界条件（有限元）")
		oprStackWidget->setCurrentIndex(29);

	if (item->text(column) == "2D载荷设置（有限元）")
		oprStackWidget->setCurrentIndex(30);

	if (item->text(column) == "2D计算参数")
		oprStackWidget->setCurrentIndex(31);

	if (item->text(column) == "2D结果查看（有限元）")
		oprStackWidget->setCurrentIndex(32);

	if (item->text(column) == "3D模型网格")
		oprStackWidget->setCurrentIndex(33);

	if (item->text(column) == "3D材料属性")
		oprStackWidget->setCurrentIndex(34);

	if (item->text(column) == "3D边界条件（有限元）")
		oprStackWidget->setCurrentIndex(35);

	if (item->text(column) == "3D载荷设置（有限元）")
		oprStackWidget->setCurrentIndex(36);

	if (item->text(column) == "3D计算参数")
		oprStackWidget->setCurrentIndex(37);

	if (item->text(column) == "3D结果查看（有限元）")
		oprStackWidget->setCurrentIndex(38);
}

//设计域中导入设计域网格文件对应的选择文件路径对话框
void TopoOptimizeWidget::importDesignGridFile()
{
	fileRoute = QFileDialog::getOpenFileName(this, QStringLiteral("Please Select File"), "F:", QStringLiteral("textfile(*txt)"));
}

void MaterialSetWidget::sameButton(int state)
{
	if (state == Qt::Checked)
	{
		uiMaterialSet->lineEdit->setEnabled(true);
		uiMaterialSet->lineEdit_2->setEnabled(true);
		uiMaterialSet->addMaterial_1->setEnabled(true);
	}
	if (state == Qt::Unchecked)
	{
		uiMaterialSet->lineEdit->setEnabled(false);
		uiMaterialSet->lineEdit_2->setEnabled(false);
		uiMaterialSet->addMaterial_1->setEnabled(false);
	}
}

void MaterialSetWidget::diffButton(int state)
{
	if (state == Qt::Checked)
	{
		uiMaterialSet->importElasticityMatrixButton->setEnabled(true);
		uiMaterialSet->addMaterial_2->setEnabled(true);
	}
	if (state == Qt::Unchecked)
	{
		uiMaterialSet->importElasticityMatrixButton->setEnabled(false);
		uiMaterialSet->addMaterial_2->setEnabled(false);
	}
}


osg::Vec3 TopoOptimizeWidget::getnormal(osg::Vec3 v1, osg::Vec3 v2, osg::Vec3 v3, osg::Vec3 v4)
{ 
	return -(v2 - v1) ^ (v3 - v2);
}

bool TopoOptimizeWidget::cmpAixsX(Point3D x, Point3D y)
{
	return x(0) < y(0);
}
bool TopoOptimizeWidget::cmpAixsY(Point3D x, Point3D y)
{
	return x(1) < y(1);
}

bool TopoOptimizeWidget::cmpAixsZ(Point3D x, Point3D y)
{
	return x(2) < y(2);
}


void TopoOptimizeWidget::pickSurfaceCoors(CoorSet unPickedCoors, CoorSet& PickCoors)
//对Coors引用传参对内存更友好，之后优化方向可以考虑一下？？？？？？？？？？？？？？？？？
{

	if (unPickedCoors.size() == 1)
		//如果只有一个元素?????????????????????
		PickCoors = unPickedCoors;
	else
	{
		//添加首尾坐标值
		if (!PickCoors.empty())
			PickCoors.clear();
		PickCoors.push_back(*unPickedCoors.begin());
		PickCoors.push_back(*(--unPickedCoors.end()));
	}
	//添加镂空坐标值，目前的立方体模型没有办法测试，找师兄要模型优化？？？？？？？？？？？？？？？？？
}

void TopoOptimizeWidget::getShellVoxel(V v, C c, CoorSet& finalCoors)
{
	//v/c如果是零矩阵的情况没有考虑，待优化？？？？？？？？？？？？？？？？？？？？？？
	std::set<float> xCoorSet;
	std::set<float> yCoorSet;
	std::set<float> zCoorSet;
	CoorSet firstCoors;
	CoorSet secondCoors;
	//V v_new; //更新后的v
	//C c_new; //更新后的c
	CoorSet tempPickedCoors;

	//提取所有的x，y，z坐标值
	for (int i = 0; i < c.rows(); ++i)
	{
		xCoorSet.insert(v(int(c(i, 0)), 0));
		yCoorSet.insert(v(int(c(i, 0)), 1));
		zCoorSet.insert(v(int(c(i, 0)), 2));
	}


	for (auto xiter = xCoorSet.begin(); xiter != xCoorSet.end(); ++xiter)
		//确定要选定的垂直于x=*xiter平面的*xiter值
	{
		firstCoors.clear();
		for (int i = 0; i < c.rows(); ++i)
		{
			if (v(int(c(i, 0)), 0) == *xiter)
				//遍历所有的点，并找到x坐标与*xiter相同值的所有点，
				//并将对应的点向量保存到coors（体到面x = *xiter）
				firstCoors.push_back(v.row(int(c(i, 0))));
		}
		for (auto yiter = yCoorSet.begin(); yiter != yCoorSet.end(); ++yiter)
			//确定要选定的垂直于y=*yiter平面的*yiter值
		{
			if (!secondCoors.empty())
				secondCoors.clear();
			for (auto firstPickedCoor : firstCoors)
			{
				if (firstPickedCoor(1) == *yiter)
					//遍历coors中所有的点，并找到y坐标与*yiter相同值的所有点，
					//并将对应的点向量保存到secondCoors（面到线 x = *xiter && y = *yiter）
					secondCoors.push_back(firstPickedCoor);
			}
			//对secondCoors中的点向量按照z坐标从小到大排序
			std::sort(secondCoors.begin(), secondCoors.end(), cmpAixsZ);
			pickSurfaceCoors(secondCoors, tempPickedCoors);
			finalCoors.insert(finalCoors.end(), tempPickedCoors.begin(), tempPickedCoors.end());
			//没有去重？？？？？？？？？？？？
		}

		for (auto ziter = zCoorSet.begin(); ziter != zCoorSet.end(); ++ziter)
			//确定要选定的垂直于z=*ziter平面的*ziter值
		{
			if (!secondCoors.empty())
				secondCoors.clear();
			for (auto firstPickedCoor : firstCoors)
			{
				if (firstPickedCoor(2) == *ziter)
					//遍历coors中所有的点，并找到z坐标与*ziter相同值的所有点，
					//并将对应的点向量保存到secondCoors（面到线 x = *xiter && z = *ziter）
					secondCoors.push_back(firstPickedCoor);
			}
			//对secondCoors中的点向量按照y坐标从小到大排序
			std::sort(secondCoors.begin(), secondCoors.end(), cmpAixsY);
			pickSurfaceCoors(secondCoors, tempPickedCoors);
			finalCoors.insert(finalCoors.end(), tempPickedCoors.begin(), tempPickedCoors.end());
			//没有去重？？？？？？？？？？？？
		}
	}

	

	for (auto yiter = yCoorSet.begin(); yiter != yCoorSet.end(); ++yiter)
		//确定要选定的垂直于y=*yiter平面的*yiter值
	{
		firstCoors.clear();
		for (int i = 0; i < c.rows(); ++i)
		{
			if (v(int(c(i, 0)), 1) == *yiter)
				//遍历所有的点，并找到y坐标与*yiter相同值的所有点，
				//并将对应的点向量保存到firstCoors（体到面y = *yiter）
				firstCoors.push_back(v.row(int(c(i, 0))));
		}
		for (auto ziter = zCoorSet.begin(); ziter != zCoorSet.end(); ++ziter)
			//确定要选定的垂直于z=*ziter平面的*ziter值
		{
			if (!secondCoors.empty())
				secondCoors.clear();
			for (auto firstPickedCoor : firstCoors)
			{
				if (firstPickedCoor(2) == *ziter)
					//遍历coors中所有的点，并找到y坐标与*yiter相同值的所有点，
					//并将对应的点向量保存到secondCoors（面到线 x = *xiter && y = *yiter）
					secondCoors.push_back(firstPickedCoor);
			}
			//对secondCoors中的点向量按照x坐标从小到大排序
			std::sort(secondCoors.begin(), secondCoors.end(), cmpAixsX);
			pickSurfaceCoors(secondCoors, tempPickedCoors);
			finalCoors.insert(finalCoors.end(), tempPickedCoors.begin(), tempPickedCoors.end());
			//没有去重？？？？？？？？？？？？
		}
	}
}

osg::ref_ptr<osg::Node> TopoOptimizeWidget::createLightSource(unsigned int num, const osg::Vec3d& trans,
	const osg::Vec3d& vecDir)
{
	osg::ref_ptr<osg::Light> light = new osg::Light;
	light->setLightNum(num);
	light->setDirection(vecDir);
	osg::ref_ptr<osg::LightSource> lightSource = new osg::LightSource;
	lightSource->setLight(light);
	osg::ref_ptr<osg::MatrixTransform> sourceTrans = new osg::MatrixTransform;
	sourceTrans->setMatrix(osg::Matrix::translate(trans));
	sourceTrans->addChild(lightSource.get());
	return sourceTrans.release();
}

void TopoOptimizeWidget::generate2dDesignZone()
{
	if (model != nullptr)
		model->removeChild(0, 1U);
	osg::ref_ptr<osg::Group> group = new osg::Group;
	QString len = designZoneWidget->uiDesignZone->lineEdit->text();//长
	QString wid = designZoneWidget->uiDesignZone->lineEdit_4->text();//宽
	QString re = designZoneWidget->uiDesignZone->lineEdit_3->text();//边长

	if (len != nullptr && wid != nullptr && re != nullptr)
	{
		float length = len.toFloat();
		float width = wid.toFloat();
		float resolution = re.toFloat();

		Point2D left(0, 0);
		Point2D right(length, width);
		V v;
		C c;

		aabbSplit2D(left, right, resolution, v, c);

		osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(4 * c.rows());
		osg::ref_ptr<osg::DrawElementsUInt> quadsIndices = new osg::DrawElementsUInt(GL_QUADS, 4 * c.rows());
		osg::ref_ptr<osg::DrawElementsUInt> linesIndices = new osg::DrawElementsUInt(GL_LINES, 8 * c.rows());
		osg::ref_ptr<osg::Geometry> geom_QUADS = new osg::Geometry;
		osg::ref_ptr<osg::Geometry> geom_lINES = new osg::Geometry;

		for (int i = 0; i < c.rows(); i++)
		{
			//生成几何体
			float x = v(int(c(i, 0)), 0) - v(int(c(0, 0)), 0);
			float y = v(int(c(i, 0)), 1) - v(int(c(0, 0)), 1);
			(*vertices)[i * 4 + 0].set(v(int(c(0, 0)), 0) + x, v(int(c(0, 0)), 1) + y, 0);
			(*vertices)[i * 4 + 1].set(v(int(c(0, 1)), 0) + x, v(int(c(0, 1)), 1) + y, 0);
			(*vertices)[i * 4 + 2].set(v(int(c(0, 2)), 0) + x, v(int(c(0, 2)), 1) + y, 0);
			(*vertices)[i * 4 + 3].set(v(int(c(0, 3)), 0) + x, v(int(c(0, 3)), 1) + y, 0);

			(*quadsIndices)[i * 4 + 0] = i * 4 + 0; (*quadsIndices)[i * 4 + 1] = i * 4 + 1; (*quadsIndices)[i * 4 + 2] = i * 4 + 2; (*quadsIndices)[i * 4 + 3] = i * 4 + 3;

			(*linesIndices)[i * 8 + 0] = i * 4 + 0; (*linesIndices)[i * 8 + 1] = i * 4 + 1;
			(*linesIndices)[i * 8 + 2] = i * 4 + 1; (*linesIndices)[i * 8 + 3] = i * 4 + 2;
			(*linesIndices)[i * 8 + 4] = i * 4 + 2; (*linesIndices)[i * 8 + 5] = i * 4 + 3;
			(*linesIndices)[i * 8 + 6] = i * 4 + 3; (*linesIndices)[i * 8 + 7] = i * 4 + 0;
		}

		geom_QUADS->setVertexArray(vertices.get());
		geom_QUADS->addPrimitiveSet(quadsIndices.get());
		osg::ref_ptr<osg::Vec4Array> quadsColors = new osg::Vec4Array;
		quadsColors->push_back(osg::Vec4(0., 1., 1., 1.));
		geom_QUADS->setColorArray(quadsColors);
		geom_QUADS->setColorBinding(osg::Geometry::BIND_OVERALL);
		osg::ref_ptr<osg::Geode> modelNode = new osg::Geode;
		modelNode->addDrawable(geom_QUADS.get());

		geom_lINES->setVertexArray(vertices.get());
		geom_lINES->addPrimitiveSet(linesIndices.get());
		osg::ref_ptr<osg::Vec4Array> lineColors = new osg::Vec4Array;
		lineColors->push_back(osg::Vec4(0., 0., 0., 1.));
		geom_lINES->setColorArray(lineColors);
		geom_lINES->setColorBinding(osg::Geometry::BIND_OVERALL);
		osg::ref_ptr<osg::Geode> stripNode = new osg::Geode;
		stripNode->addDrawable(geom_lINES.get());

		//网格化
		group->addChild(modelNode);
		group->addChild(stripNode);

		/****************************设置上下左右近远六个光源，但是没写阴影*********************************/
		osg::ref_ptr<osg::StateSet> stateset = group->getOrCreateStateSet();
		stateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);
		stateset->setMode(GL_LIGHT6, osg::StateAttribute::ON);	// GL_LIGHT0是默认光源
		// 设置6个光源 解决光照问题                         
		osg::Vec3d ptLight;
		osg::Vec3d ptCenter = osg::Vec3d(0, 0, 0);
		double dDis = 200000.0;
		ptLight = ptCenter + osg::Z_AXIS * dDis;
		osg::ref_ptr<osg::Node> pNodeLight = createLightSource(6, ptLight, -osg::Z_AXIS);
		pNodeLight->setName("light0");
		group->addChild(pNodeLight);

		//设置网格线宽
		osg::ref_ptr<osg::StateSet> state = stripNode->getOrCreateStateSet();
		osg::ref_ptr<osg::LineWidth> lineWid = new osg::LineWidth(4.0f);
		state->setAttribute(lineWid.get());
		model->addChild(group);
		//显示自适应模型大小
		osgWidget->view->getCameraManipulator()->computeHomePosition();
		osgWidget->view->getCameraManipulator()->home(0.0);
	}
	else
	{
		QMessageBox::information(NULL, QString("警告"), QString("数据不足"));
	}

}

void TopoOptimizeWidget::generate3dDesignZone()
//多次点击的覆盖问题？？？？？？？？？？？？？？？？？？？？？？？？？？？？
{
	if (model != nullptr)
		model->removeChild(0, 1U);
	//未考虑数据输入类型错误的bug？？？？？？？？？？？？？？？？？？？？？？
	//获取QLineEdit中的数据
	osg::ref_ptr<osg::Group> group = new osg::Group;
	QString len = designZone_3D->uiDesignZone_3d->lineEdit->text();//长
	QString wid = designZone_3D->uiDesignZone_3d->lineEdit_4->text();//宽
	QString hei = designZone_3D->uiDesignZone_3d->lineEdit_5->text();//高
	QString re = designZone_3D->uiDesignZone_3d->lineEdit_3->text();//边长

	if (len != nullptr && wid != nullptr && hei != nullptr && re != nullptr)
	{
		//文本框中文本转换
		float length = len.toFloat();
		float width = wid.toFloat();
		float height = hei.toFloat();
		float resolution = re.toFloat();

		Point3D left(0, 0, 0);
		Point3D right(length, width, height);
		V v;
		C c;
		CoorSet finalCoors;//保存最后得到的表面坐标

		aabbSplit3D(left, right, resolution, v, c);
		getShellVoxel(v, c, finalCoors);


	/*********************************所有网格生成一个几何体类，渲染效率提高*************************************/
		//生成单一体素单元
		int numOfFinalCoors = finalCoors.size();
		osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(8 * numOfFinalCoors);
		osg::ref_ptr<osg::DrawElementsUInt> quadsIndices = new osg::DrawElementsUInt(GL_QUADS, 24 * numOfFinalCoors);
		osg::ref_ptr<osg::DrawElementsUInt> linesIndices = new osg::DrawElementsUInt(GL_LINES, 24 * numOfFinalCoors);

		osg::ref_ptr<osg::Geometry> geom_QUADS = new osg::Geometry;
		osg::ref_ptr<osg::Geometry> geom_lINES = new osg::Geometry;

		int i = 0;
		for (auto iter = finalCoors.begin(); iter != finalCoors.end(); ++iter)
		{
			//生成几何体
			float x = (*iter)(0) - v(int(c(0, 0)), 0);
			float y = (*iter)(1) - v(int(c(0, 0)), 1);
			float z = (*iter)(2) - v(int(c(0, 0)), 2);
			(*vertices)[i * 8 + 0].set(v(int(c(0, 0)), 0) + x, v(int(c(0, 0)), 1) + y, v(int(c(0, 0)), 2) + z);
			(*vertices)[i * 8 + 1].set(v(int(c(0, 1)), 0) + x, v(int(c(0, 1)), 1) + y, v(int(c(0, 1)), 2) + z);
			(*vertices)[i * 8 + 2].set(v(int(c(0, 2)), 0) + x, v(int(c(0, 2)), 1) + y, v(int(c(0, 2)), 2) + z);
			(*vertices)[i * 8 + 3].set(v(int(c(0, 3)), 0) + x, v(int(c(0, 3)), 1) + y, v(int(c(0, 3)), 2) + z);
			(*vertices)[i * 8 + 4].set(v(int(c(0, 4)), 0) + x, v(int(c(0, 4)), 1) + y, v(int(c(0, 4)), 2) + z);
			(*vertices)[i * 8 + 5].set(v(int(c(0, 5)), 0) + x, v(int(c(0, 5)), 1) + y, v(int(c(0, 5)), 2) + z);
			(*vertices)[i * 8 + 6].set(v(int(c(0, 6)), 0) + x, v(int(c(0, 6)), 1) + y, v(int(c(0, 6)), 2) + z);
			(*vertices)[i * 8 + 7].set(v(int(c(0, 7)), 0) + x, v(int(c(0, 7)), 1) + y, v(int(c(0, 7)), 2) + z);

			(*quadsIndices)[i * 24 + 0] = i * 8 + 0; (*quadsIndices)[i * 24 + 1] = i * 8 + 1; (*quadsIndices)[i * 24 + 2] = i * 8 + 2; (*quadsIndices)[i * 24 + 3] = i * 8 + 3;
			(*quadsIndices)[i * 24 + 4] = i * 8 + 0; (*quadsIndices)[i * 24 + 5] = i * 8 + 3; (*quadsIndices)[i * 24 + 6] = i * 8 + 7; (*quadsIndices)[i * 24 + 7] = i * 8 + 4;
			(*quadsIndices)[i * 24 + 8] = i * 8 + 4; (*quadsIndices)[i * 24 + 9] = i * 8 + 5; (*quadsIndices)[i * 24 + 10] = i * 8 + 6; (*quadsIndices)[i * 24 + 11] = i * 8 + 7;
			(*quadsIndices)[i * 24 + 12] = i * 8 + 1; (*quadsIndices)[i * 24 + 13] = i * 8 + 2; (*quadsIndices)[i * 24 + 14] = i * 8 + 6; (*quadsIndices)[i * 24 + 15] = i * 8 + 5;
			(*quadsIndices)[i * 24 + 16] = i * 8 + 2; (*quadsIndices)[i * 24 + 17] = i * 8 + 3; (*quadsIndices)[i * 24 + 18] = i * 8 + 7; (*quadsIndices)[i * 24 + 19] = i * 8 + 6;
			(*quadsIndices)[i * 24 + 20] = i * 8 + 1; (*quadsIndices)[i * 24 + 21] = i * 8 + 0; (*quadsIndices)[i * 24 + 22] = i * 8 + 4; (*quadsIndices)[i * 24 + 23] = i * 8 + 5;
	
			(*linesIndices)[i * 24 + 0] = i * 8 + 0; (*linesIndices)[i * 24 + 1] = i * 8 + 1; 
			(*linesIndices)[i * 24 + 2] = i * 8 + 1; (*linesIndices)[i * 24 + 3] = i * 8 + 2;
			(*linesIndices)[i * 24 + 4] = i * 8 + 2; (*linesIndices)[i * 24 + 5] = i * 8 + 3; 
			(*linesIndices)[i * 24 + 6] = i * 8 + 3; (*linesIndices)[i * 24 + 7] = i * 8 + 0;
			(*linesIndices)[i * 24 + 8] = i * 8 + 1; (*linesIndices)[i * 24 + 9] = i * 8 + 5; 
			(*linesIndices)[i * 24 + 10] = i * 8 + 5; (*linesIndices)[i * 24 + 11] = i * 8 + 6;
			(*linesIndices)[i * 24 + 12] = i * 8 + 6; (*linesIndices)[i * 24 + 13] = i * 8 + 2; 
			(*linesIndices)[i * 24 + 14] = i * 8 + 6; (*linesIndices)[i * 24 + 15] = i * 8 + 7;
			(*linesIndices)[i * 24 + 16] = i * 8 + 7; (*linesIndices)[i * 24 + 17] = i * 8 + 3;
			(*linesIndices)[i * 24 + 18] = i * 8 + 7; (*linesIndices)[i * 24 + 19] = i * 8 + 4;
			(*linesIndices)[i * 24 + 20] = i * 8 + 4; (*linesIndices)[i * 24 + 21] = i * 8 + 5; 
			(*linesIndices)[i * 24 + 22] = i * 8 + 4; (*linesIndices)[i * 24 + 23] = i * 8 + 0;

			i++;
		}

		geom_QUADS->setVertexArray(vertices.get());
		geom_QUADS->addPrimitiveSet(quadsIndices.get());
		osg::ref_ptr<osg::Vec4Array> quadsColors = new osg::Vec4Array;
		quadsColors->push_back(osg::Vec4(0., 1., 1., 1.));
		geom_QUADS->setColorArray(quadsColors);
		geom_QUADS->setColorBinding(osg::Geometry::BIND_OVERALL);
		osg::ref_ptr<osg::Geode> modelNode = new osg::Geode;
		modelNode->addDrawable(geom_QUADS.get());

		geom_lINES->setVertexArray(vertices.get());
		geom_lINES->addPrimitiveSet(linesIndices.get());
		osg::ref_ptr<osg::Vec4Array> lineColors = new osg::Vec4Array;
		lineColors->push_back(osg::Vec4(0., 0., 0., 1.));
		geom_lINES->setColorArray(lineColors);
		geom_lINES->setColorBinding(osg::Geometry::BIND_OVERALL);
		osg::ref_ptr<osg::Geode> stripNode = new osg::Geode;
		stripNode->addDrawable(geom_lINES.get());
		
		//网格化
		group->addChild(modelNode);
		group->addChild(stripNode);


		/****************************设置上下左右近远六个光源，但是没写阴影*********************************/
		osg::ref_ptr<osg::StateSet> stateset = group->getOrCreateStateSet();
		stateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);
		stateset->setMode(GL_LIGHT6, osg::StateAttribute::ON);	// GL_LIGHT0是默认光源
		// 设置6个光源 解决光照问题                         
		osg::Vec3d ptLight;
		osg::Vec3d ptCenter = osg::Vec3d(0, 0, 0);
		double dDis = 200000.0;
		ptLight = ptCenter + osg::Z_AXIS * dDis;
		osg::ref_ptr<osg::Node> pNodeLight = createLightSource(6, ptLight, -osg::Z_AXIS);
		pNodeLight->setName("light0");
		group->addChild(pNodeLight);
		
		//设置网格线宽
		osg::ref_ptr<osg::StateSet> state = stripNode->getOrCreateStateSet();
		osg::ref_ptr<osg::LineWidth> lineWid = new osg::LineWidth(4.0f);
		state->setAttribute(lineWid.get());
		model->addChild(group);
		//显示自适应模型大小
		osgWidget->view->getCameraManipulator()->computeHomePosition();
		osgWidget->view->getCameraManipulator()->home(0.0);
	}
	else
	{
		QMessageBox::information(NULL, QString("警告"), QString("数据不足"));
	}
}

//void TopoOptimizeWidget::addTangentPlane()
//{
//	Function function;
//	function.genPlaneCoordinateSystem();
//}
//
void TopoOptimizeWidget::addArrow0()
{
	QString inputText = loadSet_3D->uiLoadSet_3D->lineEdit_x0->text();
	double x = inputText.toDouble();
	QString inputText2 = loadSet_3D->uiLoadSet_3D->lineEdit_y0->text();
	double y = inputText2.toDouble();
	QString inputText3 = loadSet_3D->uiLoadSet_3D->lineEdit_z0->text();
	double z = inputText3.toDouble();
	osg::Vec3 input(x, y, z);
	//function.genPlaneCoordinateSystem();
	CreatArrow(arrow, startPoint, input);

	QString text = QString("在坐标(%1,%2,%3)处插入向量(%4,%5,%6)")
		.arg(startPoint.x(), 0, 'f', 2).arg(startPoint.y(), 0, 'f', 2).arg(startPoint.z(), 0, 'f', 2)
		.arg(input.x()).arg(input.y()).arg(input.z());
	loadSet_3D->uiLoadSet_3D->listWidget->addItem(text);
}
//
//
//void TopoOptimizeWidget::add2DArrow()
//{
//	Function function;
//	QString inputText = loadSetWidget->uiLoadSet->lineEdit->text();
//	double x = inputText.toDouble();
//	QString inputText2 = loadSetWidget->uiLoadSet->lineEdit_2->text();
//	double y = inputText2.toDouble();
//	double z = 0;
//	osg::Vec3 input(x, y, z);
//	function.genArrow(input);
//
//	QString text = QString("在坐标(%1,%2,%3)处插入向量(%4,%5,%6)")
//		.arg(startPoint.x(), 0, 'f', 2).arg(startPoint.y(), 0, 'f', 2)
//		.arg(input.x()).arg(input.y());
//	loadSetWidget->uiLoadSet->listWidget->addItem(text);
//}
//
//void TopoOptimizeWidget::delArrow()
//{
//	Function function;
//	function.deleteArrow();
//
//	QString text = QString("在坐标(%1,%2,%3)处删除向量")
//		.arg(startPoint.x(), 0, 'f', 2).arg(startPoint.y(), 0, 'f', 2).arg(startPoint.z(), 0, 'f', 2);
//	loadSet_3D->uiLoadSet_3D->listWidget->addItem(text);
//}
//
//void TopoOptimizeWidget::del2DArrow()
//{
//	Function function;
//	function.deleteArrow();
//
//	QString text = QString("在坐标(%1,%2,%3)处删除向量")
//		.arg(startPoint.x(), 0, 'f', 2).arg(startPoint.y(), 0, 'f', 2);
//	loadSetWidget->uiLoadSet->listWidget->addItem(text);
//}

void TopoOptimizeWidget::VectorDieldDriven_SurfaceMesh_on_ImportTriMesh_push()
{
	fileRoute = QFileDialog::getOpenFileName(this, QStringLiteral("Please Select File"), "D:", QStringLiteral("textfile(*stl)"));
	osgDB::Options* option = new osgDB::Options(std::string("noTriStripPolygons"));
	osg::ref_ptr<osg::Node> stl = osgDB::readNodeFile(fileRoute.toStdString(), option);
	//osg::ref_ptr<osg::Node> stl = osgDB::readNodeFile("./data/cow.osg");
	// 创建材质对象
	osg::Material* mat = new osg::Material();
	mat->setColorMode(osg::Material::ColorMode::DIFFUSE);   // 设置绘制颜色的模式 
	mat->setDiffuse(osg::Material::FRONT, osg::Vec4(0,1,1,1));      // 设置此种模式下的颜色 
	stl->getOrCreateStateSet()->setAttribute(mat);
	osg::ref_ptr<osgFX::Scribe> scribe = new osgFX::Scribe;
	scribe->setWireframeColor(osg::Vec4f(0, 0, 0, 1.0));
	scribe->addChild(stl);
	model->addChild(scribe);
	osgWidget->getBestView();
}