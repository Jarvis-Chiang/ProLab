#include "Function.h"
#include "readINP.h"

osg::ref_ptr<osg::Group> Root = new osg::Group();
osg::ref_ptr<osg::Geode> lastPlaneGeode = new osg::Geode();
Eigen::MatrixXd V0;
Eigen::MatrixXd PD1;
Eigen::MatrixXd PD2;
osg::Vec3 startPoint;
osg::Vec3 DirX;
osg::Vec3 DirY;
osg::Vec3 selEdge;
std::vector<osg::Vec3> featurePoints;
std::vector<osg::Vec3> featureVectors;
vector<osg::ref_ptr<osg::Geode>> anAisArrows;
double PAI = 3.1415926;

Function::Function()
{
    
}

void Function::CreatArrow(osg::ref_ptr<osg::Group> root, const osg::Vec3& startPoint, const osg::Vec3& direction)
{
    double radius = 0.3;
    double height = direction.length()*2;
    double coneRadius = 0.5;
    double coneHeight = 2;

    osg::ref_ptr<osg::Cone> cone = new osg::Cone(osg::Vec3(0.0f, 0.0f, height), coneRadius, coneHeight);
    osg::ref_ptr<osg::ShapeDrawable> coneDrawable = new osg::ShapeDrawable(cone.get());

    osg::ref_ptr<osg::Cylinder> cylinder = new osg::Cylinder(osg::Vec3(0.0f, 0.0f, 0.5* height), radius, height);
    osg::ref_ptr<osg::ShapeDrawable> cylinderDrawable = new osg::ShapeDrawable(cylinder.get());

    // 创建变换节点，并将圆柱和圆锥的几何体添加到变换节点中
    osg::ref_ptr<osg::PositionAttitudeTransform> arrowTransform = new osg::PositionAttitudeTransform;
    arrowTransform->addChild(coneDrawable.get());
    arrowTransform->addChild(cylinderDrawable.get());

    // 设置变换节点的位置和方向
    arrowTransform->setPosition(startPoint);
    osg::Vec3 normalizedDirection = direction;
    normalizedDirection.normalize();
    osg::Quat rotation;
    rotation.makeRotate(osg::Vec3(0, 0, 1), normalizedDirection);
    arrowTransform->setAttitude(rotation);

    // 将变换节点添加到箭头的根节点中
    root->addChild(arrowTransform.get());

}

void Function::RemoveArrow(osg::ref_ptr<osg::Group> root, const osg::Vec3& startPoint)
{
    // 查找并删除具有匹配起点的箭头
    for (unsigned int i = 0; i < root->getNumChildren(); i++)
    {
        osg::ref_ptr<osg::Node> child = root->getChild(i);
        osg::ref_ptr<osg::PositionAttitudeTransform> transform = dynamic_cast<osg::PositionAttitudeTransform*>(child.get());
        if (transform && transform->getPosition() == startPoint)
        {
            root->removeChild(i);
            break;
        }
    }
}

void Function::Compute_curvature_dirction(const Eigen::MatrixXd& V0, const Eigen::MatrixXd& PD1, const Eigen::MatrixXd& PD2, const osg::Vec3& point, osg::Vec3& dir1, osg::Vec3& dir2)
{
    // 确定目标点的坐标
    Eigen::Vector3d targetPoint(point.x(), point.y(), point.z());

    double minDistance = std::numeric_limits<double>::max();
    int nearestIndex = -1;

    for (int i = 0; i < V0.rows(); i++) {
        Eigen::Vector3d vertex = V0.row(i);
        double distance = (vertex - targetPoint).squaredNorm();

        if (distance < minDistance) {
            minDistance = distance;
            nearestIndex = i;
        }
    }
    ////输出最近点索引
    //std::cout << "最近点索引" << nearestIndex << std::endl;
    // 获取最近点的最大曲率方向向量
    Eigen::Vector3d maxCurvatureDirection = PD1.row(nearestIndex);
    // 获取最近点的最小曲率方向向量
    Eigen::Vector3d minCurvatureDirection = PD2.row(nearestIndex);
    dir1 = osg::Vec3(maxCurvatureDirection.x(), maxCurvatureDirection.y(), maxCurvatureDirection.z());
    dir2 = osg::Vec3(minCurvatureDirection.x(), minCurvatureDirection.y(), minCurvatureDirection.z());

    std::cout << "最大曲率方向: " << dir1.x() << " " << dir1.y() << " " << dir1.z() << " " << std::endl;
    std::cout << "最小曲率方向: " << dir2.x() << " " << dir2.y() << " " << dir2.z() << " " << std::endl;
}

void Function::TransformPoint(const osg::Vec3& localDirection, const osg::Vec3& localOrigin, const osg::Vec3& localXAxis, const osg::Vec3& localYAxis, osg::Vec3& mainDirection)
{
    // 计算局部坐标系的第三个坐标轴
    osg::Vec3d localZAxis = localXAxis ^ localYAxis;

    double x = localDirection.x() * localXAxis.x() + localDirection.y() * localYAxis.x() + localDirection.z() * localZAxis.x();
    double y = localDirection.x() * localXAxis.y() + localDirection.y() * localYAxis.y() + localDirection.z() * localZAxis.y();
    double z = localDirection.x() * localXAxis.z() + localDirection.y() * localYAxis.z() + localDirection.z() * localZAxis.z();

    // 将结果赋值给mainDirection
    mainDirection.set(x, y, z);
}

