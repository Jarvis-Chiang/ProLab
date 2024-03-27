#include <QFontComboBox>
#include <QScreen>
#include <QDockWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QGroupBox>
#include <QBoxLayout>
#include <QTreeWidget>
#include <QTime>


#include "aboutdialog.h"
#include "mainwindow.h"
#include "QtitanRibbon.h"
#include "QtitanBase.h"
#include "QtnRibbonButton.h"



/* MainWindow */
MainWindow::MainWindow(QWidget* parent)
    : DemoRibbonWindow(parent),
    topoOptimizeWidget(new TopoOptimizeWidget)
{
    // init
    setWindowTitle(QObject::tr("ProLab"));
    setWindowIcon(QIcon(":/res/MainWindow/companyLogo.png"));
    setStyleByName(QStringLiteral("Office2007Blue"));
    ribbonBar()->setFrameThemeEnabled();
    QFont defautFont = QApplication::font();
    defautFont.setPointSize(defautFont.pointSize() + 2);
    ribbonBar()->setFont(defautFont);


    RibbonPage* homePage = ribbonBar()->addPage("&开始");
    RibbonPage* structureOptiPage = ribbonBar()->addPage("&结构优化");
    RibbonPage* processPlanPage = ribbonBar()->addPage("&工艺规划");
    RibbonPage* cadPage = ribbonBar()->addPage("&CAD");
    RibbonPage* caePage = ribbonBar()->addPage("&CAE");
    RibbonPage* camPage = ribbonBar()->addPage("&CAM");

    creatHomeButton(homePage);
    creatStructureOptiButton(structureOptiPage);
    creatprocessPlanButton(processPlanPage);
    creatCadButton(cadPage);
    creatCaeButton(caePage);
    creatCamButton(camPage);

    creatDockWindows();
    creatConnect();

/*    selectedIndex = treeView->currentIndex();     */                  // selected row


#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    const int factor = 5;
    const QRect availableGeometry = screen()->availableGeometry();
    resize(2 * availableGeometry.width() / factor, 2 * availableGeometry.height() / (factor * 3));
    move((availableGeometry.width() - width()) / 2, (availableGeometry.height() - height()) / 2);
#else
    resize(1000, 300); move(200, 200);
#endif
}

MainWindow::~MainWindow()
{
}

void MainWindow::creatConnect()
{
    QObject::connect(m_newFile, &QAction::triggered, this, &MainWindow::openFile);
    QObject::connect(m_Topo2D, &QAction::triggered, this, &MainWindow::topo2D);
    QObject::connect(m_Topo3D, &QAction::triggered, this, &MainWindow::topo3D);

    QObject::connect(m_VectorDriven, &QAction::triggered, this, &MainWindow::on_vectorFieldDriven_trigged);
    QObject::connect(m_OffsetPath, &QAction::triggered, this, &MainWindow::on_offset_trigged);
    QObject::connect(m_GradientFilling, &QAction::triggered, this, &MainWindow::on_GradientFilling_trigged);
    QObject::connect(m_ReferenceSurfaceBased, &QAction::triggered, this, &MainWindow::on_ReferenceSurfaceBased_trigged);
    QObject::connect(m_VectorFieldBased, &QAction::triggered, this, &MainWindow::on_VectorFieldBased_trigged);

    QObject::connect(m_Finite2D, &QAction::triggered, this, &MainWindow::on_m_Finite2D_trigged);
    QObject::connect(m_Finite3D, &QAction::triggered, this, &MainWindow::on_m_Finite3D_trigged);

    //QObject::connect(m_addDock, &QAction::triggered, this, &MainWindow::creatPage);
    //QObject::connect(m_addDock, SIGNAL(button1->triggered()), this, SLOT(creatPage(oprDock)));

    // ????
    connect(m_addDock, SIGNAL(m_addDock->triggered()), this, SLOT(openFile()));
    //connect(m_Topo2D, SIGNAL(m_Topo2D->triggered()), this, SLOT(topo2D));
    //connect(m_Topo3D, SIGNAL(m_Topo3D->triggered()), this, SLOT(topo3D));
}

void MainWindow::creatHomeButton(RibbonPage* page)
{
    RibbonGroup* groupHome = page->addGroup("文件操作");
    RibbonToolBarControl* toolBar = new RibbonToolBarControl(groupHome);
    m_newFile = toolBar->addAction(QIcon(QStringLiteral(":/res/largeNewFile.png")), "new", Qt::ToolButtonTextUnderIcon);
    m_addDock = toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "新建\n文件", Qt::ToolButtonTextUnderIcon);
    toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "新建\n文件", Qt::ToolButtonTextUnderIcon);
    toolBar->addSeparator();
    toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "新建\n文件", Qt::ToolButtonTextUnderIcon);
    toolBar->addAction(QIcon(QStringLiteral("C:/Users/49769/Desktop/plIcon.png")), "新建\n文件2", Qt::ToolButtonTextUnderIcon);
    groupHome->addControl(toolBar);
}

