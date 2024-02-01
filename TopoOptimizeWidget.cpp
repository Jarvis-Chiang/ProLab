#include "TopoOptimizeWidget.h"
#include "Function.h"
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
	designZone_3D(new DesignZone_3D),
	treeStackWidget(new QStackedWidget),
	boundaryCases_3D(new BoundaryCases_3D),
	loadSet_3D(new LoadSet_3D),
	optimizePara_3D(new OptimizePara_3D),
	osgWidget(new OsgWidget(0, Qt::Widget, osgViewer::ViewerBase::SingleThreaded)),
	group(new osg::Group)

{
	init();
	creatAction();
}

TopoOptimizeWidget :: ~TopoOptimizeWidget()
{

}

void TopoOptimizeWidget :: init()
{
	//右侧操作栏堆栈窗口
	oprStackWidget->addWidget(designZoneWidget);//QStackedWidget类适addWidget函数适只适用于标准指针，Qt智能指针不行
	oprStackWidget->addWidget(materialSetWidget);
	oprStackWidget->addWidget(boundaryCasesWidget);
	oprStackWidget->addWidget(loadSetWidget);
	oprStackWidget->addWidget(optimizeParaWidget);
	oprStackWidget->addWidget(resultCheckWidget);
	oprStackWidget->addWidget(designZone_3D);
	oprStackWidget->addWidget(boundaryCases_3D);
	oprStackWidget->addWidget(loadSet_3D);
	oprStackWidget->addWidget(optimizePara_3D);

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

	//左侧树状结构堆栈窗口
	treeStackWidget->addWidget(treeWidget1);
	treeStackWidget->addWidget(treeWidget2);
}

void TopoOptimizeWidget::creatAction()
{
	//树结构和堆栈窗口关联
	connect(treeWidget1, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget2, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));

	//文件读取对话框
	connect(designZoneWidget->uiDesignZone->importDesignGridButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));
	connect(materialSetWidget->uiMaterialSet->importElasticityMatrixButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));

	connect(designZone_3D->uiDesignZone_3d->generateButton, SIGNAL(clicked()), this, SLOT(generate3dDesignZone()));
	//载荷功能
	connect(loadSet_3D->uiLoadSet_3D->pushButton_del, SIGNAL(clicked()), this, SLOT(delArrow()));
	connect(loadSet_3D->uiLoadSet_3D->pushButton_add, SIGNAL(clicked()), this, SLOT(addArrow0()));
	connect(loadSet_3D->uiLoadSet_3D->pushButton_add_2, SIGNAL(clicked()), this, SLOT(addArrow()));
	connect(loadSet_3D->uiLoadSet_3D->pushButton_plane, SIGNAL(clicked()), this, SLOT(addTangentPlane()));
	connect(loadSetWidget->uiLoadSet->pushButton, SIGNAL(clicked()), this, SLOT(del2DArrow()));
	connect(loadSetWidget->uiLoadSet->pushButton_2, SIGNAL(clicked()), this, SLOT(add2DArrow()));

}


//加载设计域ui
DesignZoneWidget::DesignZoneWidget() :
	uiDesignZone(new Ui_DesignZone::DesignZoneWidget)
{
	uiDesignZone->setupUi(this);
}

DesignZoneWidget :: ~DesignZoneWidget()
{
	delete uiDesignZone;
}

void DesignZoneWidget::aabbSplit2D(const Point2D& left, const Point2D& right, double resolution, V& vers, C& cells)
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
				start + Xnums + 2,
				start + 1 + (Xnums + 1),
				start + Xnums + 1;
			crows++;
		}
	}
}

//加载3D设计域
DesignZone_3D::DesignZone_3D():
	uiDesignZone_3d(new Ui_DesignZone_3D::DesignZoneWidget)
{
	uiDesignZone_3d->setupUi(this);
}

DesignZone_3D::~DesignZone_3D()
{
	delete uiDesignZone_3d;
}

//加载材料属性设置ui
MaterialSetWidget::MaterialSetWidget():
	uiMaterialSet(new Ui_Material::MeterialSetWidget),
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
	uiBoundaryCases(new Ui_BoundaryCases::BoundaryCasesWidget)
{
	uiBoundaryCases->setupUi(this);
}

BoundaryCasesWidget::~BoundaryCasesWidget()
{
	delete uiBoundaryCases;
}

