#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "igl/principal_curvature.h"
#include "igl/per_vertex_normals.h"
#include <igl/signed_distance.h>
#include <igl/marching_cubes.h>
#include <igl/boundary_facets.h>
#include <osg/Array>
#include <osg/Vec3>
#include <osg/Geometry>
#include <osg/Geode>
#include <osg/Point>
#include <osg/LineWidth>
#include <osgViewer/Viewer>
#include <Eigen/Dense>

using namespace std;

class readINP
{

public:
	readINP();
	void readVertex(string filename, osg::ref_ptr<osg::Geode> geode, Eigen::MatrixXd& Vb, Eigen::MatrixXd& PD1, Eigen::MatrixXd& PD2);

public:
	//Define::NODE	_node;
	//Define::ELEMENT _element;

public:
	Eigen::MatrixXd T;
	struct myNode
	{
		int id;
	};
	struct myElement
	{
		int id;
		int node1;
		int node2;
		int node3;
		int node4;
	};

};

