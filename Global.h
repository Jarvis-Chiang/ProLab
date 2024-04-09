#pragma once
#include <osg/Group>
#include <osg/Array>

#include <QPlainTextEdit>
#include <QTime>

#include <vector>

#include <Eigen/Dense>

enum LOGLEVAL {
    INFO,
    WARNNING,
    WRONG,
    ATTENION
};

//typedef Eigen::Matrix<double, Eigen::Dynamic, 6> VectorField;

static osg::ref_ptr<osg::Group> root = new osg::Group;//osg窗口显示的所有节点的根节点
static osg::ref_ptr<osg::Group> arrow = new osg::Group;//osg窗口显示的所有箭头
static osg::ref_ptr<osg::Group> slicePlane = new osg::Group;//osg窗口显示的所有切平面节点
static osg::ref_ptr<osg::Group> model = new osg::Group;//osg窗口显示的所有模型节点

static osg::Vec3 position;//视点坐标
static osg::Vec3 center_1;
static osg::Vec3 up;

static osg::Vec3 startPoint;//保存添加的各个向量箭头的临时变量
static osg::Quat rotation_Global;
static std::vector <std::array<double, 6> *> vectorField;//向量场数据

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
        fmt.setForeground(QColor("black"));
        logtext->mergeCurrentCharFormat(fmt);
        logtext->appendPlainText(log);
        break;
    case LOGLEVAL::WRONG:
        log = QTime::currentTime().toString("hh:mm:ss:zzz ") + QString(" [   ERROR\t") + QString("]\t") + message;
        fmt.setForeground(QColor("red"));
        logtext->mergeCurrentCharFormat(fmt);
        logtext->appendPlainText(log);
        break;
    case LOGLEVAL::ATTENION:
        log = QTime::currentTime().toString("hh:mm:ss:zzz ") + QString(" [   ATTENTION\t") + QString("]\t") + message;
        fmt.setForeground(QColor("green"));
        logtext->mergeCurrentCharFormat(fmt);
        logtext->appendPlainText(log);
    }
}