//加载3D边界条件ui
BoundaryCases_3D::BoundaryCases_3D() :
	uiBoundaryCases_3D(new Ui_BoundaryCases_3D::BoundaryCasesWidget_3D)
{
	uiBoundaryCases_3D->setupUi(this);
}

BoundaryCases_3D::~BoundaryCases_3D()
{
	delete uiBoundaryCases_3D;
}

//加载载荷设置ui
LoadSetWidget::LoadSetWidget():
	uiLoadSet(new Ui_LoadSet::LoadSetWidget)
{
	uiLoadSet->setupUi(this);
}

LoadSetWidget::~LoadSetWidget()
{
	delete uiLoadSet;
}

//加载3D载荷设置ui
LoadSet_3D::LoadSet_3D() :
	uiLoadSet_3D(new Ui_LoadSet_3D::LoadSetWidget_3D)
{
	uiLoadSet_3D->setupUi(this);
}

LoadSet_3D::~LoadSet_3D()
{
	delete uiLoadSet_3D;
}

//加载参数优化ui
OptimizeParaWidget::OptimizeParaWidget():
	uiOptimizePara(new Ui_OptimizePara::OptimizeParaWidget)
{
	uiOptimizePara->setupUi(this);
}

OptimizeParaWidget::~OptimizeParaWidget()
{
	delete uiOptimizePara;
}

//加载3D参数优化ui
OptimizePara_3D::OptimizePara_3D() :
	uiOptimizePara_3D(new Ui_OptimizePara_3D::OptimizeParaWidget_3D)
{
	uiOptimizePara_3D->setupUi(this);
}

OptimizePara_3D::~OptimizePara_3D()
{
	delete uiOptimizePara_3D;
}

//加载结果查看ui
ResultCheckWidget::ResultCheckWidget():
	uiRecultCheck(new Ui_Result:: ResultCheckWidget)
{
	uiRecultCheck->setupUi(this);
}

