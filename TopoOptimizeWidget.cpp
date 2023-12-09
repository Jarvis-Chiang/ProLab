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
	//�Ҳ��������ջ����
	oprStackWidget->addWidget(designZoneWidget);//QStackedWidget����addWidget������ֻ�����ڱ�׼ָ�룬Qt����ָ�벻��
	oprStackWidget->addWidget(materialSetWidget);
	oprStackWidget->addWidget(boundaryCasesWidget);
	oprStackWidget->addWidget(loadSetWidget);
	oprStackWidget->addWidget(optimizeParaWidget);
	oprStackWidget->addWidget(resultCheckWidget);
	oprStackWidget->addWidget(designZone_3D);
	oprStackWidget->addWidget(boundaryCases_3D);
	oprStackWidget->addWidget(loadSet_3D);
	oprStackWidget->addWidget(optimizePara_3D);

	//�����״�ṹ����1
	treeWidget1->setColumnCount(1); //��������
	treeWidget1->setHeaderLabel(QString("2D���˽ṹ��"));

	QTreeWidgetItem* tree1_0 = new QTreeWidgetItem(treeWidget1, QStringList(QString("2D�����")));
	QTreeWidgetItem* tree1_1 = new QTreeWidgetItem(treeWidget1, QStringList(QString("��������")));
	QTreeWidgetItem* tree1_2 = new QTreeWidgetItem(treeWidget1, QStringList(QString("2D�߽�����")));
	QTreeWidgetItem* tree1_3 = new QTreeWidgetItem(treeWidget1, QStringList(QString("2D�غ�����")));
	QTreeWidgetItem* tree1_4 = new QTreeWidgetItem(treeWidget1, QStringList(QString("2D�Ż�����")));
	QTreeWidgetItem* tree1_5 = new QTreeWidgetItem(treeWidget1, QStringList(QString("����鿴")));
	treeWidget1->expandAll();

	//�����״�ṹ����2
	treeWidget2->setColumnCount(1); //��������
	treeWidget2->setHeaderLabel(QString("3D���˽ṹ��"));

	QTreeWidgetItem* tree2_0 = new QTreeWidgetItem(treeWidget2, QStringList(QString("3D�����")));
	QTreeWidgetItem* tree2_1 = new QTreeWidgetItem(treeWidget2, QStringList(QString("��������")));
	QTreeWidgetItem* tree2_2 = new QTreeWidgetItem(treeWidget2, QStringList(QString("3D�߽�����")));
	QTreeWidgetItem* tree2_3 = new QTreeWidgetItem(treeWidget2, QStringList(QString("3D�غ�����")));
	QTreeWidgetItem* tree2_4 = new QTreeWidgetItem(treeWidget2, QStringList(QString("3D�Ż�����")));
	QTreeWidgetItem* tree2_5 = new QTreeWidgetItem(treeWidget2, QStringList(QString("����鿴")));
	treeWidget2->expandAll();

	//�����״�ṹ��ջ����
	treeStackWidget->addWidget(treeWidget1);
	treeStackWidget->addWidget(treeWidget2);
}

void TopoOptimizeWidget::creatAction()
{
	//���ṹ�Ͷ�ջ���ڹ���
	connect(treeWidget1, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));
	connect(treeWidget2, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(stackedWidgetPageChange(QTreeWidgetItem*, int)));

	//�ļ���ȡ�Ի���
	connect(designZoneWidget->uiDesignZone->importDesignGridButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));
	connect(materialSetWidget->uiMaterialSet->importElasticityMatrixButton, SIGNAL(clicked()), this, SLOT(importDesignGridFile()));
	connect(designZone_3D->uiDesignZone_3d->generateButton, SIGNAL(clicked()), this, SLOT(generate3dDesignZone()));

}


//���������ui
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

//����3D�����
DesignZone_3D::DesignZone_3D():
	uiDesignZone_3d(new Ui_DesignZone_3D::DesignZoneWidget)
{
	uiDesignZone_3d->setupUi(this);
}

DesignZone_3D::~DesignZone_3D()
{
	delete uiDesignZone_3d;
}

