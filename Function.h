#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/Geometry>
#include <osg/MatrixTransform>
#include <osg/Group>
#include <osg/Matrixd>
#include <osg/Quat>
#include <osg/PositionAttitudeTransform>
#include "igl/principal_curvature.h"
#include "igl/per_vertex_normals.h"
#include <igl/signed_distance.h>
#include <igl/marching_cubes.h>
#include "OsgWidget.h"
#include "mainwindow.h"
#include "TopoOptimizeWidget.h"

using namespace std;
using namespace osg;

extern osg::ref_ptr<osg::Group> Root;
extern osg::ref_ptr<osg::Geode> lastPlaneGeode;// 存储上一次生成的切平面节点
extern Eigen::MatrixXd V0;
extern Eigen::MatrixXd PD1;
extern Eigen::MatrixXd PD2;
extern osg::Vec3 startPoint;
extern osg::Vec3 DirX;
extern osg::Vec3 DirY;
extern osg::Vec3 selEdge;
extern std::vector<osg::Vec3> featurePoints;
extern std::vector<osg::Vec3> featureVectors;
extern vector<osg::ref_ptr<osg::Geode>> anAisArrows;
extern double PAI;

class Function
{
public:
    Function();

    void CreatArrow(osg::ref_ptr<osg::Group> root, const osg::Vec3& startPoint, const osg::Vec3& direction);
    void RemoveArrow(osg::ref_ptr<osg::Group> root, const osg::Vec3& startPoint);
    void Compute_curvature_dirction(const Eigen::MatrixXd& V, const Eigen::MatrixXd& PD1, const Eigen::MatrixXd& PD2, const osg::Vec3& point, osg::Vec3& dir1, osg::Vec3& dir2);
    void TransformPoint(const osg::Vec3& relativePoint, const osg::Vec3& relativeOrigin, const osg::Vec3& relativeXAxis, const osg::Vec3& relativeYAxis, osg::Vec3& mainPoint);
    osg::ref_ptr<osg::Geometry> CreateSquarePlane(const osg::Vec3& center, const osg::Vec3& dir1, const osg::Vec3& dir2);
    osg::ref_ptr<osg::Geometry> CreatCoordinateSystem(const osg::Vec3& center, const osg::Vec3& dir1, const osg::Vec4& color);
    void genPlaneCoordinateSystem();//创建参考平面
    void genArrow0(const osg::Vec3& input);
    void genArrow(const osg::Vec3& direction);
    void deleteArrow();
};