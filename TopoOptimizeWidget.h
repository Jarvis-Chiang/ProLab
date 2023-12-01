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


//�����
class DesignZoneWidget : public QWidget
{

	Q_OBJECT

public:
	DesignZoneWidget(QWidget* parent = 0);
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
	QStackedWidget* oprStackWidget; //�Ҳ��������ջ����
	QTreeWidget* treeWidget; //�����״�ṹ����
	QString fileRoute;//�ⲿ�ļ�·���ӿڣ���Ҫѡ���·������ֱ�������QString���ַ���
private:
	DesignZoneWidget* designZoneWidget;
	MaterialSetWidget* materialSetWidget;
	QSharedPointer<QGridLayout> gridLayout;


public slots:
	void stackedWidgetPageChange(QTreeWidgetItem* item, int column);
	void importDesignGridFile();
};



