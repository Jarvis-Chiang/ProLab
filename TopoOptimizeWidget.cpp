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
	interpolation(new Interpolation),
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
	//��ʼ����־����
	LogText->setReadOnly(true);

	//�Ҳ��������ջ����
	/********************************�ṹ�Ż��Ҳ����************************************/
	oprStackWidget->addWidget(designZoneWidget);//QStackedWidget����addWidget������ֻ�����ڱ�׼ָ�룬Qt����ָ�벻��//0
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

	//�����״�ṹ����0
	treeWidget1->setColumnCount(1); //��������
	treeWidget1->setHeaderLabel(QString("2D���˽ṹ��"));

	QTreeWidgetItem* tree1_0 = new QTreeWidgetItem(treeWidget1, QStringList(QString("2D�����")));
	QTreeWidgetItem* tree1_1 = new QTreeWidgetItem(treeWidget1, QStringList(QString("��������")));
	QTreeWidgetItem* tree1_2 = new QTreeWidgetItem(treeWidget1, QStringList(QString("2D�߽�����")));
	QTreeWidgetItem* tree1_3 = new QTreeWidgetItem(treeWidget1, QStringList(QString("2D�غ�����")));
	QTreeWidgetItem* tree1_4 = new QTreeWidgetItem(treeWidget1, QStringList(QString("2D�Ż�����")));
	QTreeWidgetItem* tree1_5 = new QTreeWidgetItem(treeWidget1, QStringList(QString("����鿴")));
	treeWidget1->expandAll();

	//�����״�ṹ����1
	treeWidget2->setColumnCount(1); //��������
	treeWidget2->setHeaderLabel(QString("3D���˽ṹ��"));

	QTreeWidgetItem* tree2_0 = new QTreeWidgetItem(treeWidget2, QStringList(QString("3D�����")));
	QTreeWidgetItem* tree2_1 = new QTreeWidgetItem(treeWidget2, QStringList(QString("��������")));
	QTreeWidgetItem* tree2_2 = new QTreeWidgetItem(treeWidget2, QStringList(QString("3D�߽�����")));
	QTreeWidgetItem* tree2_3 = new QTreeWidgetItem(treeWidget2, QStringList(QString("3D�غ�����")));
	QTreeWidgetItem* tree2_4 = new QTreeWidgetItem(treeWidget2, QStringList(QString("3D�Ż�����")));
	QTreeWidgetItem* tree2_5 = new QTreeWidgetItem(treeWidget2, QStringList(QString("����鿴")));
	treeWidget2->expandAll();

	//�����״�ṹ����2����������·����
	treeWidget3->setColumnCount(2); //��������
	QStringList strlist;
	strlist << "��Ŀ"  << "λ������" /*<< "��̬����"*/;
	treeWidget3->setHeaderLabels(strlist);
	treeWidget3->header()->setSectionResizeMode(QHeaderView::Stretch);
	treeWidget3->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
	QTreeWidgetItem* tree3_0 = new QTreeWidgetItem(treeWidget3, QStringList(QString("��������(��������·��)")));
	QTreeWidgetItem* tree3_1 = new QTreeWidgetItem(treeWidget3, QStringList(QString("����(��������·��)")));
	QTreeWidgetItem* tree3_2 = new QTreeWidgetItem(treeWidget3, QStringList(QString("·������(��������·��)")));
	treeWidget3->expandAll();

	//��״�ṹ����3��ƫ��·����
	treeWidget4->setColumnCount(1); //��������
	treeWidget4->setHeaderLabel(QString("ƫ��·���ṹ��"));
	QTreeWidgetItem* tree4_0 = new QTreeWidgetItem(treeWidget4, QStringList(QString("��������(ƫ��·��)")));
	QTreeWidgetItem* tree4_1 = new QTreeWidgetItem(treeWidget4, QStringList(QString("·������(ƫ��·��)")));
	treeWidget4->expandAll();

	//��״�ṹ����4���ݶ����·����
	treeWidget5->setColumnCount(1); //��������
	treeWidget5->setHeaderLabel(QString("�ݶ����·���ṹ��"));
	QTreeWidgetItem* tree5_0 = new QTreeWidgetItem(treeWidget5, QStringList(QString("��������(�ݶ����·��)")));
	QTreeWidgetItem* tree5_1 = new QTreeWidgetItem(treeWidget5, QStringList(QString("·������(�ݶ����·��)")));
	treeWidget5->expandAll();

	//��״�ṹ����5����׼�淨������Ƭ��
	treeWidget6->setColumnCount(1); //��������
	treeWidget6->setHeaderLabel(QString("��׼�淨������Ƭ�ṹ��"));
	QTreeWidgetItem* tree6_0 = new QTreeWidgetItem(treeWidget6, QStringList(QString("ģ������(��׼�淨)")));
	QTreeWidgetItem* tree6_1 = new QTreeWidgetItem(treeWidget6, QStringList(QString("��ӡ��(��׼�淨)")));
	QTreeWidgetItem* tree6_2 = new QTreeWidgetItem(treeWidget6, QStringList(QString("��׼��")));
	QTreeWidgetItem* tree6_3 = new QTreeWidgetItem(treeWidget6, QStringList(QString("������Ƭ(��׼�淨)")));
	QTreeWidgetItem* tree6_4 = new QTreeWidgetItem(treeWidget6, QStringList(QString("·���滮(��׼�淨)")));
	treeWidget6->expandAll();

	//��״�ṹ����6�����򳡷�������Ƭ��
	treeWidget7->setColumnCount(1); //��������
	treeWidget7->setHeaderLabel(QString("���򳡷�������Ƭ�ṹ��"));
	QTreeWidgetItem* tree7_0 = new QTreeWidgetItem(treeWidget7, QStringList(QString("ģ������(���򳡷�)")));
	QTreeWidgetItem* tree7_1 = new QTreeWidgetItem(treeWidget7, QStringList(QString("��ӡ��(���򳡷�)")));
	QTreeWidgetItem* tree7_2 = new QTreeWidgetItem(treeWidget7, QStringList(QString("����")));
	QTreeWidgetItem* tree7_3 = new QTreeWidgetItem(treeWidget7, QStringList(QString("������Ƭ(���򳡷�)")));
	QTreeWidgetItem* tree7_4 = new QTreeWidgetItem(treeWidget7, QStringList(QString("·���滮(���򳡷�)")));
	treeWidget7->expandAll();

	//�����״�ṹ����7(����Ԫ2D����)
	treeWidget8->setColumnCount(1); //��������
	treeWidget8->setHeaderLabel(QString("2D����Ԫ����"));

	QTreeWidgetItem* tree8_0 = new QTreeWidgetItem(treeWidget8, QStringList(QString("2Dģ������")));
	QTreeWidgetItem* tree8_1 = new QTreeWidgetItem(treeWidget8, QStringList(QString("2D��������")));
	QTreeWidgetItem* tree8_2 = new QTreeWidgetItem(treeWidget8, QStringList(QString("2D�߽�����������Ԫ��")));
	QTreeWidgetItem* tree8_3 = new QTreeWidgetItem(treeWidget8, QStringList(QString("2D�غ����ã�����Ԫ��")));
	QTreeWidgetItem* tree8_4 = new QTreeWidgetItem(treeWidget8, QStringList(QString("2D�������")));
	QTreeWidgetItem* tree8_5 = new QTreeWidgetItem(treeWidget8, QStringList(QString("2D����鿴������Ԫ��")));
	treeWidget8->expandAll();

	//�����״�ṹ����8��3D����Ԫ������
	treeWidget9->setColumnCount(1); //��������
	treeWidget9->setHeaderLabel(QString("2D���˽ṹ��"));

	QTreeWidgetItem* tree9_0 = new QTreeWidgetItem(treeWidget9, QStringList(QString("3Dģ������")));
	QTreeWidgetItem* tree9_1 = new QTreeWidgetItem(treeWidget9, QStringList(QString("3D��������")));
	QTreeWidgetItem* tree9_2 = new QTreeWidgetItem(treeWidget9, QStringList(QString("3D�߽�����������Ԫ��")));
	QTreeWidgetItem* tree9_3 = new QTreeWidgetItem(treeWidget9, QStringList(QString("3D�غ����ã�����Ԫ��")));
	QTreeWidgetItem* tree9_4 = new QTreeWidgetItem(treeWidget9, QStringList(QString("3D�������")));
	QTreeWidgetItem* tree9_5 = new QTreeWidgetItem(treeWidget9, QStringList(QString("3D����鿴������Ԫ��")));
	treeWidget9->expandAll();

	//�����״�ṹ��ջ����
	treeStackWidget->addWidget(treeWidget1);
	treeStackWidget->addWidget(treeWidget2);
	treeStackWidget->addWidget(treeWidget3);
	treeStackWidget->addWidget(treeWidget4);
	treeStackWidget->addWidget(treeWidget5);
	treeStackWidget->addWidget(treeWidget6);
	treeStackWidget->addWidget(treeWidget7);
	treeStackWidget->addWidget(treeWidget8);
	treeStackWidget->addWidget(treeWidget9);

	//��ʾ�ṹ��ʼ��
	root->addChild(model.get());
	root->addChild(arrow.get());
	root->addChild(gridVec.get());

	//model->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);//ģ��ʼ�շ������ʹر�ģ�ͽڵ�Ĺ�������
	gridVec->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);//ģ��ʼ�շ������ʹر�ģ�ͽڵ�Ĺ�������
}

