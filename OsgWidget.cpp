#include "OsgWidget.h"
#include "Function.h"
#include "readINP.h"

class MouseEventHandler : public osgGA::GUIEventHandler
{
public:
	MouseEventHandler(const Eigen::MatrixXd& vertices) : vertices_(vertices) {}

	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
	{
		if (ea.getEventType() == osgGA::GUIEventAdapter::PUSH && ea.getButton() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON)
		{
			osgViewer::View* view = dynamic_cast<osgViewer::View*>(&aa);
			if (view)
			{
				int x = ea.getX();
				int y = ea.getY();

				osg::Viewport* viewport = view->getCamera()->getViewport();
				double winX = viewport->x() + x;
				double winY = viewport->y() + y;

				osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector = new osgUtil::LineSegmentIntersector(
					osgUtil::Intersector::WINDOW, winX, winY);
				osgUtil::IntersectionVisitor intersectionVisitor(intersector.get());
				view->getCamera()->accept(intersectionVisitor);

				if (intersector->containsIntersections())
				{
					const osgUtil::LineSegmentIntersector::Intersection& intersection = intersector->getFirstIntersection();
					osg::Vec3 startpoint = intersection.getWorldIntersectPoint();

					// 查找距离最近的顶点
					double minDistance = std::numeric_limits<double>::max();
					osg::Vec3 nearestVertex;

					for (int i = 0; i < vertices_.rows(); ++i)
					{
						osg::Vec3 vertex(vertices_(i, 0), vertices_(i, 1), vertices_(i, 2));
						double distance = (vertex - startpoint).length();
						if (distance < minDistance)
						{
							minDistance = distance;
							startPoint = vertex;

						}
					}
				}
			}
		}

		return false;
	}

private:
	Eigen::MatrixXd vertices_;
};

OsgWidget::OsgWidget(QWidget* parent, Qt::WindowFlags f, osgViewer::ViewerBase::ThreadingModel threadingModel, osg::Node* node):
	view(new osgViewer::View)
{
	setThreadingModel(threadingModel);

	// disable the default setting of viewer.done() by pressing Escape.
	setKeyEventSetsDone(0);

	QWidget* popupWidget = addViewWidget(createGraphicsWindow(900, 100, 800, 600, "Popup window", true), node);
	QGridLayout* grid = new QGridLayout;
	grid->addWidget(popupWidget, 0, 0);
	setLayout(grid);

	connect(&_timer, SIGNAL(timeout()), this, SLOT(update()));
	_timer.start(5);
}

QWidget* OsgWidget::addViewWidget(osgQt::GraphicsWindowQt* gw, osg::Node* scene)
{
	addView(view);

	osg::Camera* camera = view->getCamera();
	camera->setGraphicsContext(gw);

	const osg::GraphicsContext::Traits* traits = gw->getTraits();

	camera->setClearColor(osg::Vec4(0, 0, 0, 1));
	camera->setViewport(new osg::Viewport(0, 0, traits->width, traits->height));
	camera->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(traits->width) / static_cast<double>(traits->height), 1.0f, 10000.0f);

	view->setSceneData(scene);
	view->addEventHandler(new MouseEventHandler(V0));
	view->addEventHandler(new osgViewer::StatsHandler);
	//view->addEventHandler(new osgGA::StateSetManipulator(view->getCamera()->getOrCreateStateSet()));
	view->setCameraManipulator(new osgGA::MultiTouchTrackballManipulator);
	gw->setTouchEventsEnabled(true);
	return gw->getGLWidget();
}

osgQt::GraphicsWindowQt* OsgWidget::createGraphicsWindow(int x, int y, int w, int h, const std::string& name, bool windowDecoration)
{
	osg::DisplaySettings* ds = osg::DisplaySettings::instance().get();
	osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	traits->windowName = name;
	traits->windowDecoration = windowDecoration;
	traits->x = x;
	traits->y = y;
	traits->width = w;
	traits->height = h;
	traits->doubleBuffer = true;
	traits->alpha = ds->getMinimumNumAlphaBits();
	traits->stencil = ds->getMinimumNumStencilBits();
	traits->sampleBuffers = ds->getMultiSamples();
	traits->samples = ds->getNumMultiSamples();

	return new osgQt::GraphicsWindowQt(traits.get());
}

void OsgWidget::paintEvent(QPaintEvent* event)
{
	frame();
}