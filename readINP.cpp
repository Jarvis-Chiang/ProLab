#include "readINP.h"
//#include "ProLab.h"

readINP::readINP() {
    //readVertex();
};

void readINP::readVertex(string filename, osg::ref_ptr<osg::Geode> geode, Eigen::MatrixXd& Vb, Eigen::MatrixXd& PD1, Eigen::MatrixXd& PD2)
{
    ifstream inputFile(filename);
    string line;
    vector<osg::Vec3> vertexPoints;// 存储顶点信息

    int a = 0;
    int b = 0;

    osg::ref_ptr<osg::Geometry> pointGeometry = new osg::Geometry;
    osg::ref_ptr<osg::Vec3Array> pointVertices = new osg::Vec3Array;
    osg::ref_ptr<osg::Vec4Array> pointColors = new osg::Vec4Array;

    osg::ref_ptr<osg::Geometry> faceGeometry = new osg::Geometry;
    osg::ref_ptr<osg::Vec3Array> faceVertices = new osg::Vec3Array;
    osg::ref_ptr<osg::Vec4Array> faceColors = new osg::Vec4Array;

    osg::ref_ptr<osg::Geometry> edgeGeometry = new osg::Geometry;
    osg::ref_ptr<osg::Vec3Array> edgeVertices = new osg::Vec3Array;
    osg::ref_ptr<osg::Vec4Array> edgeColors = new osg::Vec4Array;

    std::vector<Eigen::Vector4i> tetrahedraIndices;

    while (getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string keyword;

        iss >> keyword;

        for (auto it = line.begin(); it != line.end(); ++it)
        {
            if (*it == ',')
            {
                line.erase(it);
                --it;
            }
        }
        if (keyword == "*NODE")a = 1;
        if (keyword == "**HWCOLOR")b = 1;
        if (keyword == "*ELEMENT")a = 2;

        if (a == 1 && b != 1 && keyword != "*NODE")
        {
            std::istringstream issVertex(line);
            int vertexId;
            double x, y, z;
            issVertex >> vertexId >> x >> y >> z;
            if (vertexId >= vertexPoints.size())
            {
                vertexPoints.resize(vertexId + 1);
                //vertices.resize(vertexId + 1);
            }
            vertexPoints[vertexId]= osg::Vec3(x,y,z);
        }
        else if (a == 2 && line != "*****" && keyword != "*ELEMENT")
        {
            std::istringstream issElement(line);
            int elementId;
            int node1, node2, node3, node4;
            issElement >> elementId >> node1 >> node2 >> node3 >> node4;
            Eigen::Vector4i indices;
            indices << node1, node2, node3, node4;
            tetrahedraIndices.push_back(indices);

            
        }
    }




    //Libigl生成外表面索引F
    Eigen::MatrixXi T(tetrahedraIndices.size(), 4);
    Eigen::MatrixXi F; // 输出的边界面
    for (int i = 0; i < tetrahedraIndices.size(); i++)
    {
        T.row(i) = tetrahedraIndices[i];
    }
    igl::boundary_facets(T, F);
    std::cout << "Number of extracted all tetrahedrons: " << T.rows() << std::endl;
    std::cout << "Number of extracted outer faces: " << F.rows() << std::endl;

    //获取V
    Eigen::MatrixXd V(vertexPoints.size(), 3);
    for (int i = 0; i < vertexPoints.size(); i++)
    {
        auto point = vertexPoints[i];
        V(i, 0) = point.x();
        V(i, 1) = point.y();
        V(i, 2) = point.z();
    }

    // 3. 提取外表面的顶点坐标V_boundary和更新面索引F_boundary
    Eigen::MatrixXd V_boundary(V.rows(), 3);
    Eigen::MatrixXi F_boundary(F.rows(), 3);
    std::vector<int> boundary_vertex_indices(V.rows(), -1); // 初始化为-1，用于标记未被提取的顶点
    int vertex_count = 0;
    for (int i = 0; i < F.rows(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int vertex_index = F(i, j);
            if (boundary_vertex_indices[vertex_index] == -1)
            {
                boundary_vertex_indices[vertex_index] = vertex_count;
                V_boundary.row(vertex_count) = V.row(vertex_index);
                vertex_count++;
            }
            F_boundary(i, j) = boundary_vertex_indices[vertex_index];
        }
    }
    V_boundary.conservativeResize(vertex_count, 3); // 调整V_boundary的大小

    //// 输出 V_boundary
    //std::cout << "V_boundary:\n";
    //for (int i = 0; i < V_boundary.rows(); i++)
    //{
    //    std::cout << i << " " << V_boundary(i, 0) << " " << V_boundary(i, 1) << " " << V_boundary(i, 2) << std::endl;
    //}
    //// 输出 F_boundary
    //std::cout << "F_boundary:\n";
    //for (int i = 0; i < F_boundary.rows(); i++)
    //{
    //    std::cout << F_boundary(i, 0) << " " << F_boundary(i, 1) << " " << F_boundary(i, 2) << std::endl;
    //}

    for (int i = 0; i < V_boundary.rows(); ++i)
    {
        osg::Vec3 vertex(V_boundary(i, 0), V_boundary(i, 1), V_boundary(i, 2));
        pointVertices->push_back(vertex);
        pointColors->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f));
    }
    pointGeometry->setVertexArray(pointVertices.get());
    pointGeometry->setColorArray(pointColors.get());
    pointGeometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
    pointGeometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, pointVertices->size()));

    // 将点的 Geometry 添加到 Geode
    geode->addDrawable(pointGeometry.get());

    // 创建点的渲染属性 osg::Point
    osg::ref_ptr<osg::Point> point = new osg::Point;
    point->setSize(5.0f); // 设置点的大小

    // 将点的渲染属性应用到点对象
    geode->getOrCreateStateSet()->setAttributeAndModes(point, osg::StateAttribute::ON);

    for (int i = 0; i < F_boundary.rows(); ++i)
    {
        for (int j = 0; j < F_boundary.cols(); ++j)
        {
            int vertexIndex = F_boundary(i, j);
            osg::Vec3 vertex(V_boundary(vertexIndex, 0), V_boundary(vertexIndex, 1), V_boundary(vertexIndex, 2));
            faceVertices->push_back(vertex);

            int vertexIndex1 = F_boundary(i, j);
            int vertexIndex2 = F_boundary(i, (j + 1) % F_boundary.cols());
            osg::Vec3 vertex1(V_boundary(vertexIndex1, 0), V_boundary(vertexIndex1, 1), V_boundary(vertexIndex1, 2));
            osg::Vec3 vertex2(V_boundary(vertexIndex2, 0), V_boundary(vertexIndex2, 1), V_boundary(vertexIndex2, 2));
            edgeVertices->push_back(vertex1);
            edgeVertices->push_back(vertex2);
            edgeColors->push_back(osg::Vec4(1.0f, 1.0f, 0.0f, 1.0f));
        }
        faceColors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f));
    }
    // 设置边的顶点数据
    edgeGeometry->setVertexArray(edgeVertices.get());
    edgeGeometry->setColorArray(edgeColors.get());
    edgeGeometry->setColorBinding(osg::Geometry::BIND_OVERALL);

    osg::ref_ptr<osg::DrawArrays> drawArrays = new osg::DrawArrays(osg::PrimitiveSet::LINES, 0, edgeVertices->size());

    // 将DrawArrays对象添加到几何体的绘制列表中
    edgeGeometry->addPrimitiveSet(drawArrays.get());

    // 设置边的宽度
    osg::ref_ptr<osg::LineWidth> lineWidth = new osg::LineWidth(1.5f);
    edgeGeometry->getOrCreateStateSet()->setAttributeAndModes(lineWidth.get(), osg::StateAttribute::ON);

    // 将边的Geometry对象添加到Geode对象中
    geode->addDrawable(edgeGeometry.get());

    faceGeometry->setVertexArray(faceVertices.get());
    faceGeometry->setColorArray(faceColors.get());
    faceGeometry->setColorBinding(osg::Geometry::BIND_OVERALL);

    // 添加面的绘制方式
    faceGeometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::TRIANGLES, 0, faceVertices->size()));

    // 将面的 Geometry 添加到 Geode
    geode->addDrawable(faceGeometry.get());

    // 计算外表面的主曲率
    //Eigen::MatrixXd PD1, PD2; // 主曲率方向
    PD1 = Eigen::MatrixXd();
    PD2 = Eigen::MatrixXd();
    Eigen::VectorXd PV1, PV2; // 主曲率值
    igl::principal_curvature(V_boundary, F_boundary, PD1, PD2, PV1, PV2);

    Vb = Eigen::MatrixXd();
    Vb = V_boundary;
}