void TopoOptimizeWidget::creatAction()
{
	//���ṹ�Ͷ�ջ���ڹ���
	connect(treeWidget1, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget2, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget3, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget4, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget5, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget6, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget7, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget8, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget9, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));

	//�ļ���ȡ�Ի���
	connect(designZoneWidget->uiDesignZone->importDesignGridButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));
	connect(materialSetWidget->uiMaterialSet->importElasticityMatrixButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));

	connect(vectorDieldDriven_SurfaceMesh->uiSurfaceMesh->pushButton_ImportTriMesh, &QPushButton::clicked, this, &TopoOptimizeWidget::VectorDieldDriven_SurfaceMesh_on_ImportTriMesh_push);
	connect(vectorDieldDriven_VecField->uiVecField->pushButton_ImportCtrlPntsField, SIGNAL(clicked()), this, SLOT(VectorDieldDriven_VectorField_on_ImportCtrlPntsField_push()));
	connect(vectorDieldDriven_VecField->uiVecField->pushButton_AddCtrlPnt, SIGNAL(clicked()), this, SLOT(VectorDieldDriven_VectorField_on_AddCtrlPnt_push()));
	connect(vectorDieldDriven_VecField->uiVecField->pushButton_ExprtAnchorField, SIGNAL(clicked()), this, SLOT(VectorDieldDriven_VectorField_on_ExprtAnchorField_push()));
	connect(vectorDieldDriven_SurfaceMesh->uiSurfaceMesh->pushButton_clear, &QPushButton::clicked, this, &TopoOptimizeWidget::VectorDieldDriven_VectorField_on_ClearMesh_push);
	connect(vectorDieldDriven_VecField->uiVecField->pushButton_ClearCtrlPnts, &QPushButton::clicked, this, &TopoOptimizeWidget::VectorDieldDriven_VectorField_on_ClearCtrlPnts_push);
	connect(treeWidget3, &QTreeWidget::itemClicked, this, &TopoOptimizeWidget::VectorDieldDriven_VectorField_on_VecItem_clicked);
	connect(vectorDieldDriven_VecField->uiVecField->pushButton_GeneFromCtrlPnt, &QPushButton::clicked, this, &TopoOptimizeWidget::VectorDieldDriven_VectorField_on_GenerateFromCtrlPnts_clicked);
	connect(vectorDieldDriven_VecField->uiVecField->pushButton_ImportVecField, &QPushButton::clicked, this, &TopoOptimizeWidget::VectorDieldDriven_VectorField_on_ImportVecField_push);
	connect(vectorDieldDriven_VecField->uiVecField->pushButton_ExprtVecField, &QPushButton::clicked, this, &TopoOptimizeWidget::VectorDieldDriven_VectorField_on_ExprtVecField_push);
	connect(vectorDieldDriven_VecField->uiVecField->pushButton_ClearVecField, &QPushButton::clicked, this, &TopoOptimizeWidget::VectorDieldDriven_VectorField_on_ClearVecField_push);
	connect(vectorDieldDriven_VecField->uiVecField->checkBox_AnF, &QCheckBox::stateChanged, this, &TopoOptimizeWidget::VectorDieldDriven_VectorField_on_CHeckBoxAnF_push);
	connect(vectorDieldDriven_VecField->uiVecField->checkBox_VecF, &QCheckBox::stateChanged, this, &TopoOptimizeWidget::VectorDieldDriven_VectorField_on_CHeckBoxVecF_push);
	connect(vectorDieldDriven_VecField->uiVecField->checkBox_TriModel, &QCheckBox::stateChanged, this, &TopoOptimizeWidget::VectorDieldDriven_VectorField_on_CHeckBoxTriModel_push);
	connect(vectorDieldDriven_VecField->uiVecField->horizontalSlider, &QSlider::valueChanged, this, &TopoOptimizeWidget::VectorDieldDriven_VectorField_on_Slider_changed);

	connect(designZone_3D->uiDesignZone_3d->generateButton, SIGNAL(clicked()), this, SLOT(generate3dDesignZone()));
	connect(designZoneWidget->uiDesignZone->generateButton, SIGNAL(clicked()), this, SLOT(generate2dDesignZone()));
	connect(loadSet_3D->uiLoadSet_3D->pushButton_add, SIGNAL(clicked()), this, SLOT(addArrow0()));

	//qt��osg����
	connect(osgWidget->addLinePointHandler, &AddLinePointHandler::HavePicked, this, &TopoOptimizeWidget::on_HavePicked);
	connect(osgWidget->addLinePointHandler, &AddLinePointHandler::DragEnd, this, &TopoOptimizeWidget::on_DragEnd);
	connect(osgWidget->addLinePointHandler, &AddLinePointHandler::SurfPicked, this, &TopoOptimizeWidget::on_SurfPicked);
	connect(osgWidget->addLinePointHandler, &AddLinePointHandler::getBestView, [=]() { osgWidget->getBestView(); });

	//TreWidgetItem�źŲ�
}
//osgwidget
OsgWidget::OsgWidget(QWidget* parent, Qt::WindowFlags f, osgViewer::ViewerBase::ThreadingModel threadingModel) :
	view(new osgViewer::Viewer),
	addLinePointHandler(new AddLinePointHandler)
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

	camera->setClearColor(osg::Vec4(0.2, 0.2, 0.6, 1));
	camera->setViewport(new osg::Viewport(0, 0, traits->width, traits->height));
	camera->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(traits->width) / static_cast<double>(traits->height), 1.0f, 10000.0f);

	view->setSceneData(root);
	view->addEventHandler(new osgViewer::StatsHandler);
	view->addEventHandler(new osgGA::StateSetManipulator(camera->getOrCreateStateSet()));
	//view->addEventHandler(new osgGA::StateSetManipulator(view->getCamera()->getOrCreateStateSet()));
	view->addEventHandler(addLinePointHandler);
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


//���������ui
DesignZoneWidget::DesignZoneWidget() :
	uiDesignZone(new Ui::DesignZoneWidget)
{
	uiDesignZone->setupUi(this);
}

DesignZoneWidget :: ~DesignZoneWidget()
{
	delete uiDesignZone;
}

//����3D�����
DesignZone_3D::DesignZone_3D():
	uiDesignZone_3d(new Ui::DesignZoneWidget_3D)
{
	uiDesignZone_3d->setupUi(this);
}

DesignZone_3D::~DesignZone_3D()
{
	delete uiDesignZone_3d;
}

//���ز�����������ui
MaterialSetWidget::MaterialSetWidget():
	uiMaterialSet(new Ui::MeterialSetWidget),
	radioButtons(new QButtonGroup)
{
	uiMaterialSet->setupUi(this);

	//���ø���ͬ��/�������԰�ť����
	radioButtons->addButton(uiMaterialSet->sameButton);
	radioButtons->addButton(uiMaterialSet->differentButton);
	radioButtons->setExclusive(true);
	//����Ĭ��
	uiMaterialSet->sameButton->setChecked(true);

	//��������
	//���ϸ���ͬ��/��������ѡ��
	connect(uiMaterialSet->sameButton, SIGNAL(stateChanged(int)), this, SLOT(sameButton(int)));
	connect(uiMaterialSet->differentButton, SIGNAL(stateChanged(int)), this, SLOT(diffButton(int)));
	
}

MaterialSetWidget::~MaterialSetWidget()
{
	delete uiMaterialSet;
}

//���ر߽�����ui

BoundaryCasesWidget::BoundaryCasesWidget():
	uiBoundaryCases(new Ui::BoundaryCasesWidget)
{
	uiBoundaryCases->setupUi(this);
}

BoundaryCasesWidget::~BoundaryCasesWidget()
{
	delete uiBoundaryCases;
}

//����3D�߽�����ui
BoundaryCases_3D::BoundaryCases_3D() :
	uiBoundaryCases_3D(new Ui::BoundaryCasesWidget_3D)
{
	uiBoundaryCases_3D->setupUi(this);
}

BoundaryCases_3D::~BoundaryCases_3D()
{
	delete uiBoundaryCases_3D;
}

//�����غ�����ui
LoadSetWidget::LoadSetWidget():
	uiLoadSet(new Ui::LoadSetWidget)
{
	uiLoadSet->setupUi(this);
}

LoadSetWidget::~LoadSetWidget()
{
	delete uiLoadSet;
}

//����3D�غ�����ui
LoadSet_3D::LoadSet_3D() :
	uiLoadSet_3D(new Ui::LoadSetWidget_3D)
{
	uiLoadSet_3D->setupUi(this);
}

LoadSet_3D::~LoadSet_3D()
{
	delete uiLoadSet_3D;
}

//���ز����Ż�ui
OptimizeParaWidget::OptimizeParaWidget():
	uiOptimizePara(new Ui::OptimizeParaWidget)
{
	uiOptimizePara->setupUi(this);
}

