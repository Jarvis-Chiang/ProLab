#pragma once
#include <osg/Group>
#include <osg/Array>

#include <QPlainTextEdit>
#include <QTime>
#include <QTreeWidgetItem>

#include <vector>
#include <map>

#include <Eigen/Dense>

#include <pcl/point_cloud.h>        //�����Ͷ���ͷ�ļ�
#include <pcl/kdtree/kdtree_flann.h> //kdtree�ඨ��ͷ�ļ�

enum LOGLEVAL {
    INFO,
    WARNNING,
    WRONG,
    ATTEN
};

//��������ֵָ�����ݽṹ
struct Points {
    double x;
    double y;
    double z;
    double X;
    double Y;
    double Z;
    int p;

    Points(double _x, double _y, double _z, double _X, double _Y, double _Z, int _p) : x(_x), y(_y), z(_z), X(_X), Y(_Y), Z(_Z), p(_p) {}
};

static std::vector<Points> grids;//��������������
static std::vector <std::array<double, 6>*> vectorField;//ê����������
static pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);//kdtree����
static pcl::KdTreeFLANN<pcl::PointXYZ> kdtree;//kdTree�ṹ


static osg::ref_ptr<osg::Group> root = new osg::Group;//osg������ʾ�����нڵ�ĸ��ڵ�
static osg::ref_ptr<osg::Group> arrow = new osg::Group;//osg������ʾ������ê���ͷ
static osg::ref_ptr<osg::Group> gridVec = new osg::Group;//osg������ʾ������������
static osg::ref_ptr<osg::Group> model = new osg::Group;//osg������ʾ������ģ�ͽڵ�


static osg::Vec3 position;//�ӵ�����
static osg::Vec3 center_1;
static osg::Vec3 up;

static osg::Vec3 startPoint;//������ӵĸ���������ͷ����ʱ����
static osg::Quat rotation_Global;
static std::map <QTreeWidgetItem*, osg::Group*> QTtoOSG_Link;

// log textbrowser 

static void addLog(QPlainTextEdit* logtext, const QString& message, LOGLEVAL level)
{
    QString log;
    // set text format
    QTextCharFormat fmt;
    fmt.setFontPointSize(9);
    logtext->document()->setMaximumBlockCount(200);                     // set maximum display rows 

    switch (level)
    {
    case LOGLEVAL::INFO:
        log = QTime::currentTime().toString("hh:mm:ss:zzz ") + QString(" [   INFO\t") + QString("]\t") + message;
        fmt.setForeground(QColor("black"));
        logtext->mergeCurrentCharFormat(fmt);
        logtext->appendPlainText(log);
        break;
    case LOGLEVAL::WARNNING:
        log = QTime::currentTime().toString("hh:mm:ss:zzz ") + QString(" [  WARNNING\t") + QString("]\t") + message;
        fmt.setForeground(QColor("blue"));
        logtext->mergeCurrentCharFormat(fmt);
        logtext->appendPlainText(log);
        break;
    case LOGLEVAL::WRONG:
        log = QTime::currentTime().toString("hh:mm:ss:zzz ") + QString(" [   ERROR\t") + QString("]\t") + message;
        fmt.setForeground(QColor("red"));
        logtext->mergeCurrentCharFormat(fmt);
        logtext->appendPlainText(log);
        break;
    case LOGLEVAL::ATTEN:
        log = QTime::currentTime().toString("hh:mm:ss:zzz ") + QString(" [   ATTEN\t") + QString("]\t") + message;
        fmt.setForeground(QColor("green"));
        logtext->mergeCurrentCharFormat(fmt);
        logtext->appendPlainText(log);
    }
}