//���ز�����������ui
MaterialSetWidget::MaterialSetWidget():
	uiMaterialSet(new Ui_Material::MeterialSetWidget),
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
	uiBoundaryCases(new Ui_BoundaryCases::BoundaryCasesWidget)
{
	uiBoundaryCases->setupUi(this);
}

BoundaryCasesWidget::~BoundaryCasesWidget()
{
	delete uiBoundaryCases;
}

//����3D�߽�����ui
BoundaryCases_3D::BoundaryCases_3D() :
	uiBoundaryCases_3D(new Ui_BoundaryCases_3D::BoundaryCasesWidget_3D)
{
	uiBoundaryCases_3D->setupUi(this);
}

BoundaryCases_3D::~BoundaryCases_3D()
{
	delete uiBoundaryCases_3D;
}

//�����غ�����ui
LoadSetWidget::LoadSetWidget():
	uiLoadSet(new Ui_LoadSet::LoadSetWidget)
{
	uiLoadSet->setupUi(this);
}

LoadSetWidget::~LoadSetWidget()
{
	delete uiLoadSet;
}

//����3D�غ�����ui
LoadSet_3D::LoadSet_3D() :
	uiLoadSet_3D(new Ui_LoadSet_3D::LoadSetWidget_3D)
{
	uiLoadSet_3D->setupUi(this);
}

LoadSet_3D::~LoadSet_3D()
{
	delete uiLoadSet_3D;
}

//���ز����Ż�ui
OptimizeParaWidget::OptimizeParaWidget():
	uiOptimizePara(new Ui_OptimizePara::OptimizeParaWidget)
{
	uiOptimizePara->setupUi(this);
}

OptimizeParaWidget::~OptimizeParaWidget()
{
	delete uiOptimizePara;
}

//����3D�����Ż�ui
OptimizePara_3D::OptimizePara_3D() :
	uiOptimizePara_3D(new Ui_OptimizePara_3D::OptimizeParaWidget_3D)
{
	uiOptimizePara_3D->setupUi(this);
}

OptimizePara_3D::~OptimizePara_3D()
{
	delete uiOptimizePara_3D;
}

//���ؽ���鿴ui
ResultCheckWidget::ResultCheckWidget():
	uiRecultCheck(new Ui_Result:: ResultCheckWidget)
{
	uiRecultCheck->setupUi(this);
}