OptimizeParaWidget::~OptimizeParaWidget()
{
	delete uiOptimizePara;
}

//����3D�����Ż�ui
OptimizePara_3D::OptimizePara_3D() :
	uiOptimizePara_3D(new Ui::OptimizeParaWidget_3D)
{
	uiOptimizePara_3D->setupUi(this);
}

OptimizePara_3D::~OptimizePara_3D()
{
	delete uiOptimizePara_3D;
}

//���ؽ���鿴ui
ResultCheckWidget::ResultCheckWidget():
	uiRecultCheck(new Ui:: ResultCheckWidget)
{
	uiRecultCheck->setupUi(this);
}

ResultCheckWidget::~ResultCheckWidget()
{
	delete uiRecultCheck;
}

//2D��������ɺ���
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

//3D��������ɺ���
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


osg::ref_ptr<ArrowShape> TopoOptimizeWidget::CreatArrow(osg::ref_ptr<osg::Group> root_t, const osg::Vec3& startPoint_1, const osg::Vec3& direction)
{

	osg::ref_ptr<ArrowShape> arrowShape = new ArrowShape(direction, startPoint_1);

	vectorField.push_back(&(arrowShape->vector_Data));

	// ���任�ڵ���ӵ���ͷ�ĸ��ڵ���
	root_t->addChild(arrowShape);

	return arrowShape;
}

HUDAxis::HUDAxis()
{
	//��������ֱ�Ӷ�ȡaxes.osgt;
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
	//this->setProjectionMatrixAsOrtho(-10.0*aspectRatio, 10.0*aspectRatio, -10.0, 10.0, 2.0, -2.0); //����ͶӰ����ʹ���Ų���Ч��
	this->setProjectionMatrixAsOrtho2D(-10.0 * aspectRatio, 10.0 * aspectRatio, -10.0, 10.0);
	osg::Vec3 trans(8.5 * aspectRatio, -8.5, -8.0);
	if (_mainCamera.valid() && nv.getVisitorType() == osg::NodeVisitor::CULL_VISITOR)
	{
		osg::Matrix matrix = _mainCamera->getViewMatrix();//�ı���ͼ�������ƶ�λ�ù̶�
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
	hudAxes->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);//ģ��ʼ�շ������ʹر�ģ�ͽڵ�Ĺ�������
	root->addChild(hudAxes);//�ӽڵ�2
}

osg::ref_ptr<osg::Node> TopoOptimizeWidget::makeCoordinate()
{
	osg::ref_ptr<osg::Node> axes = osgDB::readNodeFile("./third_part/axes.osgt");

	return axes;
}



ArrowShape::ArrowShape( osg::Vec3 direction, osg::Vec3 strtPnt) : 
ot(new osgFX::Outline),
mDragger(new osgManipulator::TrackballDragger()),
treeLabel(new QTreeWidgetItem(QString("ê������%1").arg(arrow->getNumChildren()).split(","))),
vector_Data({ strtPnt.x(), strtPnt.y(), strtPnt.z(), direction.x(), direction.y(), direction.z() }),
mSelection(new osgManipulator::Selection()),
Pos(new QLineEdit)
{
	length = direction.length();
	QTtoOSG_Link[treeLabel] = this;
	Pos->setReadOnly(true);
	Pos->setStyleSheet("background-color:Qt::RGB(230,230,0);");
	Pos->setText(QString("(%1, %2, %3)")
		.arg(strtPnt.x()).arg(strtPnt.y()).arg(strtPnt.z()));

	double radius = direction.length()/15;
	double height = direction.length() * 2;
	double coneRadius = direction.length()/10;
	double coneHeight = direction.length()/5;

	osg::ref_ptr<osg::Cone> cone = new osg::Cone(osg::Vec3(0.0f, 0.0f, height), coneRadius, coneHeight);
	osg::ref_ptr<osg::ShapeDrawable> coneDrawable = new osg::ShapeDrawable(cone.get());
	coneDrawable->setColor(osg::Vec4(1, 0, 0, 1));

	osg::ref_ptr<osg::Cylinder> cylinder = new osg::Cylinder(osg::Vec3(0.0f, 0.0f, 0.5 * height), radius, height);
	osg::ref_ptr<osg::ShapeDrawable> cylinderDrawable = new osg::ShapeDrawable(cylinder.get());
	cylinderDrawable->setColor(osg::Vec4(1, 0, 0, 1));

	// �����任�ڵ㣬����Բ����Բ׶�ļ�������ӵ��任�ڵ���
	osg::ref_ptr<osg::PositionAttitudeTransform> arrowTransform = new osg::PositionAttitudeTransform;
	osg::ref_ptr<osg::Geode> geo = new osg::Geode;
	geo->addChild(coneDrawable.get());
	geo->addChild(cylinderDrawable.get());
	arrowTransform->addChild(geo);
	mSelection->addChild(arrowTransform);
	addChild(mSelection);

	// ���ñ任�ڵ��λ�úͷ���
	arrowTransform->setPosition(strtPnt);
	osg::Vec3 normalizedDirection = direction;
	normalizedDirection.normalize();
	osg::Quat rotation;
	rotation.makeRotate(osg::Vec3(0, 0, 1), normalizedDirection);
	arrowTransform->setAttitude(rotation);

	//��ק��������������
	float scale = arrowTransform->getBound().radius() * 0.8;
	mDragger->setMatrix(osg::Matrix::scale(scale, scale, scale) * osg::Matrix::rotate(rotation) * osg::Matrix::translate(strtPnt));
	mDragger->setupDefaultGeometry();

	mShape = geo;
	mTrans = arrowTransform;

	ot->setColor(osg::Vec4(0.0, 1.0, 0.0, 1.0));
	ot->setWidth(1.0);
}

void ArrowShape::EnableDragger()
{
	addChild(mDragger);
	mDragger->addTransformUpdating(mSelection);
	mDragger->setHandleEvents(true);
}

void ArrowShape::DisableDragger()
{
	removeChild(mDragger);
	mDragger->removeTransformUpdating(mSelection);
	mDragger->setHandleEvents(false);
}

void ArrowShape::UpdateDragger(osg::Quat attitude, osg::Vec3 position)
{
	float scale = mShape->getBound().radius() * 0.8;
	mDragger->setMatrix(osg::Matrix::scale(scale, scale, scale) * osg::Matrix::rotate(attitude) * osg::Matrix::translate(position));
}

void ArrowShape::setData(osg::Vec3 position, osg::Quat rotation)
{
	osg::Matrix rotationMatrix;
	rotationMatrix.makeRotate(rotation);
	osg::Vec3 transformedZAxis = osg::Vec3(0, 0, 1) * rotationMatrix * length;
	vector_Data = { position.x(), position.y(), position.z(), transformedZAxis.x(), transformedZAxis.y(), transformedZAxis.z() };
}

void ArrowShape::EnableHighLight()
{
	if (!isHighLighted)
	{
		ot->addChild(mShape);
		mTrans->removeChild(mShape);
		mTrans->addChild(ot);
		isHighLighted = true;
	}
}

void ArrowShape::DisableHighLight()
{
	if (isHighLighted)
	{
		mTrans->removeChild(ot);
		mTrans->addChild(mShape);
		isHighLighted = false;
	}
}
//****************����Ϊ�ۺ���*********************//

