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
    : DemoRibbonWindow(parent)
{
    // init
    setWindowTitle(QObject::tr("ProLab"));
    setWindowIcon(QIcon(":/res/MainWindow/companyLogo.png"));
    setStyleByName(QStringLiteral("Office2007Blue"));
    ribbonBar()->setFrameThemeEnabled();
    QFont defautFont = QApplication::font();
    defautFont.setPointSize(defautFont.pointSize() + 2);
    ribbonBar()->setFont(defautFont);


    RibbonPage* homePage = ribbonBar()->addPage(QStringLiteral("&��ʼ"));
    RibbonPage* cadPage = ribbonBar()->addPage(QStringLiteral("&CAD"));
    RibbonPage* caePage = ribbonBar()->addPage(QStringLiteral("&CAE"));
    RibbonPage* camPage = ribbonBar()->addPage(QStringLiteral("&CAM"));
    
    creatHomeButton(homePage);
    creatCadButton(cadPage);
    creatCaeButton(caePage);
    creatCamButton(camPage);

    creatDockWindows();
    creatAction();
    creatPage(oprDock);
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

void MainWindow::creatAction()
{
    QObject::connect(m_newFile, &QAction::triggered, this, &MainWindow::openFile);
    //QObject::connect(m_addDock, &QAction::triggered, this, &MainWindow::creatPage);
    //QObject::connect(m_addDock, SIGNAL(button1->triggered()), this, SLOT(creatPage(oprDock)));
    
    // ????
    connect(m_addDock, SIGNAL(m_addDock->triggered()), this, SLOT(openFile()));
}

void MainWindow::creatHomeButton(RibbonPage* page)
{
    RibbonGroup* groupHome = page->addGroup(QStringLiteral("�ļ�����"));
    RibbonToolBarControl* toolBar = new RibbonToolBarControl(groupHome);
    m_newFile = toolBar->addAction(QIcon(QStringLiteral(":/res/largeNewFile.png")), QStringLiteral("new"), Qt::ToolButtonTextUnderIcon);
    m_addDock = toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), QStringLiteral("�½��ļ�"), Qt::ToolButtonTextUnderIcon);
    toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), QStringLiteral("�½��ļ�"), Qt::ToolButtonTextUnderIcon);
    toolBar->addSeparator();
    toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), QStringLiteral("�½��ļ�"), Qt::ToolButtonTextUnderIcon);
    toolBar->addAction(QIcon(QStringLiteral("C:/Users/49769/Desktop/plIcon.png")), QStringLiteral("�½��ļ�2"), Qt::ToolButtonTextUnderIcon);
    groupHome->addControl(toolBar);
}


void MainWindow::creatCadButton(RibbonPage* page)
{
    RibbonGroup* groupCad = page->addGroup(QStringLiteral("�ļ�����"));
    RibbonToolBarControl* toolBar = new RibbonToolBarControl(groupCad);
    m_newFile = toolBar->addAction(QIcon(QStringLiteral(":/res/largeNewFile.png")), QStringLiteral("new"), Qt::ToolButtonTextUnderIcon);
    toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), QStringLiteral("�½��ļ�"), Qt::ToolButtonTextUnderIcon);
    toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), QStringLiteral("�½��ļ�"), Qt::ToolButtonTextUnderIcon);
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
    // tree dock
    treeDock = new QDockWidget(tr("Project Tree View"), this);
    treeDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    treeDock->setFeatures(QDockWidget::DockWidgetMovable);
    creatTreeItem(treeDock);
    addDockWidget(Qt::LeftDockWidgetArea, treeDock);
    
   // log dock
    logDock = new QDockWidget(tr("Log Message"), this);
    logDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    logDock->setFeatures(QDockWidget::DockWidgetVerticalTitleBar);
    resizeDocks({ logDock }, { 400 }, Qt::Vertical);
    LogText = new QPlainTextEdit();
    LogText->setReadOnly(true);
    addLog(LogText, "hellow ProLab", MainWindow::INFO);
    addLog(LogText, "hellow ProLab", MainWindow::WARNNING);
    addLog(LogText, "hellow ProLab", MainWindow::ERROR);
    logDock->setWidget(LogText);

    addDockWidget(Qt::BottomDockWidgetArea, logDock);

    // oprDock
    oprDock = new QDockWidget(tr("operate"), this);
    oprDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    oprDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    // addOprPage();
    // oprDock->setWidget();
    addDockWidget(Qt::RightDockWidgetArea, oprDock);

    // graphWidget
    graphWidget = new QWidget();
    graphWidget->setStyleSheet("background-color:black;");
    setCentralWidget(graphWidget);

}

void MainWindow::creatTreeItem(QDockWidget* treeDock)
{
    treeItem = new QWidget();
    QWidget* styleGroup = new QWidget();
    QVBoxLayout* listLayout = new QVBoxLayout();
    QListWidget* customerList = new QListWidget();
    for (int i = 0; 10 > i; i++)
        customerList->addItems(QStringList(QObject::tr("Item %1").arg(i + 1)));
    listLayout->addWidget(customerList);
    styleGroup->setLayout(listLayout);
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(styleGroup);
    styleGroup->autoFillBackground();
    treeItem->setLayout(mainLayout);
    treeDock->setWidget(treeItem);
}

void MainWindow::addLog(QPlainTextEdit* logtext, const QString& message, LOGLEVAL level)
{
    QString log;
    //QString time = QTime::currentTime().toString("hh:mm:ss");

    switch (level)
    {
    case MainWindow::INFO:
        log = QTime::currentTime().toString("hh:mm:ss") + QString(" [ INFO ] ") + message;
        logtext->appendPlainText(log);
        break;
    case MainWindow::WARNNING:
        log = QTime::currentTime().toString("hh:mm:ss") + QString(" [ WARNNING ] ") + message;
        logtext->appendPlainText(log);
        break;
    case MainWindow::ERROR:
        log = QTime::currentTime().toString("hh:mm:ss") + QString(" [ ERROR ] ") + message;
        logtext->appendPlainText(log);
        break;
    }
}

void MainWindow::creatPage(QDockWidget* dock)
{
    QLayout* Lay = dock->layout();
    if (Lay) {
        // ������
    }

    cadOpr = new RibbonPage();
    button1 = new RibbonButton();
    button1->setText(QString("button1"));
    button1->setStyleSheet("background-color:blue;");
    QToolButton* button2 = new RibbonButton();
    button2->setText(QString("button2"));
    QToolButton* button3 = new RibbonButton();
    button3->setText(QString("button3"));
    QToolButton* button4 = new RibbonButton();
    button4->setText(QString("button4"));

    QWidget* wid = new QWidget();
    QGridLayout* Hlayout = new QGridLayout(wid);
    //wid->setMaximumWidth(300);
    //wid->setMinimumWidth(300);
    Hlayout->addWidget(button1);
    Hlayout->addWidget(button2);
    Hlayout->addWidget(button3);
    Hlayout->addWidget(button4);

    dock->setWidget(wid);
}

void MainWindow::openFile()
{
    QMessageBox::information(NULL, QString("openFile"), QString("prolab->now open file"));
    return;
}

