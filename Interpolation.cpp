#include "Interpolation.h"

void Interpolation::diffusionInterpolation(std::vector<Points>& grid, std::vector<Points>& anchor)
{
    Interpolation intp;
    for (int i = 0; i < anchor.size(); i++)
    {
        intp.convertToUnitVector(anchor[i]);
    }
    for (int i = 0; i < grid.size(); i++)
    {
        if (grid[i].p != 0) {
            continue;
        }
        intp.diffusionWeightedMean(grid[i], anchor);
    }
}

void Interpolation::diffusionWeightedMean(Points& points, std::vector<Points>& anchor)
{
    Interpolation intp;
    std::vector<double> Distance;
    for (int i = 0; i < anchor.size(); i++)
    {
        double distance = intp.calculate_distance(anchor[i], points);
        if (distance == 0.0) {
            points.X = anchor[i].X;
            points.Y = anchor[i].Y;
            points.Z = anchor[i].Z;
            return;
        }
        Distance.push_back(distance);
    }
    intp.weighted_mean(points, anchor, Distance);
    intp.convertToUnitVector(points);
}

double Interpolation::calculate_distance(const Points& p1, const Points& p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

double Interpolation::calculate_difference(const Points& p1, const Points& p2)
{
    double dx = p2.X - p1.X;
    double dy = p2.Y - p1.Y;
    double dz = p2.Z - p1.Z;
    double n = dx * dx + dy * dy + dz * dz;
    return n;
}

void Interpolation::findNeighborhoodPoints(const std::vector<Points>& grid, const Points& points, double radius, std::vector<Points> neighborhoodPointss, std::vector<double> Distance)
{
    Interpolation intp;

    double x = points.x;
    double y = points.y;
    double z = points.z;

    // ������������е����е�
    for (int i = 0; i < grid.size(); i++) {
        // �ų���ǰ��
        if (grid[i].x == x && grid[i].y == y && grid[i].z == z) {
            continue;
        }
        // �������Ŀ���֮��ľ���
        double distance = intp.calculate_distance(grid[i], points);

        // �������Ƿ���ָ���뾶��Χ��,�Ҹ�λ��������
        if (distance <= radius && grid[i].p != 0) {
            neighborhoodPointss.push_back(grid[i]);
            Distance.push_back(distance);
        }
    }
}

void Interpolation::weighted_mean(Points& point, const std::vector<Points>& neighborhoodPointss, const std::vector<double>& Distance)
{
    double p = 0;
    for (int i = 0; i < Distance.size(); i++) {
        p = p + 1 / (Distance[i] * Distance[i]);
    }
    double X = 0;
    double Y = 0;
    double Z = 0;
    for (int i = 0; i < Distance.size(); i++) {
        double a = 1 / (Distance[i] * Distance[i]);
        X = X + (a / p) * neighborhoodPointss[i].X;
        Y = Y + (a / p) * neighborhoodPointss[i].Y;
        Z = Z + (a / p) * neighborhoodPointss[i].Z;
    }
    point.X = X;
    point.Y = Y;
    point.Z = Z;
    point.p = 1;
}

double Interpolation::calculate_E(Points point, const std::vector<Points>& neighborhoodPointss, const std::vector<double>& Distance)
{
    Interpolation intp;
    double E;
    double p = 0;
    for (int i = 0; i < Distance.size(); i++) {
        p = p + 1 / (Distance[i] * Distance[i]);
    }
    for (int i = 0; i < Distance.size(); i++) {
        double a = 1 / (Distance[i] * Distance[i]);
        E = E + (a / p) * intp.calculate_difference(point, neighborhoodPointss[i]);
    }

    return E;
}


void Interpolation::convertToUnitVector(Points& Points)
{
    double length = std::sqrt(Points.X * Points.X + Points.Y * Points.Y + Points.Z * Points.Z);

    Points.X /= length;
    Points.Y /= length;
    Points.Z /= length;
}

void Interpolation::makeUniPoints(std::vector<Points>& points, std::vector<Points>& anchor)
{
    Interpolation intp;
    // ����һ������1000���������
    points.reserve(10000);

    // ��ʼ��1000����
    //for (int i = 0; i < 10; ++i) {
    //    for (int j = 0; j < 10; ++j) {
    //        for (int k = 0; k < 10; ++k) {
    //            // ��ʼ��������������
    //            Points p(i, j, k, 0.0, 0.0, 0.0, 0, 0.0);
    //            points.push_back(p);
    //        }
    //    }
    //}

    //2D
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            // ��ʼ��������������
            Points p(i, j, 0, 0.0, 0.0, 0.0, 0.0);
            points.push_back(p);
        }
    }

    // ���ѡ��10����ͬ�ĵ㣬������������p��ֵ
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<int> indices(10000);
    int count = 0;
    std::generate(indices.begin(), indices.end(), [&count]() { return count++; });
    std::shuffle(indices.begin(), indices.end(), gen);

    std::uniform_real_distribution<double> dist(-5.0, 5.0);

    for (int i = 0; i < 100; ++i) {
        int index = indices[i];
        points[index].X = dist(gen);
        points[index].Y = dist(gen);
        //points[index].Z = dist(gen);
        points[index].Z = 0.0;
        points[index].p = 1;
        intp.convertToUnitVector(points[index]);
        anchor.push_back(points[index]);
    }

}

