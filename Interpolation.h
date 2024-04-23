#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <random>
#include <algorithm>
#include <osg/Array>
#include <osg/Vec3>
#include <osg/Geometry>
#include <osg/Geode>
#include <osg/Point>
#include <osg/LineWidth>
#include <osgViewer/Viewer>
#include <fstream>

#include "Global.h"

class Interpolation
{
public:
    Interpolation() {};
    ~Interpolation() {};

    void diffusionInterpolation(std::vector<Points>& grid, std::vector<Points>& anchor);
    void diffusionWeightedMean(Points& point, std::vector<Points>& anchor);
    double calculate_distance(const Points& p1, const Points& p2);
    double calculate_difference(const Points& p1, const Points& p2);
    void findNeighborhoodPoints(const std::vector<Points>& grid, const Points& point, double radius, std::vector<Points> neighborhoodPoints, std::vector<double> Distance);
    void weighted_mean(Points& point, const std::vector<Points>& neighborhoodPoints, const std::vector<double>& Distance);
    double calculate_E(Points point, const std::vector<Points>& neighborhoodPoints, const std::vector<double>& Distance);
    void convertToUnitVector(Points& point);
    void makeUniPoints(std::vector<Points>& points, std::vector<Points>& anchor);
    void readVector(std::vector<Points> points, osg::ref_ptr<osg::Geode> geode);
};