ResultCheckWidget::~ResultCheckWidget()
{
	delete uiRecultCheck;
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


//****************以下为槽函数*********************//

void TopoOptimizeWidget::stackedWidgetPageChange(QTreeWidgetItem* item, int column)
{
	if (item->text(column) == "2D设计域")//?????????????
	{
		oprStackWidget->setCurrentIndex(0);
	}

	if (item->text(column) == "材料属性")
	{
		oprStackWidget->setCurrentIndex(1);
	}

	if (item->text(column) == "2D边界条件")
	{
		oprStackWidget->setCurrentIndex(2);
	}

	if (item->text(column) == "2D载荷设置")
	{
		oprStackWidget->setCurrentIndex(3);
	}

	if (item->text(column) == "2D优化参数")
	{
		oprStackWidget->setCurrentIndex(4);
	}

	if (item->text(column) == "结果查看")
	{
		oprStackWidget->setCurrentIndex(5);
	}

	if (item->text(column) == "3D设计域")
	{
		oprStackWidget->setCurrentIndex(6);
	}

	if (item->text(column) == "3D边界条件")
	{
		oprStackWidget->setCurrentIndex(7);
	}

	if (item->text(column) == "3D载荷设置")
	{
		oprStackWidget->setCurrentIndex(8);
	}

	if (item->text(column) == "3D优化参数")
	{
		oprStackWidget->setCurrentIndex(9);
	}
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


//osg::ref_ptr<osg::Node> TopoOptimizeWidget::createLightSource(unsigned int num, const osg::Vec3d& trans, const osg::Vec3d& vecDir)
//{
//
//	osg::ref_ptr<osg::Light> light = new osg::Light;
//	light->setLightNum(num);
//	light->setDirection(vecDir);
//	light->setAmbient(osg::Vec4(0.0f,0.0f,0.2f,1.0f));
//	//设置散射光的颜色
//	//light->setDiffuse(osg::Vec4(0.8f,0.8f,0.8f,1.0f));
//	// 
//	//light->setSpecular(osg::Vec4(1.0f,1.0f,1.0f,1.0f));
//	//light->setPosition( osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f) );
//
//	osg::ref_ptr<osg::LightSource> lightSource = new osg::LightSource;
//	lightSource->setLight(light);
//
//	osg::ref_ptr<osg::MatrixTransform> sourceTrans = new osg::MatrixTransform;
//	sourceTrans->setMatrix(osg::Matrix::translate(trans));
//	sourceTrans->addChild(lightSource.get());
//	return sourceTrans.release();
//}

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

void TopoOptimizeWidget::generate3dDesignZone()
//多次点击的覆盖问题？？？？？？？？？？？？？？？？？？？？？？？？？？？？
{
	//未考虑数据输入类型错误的bug？？？？？？？？？？？？？？？？？？？？？？
	//获取QLineEdit中的数据
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
		//osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(8 * (c.rows()));
		//osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(GL_QUADS, 24 * c.rows());
		//osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
		//for (int i = 0; i < c.rows(); i++)
		//{
		//	float x = v(int(c(i, 0)), 0) - v(int(c(0, 0)), 0);
		//	float y = v(int(c(i, 0)), 1) - v(int(c(0, 0)), 1);
		//	float z = v(int(c(i , 0)), 2) - v(int(c(0, 0)), 2);
		//	(*vertices)[i * 8 + 0].set(v(int(c(0, 0)), 0) + x, v(int(c(0, 0)), 1) + y, v(int(c(0, 0)), 2) + z);
		//	(*vertices)[i * 8 + 1].set(v(int(c(0, 1)), 0) + x, v(int(c(0, 1)), 1) + y, v(int(c(0, 1)), 2) + z);
		//	(*vertices)[i * 8 + 2].set(v(int(c(0, 2)), 0) + x, v(int(c(0, 2)), 1) + y, v(int(c(0, 2)), 2) + z);
		//	(*vertices)[i * 8 + 3].set(v(int(c(0, 3)), 0) + x, v(int(c(0, 3)), 1) + y, v(int(c(0, 3)), 2) + z);
		//	(*vertices)[i * 8 + 4].set(v(int(c(0, 4)), 0) + x, v(int(c(0, 4)), 1) + y, v(int(c(0, 4)), 2) + z);
		//	(*vertices)[i * 8 + 5].set(v(int(c(0, 5)), 0) + x, v(int(c(0, 5)), 1) + y, v(int(c(0, 5)), 2) + z);
		//	(*vertices)[i * 8 + 6].set(v(int(c(0, 6)), 0) + x, v(int(c(0, 6)), 1) + y, v(int(c(0, 6)), 2) + z);
		//	(*vertices)[i * 8 + 7].set(v(int(c(0, 7)), 0) + x, v(int(c(0, 7)), 1) + y, v(int(c(0, 7)), 2) + z);
		//	(*indices)[i * 24 + 0] = i * 8 + 0; (*indices)[i * 24 + 1] = i * 8 + 1; (*indices)[i * 24 + 2] = i * 8 + 2; (*indices)[i * 24 + 3] = i * 8 + 3;
		//	(*indices)[i * 24 + 4] = i * 8 + 0; (*indices)[i * 24 + 5] = i * 8 + 3; (*indices)[i * 24 + 6] = i * 8 + 7; (*indices)[i * 24 + 7] = i * 8 + 4;
		//	(*indices)[i * 24 + 8] = i * 8 + 4; (*indices)[i * 24 + 9] = i * 8 + 5; (*indices)[i * 24 + 10] = i * 8 + 6; (*indices)[i * 24 + 11] = i * 8 + 7;
		//	(*indices)[i * 24 + 12] = i * 8 + 1; (*indices)[i * 24 + 13] = i * 8 + 2; (*indices)[i * 24 + 14] = i * 8 + 6; (*indices)[i * 24 + 15] = i * 8 + 5;
		//	(*indices)[i * 24 + 16] = i * 8 + 2; (*indices)[i * 24 + 17] = i * 8 + 3; (*indices)[i * 24 + 18] = i * 8 + 7; (*indices)[i * 24 + 19] = i * 8 + 6;
		//	(*indices)[i * 24 + 20] = i * 8 + 1; (*indices)[i * 24 + 21] = i * 8 + 0; (*indices)[i * 24 + 22] = i * 8 + 4; (*indices)[i * 24 + 23] = i * 8 + 5;
		//}

		//geom->setVertexArray(vertices.get());
		//geom->addPrimitiveSet(indices.get());
		//osgUtil::SmoothingVisitor::smooth(*geom);//为每个地点设置法向量，实际上不用，有优化空间！！！！！
		//osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
		//colors->push_back(osg::Vec4(0., 1., 1., 1.));
		//geom->setColorArray(colors);
		//geom->setColorBinding(osg::Geometry::BIND_OVERALL);
		//osg::ref_ptr<osg::Geode> root = new osg::Geode;
		//root->addDrawable(geom.get());
		//group->addChild(root);
		


		/****************************设置上下左右近远六个光源，但是没写阴影*********************************/
		//osg::ref_ptr<osg::StateSet> stateset = group->getOrCreateStateSet();
		//stateset->setMode(GL_LIGHTING, osg::StateAttribute::ON);
		//stateset->setMode(GL_LIGHT6, osg::StateAttribute::ON);	// GL_LIGHT0是默认光源
		//// 设置6个光源 解决光照问题                         
		//osg::Vec3d ptLight;
		//osg::Vec3d ptCenter = osg::Vec3d(0, 0, 0);
		//double dDis = 200000.0;
		//ptLight = ptCenter + osg::Z_AXIS * dDis;
		//osg::ref_ptr<osg::Node> pNodeLight = createLightSource(6, ptLight, -osg::Z_AXIS);
		//pNodeLight->setName("light0");
		//group->addChild(pNodeLight);
		//osg::ref_ptr<osg::Group> addedLightGroup = createLight(root);

		/************************************添加光照************************************************/
		//decorator->addChild(root);
		//group->addChild(decorator);
		//polyoffset->setFactor(-1.0f);
		//polyoffset->setUnits(-1.0f);
		//polymode->setMode(osg::PolygonMode::FRONT_AND_BACK, osg::PolygonMode::LINE);
		//stateset->setAttributeAndModes(polyoffset, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON);
		//stateset->setAttributeAndModes(polymode, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON);
//#if 1
		//osg::ref_ptr<osg::Material> material = new osg::Material;
		//stateset->setAttributeAndModes(material, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON);
		//stateset->setMode(GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
//#endif
		//stateset->setTextureMode(0, GL_TEXTURE_2D, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
		//decorator->setStateSet(stateset);
		//optimzer.optimize(group);


		/**********************使用24顶点几何体生成体素网格，并进行相应的简化******************************/


		osg::ref_ptr<osg::Geode> geode = new osg::Geode;
		osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
		//osg::Box* voxel = new osg::Box(osg::Vec3(v(int(c(0, 0)), 0), v(int(c(0, 0)), 1), v(int(c(0, 0)), 2)), resolution); //osg::Shape类最好别用osg::ref_ptr
		osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(24);
		(*vertices)[0].set(v(int(c(0, 0)), 0), v(int(c(0, 0)), 1), v(int(c(0, 0)), 2));
		(*vertices)[1].set(v(int(c(0, 1)), 0), v(int(c(0, 1)), 1), v(int(c(0, 1)), 2));
		(*vertices)[2].set(v(int(c(0, 2)), 0), v(int(c(0, 2)), 1), v(int(c(0, 2)), 2));
		(*vertices)[3].set(v(int(c(0, 3)), 0), v(int(c(0, 3)), 1), v(int(c(0, 3)), 2));
		(*vertices)[4].set(v(int(c(0, 0)), 0), v(int(c(0, 0)), 1), v(int(c(0, 0)), 2));
		(*vertices)[5].set(v(int(c(0, 3)), 0), v(int(c(0, 3)), 1), v(int(c(0, 3)), 2));
		(*vertices)[6].set(v(int(c(0, 7)), 0), v(int(c(0, 7)), 1), v(int(c(0, 7)), 2));
		(*vertices)[7].set(v(int(c(0, 4)), 0), v(int(c(0, 4)), 1), v(int(c(0, 4)), 2));
		(*vertices)[8].set(v(int(c(0, 7)), 0), v(int(c(0, 7)), 1), v(int(c(0, 7)), 2));
		(*vertices)[9].set(v(int(c(0, 6)), 0), v(int(c(0, 6)), 1), v(int(c(0, 6)), 2));
		(*vertices)[10].set(v(int(c(0, 5)), 0), v(int(c(0, 5)), 1), v(int(c(0, 5)), 2));
		(*vertices)[11].set(v(int(c(0, 4)), 0), v(int(c(0, 4)), 1), v(int(c(0, 4)), 2));
		(*vertices)[12].set(v(int(c(0, 5)), 0), v(int(c(0, 5)), 1), v(int(c(0, 5)), 2));
		(*vertices)[13].set(v(int(c(0, 6)), 0), v(int(c(0, 6)), 1), v(int(c(0, 6)), 2));
		(*vertices)[14].set(v(int(c(0, 2)), 0), v(int(c(0, 2)), 1), v(int(c(0, 2)), 2));
		(*vertices)[15].set(v(int(c(0, 1)), 0), v(int(c(0, 1)), 1), v(int(c(0, 1)), 2));
		(*vertices)[16].set(v(int(c(0, 6)), 0), v(int(c(0, 6)), 1), v(int(c(0, 6)), 2));
		(*vertices)[17].set(v(int(c(0, 7)), 0), v(int(c(0, 7)), 1), v(int(c(0, 7)), 2));
		(*vertices)[18].set(v(int(c(0, 3)), 0), v(int(c(0, 3)), 1), v(int(c(0, 3)), 2));
		(*vertices)[19].set(v(int(c(0, 2)), 0), v(int(c(0, 2)), 1), v(int(c(0, 2)), 2));
		(*vertices)[20].set(v(int(c(0, 1)), 0), v(int(c(0, 1)), 1), v(int(c(0, 1)), 2));
		(*vertices)[21].set(v(int(c(0, 0)), 0), v(int(c(0, 0)), 1), v(int(c(0, 0)), 2));
		(*vertices)[22].set(v(int(c(0, 4)), 0), v(int(c(0, 4)), 1), v(int(c(0, 4)), 2));
		(*vertices)[23].set(v(int(c(0, 5)), 0), v(int(c(0, 5)), 1), v(int(c(0, 5)), 2));
		geom->setVertexArray(vertices.get());

		/***************************BIND_PER_PRITIMIVE_SET**************************************/
		//geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS,0,4));
		//geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 4, 4));
		//geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 8, 4));
		//geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 12, 4));
		//geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 16, 4));
		//geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 20, 4));

		//osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
		//normals->push_back(getnormal((*vertices)[0], (*vertices)[1], (*vertices)[2], (*vertices)[3]));
		//normals->push_back(getnormal((*vertices)[4], (*vertices)[5], (*vertices)[6], (*vertices)[7]));
		//normals->push_back(getnormal((*vertices)[8], (*vertices)[9], (*vertices)[10], (*vertices)[11]));
		//normals->push_back(getnormal((*vertices)[12], (*vertices)[13], (*vertices)[14], (*vertices)[15]));
		//normals->push_back(getnormal((*vertices)[16], (*vertices)[17], (*vertices)[18], (*vertices)[19]));
		//normals->push_back(getnormal((*vertices)[20], (*vertices)[21], (*vertices)[22], (*vertices)[23]));
		//geom->setNormalArray(normals.get());
		//geom->setNormalBinding(osg::Geometry::BIND_PER_PRIMITIVE_SET);

		/***************************BIND_PER_VERTEX**************************************/
		osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
		geom->setNormalArray(normals.get());
		geom->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);
		normals->push_back(getnormal((*vertices)[0], (*vertices)[1], (*vertices)[2], (*vertices)[3]));
		normals->push_back(getnormal((*vertices)[0], (*vertices)[1], (*vertices)[2], (*vertices)[3]));
		normals->push_back(getnormal((*vertices)[0], (*vertices)[1], (*vertices)[2], (*vertices)[3]));
		normals->push_back(getnormal((*vertices)[0], (*vertices)[1], (*vertices)[2], (*vertices)[3]));
		normals->push_back(getnormal((*vertices)[4], (*vertices)[5], (*vertices)[6], (*vertices)[7]));
		normals->push_back(getnormal((*vertices)[4], (*vertices)[5], (*vertices)[6], (*vertices)[7]));
		normals->push_back(getnormal((*vertices)[4], (*vertices)[5], (*vertices)[6], (*vertices)[7]));
		normals->push_back(getnormal((*vertices)[4], (*vertices)[5], (*vertices)[6], (*vertices)[7]));
		normals->push_back(getnormal((*vertices)[8], (*vertices)[9], (*vertices)[10], (*vertices)[11]));
		normals->push_back(getnormal((*vertices)[8], (*vertices)[9], (*vertices)[10], (*vertices)[11]));
		normals->push_back(getnormal((*vertices)[8], (*vertices)[9], (*vertices)[10], (*vertices)[11]));
		normals->push_back(getnormal((*vertices)[8], (*vertices)[9], (*vertices)[10], (*vertices)[11]));
		normals->push_back(getnormal((*vertices)[12], (*vertices)[13], (*vertices)[14], (*vertices)[15]));
		normals->push_back(getnormal((*vertices)[12], (*vertices)[13], (*vertices)[14], (*vertices)[15]));
		normals->push_back(getnormal((*vertices)[12], (*vertices)[13], (*vertices)[14], (*vertices)[15]));
		normals->push_back(getnormal((*vertices)[12], (*vertices)[13], (*vertices)[14], (*vertices)[15]));
		normals->push_back(getnormal((*vertices)[16], (*vertices)[17], (*vertices)[18], (*vertices)[19]));
		normals->push_back(getnormal((*vertices)[16], (*vertices)[17], (*vertices)[18], (*vertices)[19]));
		normals->push_back(getnormal((*vertices)[16], (*vertices)[17], (*vertices)[18], (*vertices)[19]));
		normals->push_back(getnormal((*vertices)[16], (*vertices)[17], (*vertices)[18], (*vertices)[19]));
		normals->push_back(getnormal((*vertices)[20], (*vertices)[21], (*vertices)[22], (*vertices)[23]));
		normals->push_back(getnormal((*vertices)[20], (*vertices)[21], (*vertices)[22], (*vertices)[23]));
		normals->push_back(getnormal((*vertices)[20], (*vertices)[21], (*vertices)[22], (*vertices)[23]));
		normals->push_back(getnormal((*vertices)[20], (*vertices)[21], (*vertices)[22], (*vertices)[23]));
		geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 24));
		geode->addDrawable(geom.get());

		/**********************使用8顶点几何体生成体素网格，并进行相应的简化******************************/

		//osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(8);
		//(*vertices)[0].set(v(int(c(0, 0)), 0), v(int(c(0, 0)), 1), v(int(c(0, 0)), 2));
		//(*vertices)[1].set(v(int(c(0, 1)), 0), v(int(c(0, 1)), 1), v(int(c(0, 1)), 2));
		//(*vertices)[2].set(v(int(c(0, 2)), 0), v(int(c(0, 2)), 1), v(int(c(0, 2)), 2));
		//(*vertices)[3].set(v(int(c(0, 3)), 0), v(int(c(0, 3)), 1), v(int(c(0, 3)), 2));
		//(*vertices)[4].set(v(int(c(0, 4)), 0), v(int(c(0, 4)), 1), v(int(c(0, 4)), 2));
		//(*vertices)[5].set(v(int(c(0, 5)), 0), v(int(c(0, 5)), 1), v(int(c(0, 5)), 2));
		//(*vertices)[6].set(v(int(c(0, 6)), 0), v(int(c(0, 6)), 1), v(int(c(0, 6)), 2));
		//(*vertices)[7].set(v(int(c(0, 7)), 0), v(int(c(0, 7)), 1), v(int(c(0, 7)), 2));
		//osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(GL_QUADS, 24);
		//(*indices)[0] = 0; (*indices)[1] = 1; (*indices)[2] = 2; (*indices)[3] = 3;
		//(*indices)[4] = 0; (*indices)[5] = 3; (*indices)[6] = 7; (*indices)[7] = 4;
		//(*indices)[8] = 4; (*indices)[9] = 5; (*indices)[10] = 6; (*indices)[11] = 7;
		//(*indices)[12] = 1; (*indices)[13] = 2; (*indices)[14] = 6; (*indices)[15] = 5;
		//(*indices)[16] = 2; (*indices)[17] = 3; (*indices)[18] = 7; (*indices)[19] = 6;
		//(*indices)[20] = 1; (*indices)[21] = 0; (*indices)[22] = 4; (*indices)[23] = 5;
		//osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
		//geom->setVertexArray(vertices.get());
		//geom->addPrimitiveSet(indices.get());
		//osgUtil::SmoothingVisitor::smooth(*geom);
		//osg::ref_ptr<osg::Geode> geode = new osg::Geode;
		//geode->addDrawable(geom.get());
		//拷贝并平行变换
		for (auto iter = finalCoors.begin(); iter != finalCoors.end(); ++iter)
		{
			osg::ref_ptr<osg::MatrixTransform> translateMT = new osg::MatrixTransform;
			float x = (*iter)(0) - v(int(c(0, 0)), 0);
			float y = (*iter)(1) - v(int(c(0, 0)), 1);
			float z = (*iter)(2) - v(int(c(0, 0)), 2);
			translateMT->setMatrix(osg::Matrix::translate(x, y, z));
			translateMT->addChild(geode);
			group->addChild(translateMT);
		}
		group->addChild(geode);
		osg::ref_ptr<osg::StateSet> state = group->getOrCreateStateSet();
		osg::ref_ptr<osg::CullFace> cullface = new osg::CullFace(osg::CullFace::FRONT);
		state->setAttribute(cullface.get());
		state->setMode(GL_CULL_FACE, osg::StateAttribute::ON);
		osgWidget->view->setSceneData(group);
	}
	else
	{
		QMessageBox::information(NULL, QString("警告"), QString("数据不足"));
	}
}