void TopoOptimizeWidget::stackedWidgetPageChange(QTreeWidgetItem* item, int column)
{
	if (item->text(column) == "2D�����")//?????????????
		oprStackWidget->setCurrentIndex(0);

	if (item->text(column) == "��������")
		oprStackWidget->setCurrentIndex(1);

	if (item->text(column) == "2D�߽�����")
		oprStackWidget->setCurrentIndex(2);

	if (item->text(column) == "2D�غ�����")
		oprStackWidget->setCurrentIndex(3);

	if (item->text(column) == "2D�Ż�����")
		oprStackWidget->setCurrentIndex(4);

	if (item->text(column) == "����鿴")
		oprStackWidget->setCurrentIndex(5);

	if (item->text(column) == "3D�����")
		oprStackWidget->setCurrentIndex(6);

	if (item->text(column) == "3D�߽�����")
		oprStackWidget->setCurrentIndex(7);

	if (item->text(column) == "3D�غ�����")
		oprStackWidget->setCurrentIndex(8);

	if (item->text(column) == "3D�Ż�����")
		oprStackWidget->setCurrentIndex(9);

	if (item->text(column) == "��������(��������·��)")
		oprStackWidget->setCurrentIndex(11);

	if (item->text(column) == "����(��������·��)")
		oprStackWidget->setCurrentIndex(12);

	if (item->text(column) == "·������(��������·��)")
		oprStackWidget->setCurrentIndex(10);

	if (item->text(column) == "��������(ƫ��·��)")
		oprStackWidget->setCurrentIndex(13);

	if (item->text(column) == "·������(ƫ��·��)")
		oprStackWidget->setCurrentIndex(14);

	if (item->text(column) == "��������(�ݶ����·��)")
		oprStackWidget->setCurrentIndex(15);

	if (item->text(column) == "·������(�ݶ����·��)")
		oprStackWidget->setCurrentIndex(16);

	if (item->text(column) == "ģ������(��׼�淨)")
		oprStackWidget->setCurrentIndex(17);

	if (item->text(column) == "��ӡ��(��׼�淨)")
		oprStackWidget->setCurrentIndex(18);

	if (item->text(column) == "��׼��")
		oprStackWidget->setCurrentIndex(19);

	if (item->text(column) == "������Ƭ(��׼�淨)")
		oprStackWidget->setCurrentIndex(20);

	if (item->text(column) == "·���滮(��׼�淨)")
		oprStackWidget->setCurrentIndex(21);

	if (item->text(column) == "ģ������(���򳡷�)")
		oprStackWidget->setCurrentIndex(22);

	if (item->text(column) == "��ӡ��(���򳡷�)")
		oprStackWidget->setCurrentIndex(23);

	if (item->text(column) == "����")
		oprStackWidget->setCurrentIndex(24);

	if (item->text(column) == "������Ƭ(���򳡷�)")
		oprStackWidget->setCurrentIndex(25);

	if (item->text(column) == "·���滮(���򳡷�)")
		oprStackWidget->setCurrentIndex(26);

	if (item->text(column) == "2Dģ������")
		oprStackWidget->setCurrentIndex(27);

	if (item->text(column) == "2D��������")
		oprStackWidget->setCurrentIndex(28);

	if (item->text(column) == "2D�߽�����������Ԫ��")
		oprStackWidget->setCurrentIndex(29);

	if (item->text(column) == "2D�غ����ã�����Ԫ��")
		oprStackWidget->setCurrentIndex(30);

	if (item->text(column) == "2D�������")
		oprStackWidget->setCurrentIndex(31);

	if (item->text(column) == "2D����鿴������Ԫ��")
		oprStackWidget->setCurrentIndex(32);

	if (item->text(column) == "3Dģ������")
		oprStackWidget->setCurrentIndex(33);

	if (item->text(column) == "3D��������")
		oprStackWidget->setCurrentIndex(34);

	if (item->text(column) == "3D�߽�����������Ԫ��")
		oprStackWidget->setCurrentIndex(35);

	if (item->text(column) == "3D�غ����ã�����Ԫ��")
		oprStackWidget->setCurrentIndex(36);

	if (item->text(column) == "3D�������")
		oprStackWidget->setCurrentIndex(37);

	if (item->text(column) == "3D����鿴������Ԫ��")
		oprStackWidget->setCurrentIndex(38);
}

//������е�������������ļ���Ӧ��ѡ���ļ�·���Ի���
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
//��Coors���ô��ζ��ڴ���Ѻã�֮���Ż�������Կ���һ�£���������������������������������
{

	if (unPickedCoors.size() == 1)
		//���ֻ��һ��Ԫ��?????????????????????
		PickCoors = unPickedCoors;
	else
	{
		//�����β����ֵ
		if (!PickCoors.empty())
			PickCoors.clear();
		PickCoors.push_back(*unPickedCoors.begin());
		PickCoors.push_back(*(--unPickedCoors.end()));
	}
	//����ο�����ֵ��Ŀǰ��������ģ��û�а취���ԣ���ʦ��Ҫģ���Ż�����������������������������������
}

void TopoOptimizeWidget::getShellVoxel(V v, C c, CoorSet& finalCoors)
{
	//v/c��������������û�п��ǣ����Ż���������������������������������������������
	std::set<float> xCoorSet;
	std::set<float> yCoorSet;
	std::set<float> zCoorSet;
	CoorSet firstCoors;
	CoorSet secondCoors;
	//V v_new; //���º��v
	//C c_new; //���º��c
	CoorSet tempPickedCoors;

	//��ȡ���е�x��y��z����ֵ
	for (int i = 0; i < c.rows(); ++i)
	{
		xCoorSet.insert(v(int(c(i, 0)), 0));
		yCoorSet.insert(v(int(c(i, 0)), 1));
		zCoorSet.insert(v(int(c(i, 0)), 2));
	}


	for (auto xiter = xCoorSet.begin(); xiter != xCoorSet.end(); ++xiter)
		//ȷ��Ҫѡ���Ĵ�ֱ��x=*xiterƽ���*xiterֵ
	{
		firstCoors.clear();
		for (int i = 0; i < c.rows(); ++i)
		{
			if (v(int(c(i, 0)), 0) == *xiter)
				//�������еĵ㣬���ҵ�x������*xiter��ֵͬ�����е㣬
				//������Ӧ�ĵ��������浽coors���嵽��x = *xiter��
				firstCoors.push_back(v.row(int(c(i, 0))));
		}
		for (auto yiter = yCoorSet.begin(); yiter != yCoorSet.end(); ++yiter)
			//ȷ��Ҫѡ���Ĵ�ֱ��y=*yiterƽ���*yiterֵ
		{
			if (!secondCoors.empty())
				secondCoors.clear();
			for (auto firstPickedCoor : firstCoors)
			{
				if (firstPickedCoor(1) == *yiter)
					//����coors�����еĵ㣬���ҵ�y������*yiter��ֵͬ�����е㣬
					//������Ӧ�ĵ��������浽secondCoors���浽�� x = *xiter && y = *yiter��
					secondCoors.push_back(firstPickedCoor);
			}
			//��secondCoors�еĵ���������z�����С��������
			std::sort(secondCoors.begin(), secondCoors.end(), cmpAixsZ);
			pickSurfaceCoors(secondCoors, tempPickedCoors);
			finalCoors.insert(finalCoors.end(), tempPickedCoors.begin(), tempPickedCoors.end());
			//û��ȥ�أ�����������������������
		}

		for (auto ziter = zCoorSet.begin(); ziter != zCoorSet.end(); ++ziter)
			//ȷ��Ҫѡ���Ĵ�ֱ��z=*ziterƽ���*ziterֵ
		{
			if (!secondCoors.empty())
				secondCoors.clear();
			for (auto firstPickedCoor : firstCoors)
			{
				if (firstPickedCoor(2) == *ziter)
					//����coors�����еĵ㣬���ҵ�z������*ziter��ֵͬ�����е㣬
					//������Ӧ�ĵ��������浽secondCoors���浽�� x = *xiter && z = *ziter��
					secondCoors.push_back(firstPickedCoor);
			}
			//��secondCoors�еĵ���������y�����С��������
			std::sort(secondCoors.begin(), secondCoors.end(), cmpAixsY);
			pickSurfaceCoors(secondCoors, tempPickedCoors);
			finalCoors.insert(finalCoors.end(), tempPickedCoors.begin(), tempPickedCoors.end());
			//û��ȥ�أ�����������������������
		}
	}

	

	for (auto yiter = yCoorSet.begin(); yiter != yCoorSet.end(); ++yiter)
		//ȷ��Ҫѡ���Ĵ�ֱ��y=*yiterƽ���*yiterֵ
	{
		firstCoors.clear();
		for (int i = 0; i < c.rows(); ++i)
		{
			if (v(int(c(i, 0)), 1) == *yiter)
				//�������еĵ㣬���ҵ�y������*yiter��ֵͬ�����е㣬
				//������Ӧ�ĵ��������浽firstCoors���嵽��y = *yiter��
				firstCoors.push_back(v.row(int(c(i, 0))));
		}
		for (auto ziter = zCoorSet.begin(); ziter != zCoorSet.end(); ++ziter)
			//ȷ��Ҫѡ���Ĵ�ֱ��z=*ziterƽ���*ziterֵ
		{
			if (!secondCoors.empty())
				secondCoors.clear();
			for (auto firstPickedCoor : firstCoors)
			{
				if (firstPickedCoor(2) == *ziter)
					//����coors�����еĵ㣬���ҵ�y������*yiter��ֵͬ�����е㣬
					//������Ӧ�ĵ��������浽secondCoors���浽�� x = *xiter && y = *yiter��
					secondCoors.push_back(firstPickedCoor);
			}
			//��secondCoors�еĵ���������x�����С��������
			std::sort(secondCoors.begin(), secondCoors.end(), cmpAixsX);
			pickSurfaceCoors(secondCoors, tempPickedCoors);
			finalCoors.insert(finalCoors.end(), tempPickedCoors.begin(), tempPickedCoors.end());
			//û��ȥ�أ�����������������������
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
	QString len = designZoneWidget->uiDesignZone->lineEdit->text();//��
	QString wid = designZoneWidget->uiDesignZone->lineEdit_4->text();//��
	QString re = designZoneWidget->uiDesignZone->lineEdit_3->text();//�߳�

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
			//���ɼ�����
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

		//����
		group->addChild(modelNode);
		group->addChild(stripNode);

		/****************************�����������ҽ�Զ������Դ������ûд��Ӱ*********************************/
		osg::ref_ptr<osg::StateSet> stateset = group->getOrCreateStateSet();
		stateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);
		stateset->setMode(GL_LIGHT6, osg::StateAttribute::ON);	// GL_LIGHT0��Ĭ�Ϲ�Դ
		// ����6����Դ �����������                         
		osg::Vec3d ptLight;
		osg::Vec3d ptCenter = osg::Vec3d(0, 0, 0);
		double dDis = 200000.0;
		ptLight = ptCenter + osg::Z_AXIS * dDis;
		osg::ref_ptr<osg::Node> pNodeLight = createLightSource(6, ptLight, -osg::Z_AXIS);
		pNodeLight->setName("light0");
		group->addChild(pNodeLight);

		//���������߿�
		osg::ref_ptr<osg::StateSet> state = stripNode->getOrCreateStateSet();
		osg::ref_ptr<osg::LineWidth> lineWid = new osg::LineWidth(4.0f);
		state->setAttribute(lineWid.get());
		model->addChild(group);
		//��ʾ����Ӧģ�ʹ�С
		osgWidget->view->getCameraManipulator()->computeHomePosition();
		osgWidget->view->getCameraManipulator()->home(0.0);

		addLog(LogText, QString("���� %1 X %2 �����������,�ֱ���Ϊ %3").arg(len).arg(wid).arg(re), LOGLEVAL::INFO);
	}
	else
	{
		QMessageBox::information(NULL, QString("����"), QString("���ݲ���"));
	}

}

