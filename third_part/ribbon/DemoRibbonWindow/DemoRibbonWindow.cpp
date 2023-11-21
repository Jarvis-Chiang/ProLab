#include <QApplication>
#include <QScreen>
#include <QSettings>
#include <QBuffer>
#include <QDir>
#include <QFileInfo>
#include <QActionGroup>
#include <QFileDialog>
#include <QInputDialog>
#include <QDesktopServices>

#include "aboutdialog.h"
#include "DemoRibbonWindow.h"


/* DemoRibbonWindow */
DemoRibbonWindow::DemoRibbonWindow(QWidget* parent)
    : RibbonMainWindow(parent)
    , m_defaultStyle(qApp->style()->objectName())
    , m_styleName(QStringLiteral("Default"))
    , m_loggingIn(false)
    , m_defaultFont(QFont())
{
    ToolTip::setWrapMode(ToolTip::NativeWrap);
    //Add Your Company Logo
    //ribbonBar()->setLogoPixmap(QPixmap(QStringLiteral(":/res/MainWindow/companyLogo.png")), Qt::AlignLeft /* Qt::AlignRight */);
    //m_switchUserAction = ribbonBar()->addTitleButton(SegoeMDL2Font::icon(SegoeMDL2Font::AddFriend), tr("Switch User"));

    //Switch User 
    //m_switchUserAction = ribbonBar()->addTitleButton(SegoeMDL2Font::icon(SegoeMDL2Font::AddFriend), tr("Switch User"));
    //m_switchUserAction->setText(tr("Login"));
    //connect(m_switchUserAction, SIGNAL(triggered()), this, SLOT(switchUser()));

    //setting
    //QAction* action = ribbonBar()->addTitleButton(SegoeMDL2Font::icon(SegoeMDL2Font::Setting), tr("Ribbon Display Options"));
    //connect(action, SIGNAL(triggered()), this, SLOT(displayOptions()));

    //QAction* actionAbout = ribbonBar()->addAction(QIcon(QStringLiteral(":/shared/res/about.png")), tr("About"), Qt::ToolButtonIconOnly);
    QAction* actionAbout = ribbonBar()->addAction(QIcon(QStringLiteral("E:/Qt/Developer Machines/QtitanRibbon6.5.0/examples/shared/res/about.png")), tr("About"), Qt::ToolButtonIconOnly);
    actionAbout->setToolTip(tr("Display program<br />information, version number and copyright"));
    connect(actionAbout, SIGNAL(triggered()), this, SLOT(about()));

    createOptions();
    updateStyleActions();
    addSearchBar();
    m_minimizeAction = ribbonBar()->addAction(QIcon(QStringLiteral("E:/Qt/Developer Machines/QtitanRibbon6.5.0/examples/shared/ribbonMinimize.png")), RibbonBar::tr_compatible(QtnRibbonMinimizeActionString), Qt::ToolButtonIconOnly);
    m_minimizeAction->setStatusTip(tr("Show the tab titles on the Ribbon only"));
    m_minimizeAction->setShortcut(tr("Ctrl+F1"));
    connect(m_minimizeAction, SIGNAL(triggered()), this, SLOT(maximizeToggle()));

    connect(ribbonBar(), SIGNAL(minimizationChanged(bool)), this, SLOT(minimizationChangedIcon(bool)));
    connect(ribbonBar()->quickAccessBar(), SIGNAL(showCustomizeMenu(QMenu*)), this, SLOT(showQuickAccessCustomizeMenu(QMenu*)));
    connect(ribbonBar(), SIGNAL(showRibbonContextMenu(QMenu*, QContextMenuEvent*)), this, SLOT(showRibbonContextMenu(QMenu*, QContextMenuEvent*)));

    setBackgroundByName(QLatin1String("treerings"));

    WindowTitleBar* titleBar = WindowTitleBar::get(this);
    titleBar->setBlurBehindWindowEnabled(true); //Enable it, to use RibbonBar::setAcrilycEnabled(true);
}

void DemoRibbonWindow::readSettings()
{
    QSettings settings(this);

    bool autoSave = settings.value(QStringLiteral("autosave"), false).toBool();
    m_autoSaveAction->setChecked(autoSave);
    if (!autoSave)
        return;

    QString styleName = settings.value(QStringLiteral("style"), QStringLiteral("Default")).toString();
    QColor accentColor = qvariant_cast<QColor>(settings.value(QStringLiteral("accentColor")));

    setStyleByName(styleName);
    OfficeStyle* officeStyle = qobject_cast<OfficeStyle*>(qApp->style());
    if (!accentColor.isValid() && officeStyle != Q_NULL)
        officeStyle->setAccentColor(accentColor);

    QByteArray data = settings.value(QStringLiteral("ribbonUICustomization")).toByteArray();
    {
        QBuffer buffer(&data);
        if (!buffer.open(QIODevice::ReadOnly))
            Q_ASSERT(false);
        ribbonBar()->customizeManager()->loadStateFromDevice(&buffer);
    }
    data = settings.value(QStringLiteral("geometry")).toByteArray();
    if (!data.isEmpty())
        restoreGeometry(data);

    const bool minimized = settings.value(QStringLiteral("minimized"), false).toBool();
    ribbonBar()->setMinimized(minimized);

    const bool topPosition = settings.value(QStringLiteral("quickAccessBarPosition"), true).toBool();
    ribbonBar()->setQuickAccessBarPosition(topPosition ? RibbonBar::TopPosition : RibbonBar::BottomPosition);

    QString name = settings.value(QStringLiteral("backgroundName"), QString()).toString();
    setBackgroundByName(name);

    bool simplifiedMode = settings.value(QStringLiteral("simplifiedMode"), false).toBool();
    ribbonBar()->setSimplifiedMode(simplifiedMode);

#if QTN_ACTION_RTL
    bool layoutDirectionRight = settings.value(QStringLiteral("layoutDirection"), layoutDirection() == Qt::RightToLeft).toBool();
    QApplication::setLayoutDirection(layoutDirectionRight ? Qt::RightToLeft : Qt::LeftToRight);
#endif
}