void TopoOptimizeWidget::addTangentPlane()
{
	Function function;
	function.genPlaneCoordinateSystem();
}

void TopoOptimizeWidget::addArrow0()
{
	Function function;
	QString inputText = loadSet_3D->uiLoadSet_3D->lineEdit_x0->text();
	double x = inputText.toDouble();
	QString inputText2 = loadSet_3D->uiLoadSet_3D->lineEdit_y0->text();
	double y = inputText2.toDouble();
	QString inputText3 = loadSet_3D->uiLoadSet_3D->lineEdit_z0->text();
	double z = inputText3.toDouble();
	osg::Vec3 input(x, y, z);
	//function.genPlaneCoordinateSystem();
	function.genArrow0(input);

	QString text = QString("在坐标(%1,%2,%3)处插入向量(%4,%5,%6)")
		.arg(startPoint.x(), 0, 'f', 2).arg(startPoint.y(), 0, 'f', 2).arg(startPoint.z(), 0, 'f', 2)
		.arg(input.x()).arg(input.y()).arg(input.z());
	loadSet_3D->uiLoadSet_3D->listWidget->addItem(text);
}

void TopoOptimizeWidget::addArrow()
{
	Function function;
	QString inputText = loadSet_3D->uiLoadSet_3D->lineEdit_x1->text();
	double x = inputText.toDouble();
	QString inputText2 = loadSet_3D->uiLoadSet_3D->lineEdit_y1->text();
	double y = inputText2.toDouble();
	QString inputText3 = loadSet_3D->uiLoadSet_3D->lineEdit_z1->text();
	double z = inputText3.toDouble();
	osg::Vec3 input(x, y, z);
	//function.genPlaneCoordinateSystem();
	function.genArrow(input);

	QString text = QString("在坐标(%1,%2,%3)处相对切平面插入向量(%4,%5,%6)")
		.arg(startPoint.x(), 0, 'f', 2).arg(startPoint.y(), 0, 'f', 2).arg(startPoint.z(), 0, 'f', 2)
		.arg(input.x()).arg(input.y()).arg(input.z());
	loadSet_3D->uiLoadSet_3D->listWidget->addItem(text);
}