void Interpolation::readVector(std::vector<Points> Pointss, osg::ref_ptr<osg::Geode> geode)
{
    osg::ref_ptr<osg::Geometry> PointsGeometry = new osg::Geometry;
    osg::ref_ptr<osg::Geometry> vectorGeometry = new osg::Geometry;
    // ������������
    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array();
    osg::ref_ptr<osg::Vec4Array> PointsColors = new osg::Vec4Array;

    // ������������
    osg::ref_ptr<osg::Vec3Array> vectors = new osg::Vec3Array();
    osg::ref_ptr<osg::Vec4Array> vectorColors = new osg::Vec4Array;

    // ��ӵ������������
    for (const auto& Points : Pointss)
    {
        // ��ӵ������
        vertices->push_back(osg::Vec3(Points.x, Points.y, Points.z));
        PointsColors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
        // �������������
        vectors->push_back(osg::Vec3(Points.x, Points.y, Points.z));
        vectors->push_back(osg::Vec3(Points.x + Points.X, Points.y + Points.Y, Points.z + Points.Z));
        vectorColors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f));
    }
    PointsGeometry->setVertexArray(vertices.get());
    PointsGeometry->setColorArray(PointsColors.get());
    PointsGeometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
    PointsGeometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, vertices->size()));

    // ����� Geometry ��ӵ� Geode
    geode->addDrawable(PointsGeometry.get());

    // ���������Ⱦ���� osg::Points
    osg::ref_ptr<osg::Point> Points = new osg::Point;
    Points->setSize(5.0f); // ���õ�Ĵ�С

    // �������Ⱦ����Ӧ�õ������
    geode->getOrCreateStateSet()->setAttributeAndModes(Points, osg::StateAttribute::ON);

    // ���ñߵĶ�������
    vectorGeometry->setVertexArray(vectors.get());
    vectorGeometry->setColorArray(vectorColors.get());
    vectorGeometry->setColorBinding(osg::Geometry::BIND_OVERALL);

    osg::ref_ptr<osg::DrawArrays> drawArrays = new osg::DrawArrays(osg::PrimitiveSet::LINES, 0, vectors->size());

    // ��DrawArrays������ӵ�������Ļ����б���
    vectorGeometry->addPrimitiveSet(drawArrays.get());

    // ���ñߵĿ��
    osg::ref_ptr<osg::LineWidth> lineWidth = new osg::LineWidth(1.5f);
    vectorGeometry->getOrCreateStateSet()->setAttributeAndModes(lineWidth.get(), osg::StateAttribute::ON);

    // ���ߵ�Geometry������ӵ�Geode������
    geode->addDrawable(vectorGeometry.get());

}