void MainWindow::creatStructureOptiButton(RibbonPage* page)
{
    RibbonGroup* groupCad = page->addGroup("优化选择");
    RibbonToolBarControl* toolBar = new RibbonToolBarControl(groupCad);
    m_Topo2D = toolBar->addAction(QIcon(QStringLiteral(":/res/largeNewFile.png")), "2D拓扑优化", Qt::ToolButtonTextUnderIcon);
    m_Topo3D = toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "3D拓扑优化", Qt::ToolButtonTextUnderIcon);

    RibbonGroup* groupFinite = page->addGroup("有限元分析");
    RibbonToolBarControl* toolBar_Finite = new RibbonToolBarControl(groupFinite);
    m_Finite2D = toolBar_Finite->addAction(QIcon(QStringLiteral(":/res/largeNewFile.png")), "2D有限元分析", Qt::ToolButtonTextUnderIcon);
    m_Finite3D = toolBar_Finite->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "3D有限元分析", Qt::ToolButtonTextUnderIcon);

    groupCad->addControl(toolBar);
    groupFinite->addControl(toolBar_Finite);
}


void MainWindow::creatprocessPlanButton(RibbonPage* page)
{
    RibbonGroup* groupCad = page->addGroup("路径规划");
    RibbonToolBarControl* toolBar = new RibbonToolBarControl(groupCad);
    m_VectorDriven = toolBar->addAction(QIcon(QStringLiteral(":/res/largeNewFile.png")), "方向场驱动路径", Qt::ToolButtonTextUnderIcon);
    m_OffsetPath = toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "偏移路径", Qt::ToolButtonTextUnderIcon);
    m_GradientFilling = toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "梯度填充路径", Qt::ToolButtonTextUnderIcon);

    RibbonGroup* groupFinite = page->addGroup("曲面切片");
    RibbonToolBarControl* toolBar_Finite = new RibbonToolBarControl(groupFinite);
    m_ReferenceSurfaceBased = toolBar_Finite->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "基准面法曲面切片", Qt::ToolButtonTextUnderIcon);
    m_VectorFieldBased = toolBar_Finite->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "方向场法曲面切片", Qt::ToolButtonTextUnderIcon);
    //m_Topo2D->setCheckable(true);
    //m_Topo3D->setCheckable(true);//设置按下样式
    groupCad->addControl(toolBar);
    groupFinite->addControl(toolBar_Finite);
}

void MainWindow::creatCadButton(RibbonPage* page)
{
    RibbonGroup* groupCad = page->addGroup("文件操作");
    RibbonToolBarControl* toolBar = new RibbonToolBarControl(groupCad);
    m_newFile = toolBar->addAction(QIcon(QStringLiteral(":/res/largeNewFile.png")), "new", Qt::ToolButtonTextUnderIcon);
    toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "新建\n文件", Qt::ToolButtonTextUnderIcon);
    toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "新建\n文件", Qt::ToolButtonTextUnderIcon);
    groupCad->addControl(toolBar);
}

void MainWindow::creatCaeButton(RibbonPage* page)
{
}

void MainWindow::creatCamButton(RibbonPage* page)
{
}

void MainWindow::creatDockWindows()
{
    // creat tree dock
    treeDock = new QDockWidget(tr("Project Tree View"), this);
    treeDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    treeDock->setFeatures(QDockWidget::DockWidgetMovable);
    treeDock->setWidget(topoOptimizeWidget->treeStackWidget);
    addDockWidget(Qt::LeftDockWidgetArea, treeDock);
    // creat log dock
    myLogWidget* logWidget = new myLogWidget;
    logDock = new QDockWidget(tr("Log Message"));
    logDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    logDock->setFeatures(QDockWidget::DockWidgetVerticalTitleBar);
    //resizeDocks({ logDock }, { 400 }, Qt::Vertical);
    logDock->setWidget(logWidget);
    LogText = new QPlainTextEdit();
    //LogText->setStyleSheet(QString("background-color: #E7EEF6;"));
    LogText->setReadOnly(true);                                             // set read only
    for (int i = 0; i < 100; i++) {
        addLog(LogText, "hello ProLab", MainWindow::INFO);
        addLog(LogText, "hello ProLab", MainWindow::WARNNING);
        addLog(LogText, "hello ProLab", MainWindow::WRONG);
    }

    logDock->setWidget(LogText);
    addDockWidget(Qt::BottomDockWidgetArea, logDock);

    // creat operate Dock
    oprDock = new QDockWidget(tr("operate"), this);
    oprDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    oprDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // addOprPage();
    oprDock->setWidget(topoOptimizeWidget->oprStackWidget);
    //creatOprPage(oprDock);
    addDockWidget(Qt::RightDockWidgetArea, oprDock);

    // creat graphWidget
    //osg::Node* displaynode = osgDB::readNodeFile("D:/Project_3D_Slice/ProLab/cow.osg");
    //OsgWidget* osgWidget = new OsgWidget(0, Qt::Widget, osgViewer::ViewerBase::SingleThreaded);
    setCentralWidget(topoOptimizeWidget->osgWidget);

}


