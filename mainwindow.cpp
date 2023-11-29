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


    RibbonPage* homePage = ribbonBar()->addPage("&��ʼ");
    RibbonPage* cadPage = ribbonBar()->addPage("&CAD");
    RibbonPage* caePage = ribbonBar()->addPage("&CAE");
    RibbonPage* camPage = ribbonBar()->addPage("&CAM");

    creatHomeButton(homePage);
    creatCadButton(cadPage);
    creatCaeButton(caePage);
    creatCamButton(camPage);

    creatDockWindows();
    creatConnect();

    selectedIndex = treeView->currentIndex();                       // selected row


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
    //QObject::connect(m_addDock, &QAction::triggered, this, &MainWindow::creatPage);
    //QObject::connect(m_addDock, SIGNAL(button1->triggered()), this, SLOT(creatPage(oprDock)));

    // ????
    connect(m_addDock, SIGNAL(m_addDock->triggered()), this, SLOT(openFile()));
}

void MainWindow::creatHomeButton(RibbonPage* page)
{
    RibbonGroup* groupHome = page->addGroup("�ļ�����");
    RibbonToolBarControl* toolBar = new RibbonToolBarControl(groupHome);
    m_newFile = toolBar->addAction(QIcon(QStringLiteral(":/res/largeNewFile.png")), "new", Qt::ToolButtonTextUnderIcon);
    m_addDock = toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "�½�\n�ļ�", Qt::ToolButtonTextUnderIcon);
    toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "�½�\n�ļ�", Qt::ToolButtonTextUnderIcon);
    toolBar->addSeparator();
    toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), "�½�\n�ļ�", Qt::ToolButtonTextUnderIcon);
    toolBar->addAction(QIcon(QStringLiteral("C:/Users/49769/Desktop/plIcon.png")), "�½�\n�ļ�2", Qt::ToolButtonTextUnderIcon);
    groupHome->addControl(toolBar);
}


void MainWindow::creatCadButton(RibbonPage* page)
{
    RibbonGroup* groupCad = page->addGroup("�ļ�����");
    RibbonToolBarControl* toolBar = new RibbonToolBarControl(groupCad);
    m_newFile = toolBar->addAction(QIcon(QStringLiteral(":/res/largeNewFile.png")), QStringLiteral("new"), Qt::ToolButtonTextUnderIcon);
    toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), QStringLiteral("�½�\n�ļ�"), Qt::ToolButtonTextUnderIcon);
    toolBar->addAction(QIcon(QStringLiteral(":/res/MainWindow/companyLogo.png")), QStringLiteral("�½�\n�ļ�"), Qt::ToolButtonTextUnderIcon);
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
    creatTreeItem(treeDock);
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
        addLog(LogText, "hello ProLab", MainWindow::ERROR);
    }

    logDock->setWidget(LogText);
    addDockWidget(Qt::BottomDockWidgetArea, logDock);

    // creat operate Dock
    myOprWidget* oprWidget = new myOprWidget;
    oprDock = new QDockWidget(tr("operate"), this);
    oprDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    oprDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // addOprPage();
    // oprDock->setWidget();
    creatOprPage(oprDock);
    addDockWidget(Qt::RightDockWidgetArea, oprDock);

    // creat graphWidget
    graphWidget = new QWidget();
    graphWidget->setStyleSheet("background-color:black;");
    setCentralWidget(graphWidget);

}

void MainWindow::creatTreeItem(QDockWidget* treeDock)
{
    treeView = new QTreeView;
    treeView->setHeaderHidden(true);                            // hide header, otherwise display a ugly header
    QList<QStandardItem*> list_domain;
    auto item_domain = new QStandardItem("�����");
    list_domain.push_back(item_domain);

    QList<QStandardItem*> list_material;
    auto item_material = new QStandardItem("��������");
    list_material.push_back(item_material);


    QList<QStandardItem*> list_boundary;
    auto item_boundary = new QStandardItem("�߽�����");
    list_boundary.push_back(item_boundary);

    QList<QStandardItem*> list_load;
    auto item_load = new QStandardItem("�غ�����");
    list_load.push_back(item_load);

    QList<QStandardItem*> list_optimization;
    auto item_optimization = new QStandardItem("�Ż�����");
    list_optimization.push_back(item_optimization);

    QList<QStandardItem*> list_result;
    auto item_result = new QStandardItem("����鿴");
    list_result.push_back(item_result);

    model.appendRow(list_domain);
    model.appendRow(list_material);
    model.appendRow(list_boundary);
    model.appendRow(list_load);
    model.appendRow(list_optimization);
    model.appendRow(list_result);

    treeView->setModel(&model);
    treeDock->setWidget(treeView);
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
    case MainWindow::ERROR:
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