void TopoOptimizeWidget::generate3dDesignZone()
//��ε���ĸ������⣿������������������������������������������������������
{
	if (model != nullptr)
		model->removeChild(0, 1U);
	//δ���������������ʹ����bug��������������������������������������������
	//��ȡQLineEdit�е�����
	osg::ref_ptr<osg::Group> group = new osg::Group;
	QString len = designZone_3D->uiDesignZone_3d->lineEdit->text();//��
	QString wid = designZone_3D->uiDesignZone_3d->lineEdit_4->text();//��
	QString hei = designZone_3D->uiDesignZone_3d->lineEdit_5->text();//��
	QString re = designZone_3D->uiDesignZone_3d->lineEdit_3->text();//�߳�

	if (len != nullptr && wid != nullptr && hei != nullptr && re != nullptr)
	{
		//�ı������ı�ת��
		float length = len.toFloat();
		float width = wid.toFloat();
		float height = hei.toFloat();
		float resolution = re.toFloat();

		Point3D left(0, 0, 0);
		Point3D right(length, width, height);
		V v;
		C c;
		CoorSet finalCoors;//�������õ��ı�������

		aabbSplit3D(left, right, resolution, v, c);
		getShellVoxel(v, c, finalCoors);


	/*********************************������������һ���������࣬��ȾЧ�����*************************************/
		//���ɵ�һ���ص�Ԫ
		int numOfFinalCoors = finalCoors.size();
		osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(8 * numOfFinalCoors);
		osg::ref_ptr<osg::DrawElementsUInt> quadsIndices = new osg::DrawElementsUInt(GL_QUADS, 24 * numOfFinalCoors);
		osg::ref_ptr<osg::DrawElementsUInt> linesIndices = new osg::DrawElementsUInt(GL_LINES, 24 * numOfFinalCoors);

		osg::ref_ptr<osg::Geometry> geom_QUADS = new osg::Geometry;
		osg::ref_ptr<osg::Geometry> geom_lINES = new osg::Geometry;

		int i = 0;
		for (auto iter = finalCoors.begin(); iter != finalCoors.end(); ++iter)
		{
			//���ɼ�����
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
		
		//����
		group->addChild(modelNode);
		group->addChild(stripNode);

		/****************************�����������ҽ�Զ������Դ������ûд��Ӱ*********************************/
		osg::ref_ptr<osg::StateSet> stateset = group->getOrCreateStateSet();
		stateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);
		stateset->setMode(GL_LIGHT6, osg::StateAttribute::ON);	// GL_LIGHT0��Ĭ�Ϲ�Դ
		// ����6����Դ �����������                         
		osg::Vec3d ptLight;
		osg::Vec3d ptCenter = osg::Vec3d(0, 0, 0);
		double dDis = 200000.0;
		ptLight = ptCenter + osg::Z_AXIS * dDis;
		osg::ref_ptr<osg::Node> pNodeLight = createLightSource(6, ptLight, -osg::Z_AXIS);
		pNodeLight->setName("light0");
		group->addChild(pNodeLight);
		
		//���������߿�
		osg::ref_ptr<osg::StateSet> state = stripNode->getOrCreateStateSet();
		osg::ref_ptr<osg::LineWidth> lineWid = new osg::LineWidth(4.0f);
		state->setAttribute(lineWid.get());
		model->addChild(group);

		//��ʾ����Ӧģ�ʹ�С
		osgWidget->view->getCameraManipulator()->computeHomePosition();
		osgWidget->view->getCameraManipulator()->home(0.0);

		addLog(LogText, QString("���� %1 X %2 X %3 �����������,�ֱ���Ϊ %4").arg(len).arg(wid).arg(hei).arg(re), LOGLEVAL::INFO);
	}
	else
	{
		QMessageBox::information(NULL, QString("����"), QString("���ݲ���"));
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

	QString text = QString("������(%1,%2,%3)����������(%4,%5,%6)")
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
//	QString text = QString("������(%1,%2,%3)����������(%4,%5,%6)")
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
//	QString text = QString("������(%1,%2,%3)��ɾ������")
//		.arg(startPoint.x(), 0, 'f', 2).arg(startPoint.y(), 0, 'f', 2).arg(startPoint.z(), 0, 'f', 2);
//	loadSet_3D->uiLoadSet_3D->listWidget->addItem(text);
//}
//
//void TopoOptimizeWidget::del2DArrow()
//{
//	Function function;
//	function.deleteArrow();
//
//	QString text = QString("������(%1,%2,%3)��ɾ������")
//		.arg(startPoint.x(), 0, 'f', 2).arg(startPoint.y(), 0, 'f', 2);
//	loadSetWidget->uiLoadSet->listWidget->addItem(text);
//}

void TopoOptimizeWidget::VectorDieldDriven_SurfaceMesh_on_ImportTriMesh_push()
{
	QString Route = QFileDialog::getOpenFileName(this, QStringLiteral("Please Select File"), "D:", tr("inputfiles(*.stl *.inp)"));
	if (!Route.isEmpty())
	{
		if (Route.right(4) == ".stl" || Route.right(4) == ".STL")
		{
			osgDB::Options* option = new osgDB::Options(std::string("noTriStripPolygons"));
			osg::ref_ptr<osg::Node> stl = osgDB::readNodeFile(Route.toStdString(), option);
			// �������ʶ���
			osg::Material* mat = new osg::Material();
			mat->setColorMode(osg::Material::ColorMode::DIFFUSE);   // ���û�����ɫ��ģʽ 
			mat->setDiffuse(osg::Material::FRONT, osg::Vec4(0, 1, 1, 1));      // ���ô���ģʽ�µ���ɫ 
			stl->getOrCreateStateSet()->setAttribute(mat);
			//����߿�
			//osg::ref_ptr<osgFX::Scribe> scribe = new osgFX::Scribe;
			//scribe->setWireframeColor(osg::Vec4f(0, 0, 0, 1.0));
			//scribe->addChild(stl);
			////���ص������ڵ�
			//model->addChild(scribe);
			model->addChild(stl);
			//����STL�ڵ�
			osg::ref_ptr<osg::Vec3Array> vertices = readSTL(Route.toStdString());
			CreatPoints(vertices);
			//���ݴ���kdTree
			cloud->width = vertices->size();  //�˴���������
			cloud->height = 1;                //��ʾ����Ϊ�������
			cloud->points.resize(cloud->width * cloud->height);

			int i = 0;

			for (auto it = vertices->begin(); it != vertices->end(); ++it)
			{
				cloud->points[i].x = it->x();
				cloud->points[i].y = it->y();
				cloud->points[i].z = it->z();
				i++;
			}
			kdtree.setInputCloud(cloud);

			if (grids.size() != 0)
				grids.clear();
			for (int i = 0; i < cloud->size(); ++i)
			{
				Points grid(cloud->points[i].x, cloud->points[i].y, cloud->points[i].z, 0, 0, 0, 0);
				grids.push_back(grid);
			}
		}
		if (Route.right(4) == ".inp")
		{
			addLog(LogText, "��ʼ��Ⱦ", LOGLEVAL::INFO);
			osg::ref_ptr<osg::Node> inp = readINP_C3D4(Route.toStdString());
			osg::Material* mat = new osg::Material();
			mat->setColorMode(osg::Material::ColorMode::DIFFUSE);   // ���û�����ɫ��ģʽ 
			mat->setDiffuse(osg::Material::FRONT, osg::Vec4(0, 1, 1, 1));      // ���ô���ģʽ�µ���ɫ 
			inp->getOrCreateStateSet()->setAttribute(mat);

			model->addChild(inp);
		}


		//���������������ʽǶȺ�λ��
		osgWidget->getBestView();
		addLog(LogText, "�ɹ�������������ģ��", LOGLEVAL::INFO);
		vectorDieldDriven_VecField->uiVecField->checkBox_TriModel->setEnabled(true);
	}
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_ImportCtrlPntsField_push()
{
	if (model->getNumChildren() != 0)
	{
		if (vectorField.size() != 0)
		{
			vectorField.clear();
			arrow->removeChildren(0, arrow->getNumChildren() - 1);
		}
		QString Route = QFileDialog::getOpenFileName(this, QStringLiteral("Please Select File"), "D:", QStringLiteral("textfile(*anf)"));
		if (!Route.isEmpty())
		{
			// ���ı��ļ�
			std::ifstream inputFile(Route.toStdString());
			if (!inputFile)
			{
				std::cerr << "Failed to open file." << std::endl;
			}
			// ȷ���ļ�����
			int numLines = 0;
			std::string line;
			while (std::getline(inputFile, line)) {
				++numLines;
			}
			// �ص��ļ���ʼ��
			inputFile.clear();
			inputFile.seekg(0, std::ios::beg);

			// ���ж�ȡ���ݲ����浽������
			for (int i = 0; i < numLines; ++i)
			{
				double x, y, z, roll, pitch, yaw;
				inputFile >> x >> y >> z >> roll >> pitch >> yaw;
				osg::ref_ptr<ArrowShape> arrow_temp = CreatArrow(arrow, osg::Vec3(x, y, z), osg::Vec3(roll, pitch, yaw));
				QTreeWidgetItem* treeItem_temp = arrow_temp->GetTreeItem();
				QLineEdit* lineEdit_temp = arrow_temp->GetPos();
				treeWidget3->topLevelItem(1)->addChild(treeItem_temp);
				treeWidget3->setItemWidget(treeItem_temp, 1, lineEdit_temp);
			}
			// �ر��ļ�
			inputFile.close();
			osgWidget->getBestView();
			addLog(LogText, "�ɹ�����ê������", LOGLEVAL::ATTEN);
			vectorDieldDriven_VecField->uiVecField->checkBox_AnF->setEnabled(true);
		}
	}
	else
		addLog(LogText, "���ȵ�����������ģ��", LOGLEVAL::WRONG);

	
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_AddCtrlPnt_push()
{
	if (model->getNumChildren() != 0)
	{
		QDialog dialog(this);
		QFormLayout form(&dialog);
		form.addRow(new QLabel("User input:"));
		// Value1
		QString value1 = QString("xCoor: ");
		QLineEdit* xCoor = new QLineEdit(&dialog);
		form.addRow(value1, xCoor);
		// Value2
		QString value2 = QString("yCoor: ");
		QLineEdit* yCoor = new QLineEdit(&dialog);
		form.addRow(value2, yCoor);

		// Value3
		QString value3 = QString("zCoor: ");
		QLineEdit* zCoor = new QLineEdit(&dialog);
		form.addRow(value3, zCoor);

		// Add Cancel and OK button
		QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
			Qt::Horizontal, &dialog);
		form.addRow(&buttonBox);
		QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
		QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

		// Process when OK button is clicked
		if (dialog.exec() == QDialog::Accepted)
		{
			float x = xCoor->text().toFloat();
			float y = yCoor->text().toFloat();
			float z = zCoor->text().toFloat();

			osg::ref_ptr<ArrowShape> arrow_temp = CreatArrow(arrow, startPoint, osg::Vec3(x, y, z));
			QTreeWidgetItem* treeItem_temp = arrow_temp->GetTreeItem();
			QLineEdit* lineEdit_temp = arrow_temp->GetPos();
			treeWidget3->topLevelItem(1)->addChild(treeItem_temp);
			treeWidget3->setItemWidget(treeItem_temp, 1, lineEdit_temp);
			//vectorField.push_back({ startPoint.x(), startPoint.y(), startPoint.z(), x, y, z });
			vectorDieldDriven_VecField->uiVecField->checkBox_AnF->setEnabled(true);
		}
	}
	else
		addLog(LogText, "���ȵ�����������ģ��", LOGLEVAL::WRONG);
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_ExprtAnchorField_push()
{
	if (vectorField.size() != 0)
	{
		QString Route = QFileDialog::getOpenFileName(this, QStringLiteral("Please Select File"), "D:", QStringLiteral("textfile(*anf)"));
		if (!Route.isEmpty())
		{
			std::ofstream outputFile(Route.toStdString());
			if (!outputFile) {
				std::cerr << "Failed to open file." << std::endl;
			}

			// ������д���ļ�
			for (const auto& array : vectorField) {
				for (const auto& num : *array) {
					outputFile << num << " ";
				}
				outputFile << std::endl;
			}

			// �ر��ļ�
			outputFile.close();
			addLog(LogText, "����ê������", LOGLEVAL::INFO);
		}
	}
	else
		addLog(LogText, "û�пɹ�����ê������", LOGLEVAL::WRONG);
}

void TopoOptimizeWidget::on_HavePicked()
{
	addLog(LogText, "ѡ������", LOGLEVAL::ATTEN);
}

void TopoOptimizeWidget::on_DragEnd(double x, double y, double z)
{
	ArrowShape* arrow_temp = osgWidget->addLinePointHandler->arrowShape;
	if (arrow_temp != NULL)
	{
		arrow_temp->GetPos()->setText(QString("(%1, %2, %3)").arg(x).arg(y).arg(z));
	}
}

void TopoOptimizeWidget::on_SurfPicked(double x, double y, double z)
{
	addLog(LogText, QString("������������㣨%1, %2, %3��").arg(x).arg(y).arg(z), LOGLEVAL::ATTEN);
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_ClearMesh_push()
{
	if (model->getNumChildren() == 0)
		addLog(LogText, "û�е�����������", LOGLEVAL::WARNNING);
	else
	{
		addLog(LogText, "�����������", LOGLEVAL::INFO);
		grids.clear();
		model->removeChildren(0, model->getNumChildren());
		vectorDieldDriven_VecField->uiVecField->checkBox_TriModel->setEnabled(false);
	}
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_ClearCtrlPnts_push()
{
	if (arrow->getNumChildren() == 0)
		addLog(LogText, "û������ê������", LOGLEVAL::WARNNING);
	else
	{
		arrow->removeChildren(0, arrow->getNumChildren());
		vectorField.clear();
		QTtoOSG_Link.clear();
		int itemChildrenCounts = treeWidget3->topLevelItem(1)->childCount();
		while (itemChildrenCounts--)
		{
			QTreeWidgetItem* child = treeWidget3->topLevelItem(1)->child(itemChildrenCounts); //index�Ӵ�С����ɾ������
			treeWidget3->topLevelItem(1)->removeChild(child);
			delete child;
			child = nullptr;
		}
		addLog(LogText, "���ê������", LOGLEVAL::INFO);
		vectorDieldDriven_VecField->uiVecField->checkBox_AnF->setEnabled(false);
	}
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_VecItem_clicked(QTreeWidgetItem* item, int col)
{
	if (item->parent() != NULL)
	{
		//Qt���泡������OSG
		ArrowShape* arrowShape_temp = dynamic_cast<ArrowShape*>(QTtoOSG_Link.find(item)->second);
		osgWidget->addLinePointHandler->arrowShape = arrowShape_temp;
		osgWidget->addLinePointHandler->picked = arrowShape_temp->GetTrans();
	}
}

void TopoOptimizeWidget::CreatPoints(const osg::ref_ptr<osg::Vec3Array>& vertices)
{
	osg::ref_ptr<osg::Geometry> PointsGeometry = new osg::Geometry;
	osg::ref_ptr<osg::Vec4Array> PntsColors = new osg::Vec4Array;
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;

	PointsGeometry->setVertexArray(vertices.get());
	PntsColors->push_back(osg::Vec4(1., 1., 0., 1.));
	PointsGeometry->setColorArray(PntsColors);
	PointsGeometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	PointsGeometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, vertices->size()));

	geode->addDrawable(PointsGeometry.get());
	// ���������Ⱦ���� osg::Points
	osg::ref_ptr<osg::Point> Points = new osg::Point;
	Points->setSize(2.0f); // ���õ�Ĵ�С
	// �������Ⱦ����Ӧ�õ������
	geode->getOrCreateStateSet()->setAttributeAndModes(Points, osg::StateAttribute::ON);
	geode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);//ģ��ʼ�շ������ʹر�ģ�ͽڵ�Ĺ�������
	model->addChild(geode);
}

void TopoOptimizeWidget::CreatVects(const std::vector<Points>& Vecs)
{
	osg::ref_ptr<osg::Geometry> vectorGeometry = new osg::Geometry;
	osg::ref_ptr<osg::Vec3Array> vectors = new osg::Vec3Array();
	osg::ref_ptr<osg::Vec4Array> vectorColors = new osg::Vec4Array;
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;

	// ��ӵ������������
	for (const auto& Vec : Vecs)
	{
		// �������������
		vectors->push_back(osg::Vec3(Vec.x, Vec.y, Vec.z));
		vectors->push_back(osg::Vec3(Vec.x + Vec.X * 3, Vec.y + Vec.Y * 3, Vec.z + Vec.Z * 3));
	}
	vectorGeometry->setVertexArray(vectors);
	vectorColors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f));
	vectorGeometry->setColorArray(vectorColors);
	vectorGeometry->setColorBinding(osg::Geometry::BIND_OVERALL);

	osg::ref_ptr<osg::DrawArrays> drawArrays = new osg::DrawArrays(osg::PrimitiveSet::LINES, 0, vectors->size());
	// ��DrawArrays������ӵ�������Ļ����б���
	vectorGeometry->addPrimitiveSet(drawArrays.get());

	// ���ñߵĿ��
	osg::ref_ptr<osg::LineWidth> lineWidth = new osg::LineWidth(0.05f);
	
	vectorGeometry->getOrCreateStateSet()->setAttributeAndModes(lineWidth.get(), osg::StateAttribute::ON);
	//vectorDieldDriven_VecField->uiVecField->horizontalSlider->setValue(4);
	
	geode->addDrawable(vectorGeometry);
	gridVec->addChild(geode);
}

osg::ref_ptr<osg::Vec3Array> TopoOptimizeWidget::readASCIISTL(const std::string& filename)
{
	std::ifstream file(filename);
	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;

	if (!file.is_open()) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return vertices;
	}

	std::set<osg::Vec3> uniqueVertices; // ʹ�� set ȷ��Ψһ��

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string keyword;
		iss >> keyword;

		if (keyword == "vertex") {
			osg::Vec3 vertex;
			iss >> vertex.x() >> vertex.y() >> vertex.z();
			uniqueVertices.insert(vertex);
		}
	}

	file.close();

	// �� set ת��Ϊ vector
	vertices->assign(uniqueVertices.begin(), uniqueVertices.end());
	return vertices;
}