void MainWindow::addLog(QPlainTextEdit* logtext, const QString& message, LOGLEVAL level)
{
    QString log;
    // set text format
    QTextCharFormat fmt;
    fmt.setFontPointSize(9);
    logtext->document()->setMaximumBlockCount(200);                     // set maximum display rows 

    switch (level)
    {
    case MainWindow::INFO:
        log = QTime::currentTime().toString("hh:mm:ss:zzz ") + QString(" [   INFO\t") + QString("]\t") + message;
        logtext->appendPlainText(log);
        break;
    case MainWindow::WARNNING:
        log = QTime::currentTime().toString("hh:mm:ss:zzz ") + QString(" [  WARNNING\t") + QString("]\t") + message;
        logtext->appendPlainText(log);
        break;
    case MainWindow::WRONG:
        log = QTime::currentTime().toString("hh:mm:ss:zzz ") + QString(" [   ERROR\t") + QString("]\t") + message;
        fmt.setForeground(QColor("red"));
        logtext->mergeCurrentCharFormat(fmt);
        logtext->appendPlainText(log);
        fmt.setForeground(QColor("black"));
        logtext->mergeCurrentCharFormat(fmt);
        break;
    }
}

void MainWindow::creatOprPage(QDockWidget* dock)
{
    QLayout* Lay = dock->layout();
    if (Lay) {
        // clear components
    }

    cadOpr = new RibbonPage();
    button1 = new RibbonButton();
    button1->setText(QString("button1"));
    QToolButton* button2 = new RibbonButton();
    button2->setText(QString("button2"));
    QToolButton* button3 = new RibbonButton();
    button3->setText(QString("button3"));
    QToolButton* button4 = new RibbonButton();
    button4->setText(QString("button4"));

    QWidget* wid = new QWidget();
    QGridLayout* Hlayout = new QGridLayout(wid);
    Hlayout->addWidget(button1);
    Hlayout->addWidget(button2);
    Hlayout->addWidget(button3);
    Hlayout->addWidget(button4);

    dock->setWidget(wid);
}






//**************以下为槽函数**********************//
void MainWindow::openFile()
{
    QMessageBox::information(NULL, QString("openFile"), QString("prolab->now open file"));
    return;
}


void MainWindow::topo2D()
{
    QMessageBox::information(NULL, QString("模块切换"), QString("确定切换至2D拓扑优化模块？"));
    topoOptimizeWidget->oprStackWidget->setCurrentIndex(0);
    topoOptimizeWidget->treeStackWidget->setCurrentIndex(0);
    return;
}

void MainWindow::topo3D()
{
    QMessageBox::information(NULL, QString("模块切换"), QString("确定切换至3D拓扑优化模块？"));
    topoOptimizeWidget->oprStackWidget->setCurrentIndex(6);
    topoOptimizeWidget->treeStackWidget->setCurrentIndex(1);
    return;
}

void MainWindow::on_vectorFieldDriven_trigged()
{
    QMessageBox::information(NULL, QString("模块切换"), QString("确定切换至方向场驱动路径模块？"));
    topoOptimizeWidget->oprStackWidget->setCurrentIndex(11);
    topoOptimizeWidget->treeStackWidget->setCurrentIndex(2);
}

void MainWindow::on_offset_trigged()
{
    QMessageBox::information(NULL, QString("模块切换"), QString("确定切换至偏移路径模块？"));
    topoOptimizeWidget->oprStackWidget->setCurrentIndex(13);
    topoOptimizeWidget->treeStackWidget->setCurrentIndex(3);
}

void MainWindow::on_GradientFilling_trigged()
{
    QMessageBox::information(NULL, QString("模块切换"), QString("确定切换至梯度填充路径模块？"));
    topoOptimizeWidget->oprStackWidget->setCurrentIndex(15);
    topoOptimizeWidget->treeStackWidget->setCurrentIndex(4);
}

void MainWindow::on_ReferenceSurfaceBased_trigged()
{
    QMessageBox::information(NULL, QString("模块切换"), QString("确定切换至基准面法曲面模块？"));
    topoOptimizeWidget->oprStackWidget->setCurrentIndex(17);
    topoOptimizeWidget->treeStackWidget->setCurrentIndex(5);
}

void MainWindow::on_VectorFieldBased_trigged()
{
    QMessageBox::information(NULL, QString("模块切换"), QString("确定切换至方向场法曲面模块？"));
    topoOptimizeWidget->oprStackWidget->setCurrentIndex(22);
    topoOptimizeWidget->treeStackWidget->setCurrentIndex(6);
}

void MainWindow::on_m_Finite2D_trigged()
{
    QMessageBox::information(NULL, QString("模块切换"), QString("确定切换至2D有限元分析模块？"));
    topoOptimizeWidget->oprStackWidget->setCurrentIndex(27);
    topoOptimizeWidget->treeStackWidget->setCurrentIndex(7);
}

void MainWindow::on_m_Finite3D_trigged()
{
    QMessageBox::information(NULL, QString("模块切换"), QString("确定切换至3D有限元分析模块？"));
    topoOptimizeWidget->oprStackWidget->setCurrentIndex(33);
    topoOptimizeWidget->treeStackWidget->setCurrentIndex(8);
}