osg::ref_ptr<osg::Geometry> Function::CreateSquarePlane(const osg::Vec3& center, const osg::Vec3& dir1, const osg::Vec3& dir2)
{
    double halfSize = 3;
    osg::Vec3 v0 = center - dir1 * halfSize - dir2 * halfSize;        // 左下角顶点
    osg::Vec3 v1 = v0 + dir1 * halfSize * 2;                          // 右下角顶点
    osg::Vec3 v2 = v1 + dir2 * halfSize * 2;                          // 右上角顶点
    osg::Vec3 v3 = v2 - dir1 * halfSize * 2;                          // 左上角顶点

    osg::ref_ptr<osg::Geometry> squareGeometry = new osg::Geometry;
    osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
    vertices->push_back(v0);
    vertices->push_back(v1);
    vertices->push_back(v2);
    vertices->push_back(v3);
    squareGeometry->setVertexArray(vertices.get());

    osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
    indices->push_back(0);
    indices->push_back(1);
    indices->push_back(2);
    indices->push_back(3);
    squareGeometry->addPrimitiveSet(indices.get());

    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array();
    colors->push_back(osg::Vec4(1.0f, 1.0f, 1.0f, 0.5f)); // 设置白色，并且透明度为百分之五十
    squareGeometry->setColorArray(colors);
    squareGeometry->setColorBinding(osg::Geometry::BIND_OVERALL);
    return squareGeometry;
}

osg::ref_ptr<osg::Geometry> Function::CreatCoordinateSystem(const osg::Vec3& center, const osg::Vec3& direction1, const osg::Vec4& color)
{
    ref_ptr<Geometry> xAxisGeometry = new Geometry;
    ref_ptr<Vec3Array> xAxisVertices = new Vec3Array;
    xAxisVertices->push_back(center);
    xAxisVertices->push_back(center + direction1);
    xAxisGeometry->setVertexArray(xAxisVertices.get());

    ref_ptr<Vec4Array> xAxisColors = new Vec4Array;
    xAxisColors->push_back(color);  
    xAxisGeometry->setColorArray(xAxisColors.get());
    xAxisGeometry->setColorBinding(Geometry::BIND_OVERALL);
    xAxisGeometry->addPrimitiveSet(new DrawArrays(PrimitiveSet::LINES, 0, 2));

    return xAxisGeometry;
}

void Function::genPlaneCoordinateSystem()
{
    // 删除上一次生成的切平面
    if (lastPlaneGeode)
        Root->removeChild(lastPlaneGeode);
    QMainWindow mainWindow;
    //获取最大最小曲率方向
    Compute_curvature_dirction(V0, PD1, PD2, startPoint, DirX, DirY);
    osg::ref_ptr<osg::Geode> planeGeode = new osg::Geode();
    osg::ref_ptr<osg::Geometry> quadGeometry = CreateSquarePlane(startPoint, DirX, DirY);
    planeGeode->addDrawable(quadGeometry);
    osg::Vec4 red = Vec4(1.0f, 0.0f, 0.0f, 1.0f);
    osg::Vec4 green = Vec4(0.0f, 1.0f, 0.0f, 1.0f);
    osg::ref_ptr<osg::Geometry> xGeometry = CreatCoordinateSystem(startPoint, DirX, red);
    osg::ref_ptr<osg::Geometry> yGeometry = CreatCoordinateSystem(startPoint, DirY, green);
    planeGeode->addDrawable(xGeometry);
    planeGeode->addDrawable(yGeometry);
    Root->addChild(planeGeode);
    lastPlaneGeode = planeGeode;  // 保存当前生成的切平面节点
    OsgWidget* osgWidget = new OsgWidget(0, Qt::Widget, osgViewer::ViewerBase::SingleThreaded, Root);
    mainWindow.setCentralWidget(osgWidget);
}

void Function::genArrow0(const osg::Vec3& input)
{
    QMainWindow mainWindow;
    osg::Vec3 direction = input;
    CreatArrow(Root, startPoint, direction);
    OsgWidget* osgWidget = new OsgWidget(0, Qt::Widget, osgViewer::ViewerBase::SingleThreaded, Root);
    mainWindow.setCentralWidget(osgWidget);
}

void Function::genArrow(const osg::Vec3& input)
{
    QMainWindow mainWindow;
    osg::Vec3 realInput;
    TransformPoint(input, startPoint, DirX, DirY, realInput);
    osg::Vec3 direction = realInput;
    CreatArrow(Root, startPoint, direction);
    OsgWidget* osgWidget = new OsgWidget(0, Qt::Widget, osgViewer::ViewerBase::SingleThreaded, Root);
    mainWindow.setCentralWidget(osgWidget);
}

void Function::deleteArrow()
{
    QMainWindow mainWindow;
    RemoveArrow(Root, startPoint);
    OsgWidget* osgWidget = new OsgWidget(0, Qt::Widget, osgViewer::ViewerBase::SingleThreaded, Root);
    mainWindow.setCentralWidget(osgWidget);
}