osg::ref_ptr<osg::Vec3Array> TopoOptimizeWidget::readBinarySTL(const std::string& filename)
{
	std::ifstream file(filename, std::ios::binary);
	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;

	if (!file.is_open()) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return vertices;
	}

	// ����ͷ����Ϣ
	file.seekg(80, std::ios::beg);

	// ��ȡ������Ƭ����
	uint32_t numTriangles;
	file.read(reinterpret_cast<char*>(&numTriangles), sizeof(numTriangles));

	// ʹ�� set ȷ��Ψһ��
	std::set<osg::Vec3> uniqueVertices;

	// ��ȡ������Ƭ
	for (uint32_t i = 0; i < numTriangles; ++i) {
		// ������������12���ֽڣ�
		file.seekg(12, std::ios::cur);

		// ��ȡ�������㣨9����������12���ֽ�ÿ�����㣩
		for (int j = 0; j < 3; ++j) {
			osg::Vec3 vertex;
			file.read(reinterpret_cast<char*>(&vertex), sizeof(float) * 3);
			uniqueVertices.insert(vertex);
		}

		// ���������ֽڼ�������2���ֽڣ�
		file.seekg(2, std::ios::cur);
	}

	file.close();

	// �� set ת��Ϊ vector
	vertices->assign(uniqueVertices.begin(), uniqueVertices.end());
	return vertices;
}