void TopoOptimizeWidget::add2DArrow()
{
	Function function;
	QString inputText = loadSetWidget->uiLoadSet->lineEdit->text();
	double x = inputText.toDouble();
	QString inputText2 = loadSetWidget->uiLoadSet->lineEdit_2->text();
	double y = inputText2.toDouble();
	double z = 0;
	osg::Vec3 input(x, y, z);
	function.genArrow(input);

	QString text = QString("在坐标(%1,%2,%3)处插入向量(%4,%5,%6)")
		.arg(startPoint.x(), 0, 'f', 2).arg(startPoint.y(), 0, 'f', 2)
		.arg(input.x()).arg(input.y());
	loadSetWidget->uiLoadSet->listWidget->addItem(text);
}

void TopoOptimizeWidget::delArrow()
{
	Function function;
	function.deleteArrow();

	QString text = QString("在坐标(%1,%2,%3)处删除向量")
		.arg(startPoint.x(), 0, 'f', 2).arg(startPoint.y(), 0, 'f', 2).arg(startPoint.z(), 0, 'f', 2);
	loadSet_3D->uiLoadSet_3D->listWidget->addItem(text);
}

void TopoOptimizeWidget::del2DArrow()
{
	Function function;
	function.deleteArrow();

	QString text = QString("在坐标(%1,%2,%3)处删除向量")
		.arg(startPoint.x(), 0, 'f', 2).arg(startPoint.y(), 0, 'f', 2);
	loadSetWidget->uiLoadSet->listWidget->addItem(text);
}