void DemoRibbonWindow::writeSettings()
{
    QSettings settings(this);
    settings.setValue(QStringLiteral("autosave"), m_autoSaveAction->isChecked());
    if (!m_autoSaveAction->isChecked())
    {
        settings.remove(QStringLiteral("ribbonUICustomization"));
        settings.remove(QStringLiteral("style"));
        settings.remove(QStringLiteral("geometry"));
        settings.remove(QStringLiteral("accentColor"));
        settings.remove(QStringLiteral("minimized"));
        settings.remove(QStringLiteral("quickAccessBarPosition"));
        settings.remove(QStringLiteral("backgroundName"));
        settings.remove(QStringLiteral("simplifiedMode"));
        return;
    }

    QByteArray data;
    {
        QBuffer buffer(&data);
        if (!buffer.open(QIODevice::WriteOnly))
            Q_ASSERT(false);
        ribbonBar()->customizeManager()->saveStateToDevice(&buffer);
    }
    settings.setValue(QStringLiteral("ribbonUICustomization"), QVariant(data));

    data = saveGeometry();
    settings.setValue(QStringLiteral("geometry"), data);
    settings.setValue(QStringLiteral("style"), m_styleName);

    if (OfficeStyle* officeStyle = qobject_cast<OfficeStyle*>(qApp->style()))
        settings.setValue(QStringLiteral("accentColor"), QVariant(officeStyle->accentColor()));

    settings.setValue(QStringLiteral("minimized"), ribbonBar()->isMinimized());
    settings.setValue(QStringLiteral("quickAccessBarPosition"), ribbonBar()->quickAccessBarPosition() == RibbonBar::TopPosition);
    settings.setValue(QStringLiteral("backgroundName"), backgroundName());
    settings.setValue(QStringLiteral("simplifiedMode"), ribbonBar()->simplifiedMode());

#if QTN_ACTION_RTL
    settings.setValue("layoutDirection", m_actionRTL->isChecked());
#endif
}

QIcon DemoRibbonWindow::createIcon(ImagesId id, bool onlyLarge)
{
    QIcon icon;
    switch (id)
    {
    case Image_New:
        icon.addPixmap(QPixmap(QStringLiteral(":/res/new32x32.png")));
        break;
    case Image_Open:
        if (!onlyLarge)
            icon.addPixmap(QPixmap(QStringLiteral(":/res/open16x16.png")));
        icon.addPixmap(QPixmap(QStringLiteral(":/res/open32x32.png")));
        break;
    case Image_Save:
        if (!onlyLarge)
            icon.addPixmap(QPixmap(QStringLiteral(":/res/save16x16.png")));
        icon.addPixmap(QPixmap(QStringLiteral(":/res/save32x32.png")));
        break;
    case Image_SaveAs:
        if (!onlyLarge)
            icon.addPixmap(QPixmap(QStringLiteral(":/res/saveasfile16x16.png")));
        icon.addPixmap(QPixmap(QStringLiteral(":/res/saveasfile32x32.png")));
        break;
    case Image_Clipboard:
        if (!onlyLarge)
            icon.addPixmap(QPixmap(QStringLiteral(":/res/clipboard16x16.png")));
        icon.addPixmap(QPixmap(QStringLiteral(":/res/clipboard32x32.png")));
        break;
    case Image_Close:
        if (!onlyLarge)
            icon.addPixmap(QPixmap(QStringLiteral(":/res/close16x16.png")));
        icon.addPixmap(QPixmap(QStringLiteral(":/res/close32x32.png")));
        break;
    case Image_Cut:
        icon.addPixmap(QPixmap(QStringLiteral(":/res/cut16x16.png")));
        break;
    case Image_Undo:
        icon.addPixmap(QPixmap(QStringLiteral(":/res/undo16x16.png")));
        break;
    case Image_Redo:
        icon.addPixmap(QPixmap(QStringLiteral(":/res/redo16x16.png")));
        break;
    case Image_Print:
        if (!onlyLarge)
            icon.addPixmap(QPixmap(QStringLiteral(":/res/print16x16.png")));
        icon.addPixmap(QPixmap(QStringLiteral(":/res/print32x32.png")));
        break;
    default:
        Q_ASSERT(false);
        break;
    }
    return icon;
}