osg::ref_ptr<osg::Vec3Array> TopoOptimizeWidget::readSTL(const std::string& filename)
{
	std::ifstream file(filename, std::ios::binary);
	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;

	if (!file.is_open()) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return vertices;
	}

	// ��ȡǰ 80 ���ֽ����ж��ļ�����
	std::array<char, 80> header;
	file.read(header.data(), header.size());

	//// �ж��ļ�����
	//bool isBinary = true;
	//for (char ch : header) {
	//	if (ch == '\0') {
	//		continue;
	//	}
	//	if (!std::isprint(ch)) {
	//		isBinary = true;
	//		break;
	//	}
	//}

	file.close();

	// �����жϵ��ļ����Ͷ�ȡ�ļ�
	//if (isBinary) {
	//	vertices = readBinarySTL(filename);
	//}
	//else {
	//	vertices = readASCIISTL(filename);
	//}
	//vertices = readBinarySTL(filename);
	vertices = readASCIISTL(filename);

	return vertices;
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_GenerateFromCtrlPnts_clicked()
{
	if (gridVec->getNumChildren() != 0)
		gridVec->removeChild(0, 1U);
	std::vector<Points> anchors;

	if (vectorField.size() != 0 && grids.size() != 0)
	{
		//��֪���ݴ���ָ�����ݽṹ
		for (auto vector : vectorField)
		{
			Points anchor((*vector)[0], (*vector)[1], (*vector)[2],
				(*vector)[3], (*vector)[4], (*vector)[5], 1);
			anchors.push_back(anchor);
		}

		interpolation->diffusionInterpolation(grids, anchors);
		CreatVects(grids);
		addLog(LogText, "�ɹ�����������", LOGLEVAL::ATTEN);
		vectorDieldDriven_VecField->uiVecField->checkBox_VecF->setEnabled(true);
	}
	else
	{
		addLog(LogText, "���ݲ���", LOGLEVAL::WRONG);
	}
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_ImportVecField_push()
{
	if (model->getNumChildren() != 0)
	{
		if (grids.size() != 0)
		{
			grids.clear();
			gridVec->removeChild(0, 1U);
		}
		QString Route = QFileDialog::getOpenFileName(this, QStringLiteral("Please Select File"), "D:", QStringLiteral("textfile(*vecf)"));
		if (!Route.isEmpty())
		{
			// ���ı��ļ�
			std::ifstream inputFile(Route.toStdString());
			if (!inputFile)
			{
				std::cerr << "Failed to open file." << std::endl;
			}
			// ȷ���ļ�����
			int numLines = 0;
			std::string line;
			while (std::getline(inputFile, line)) {
				++numLines;
			}
			// �ص��ļ���ʼ��
			inputFile.clear();
			inputFile.seekg(0, std::ios::beg);

			// ���ж�ȡ���ݲ����浽������
			for (int i = 0; i < numLines; ++i)
			{
				double x, y, z, roll, pitch, yaw;
				inputFile >> x >> y >> z >> roll >> pitch >> yaw;
				Points points_temp(x, y, z, roll, pitch, yaw, 0);
				grids.push_back(points_temp);
			}
			// �ر��ļ�
			inputFile.close();

			CreatVects(grids);
			osgWidget->getBestView();
			addLog(LogText, "�ɹ�����������", LOGLEVAL::ATTEN);
			vectorDieldDriven_VecField->uiVecField->checkBox_VecF->setEnabled(true);
		}
	}
	else
		addLog(LogText, "���ȵ�����������ģ��", LOGLEVAL::WRONG);
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_ExprtVecField_push()
{
	if (grids.size() != 0)
	{
		QString Route = QFileDialog::getOpenFileName(this, QStringLiteral("Please Select File"), "D:", QStringLiteral("textfile(*vecf)"));
		if (!Route.isEmpty())
		{
			std::ofstream outputFile(Route.toStdString());
			if (!outputFile) {
				std::cerr << "Failed to open file." << std::endl;
			}

			// ������д���ļ�
			for (const auto& array : grids) {
				outputFile << array.x << " " << array.y << " " << array.z << " "
					<< array.X << " " << array.Y << " " << array.Z;
				outputFile << std::endl;
			}

			// �ر��ļ�
			outputFile.close();
			addLog(LogText, "�ɹ�����������", LOGLEVAL::INFO);
		}
	}
	else
		addLog(LogText, "û�пɹ�������������", LOGLEVAL::WRONG);
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_ClearVecField_push()
{
	if (grids.size() != 0)
	{
		gridVec->removeChild(0, 1U);
		addLog(LogText, "���������", LOGLEVAL::INFO);
		vectorDieldDriven_VecField->uiVecField->checkBox_VecF->setEnabled(false);
	}
	else
		addLog(LogText, "û������������", LOGLEVAL::WARNNING);
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_CHeckBoxAnF_push(int state)
{
	if (state == Qt::Checked)
	{
		arrow->setNodeMask(1);
		addLog(LogText, "��ʾê������", LOGLEVAL::INFO);
	}
	if (state == Qt::Unchecked)
	{
		arrow->setNodeMask(0);
		addLog(LogText, "����ê������", LOGLEVAL::INFO);
	}
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_CHeckBoxVecF_push(int state)
{
	if (state == Qt::Checked)
	{
		gridVec->setNodeMask(1);
		addLog(LogText, "��ʾ������", LOGLEVAL::INFO);
	}
	if (state == Qt::Unchecked)
	{
		gridVec->setNodeMask(0);
		addLog(LogText, "����������", LOGLEVAL::INFO);
	}
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_CHeckBoxTriModel_push(int state)
{
	if (state == Qt::Checked)
	{
		model->setNodeMask(1);
		addLog(LogText, "��ʾ��������ģ��", LOGLEVAL::INFO);
	}
	if (state == Qt::Unchecked)
	{
		model->setNodeMask(0);
		addLog(LogText, "������������ģ��", LOGLEVAL::INFO);
	}
}

osg::ref_ptr<osg::Node> TopoOptimizeWidget::readINP_C3D4(const std::string& filename)
{
	std::ifstream inputFile(filename);
	std::string line;
	std::vector<osg::Vec3> vertexPoints;// �洢������Ϣ

	int a = 0;
	int b = 0;

	std::vector<Eigen::Vector4i> tetrahedraIndices;

	while (getline(inputFile, line))
	{
		std::istringstream iss(line);
		std::string keyword;

		iss >> keyword;

		for (auto it = line.begin(); it != line.end(); ++it)
		{
			if (*it == ',')
			{
				line.erase(it);
				--it;
			}
		}
		if (keyword == "*NODE")
			a = 1;
		if (keyword == "**HWCOLOR")
			b = 1;
		if (keyword == "*ELEMENT,")
			a = 2;

		if (a == 1 && b != 1 && keyword != "*NODE")
		{
			std::istringstream issVertex(line);
			int vertexId;
			double x, y, z;
			issVertex >> vertexId >> x >> y >> z;
			if (vertexId >= vertexPoints.size())
			{
				vertexPoints.resize(vertexId + 1);
				//vertices.resize(vertexId + 1);
			}
			vertexPoints[vertexId] = osg::Vec3(x, y, z);
		}
		else if (a == 2 && line != "*****" && keyword != "*ELEMENT,")
		{
			std::istringstream issElement(line);
			int elementId;
			int node1, node2, node3, node4;
			issElement >> elementId >> node1 >> node2 >> node3 >> node4;
			Eigen::Vector4i indices;
			indices << node1, node2, node3, node4;
			tetrahedraIndices.push_back(indices);


		}
	}

	//Libigl�������������F
	Eigen::MatrixXi T(tetrahedraIndices.size(), 4);
	Eigen::MatrixXi F; // ����ı߽���
	for (int i = 0; i < tetrahedraIndices.size(); i++)
	{
		T.row(i) = tetrahedraIndices[i];
	}
	igl::boundary_facets(T, F);
	//std::cout << "Number of extracted all tetrahedrons: " << T.rows() << std::endl;
	//std::cout << "Number of extracted outer faces: " << F.rows() << std::endl;

	//��ȡV
	Eigen::MatrixXd V(vertexPoints.size(), 3);
	for (int i = 0; i < vertexPoints.size(); i++)
	{
		auto point = vertexPoints[i];
		V(i, 0) = point.x();
		V(i, 1) = point.y();
		V(i, 2) = point.z();
	}

	// 3. ��ȡ�����Ķ�������V_boundary�͸���������F_boundary
	Eigen::MatrixXd V_boundary(V.rows(), 3);
	Eigen::MatrixXi F_boundary(F.rows(), 3);
	std::vector<int> boundary_vertex_indices(V.rows(), -1); // ��ʼ��Ϊ-1�����ڱ��δ����ȡ�Ķ���
	int vertex_count = 0;
	for (int i = 0; i < F.rows(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int vertex_index = F(i, j);
			if (boundary_vertex_indices[vertex_index] == -1)
			{
				boundary_vertex_indices[vertex_index] = vertex_count;
				V_boundary.row(vertex_count) = V.row(vertex_index);
				vertex_count++;
			}
			F_boundary(i, j) = boundary_vertex_indices[vertex_index];
		}
	}
	V_boundary.conservativeResize(vertex_count, 3); // ����V_boundary�Ĵ�С

	Eigen::MatrixXd N_faces;
	igl::per_face_normals(V_boundary, F_boundary, N_faces);

	//������Ʊ����������������
	cloud->width = V_boundary.rows();  //�˴���������
	cloud->height = 1;                //��ʾ����Ϊ�������
	cloud->points.resize(cloud->width * cloud->height);

	int i = 0;

	for (int i = 0; i < V_boundary.rows(); ++i)
	{
		cloud->points[i].x = V_boundary(i, 0);
		cloud->points[i].y = V_boundary(i, 1);
		cloud->points[i].z = V_boundary(i, 2);
	}
	kdtree.setInputCloud(cloud);

	//���2����stl�ļ�
	std::ofstream fout;
	fout.open("./temp/inp2stlbinary_temp.stl", std::ios::out | std::ios::binary);
	char buf[80];
	for (int i = 0; i < 80; i++)
		buf[i] = '\0';
	fout.write((char*)&buf, sizeof(buf));
	int num = F_boundary.rows();
	fout.write((char*)&num, sizeof(num));
	for (int i = 0; i < F_boundary.rows(); ++i)
	{
		float x_n, y_n, z_n;
		x_n = N_faces(i, 0);
		y_n = N_faces(i, 1);
		z_n = N_faces(i, 2);
		fout.write((char*)&x_n, sizeof(x_n));
		fout.write((char*)&y_n, sizeof(y_n));
		fout.write((char*)&z_n, sizeof(z_n));

		for (int j = 2; j >= 0; --j)
		{
			float x, y, z;
			x = V_boundary(F_boundary(i, j), 0);
			y = V_boundary(F_boundary(i, j), 1);
			z = V_boundary(F_boundary(i, j), 2);
			fout.write((char*)&x, sizeof(x));
			fout.write((char*)&y, sizeof(y));
			fout.write((char*)&z, sizeof(z));
		}

		char tem[2];
		tem[0] = '\0'; tem[1] = '\0';
		fout.write((char*)&tem, sizeof(tem));
	}
	fout.close();

	//��ȡ������stl
	osgDB::Options* option = new osgDB::Options(std::string("noTriStripPolygons"));
	osg::ref_ptr<osg::Node> stl = osgDB::readNodeFile("./temp/inp2stlbinary_temp.stl", option);

	//��ʾ�ڲ����е�
	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	for (auto it = vertexPoints.begin() + 1; it != vertexPoints.end(); ++it)
		vertices->push_back(*it);
	CreatPoints(vertices);

	if (grids.size() != 0)
		grids.clear();

	for (int i = 0; i < vertices->size(); ++i)
	{
		Points grid((*vertices)[i].x(), (*vertices)[i].y(), (*vertices)[i].z(), 0, 0, 0, 0);
		grids.push_back(grid);
	}

	return stl;
}

void TopoOptimizeWidget::VectorDieldDriven_VectorField_on_Slider_changed(int val)
{
	float step = 0.05;
	osg::ref_ptr<osg::LineWidth> lineWidth = new osg::LineWidth(val * step);
	gridVec->getChild(0)->getOrCreateStateSet()->setAttributeAndModes(lineWidth.get(), osg::StateAttribute::ON);
}






osg::Vec3 AddLinePointHandler::getSurfPoint(float x, float y, osg::ref_ptr<osgViewer::Viewer> viewer)
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
			/*return pointsToChoose[0];*/
			pcl::PointXYZ searchPoint;
			searchPoint.x = pointsToChoose[0].x();
			searchPoint.y = pointsToChoose[0].y();
			searchPoint.z = pointsToChoose[0].z();
			std::vector<int> pointIdxNKNSearch(1);      //�洢��ѯ���������
			std::vector<float> pointNKNSquaredDistance(1); //�洢���ڵ��Ӧ����ƽ��
			if (kdtree.nearestKSearch(searchPoint, 1, pointIdxNKNSearch, pointNKNSquaredDistance) > 0)  //ִ��K��������
			{
				return osg::Vec3(cloud->points[pointIdxNKNSearch[0]].x,
					cloud->points[pointIdxNKNSearch[0]].y,
					cloud->points[pointIdxNKNSearch[0]].z);
			}
		}
	}
	else
		return osg::Vec3(0, 0, 0);
}


void AddLinePointHandler::pick(float x, float y, osg::ref_ptr<osgViewer::Viewer> view)
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

void AddLinePointHandler::removeTraceBallTracker()
{
	FindDelNodeVisitor delVisitor;
	picked->accept(delVisitor);
	picked->setAttitude(rotation_Global);
	arrowShape->setData(picked->getPosition(), rotation_Global);
}

bool AddLinePointHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
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
			pick(x, y, viewer);
			startPoint = getSurfPoint(x, y, viewer);
			emit SurfPicked(startPoint.x(), startPoint.y(), startPoint.z());
		}
		break;

	case osgGA::GUIEventAdapter::PUSH://�������ѡ���϶�����
		if (ea.getButton() == 1)
		{
			float x = ea.getX();
			float y = ea.getY();
			pick(x, y, viewer);
		}
		break;

	case osgGA::GUIEventAdapter::DRAG://�϶������ƶ�
		if (PickedObject)//���ѡ������������϶�
		{
			float x = ea.getX();
			float y = ea.getY();
			osg::Vec3 lastPoint = getSurfPoint(x, y, viewer);
			picked->setPosition(lastPoint);
			arrowShape->UpdateDragger(picked->getAttitude(), lastPoint);
			arrowShape->setData(lastPoint, picked->getAttitude());
			emit DragEnd(lastPoint.x(), lastPoint.y(), lastPoint.z());
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
			if (arrowShape != NULL)
			{
				rotation_Global = picked->getAttitude();
				arrowShape->EnableDragger();
			}
			m_ctrlKeyPressed = true;
		}

		if ((ea.getKey() == 'B') || ea.getKey() == 'b')
			emit getBestView();
		break;

	case osgGA::GUIEventAdapter::KEYUP:
		if ((osgGA::GUIEventAdapter::KEY_Control_L == ea.getKey())
			|| (osgGA::GUIEventAdapter::KEY_Control_R == ea.getKey())) // Ctrl�����ͷ�
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