ResultCheckWidget::~ResultCheckWidget()
{
	delete uiRecultCheck;
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


//****************����Ϊ�ۺ���*********************//

void TopoOptimizeWidget::stackedWidgetPageChange(QTreeWidgetItem* item, int column)
{
	if (item->text(column) == "2D�����")//?????????????
	{
		oprStackWidget->setCurrentIndex(0);
	}

	if (item->text(column) == "��������")
	{
		oprStackWidget->setCurrentIndex(1);
	}

	if (item->text(column) == "2D�߽�����")
	{
		oprStackWidget->setCurrentIndex(2);
	}

	if (item->text(column) == "2D�غ�����")
	{
		oprStackWidget->setCurrentIndex(3);
	}

	if (item->text(column) == "2D�Ż�����")
	{
		oprStackWidget->setCurrentIndex(4);
	}

	if (item->text(column) == "����鿴")
	{
		oprStackWidget->setCurrentIndex(5);
	}

	if (item->text(column) == "3D�����")
	{
		oprStackWidget->setCurrentIndex(6);
	}

	if (item->text(column) == "3D�߽�����")
	{
		oprStackWidget->setCurrentIndex(7);
	}

	if (item->text(column) == "3D�غ�����")
	{
		oprStackWidget->setCurrentIndex(8);
	}

	if (item->text(column) == "3D�Ż�����")
	{
		oprStackWidget->setCurrentIndex(9);
	}
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

void TopoOptimizeWidget::generate3dDesignZone()
//��ε���ĸ������⣿������������������������������������������������������
{
	//δ���������������ʹ����bug��������������������������������������������
	//��ȡQLineEdit�е�����
	QString len = designZone_3D->uiDesignZone_3d->lineEdit->text();//��
	QString wid = designZone_3D->uiDesignZone_3d->lineEdit_4->text();//��
	QString hei = designZone_3D->uiDesignZone_3d->lineEdit_5->text();//��
	QString re = designZone_3D->uiDesignZone_3d->lineEdit_3->text();//�߳�

	if (len != nullptr && wid != nullptr && hei != nullptr && re != nullptr)
	{
		float length = len.toFloat();
		float width = wid.toFloat();
		float height = hei.toFloat();
		float resolution = re.toFloat();

		Point3D left(0, 0, 0);
		Point3D right(length, width, height);
		V v;
		C c;

		aabbSplit3D(left, right, resolution, v, c);

		//osg::Vec3f point1()

		osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(8);
		(*vertices)[0].set(v(int(c(0, 0)), 0), v(int(c(0, 0)), 1), v(int(c(0, 0)), 2));
		(*vertices)[1].set(v(int(c(0, 1)), 0), v(int(c(0, 1)), 1), v(int(c(0, 1)), 2));
		(*vertices)[2].set(v(int(c(0, 2)), 0), v(int(c(0, 2)), 1), v(int(c(0, 2)), 2));
		(*vertices)[3].set(v(int(c(0, 3)), 0), v(int(c(0, 3)), 1), v(int(c(0, 3)), 2));
		(*vertices)[4].set(v(int(c(0, 4)), 0), v(int(c(0, 4)), 1), v(int(c(0, 4)), 2));
		(*vertices)[5].set(v(int(c(0, 5)), 0), v(int(c(0, 5)), 1), v(int(c(0, 5)), 2));
		(*vertices)[6].set(v(int(c(0, 6)), 0), v(int(c(0, 6)), 1), v(int(c(0, 6)), 2));
		(*vertices)[7].set(v(int(c(0, 7)), 0), v(int(c(0, 7)), 1), v(int(c(0, 7)), 2));

		osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(GL_TRIANGLES, 36);
		(*indices)[0] = 0; (*indices)[1] = 1; (*indices)[2] = 2;
		(*indices)[3] = 0; (*indices)[4] = 2; (*indices)[5] = 3;
		(*indices)[6] = 0; (*indices)[7] = 3; (*indices)[8] = 4;
		(*indices)[9] = 3; (*indices)[10] = 4; (*indices)[11] = 7;
		(*indices)[12] = 4; (*indices)[13] = 5; (*indices)[14] = 7;
		(*indices)[15] = 5; (*indices)[16] = 6; (*indices)[17] = 7;
		(*indices)[18] = 1; (*indices)[19] = 2; (*indices)[20] = 5;
		(*indices)[21] = 2; (*indices)[22] = 5; (*indices)[23] = 6;
		(*indices)[24] = 2; (*indices)[25] = 3; (*indices)[26] = 7;
		(*indices)[27] = 2; (*indices)[28] = 6; (*indices)[29] = 7;
		(*indices)[30] = 0; (*indices)[31] = 1; (*indices)[32] = 4;
		(*indices)[33] = 1; (*indices)[34] = 4; (*indices)[35] = 5;


		osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
		geom->setVertexArray(vertices.get());
		geom->addPrimitiveSet(indices.get());

		osgUtil::SmoothingVisitor::smooth(*geom);

		osg::ref_ptr<osg::Geode> root = new osg::Geode;
		root->addDrawable(geom.get());
		

		group->addChild(root);

		for (int i = 1; i < c.rows(); i++)
		{
			osg::MatrixTransform* translateMT = new osg::MatrixTransform;
			float x = v(int(c(i, 0)), 0) - v(int(c(0, 0)), 0);
			float y = v(int(c(i, 0)), 1) - v(int(c(0, 0)), 1);
			float z = v(int(c(i, 0)), 2) - v(int(c(0, 0)), 2);
			translateMT->setMatrix(osg::Matrix::translate(x, y, z));
			translateMT->addChild(root);
			group->addChild(translateMT);
		}
		osgWidget->view->setSceneData(group);
	}
	else
	{
		QMessageBox::information(NULL, QString("����"), QString("���ݲ���"));
	}
}