QIcon DemoRibbonWindow::createIcon(const QString& smallIcon, const QString& largeIcon)
{
    QIcon icon;
    if (!smallIcon.isEmpty())
        icon.addPixmap(QPixmap(smallIcon));
    if (!largeIcon.isEmpty())
        icon.addPixmap(QPixmap(largeIcon));
    return icon;
}

void DemoRibbonWindow::createOptions()
{
    m_optionsMenu = ribbonBar()->addMenu(tr("Options"));
    
    // Auto Save to XML/FastInfoset
    m_autoSaveAction = new ToggleSwitchAction(tr("&AutoSave (new)"), this);
    m_autoSaveAction->setCheckable(true);
    m_autoSaveAction->setChecked(false);
    m_optionsMenu->addAction(m_autoSaveAction);
    m_optionsMenu->addSeparator();

    m_backgroundMenu = new QMenu(ribbonBar());
    connect(m_backgroundMenu, SIGNAL(triggered(QAction*)), this, SLOT(backgroundChanged(QAction*)));
    QActionGroup* actionGroup = new QActionGroup(m_backgroundMenu);
    QAction* backgroundAction = m_optionsMenu->addAction(tr("Background"));
    backgroundAction->setMenu(m_backgroundMenu);

    QAction* action = m_backgroundMenu->addAction(tr("Clouds"));
    action->setObjectName("clouds");
    actionGroup->addAction(action);
    action->setCheckable(true);
    action = m_backgroundMenu->addAction(tr("Tree Rings"));
    action->setObjectName("treerings");
    actionGroup->addAction(action);
    action->setCheckable(true);
    action = m_backgroundMenu->addAction(tr("Calligraphy"));
    action->setObjectName("calligraphy");
    actionGroup->addAction(action);
    action->setCheckable(true);
    action = m_backgroundMenu->addAction(tr("Green Fantasy"));
    action->setObjectName("greenfantasy");
    actionGroup->addAction(action);
    action->setCheckable(true);
    action = m_backgroundMenu->addAction(tr("Autumn Mood"));
    action->setObjectName("autumnmood");
    actionGroup->addAction(action);
    action->setCheckable(true);

    m_styleMenu = new QMenu(ribbonBar());
    actionGroup = new QActionGroup(m_styleMenu);
    connect(m_styleMenu, SIGNAL(triggered(QAction*)), this, SLOT(styleChanged(QAction*)));

    QAction* styleAction = m_optionsMenu->addAction(tr("Style"));
    styleAction->setMenu(m_styleMenu);

    action = m_styleMenu->addAction(tr("Default"));
    action->setObjectName(QStringLiteral("Default"));
    action->setCheckable(true);
    //action->setChecked(true);
    actionGroup->addAction(action);

    action = m_styleMenu->addAction(tr("Fusion"));
    action->setObjectName(QStringLiteral("Fusion"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    m_styleMenu->addSeparator();

    QMenu* adobePhotoshopMenu = new QMenu(tr("Adobe Photoshop"), this);
    m_styleMenu->addMenu(adobePhotoshopMenu);

    action = adobePhotoshopMenu->addAction(tr("Light Gray"));
    action->setObjectName(QStringLiteral("AdobePhotoshopLightGray"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = adobePhotoshopMenu->addAction(tr("Gray"));
    action->setObjectName(QStringLiteral("AdobePhotoshopGray"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = adobePhotoshopMenu->addAction(tr("Dark Gray"));
    action->setObjectName(QStringLiteral("AdobePhotoshopDarkGray"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = adobePhotoshopMenu->addAction(tr("Black"));
    action->setObjectName(QStringLiteral("AdobePhotoshopBlack"));
    action->setCheckable(true);
    actionGroup->addAction(action);


    QMenu* visualStudioMenu = new QMenu(tr("Visual Studio 2019"), this);
    m_styleMenu->addMenu(visualStudioMenu);

    action = visualStudioMenu->addAction(tr("Light"));
    action->setObjectName(QStringLiteral("VisualStudioLight"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = visualStudioMenu->addAction(tr("Blue"));
    action->setObjectName(QStringLiteral("VisualStudioBlue"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = visualStudioMenu->addAction(tr("Dark"));
    action->setObjectName(QStringLiteral("VisualStudioDark"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    m_styleMenu->addSeparator();


    QMenu* office2007Menu = new QMenu(tr("Office 2007"), this);
    m_styleMenu->addMenu(office2007Menu);
    m_styleMenu->addSeparator();

    action = office2007Menu->addAction(tr("Blue"));
    action->setObjectName(QStringLiteral("Office2007Blue"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = office2007Menu->addAction(tr("Black"));
    action->setObjectName(QStringLiteral("Office2007Black"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = office2007Menu->addAction(tr("Silver"));
    action->setObjectName(QStringLiteral("Office2007Silver"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = office2007Menu->addAction(tr("Aqua"));
    action->setObjectName(QStringLiteral("Office2007Aqua"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = m_styleMenu->addAction(tr("Windows 7 Scenic"));
    action->setObjectName(QStringLiteral("Windows7Scenic"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    m_styleMenu->addSeparator();

    QMenu* office2010Menu = new QMenu(tr("Office 2010"), this);
    m_styleMenu->addMenu(office2010Menu);
    m_styleMenu->addSeparator();

    action = office2010Menu->addAction(tr("Blue"));
    action->setObjectName(QStringLiteral("Office2010Blue"));
    action->setCheckable(true);
    action->setChecked(true);
    actionGroup->addAction(action);

    action = office2010Menu->addAction(tr("Silver"));
    action->setObjectName(QStringLiteral("Office2010Silver"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = office2010Menu->addAction(tr("Black"));
    action->setObjectName(QStringLiteral("Office2010Black"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    QMenu* office2013Menu = new QMenu(tr("Office 2013"), this);
    m_styleMenu->addMenu(office2013Menu);
    m_styleMenu->addSeparator();

    action = office2013Menu->addAction(tr("White"));
    action->setObjectName(QStringLiteral("Office2013White"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = office2013Menu->addAction(tr("Light Gray"));
    action->setObjectName(QStringLiteral("Office2013Gray"));
    action->setCheckable(true);
    m_styleMenu->addMenu(office2013Menu);
    actionGroup->addAction(action);

    action = office2013Menu->addAction(tr("Dark Gray"));
    action->setObjectName(QStringLiteral("Office2013Dark"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    QMenu* office2016Menu = new QMenu(tr("Office 2016"), this);
    m_styleMenu->addMenu(office2016Menu);
    m_optionsMenu->addSeparator();

    action = office2016Menu->addAction(tr("Colorful"));
    action->setObjectName(QStringLiteral("Office2016Colorful"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = office2016Menu->addAction(tr("White"));
    action->setObjectName(QStringLiteral("Office2016White"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = office2016Menu->addAction(tr("Dark Gray"));
    action->setObjectName(QStringLiteral("Office2016DarkGray"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    action = office2016Menu->addAction(tr("Black"));
    action->setObjectName(QStringLiteral("Office2016Black"));
    action->setCheckable(true);
    actionGroup->addAction(action);

    m_animationAction = m_optionsMenu->addAction(tr("Animation Enabled"));
    m_animationAction->setCheckable(true);
    m_animationAction->setChecked(true);
    connect(m_animationAction, SIGNAL(triggered(bool)), this, SLOT(animationEnabled(bool)));

    m_simplifiedModeAction = m_optionsMenu->addAction(tr("Simplified mode Enabled (new)"));
    m_simplifiedModeAction->setCheckable(true);
    m_simplifiedModeAction->setChecked(true);
    connect(m_simplifiedModeAction, SIGNAL(triggered(bool)), this, SLOT(simplifiedModeEnabled(bool)));

    m_optionsMenu->addSeparator();

    QAction* actionTitleGroupsVisible = m_optionsMenu->addAction(tr("Title Groups Visible"));
    actionTitleGroupsVisible ->setCheckable(true);
    actionTitleGroupsVisible ->setChecked(true);
    connect(actionTitleGroupsVisible , SIGNAL(triggered(bool)), this, SLOT(setTitleGroupsVisible(bool)));

    m_optionsMenu->addSeparator();

    QAction* actionMenu = m_optionsMenu->addAction(tr("Font"));
    QMenu* fontMenu = new QMenu(ribbonBar());
    QActionGroup* group = new QActionGroup(this);
    m_actionMinimal = fontMenu->addAction(tr("Minimal"));
    m_actionMinimal->setCheckable(true);
    group->addAction(m_actionMinimal);

    m_actionNormal = fontMenu->addAction(tr("Normal"));
    m_actionNormal->setCheckable(true);
    m_actionNormal->setChecked(true);
    group->addAction(m_actionNormal);

    m_actionMedium = fontMenu->addAction(tr("Medium"));
    m_actionMedium->setCheckable(true);
    group->addAction(m_actionMedium);

    m_actionLarge = fontMenu->addAction(tr("Large"));
    m_actionLarge->setCheckable(true);
    group->addAction(m_actionLarge);

    m_actionExLarge = fontMenu->addAction(tr("Extra Large"));
    m_actionExLarge->setCheckable(true);
    //m_actionExLarge->setChecked(true);
    group->addAction(m_actionExLarge);

    actionMenu->setMenu(fontMenu);

    connect(group, SIGNAL(triggered(QAction*)), this, SLOT(fontChanged(QAction*)));

    m_optionsMenu->addSeparator();

    QAction* actionFrameThemeEnabled = m_optionsMenu->addAction(tr("Styled TitleBar"));
    actionFrameThemeEnabled->setCheckable(true);
    connect(actionFrameThemeEnabled, SIGNAL(triggered(bool)), ribbonBar(), SLOT(setFrameThemeEnabled(bool)));
    connect(ribbonBar(), SIGNAL(frameThemeChanged(bool)), actionFrameThemeEnabled, SLOT(setChecked(bool)));

    QAction* acrilycEnabled = m_optionsMenu->addAction(tr("Acrilyc Enabled (new)"));
    connect(acrilycEnabled, SIGNAL(triggered(bool)), ribbonBar(), SLOT(setAcrilycEnabled(bool)));
    acrilycEnabled->setCheckable(true);

    QAction* contextualTabsVisible = m_optionsMenu->addAction(tr("Contextual Tabs"));
    connect(contextualTabsVisible, SIGNAL(triggered(bool)), ribbonBar(), SLOT(setContextualTabsVisible(bool)));
    contextualTabsVisible->setCheckable(true);
    contextualTabsVisible->setChecked(true);

    QAction* tabBarAction = m_optionsMenu->addAction(tr("Page Tabs Position"));
    QMenu* tabBarMenu = new QMenu(ribbonBar());
    tabBarAction->setMenu(tabBarMenu);
    QActionGroup* tabBarActionGroup = new QActionGroup(this);

    m_tabBarTopAction = tabBarMenu->addAction(tr("At Top"));
    m_tabBarTopAction->setCheckable(true);
    m_tabBarTopAction->setChecked(true);
    tabBarActionGroup->addAction(m_tabBarTopAction);

    m_tabBarBottomAction = tabBarMenu->addAction(tr("At Bottom"));
    m_tabBarBottomAction->setCheckable(true);
    tabBarActionGroup->addAction(m_tabBarBottomAction);
    connect(tabBarActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(tabBarPositionChanged(QAction*)));

    QAction* searchBarAction = m_optionsMenu->addAction(tr("Search Bar Appearance (new)"));
    QMenu* searchBarMenu = new QMenu(ribbonBar());
    searchBarAction->setMenu(searchBarMenu);
    QActionGroup* searchBarActionGroup = new QActionGroup(this);

    m_searchBarCentralAction = searchBarMenu->addAction(tr("Central"));
    m_searchBarCentralAction->setCheckable(true);
    m_searchBarCentralAction->setChecked(true);
    searchBarActionGroup->addAction(m_searchBarCentralAction);

    m_searchBarCompactAction = searchBarMenu->addAction(tr("Compact"));
    m_searchBarCompactAction->setCheckable(true);
    searchBarActionGroup->addAction(m_searchBarCompactAction);

    m_searchBarHddenAction = searchBarMenu->addAction(tr("Hidden"));
    m_searchBarHddenAction->setCheckable(true);
    searchBarActionGroup->addAction(m_searchBarHddenAction);

    connect(searchBarActionGroup, SIGNAL(triggered(QAction*)), this, SLOT(searchBarChanged(QAction*)));
    //searchBarChanged(m_searchBarCentralAction);


    m_optionsMenu->addSeparator();
    m_actionNativeScrollBars = m_optionsMenu->addAction(tr("Native Scroll Bars"));
    m_actionNativeScrollBars->setCheckable(true);
    connect(m_actionNativeScrollBars, SIGNAL(triggered(bool)), this, SLOT(setNativeScrollBars(bool)));
#ifdef Q_OS_MAC
    setNativeScrollBars(true);
#endif
    m_actionNativeDialogs = m_optionsMenu->addAction(tr("Native Dialogs"));
    m_actionNativeDialogs->setCheckable(true);
    connect(m_actionNativeDialogs, SIGNAL(triggered(bool)), this, SLOT(setNativeDialogs(bool)));
 
    m_optionsMenu->addSeparator();
    QAction* save = m_optionsMenu->addAction(tr("Save layout to XML/FastInfoset (new)"));
    connect(save, SIGNAL(triggered()), this, SLOT(saveToXML()));
    
    QAction* load = m_optionsMenu->addAction(tr("Load layout from XML/FastInfoset (new)"));
    connect(load, SIGNAL(triggered()), this, SLOT(loadFromXML()));


#if QTN_ACTION_RTL
    m_actionRTL = m_optionsMenu->addAction(tr("Right to Left Layout"), this, &DemoRibbonWindow::switchLayoutDirection);
    m_actionRTL->setCheckable(true);
    m_actionRTL->setChecked(layoutDirection() == Qt::RightToLeft);
#endif
    m_customizeAction = m_optionsMenu->addAction(RibbonBar::tr_compatible(QtnRibbonCustomizeActionString));
    connect(m_customizeAction, SIGNAL(triggered()), this, SLOT(customize()));

    m_showBelowAction = new QAction(RibbonBar::tr_compatible(QtnRibbonShowQuickAccessToolBarBelowString), this);
    m_showAboveAction = new QAction(RibbonBar::tr_compatible(QtnRibbonShowQuickAccessToolBarAboveString), this);
    connect(m_showBelowAction, SIGNAL(triggered()), this, SLOT(switchQuickAccessBarPosition()));
    connect(m_showAboveAction, SIGNAL(triggered()), this, SLOT(switchQuickAccessBarPosition()));

    m_defaultFont = ribbonBar()->font();
}

void DemoRibbonWindow::updateStyleActions()
{
    QList<QAction*> actionList = m_styleMenu->actions();
    for (QList<QAction*>::ConstIterator it = actionList.begin(); it != actionList.end(); ++it)
    {
        QAction* act = (*it);
        if (act->objectName() == m_styleName)
        {
            act->setChecked(true);
            break;
        }
    }

    CommonStyle* style = qobject_cast<CommonStyle*>(qApp->style());
    if (style != Q_NULL && QLatin1String(style->metaObject()->className()) != QStringLiteral(QTITAN_META_CLASSNAME("CommonStyle")))
    {
        style->setScrollBarsIgnored(m_actionNativeScrollBars->isChecked());
        style->setDialogsIgnored(m_actionNativeDialogs->isChecked());
        style->setAnimationEnabled(m_animationAction->isChecked());
        
        m_actionNativeScrollBars->setEnabled(true);
        m_actionNativeDialogs->setEnabled(true);
        m_animationAction->setEnabled(true);
    }
    else
    {
        m_actionNativeScrollBars->setEnabled(false);
        m_actionNativeDialogs->setEnabled(false);
        m_animationAction->setEnabled(false);
    }
}

void DemoRibbonWindow::setStyleByName(const QString& name)
{
    if (m_styleName == name)
        return;

    if (name == QLatin1String("Default"))
    {
        qApp->setStyle(m_defaultStyle);
    }
    else if (name == QLatin1String("Fusion"))
    {
        qApp->setStyle(QLatin1String("fusion"));
    }
    else if (name == QLatin1String("AdobePhotoshopLightGray") ||
        name == QLatin1String("AdobePhotoshopGray") ||
        name == QLatin1String("AdobePhotoshopDarkGray") ||
        name == QLatin1String("AdobePhotoshopBlack"))
    {
        AdobePhotoshopStyle* style = qobject_cast<AdobePhotoshopStyle*>(qApp->style());
        if (style == Q_NULL)
            style = new AdobePhotoshopStyle();
        if (name == QLatin1String("AdobePhotoshopLightGray"))
            style->setTheme(AdobePhotoshopStyle::LightGray);
        if (name == QLatin1String("AdobePhotoshopGray"))
            style->setTheme(AdobePhotoshopStyle::Gray);
        if (name == QLatin1String("AdobePhotoshopDarkGray"))
            style->setTheme(AdobePhotoshopStyle::DarkGray);
        if (name == QLatin1String("AdobePhotoshopBlack"))
            style->setTheme(AdobePhotoshopStyle::Black);
        qApp->setStyle(style);
    }


    else if (name == QLatin1String("VisualStudioLight") ||
        name == QLatin1String("VisualStudioBlue") ||
        name == QLatin1String("VisualStudioDark"))
    {
        VisualStudio2019Style* style = qobject_cast<VisualStudio2019Style*>(qApp->style());
        if (style == Q_NULL)
            style = new VisualStudio2019Style();
        if (name == QLatin1String("VisualStudioLight"))
            style->setTheme(VisualStudio2019Style::Light);
        if (name == QLatin1String("VisualStudioBlue"))
            style->setTheme(VisualStudio2019Style::Blue);
        if (name == QLatin1String("VisualStudioDark"))
            style->setTheme(VisualStudio2019Style::Dark);
        qApp->setStyle(style);
    }
    else if (name == QLatin1String("Office2007Blue")  ||
        name == QLatin1String("Office2007Black") ||
        name == QLatin1String("Office2007Silver")||
        name == QLatin1String("Office2007Aqua"))
    {
        Office2007Style* style = qobject_cast<Office2007Style*>(qApp->style());
        if (style == Q_NULL)
            style = new Office2007Style();
        if (name == QLatin1String("Office2007Blue"))
            style->setTheme(Office2007Style::Blue);
        else if (name == QLatin1String("Office2007Black"))
            style->setTheme(Office2007Style::Black);
        else if (name == QLatin1String("Office2007Silver"))
            style->setTheme(Office2007Style::Silver);
        else if (name == QLatin1String("Office2007Aqua"))
            style->setTheme(Office2007Style::Aqua);
        qApp->setStyle(style);
    }
    else if (name == QLatin1String("Windows7Scenic"))
    {
        Windows7ScenicStyle* style = qobject_cast<Windows7ScenicStyle*>(qApp->style());
        if (style == Q_NULL)
            style = new Windows7ScenicStyle();
        qApp->setStyle(style);
    }
    else if (name == QLatin1String("Office2010Black") ||
        name == QLatin1String("Office2010Blue")  ||
        name == QLatin1String("Office2010Silver"))
    {
        Office2010Style* style = qobject_cast<Office2010Style*>(qApp->style());
        if (style == Q_NULL)
            style = new Office2010Style();
        if (name == QLatin1String("Office2010Black"))
            style->setTheme(Office2010Style::Black);
        else if (name == QLatin1String("Office2010Blue"))
            style->setTheme(Office2010Style::Blue);
        else if (name == QLatin1String("Office2010Silver"))
            style->setTheme(Office2010Style::Silver);
        qApp->setStyle(style);
    }
    else if (name == QLatin1String("Office2013White") ||
        name == QLatin1String("Office2013Gray")  ||
        name == QLatin1String("Office2013Dark"))
    {
        Office2013Style* style = qobject_cast<Office2013Style*>(qApp->style());
        if (style == Q_NULL)
            style = new Office2013Style();
        if (name == QLatin1String("Office2013White"))
            style->setTheme(Office2013Style::White);
        else if (name == QLatin1String("Office2013Gray"))
            style->setTheme(Office2013Style::Gray);
        else if (name == QLatin1String("Office2013Dark"))
            style->setTheme(Office2013Style::Dark);
        qApp->setStyle(style);
    }
    else if (name == QLatin1String("Office2016Colorful") ||
        name == QLatin1String("Office2016White")    ||
        name == QLatin1String("Office2016DarkGray") ||
        name == QLatin1String("Office2016Black"))
    {
        Office2016Style* style = qobject_cast<Office2016Style*>(qApp->style());
        if (style == Q_NULL)
            style = new Office2016Style();
        if (name == QLatin1String("Office2016Colorful"))
            style->setTheme(Office2016Style::Colorful);
        else if (name == QLatin1String("Office2016White"))
            style->setTheme(Office2016Style::White);
        else if (name == QLatin1String("Office2016DarkGray"))
            style->setTheme(Office2016Style::DarkGray);
        else if (name == QLatin1String("Office2016Black"))
            style->setTheme(Office2016Style::Black);
        qApp->setStyle(style);
    }

    m_styleName = name;
    m_actionNormal->setChecked(true);
    fontChanged(Q_NULL);
    updateStyleActions();
}

void DemoRibbonWindow::setBackgroundByName(const QString& name)
{
    bool validName = false;
    QList<QAction*> actionList = m_backgroundMenu->actions();
    for (QList<QAction*>::ConstIterator it = actionList.begin(); it != actionList.end(); ++it)
    {
        QAction* act = (*it);
        if (act->objectName() == name)
        {
            act->setChecked(true);
            validName = true;
            break;
        }
    }
    if (!validName)
        return;
    QString resource = QString(QLatin1String(":/res/%1.png")).arg(name);
    QPixmap pixmap(resource);
    ribbonBar()->setTitleBackground(pixmap);
}

QString DemoRibbonWindow::backgroundName() const
{
    QList<QAction*> actionList = m_backgroundMenu->actions();
    for (QList<QAction*>::ConstIterator it = actionList.begin(); it != actionList.end(); ++it)
    {
        QAction* act = (*it);
        if (act->isChecked())
            return act->objectName();
    }
    return QString();
}

QAction* DemoRibbonWindow::autoSaveAction() const
{
    return m_autoSaveAction;
}

void DemoRibbonWindow::addSearchBar()
{
    ribbonBar()->setSearchBarAppearance(RibbonBar::SearchBarCentral);
    connect(ribbonBar()->searchBar(), SIGNAL(showHelp(const QString&)), this, SLOT(showHelp(const QString&)));
    ribbonBar()->searchBar()->addSuggestedAction(m_customizeAction);
    ribbonBar()->searchBar()->addSuggestedAction(m_simplifiedModeAction);
}

void DemoRibbonWindow::switchUser()
{
    if (!m_loggingIn)
    {
        bool ok;
        QString text = QInputDialog::getText(this, tr("User Login"), tr("User name:"), QLineEdit::Normal, tr("Brad Pitt"), &ok,
            Qt::WindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint));
        if (ok && !text.isEmpty())
        {
            m_switchUserAction->setIcon(FaceIcon::createIcon(QPixmap(QStringLiteral(":/res/login_face.png"))));
            m_switchUserAction->setText(text);
            m_loggingIn = true;
        }
    }
    else
    {
        if (QMessageBox::question(this, tr("User Logoff"), tr("Are you sure you want to quit?"),
            QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
        {
            m_switchUserAction->setIcon(SegoeMDL2Font::icon(SegoeMDL2Font::AddFriend));
            m_switchUserAction->setText(tr("Login"));
            m_loggingIn = false;
        }
    }
}

void DemoRibbonWindow::displayOptions()
{
}

void DemoRibbonWindow::showHelp(const QString& text)
{
    QMessageBox::information(this, tr("Show Help"), tr("Show Help for: %1").arg(text));
    QDesktopServices::openUrl(QUrl(QLatin1String("https://www.devmachines.com/documentation/QtitanComponents/html/classes.html?") + text));
}

void DemoRibbonWindow::about()
{
    AboutDialog::show(this, tr("About Qtitan Ribbon Controls Sample"), 
        tr("QtitanRibbon"), QStringLiteral(QTN_VERSION_RIBBON_STR));
}

void DemoRibbonWindow::styleChanged(QAction* action)
{
    setStyleByName(action->objectName());
}

void DemoRibbonWindow::backgroundChanged(QAction* action)
{
    setBackgroundByName(action->objectName());
}

void DemoRibbonWindow::animationEnabled(bool checked)
{
    if (CommonStyle* style = qobject_cast<CommonStyle*>(qApp->style()))
        style->setAnimationEnabled(checked);
}

void DemoRibbonWindow::simplifiedModeEnabled(bool checked)
{
    ribbonBar()->setSimplifiedModeEnabled(checked);
}

void DemoRibbonWindow::setTitleGroupsVisible(bool checked)
{
    ribbonBar()->setTitleGroupsVisible(checked);
}

void DemoRibbonWindow::maximizeToggle()
{
    ribbonBar()->setMinimized(!ribbonBar()->isMinimized());
}

void DemoRibbonWindow::minimizationChangedIcon(bool minimized)
{
    m_minimizeAction->setChecked(minimized);
    m_minimizeAction->setIcon(minimized ? QIcon(QStringLiteral(":/shared/res/ribbonMaximize.png")) :
        QIcon(QStringLiteral(":/shared/res/ribbonMinimize.png")));
}

void DemoRibbonWindow::showQuickAccessCustomizeMenu(QMenu* menu)
{
    menu->addSeparator()->setText(tr("Common Customization"));
    menu->addAction(ribbonBar()->quickAccessBarPosition() == RibbonBar::TopPosition ? m_showBelowAction : m_showAboveAction);
    menu->addSeparator();
    menu->addAction(m_minimizeAction);
    menu->addAction(m_customizeAction);
}

void DemoRibbonWindow::switchQuickAccessBarPosition()
{
    ribbonBar()->setQuickAccessBarPosition(ribbonBar()->quickAccessBarPosition() == RibbonBar::TopPosition ? 
        RibbonBar::BottomPosition : RibbonBar::TopPosition);
}

void DemoRibbonWindow::setNativeScrollBars(bool on)
{
    if (CommonStyle* style = qobject_cast<CommonStyle*>(qApp->style()))
        style->setScrollBarsIgnored(on);
}

void DemoRibbonWindow::setNativeDialogs(bool on)
{
    if (CommonStyle* style = qobject_cast<CommonStyle*>(qApp->style()))
        style->setDialogsIgnored(on);
}

void DemoRibbonWindow::fontChanged(QAction* action)
{
    QFont font = QApplication::font(QTITAN_META_CLASSNAME("RibbonBar"));
    if (m_actionMinimal == action)
        font.setPointSize(font.pointSize() - 1);
    if (m_actionMedium == action)
        font.setPointSize(font.pointSize() + 1);
    else if (m_actionLarge == action)
        font.setPointSize(font.pointSize() + 2);
    else if (m_actionExLarge == action)
        font.setPointSize(font.pointSize() + 3);
    ribbonBar()->setFont(font);
}

void DemoRibbonWindow::tabBarPositionChanged(QAction* action)
{
    ribbonBar()->setTabBarPosition(m_tabBarTopAction == action ? RibbonBar::TopPosition : RibbonBar::BottomPosition);
}

void DemoRibbonWindow::searchBarChanged(QAction* action)
{
    if (action == m_searchBarCentralAction)
        ribbonBar()->setSearchBarAppearance(RibbonBar::SearchBarCentral);
    else if (action == m_searchBarCompactAction)
        ribbonBar()->setSearchBarAppearance(RibbonBar::SearchBarCompact);
    else
        ribbonBar()->setSearchBarAppearance(RibbonBar::SearchBarHidden);
}

void DemoRibbonWindow::switchLayoutDirection()
{
    if (layoutDirection() == Qt::LeftToRight)
        QApplication::setLayoutDirection(Qt::RightToLeft);
    else
        QApplication::setLayoutDirection(Qt::LeftToRight);
}

void DemoRibbonWindow::showRibbonContextMenu(QMenu* menu, QContextMenuEvent* event)
{
    Q_UNUSED(menu)
    event->setAccepted(false);
}

void DemoRibbonWindow::saveToXML()
{
    const QString path = QDir::currentPath() + QStringLiteral("/ribbonbar-layout");
    const QString fileName = QFileDialog::getSaveFileName(this, tr("Save RibbonBar state to XML/FastInfoset File"), path,
        QStringLiteral("XML (*.xml);;FastInfoset (*.fi)"));
    if (fileName.isEmpty())
        return;
    if (QFileInfo(fileName).completeSuffix().contains(QStringLiteral("xml"), Qt::CaseInsensitive))
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
            return;
        XmlStreamWriter writer(&file);
        writer.setAutoFormatting(true);
        ribbonBar()->customizeManager()->saveStateToXML(&writer);
    }
    else
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
            return;
        FastInfosetStreamWriter writer(&file);
        ribbonBar()->customizeManager()->saveStateToXML(&writer);
    }
}

void DemoRibbonWindow::loadFromXML()
{
    const QString path = QDir::currentPath() + QStringLiteral("/");
    const QString fileName = QFileDialog::getOpenFileName(this, tr("Load RibbonBar state from XML/FastInfoset File"), path,
        QStringLiteral("XML (*.xml);;FastInfoset (*.fi)"));
    if (fileName.isEmpty())
        return;
    if (QFileInfo(fileName).completeSuffix().contains(QStringLiteral("xml"), Qt::CaseInsensitive))
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
            return;
        XmlStreamReader reader(&file);
        ribbonBar()->customizeManager()->loadStateFromXML(&reader);
    }
    else
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
            return;
        FastInfosetStreamReader reader(&file);
        ribbonBar()->customizeManager()->loadStateFromXML(&reader);
    }
}

void DemoRibbonWindow::customize()
{
    ribbonBar()->showCustomizeDialog();
}

void setDefaultWidgetGeometry(QWidget* widget, int factor)
{
    Q_ASSERT(widget != Q_NULL);
    Q_ASSERT(factor > 0);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    const QRect availableGeometry = widget->screen()->availableGeometry();
    widget->resize(2 * availableGeometry.width() / factor, 2 * availableGeometry.height() / factor);
    widget->move((availableGeometry.width() - widget->width()) / 2, (availableGeometry.height() - widget->height()) / 2);
#else
    widget->resize(800, 640); widget->move(200, 200);
#endif
}
