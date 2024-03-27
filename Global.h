#pragma once
#include <osg/Group>
#include <osg/Array>

#include <osgManipulator/TrackballDragger>

#include <vector>

static osg::ref_ptr<osg::Group> root = new osg::Group;//osg������ʾ�����нڵ�ĸ��ڵ�
static osg::ref_ptr<osg::Group> arrow = new osg::Group;//osg������ʾ�����м�ͷ
static osg::ref_ptr<osg::Group> slicePlane = new osg::Group;//osg������ʾ��������ƽ��ڵ�
static osg::ref_ptr<osg::Group> model = new osg::Group;//osg������ʾ������ģ�ͽڵ�

static osg::Vec3 position;//�ӵ�����
static osg::Vec3 center_1;
static osg::Vec3 up;

static osg::Vec3 startPoint;//������ӵĸ���������ͷ����ʱ����
static osg::Quat rotation_Global;

static osg::ref_ptr<osgManipulator::TrackballDragger> dragger = new osgManipulator::TrackballDragger;





