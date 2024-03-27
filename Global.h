#pragma once
#include <osg/Group>
#include <osg/Array>

#include <osgManipulator/TrackballDragger>

#include <vector>

static osg::ref_ptr<osg::Group> root = new osg::Group;//osg窗口显示的所有节点的根节点
static osg::ref_ptr<osg::Group> arrow = new osg::Group;//osg窗口显示的所有箭头
static osg::ref_ptr<osg::Group> slicePlane = new osg::Group;//osg窗口显示的所有切平面节点
static osg::ref_ptr<osg::Group> model = new osg::Group;//osg窗口显示的所有模型节点

static osg::Vec3 position;//视点坐标
static osg::Vec3 center_1;
static osg::Vec3 up;

static osg::Vec3 startPoint;//保存添加的各个向量箭头的临时变量
static osg::Quat rotation_Global;

static osg::ref_ptr<osgManipulator::TrackballDragger> dragger = new osgManipulator::TrackballDragger;





