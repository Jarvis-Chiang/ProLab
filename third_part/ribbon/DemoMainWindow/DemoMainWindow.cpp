#include <QResizeEvent>
#include <QPainter>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QDesktopServices>
#include <QScreen>
#include <QWindow>

#include <DevMachines/QtitanStyle>

#include "DemoMainWindow.h"
#include "aboutdialog.h"

#define IMAGE_TITLE 80
#define CONTENT_BORDER 20
#define WINDOW_BORDER 4
#define CONTENT_MARGIN 30

/* TitleBarCaption */
TitleBarCaption::TitleBarCaption(const QString& productName, const QString& version, const QString& caption)
    : QLabel()
{
    setAttribute(Qt::WA_NoSystemBackground, true);
    setOpenExternalLinks(true);
    setText(QStringLiteral("<table border=\"0\"><tr style=\"vertical-align: middle;\"> \
         <td><img src=\":res/logo.png\"></td><td><strong>%1 %2</strong></td><td> %3 by \
         <a href=\"https://www.devmachines.com\">Developer Machines</a></td></tr></table>").arg(productName, version, caption));
    connect(this, SIGNAL(linkHovered(const QString &)), this, SLOT(setLink(const QString &)));
}

TitleBarCaption::~TitleBarCaption()
{
}

void TitleBarCaption::mousePressEvent(QMouseEvent* event)
{
    QLabel::mousePressEvent(event);
    if (!m_link.isEmpty())
        event->accept();
}

/* DemoMainWindow */
DemoMainWindow::DemoMainWindow(const QString& productName, const QString& version, const QString& caption)
    : QWidget(), m_infoButton(0), m_productName(productName), m_version(version)
{
#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
    const QRect availableGeometry = screen()->availableGeometry();
#else
    const QRect availableGeometry = QGuiApplication::primaryScreen()->availableGeometry();
#endif
    resize(availableGeometry.width() / 2, availableGeometry.height() / 2);
    move((availableGeometry.width() - width()) / 2, (availableGeometry.height() - height()) / 2);

    setWindowTitle(caption);
    m_material = new MaterialWidget(this);
    m_material->setBlendType(MaterialWidget::BackgroundBlend);
    m_material->setTintColor(Qt::darkGray);

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#if defined(Q_OS_WIN) || defined(Q_OS_MACOS) || defined(Q_OS_LINUX)
    titleBar()->setWidget(new TitleBarCaption(productName, version, caption));
    titleBar()->setBlurBehindWindowEnabled(true);
#if 0
    titleBar()->setExtendViewIntoTitleBar(true);
    QPalette p = palette();
    p.setColor(QPalette::WindowText, Qt::white);
    setPalette(p);
#endif
    titleBar()->show();
#endif
#endif
}

WindowTitleBar* DemoMainWindow::titleBar() const
{
    return WindowTitleBar::get(const_cast<DemoMainWindow *>(this));
}

void DemoMainWindow::aboutLinkActivated(const QString& link)
{
    Q_UNUSED(link);
    AboutDialog::show(this, m_productName + QStringLiteral(" ") + tr("Demo"), m_productName, m_version);
}

void DemoMainWindow::colorButtonClicked()
{
    ColorButton* button = qobject_cast<ColorButton *>(sender());
    if (button == Q_NULL)
        return;
    setShadeColor(button->color());
    setThemeColor(convertToTheme(button->color()));
}

void DemoMainWindow::styleChanged(int index)
{
    DemoMainWindow::StyleSetting style = static_cast<DemoMainWindow::StyleSetting>(index);
    bool styledFrame = true;

    switch (style)
    {
    case Windows7ScenicStyleSetting:
    {
        Windows7ScenicStyle* style = qobject_cast<Windows7ScenicStyle*>(qApp->style());
        if (style == Q_NULL)
            style = new Windows7ScenicStyle();
        qApp->setStyle(style);
    }
    break;
    case Office2016ColorfulStyleSetting:
    {
        Office2016Style* style = qobject_cast<Office2016Style*>(qApp->style());
        if (style == Q_NULL)
            style = new Office2016Style();
        style->setTheme(Office2016Style::Colorful);
        qApp->setStyle(style);
    }
    break;
    case Office2016BDarkGrayStyleSetting:
    {
        Office2016Style* style = qobject_cast<Office2016Style*>(qApp->style());
        if (style == Q_NULL)
            style = new Office2016Style();
        style->setTheme(Office2016Style::DarkGray);
        qApp->setStyle(style);
    }
    break;
    case Office2016BlackStyleSetting:
    {
        Office2016Style* style = qobject_cast<Office2016Style*>(qApp->style());
        if (style == Q_NULL)
            style = new Office2016Style();
        style->setTheme(Office2016Style::Black);
        qApp->setStyle(style);
    }
    break;
    case AdobePhotoshopLightGrayStyleSetting:
    {
        AdobePhotoshopStyle* style = qobject_cast<AdobePhotoshopStyle*>(qApp->style());
        if (style == Q_NULL)
            style = new AdobePhotoshopStyle();
        style->setTheme(AdobePhotoshopStyle::LightGray);
        qApp->setStyle(style);
    }
    break;
    case AdobePhotoshopDarkGrayStyleSetting:
    {
        AdobePhotoshopStyle* style = qobject_cast<AdobePhotoshopStyle*>(qApp->style());
        if (style == Q_NULL)
            style = new AdobePhotoshopStyle();
        style->setTheme(AdobePhotoshopStyle::DarkGray);
        qApp->setStyle(style);
    }
    break;
    case VisualSudio2019BlueStyleSetting:
    {
        VisualStudio2019Style* style = qobject_cast<VisualStudio2019Style*>(qApp->style());
        if (style == Q_NULL)
            style = new VisualStudio2019Style();
        style->setTheme(VisualStudio2019Style::Blue);
        qApp->setStyle(style);
    }
    break;
    case VisualSudio2019DarkStyleSetting:
    {
        VisualStudio2019Style* style = qobject_cast<VisualStudio2019Style*>(qApp->style());
        if (style == Q_NULL)
            style = new VisualStudio2019Style();
        style->setTheme(VisualStudio2019Style::Dark);
        qApp->setStyle(style);
    }
    break;
    case FluentLightStyleSetting:
    {
        ColorizedStyle* style = qobject_cast<ColorizedStyle*>(qApp->style());
        if (style == Q_NULL)
            style = new ColorizedStyle();
        style->setTheme(ColorizedStyle::Light);
        qApp->setStyle(style);
    }
    break;
    case FluentDarkStyleSetting:
    {
        ColorizedStyle* style = qobject_cast<ColorizedStyle*>(qApp->style());
        if (style == Q_NULL)
            style = new ColorizedStyle();
        style->setTheme(ColorizedStyle::Dark);
        qApp->setStyle(style);
    }
    break;
    default:
    {
        qApp->setStyle(new CommonStyle());
        styledFrame = false;
    }
    break;
    };

    titleBar()->setStyledFrame(styledFrame);
}

void DemoMainWindow::showCompanyWebSite()
{
    QDesktopServices::openUrl(QUrl(QStringLiteral("https://www.devmachines.com")));
}

void DemoMainWindow::setDemoWidget(QWidget* widget, QWidget* settings, Qt::Alignment alignment, bool useThemeLayout)
{
    const int title_magin = qtn_DPIScaled(IMAGE_TITLE, this);
    const int content_border = qtn_DPIScaled(CONTENT_BORDER, this);
    Q_UNUSED(content_border);
    const int window_border = qtn_DPIScaled(WINDOW_BORDER, this);
    const int content_margin = qtn_DPIScaled(CONTENT_MARGIN, this);

    m_settings = settings;

    if (m_settings)
    {
        QList<QLabel*> labels = m_settings->findChildren<QLabel*>();
        foreach(QLabel* l, labels)
        {
            QPalette p = l->palette();
            p.setColor(l->foregroundRole(), Qt::white);
            l->setPalette(p);
        }

        QList<QCheckBox*> boxes = m_settings->findChildren<QCheckBox*>();
        foreach(QCheckBox* b, boxes)
        {
            QPalette p = b->palette();
            p.setColor(b->foregroundRole(), Qt::white);
            b->setPalette(p);
        }
    }
    QVBoxLayout* vl = new QVBoxLayout(this);
    QHBoxLayout* hl = new QHBoxLayout();
    m_infoButton = new QLabel(this);
    m_infoButton->setCursor(Qt::PointingHandCursor);
    m_infoButton->setText(QStringLiteral("<a href=\"#\"><img src=\":res/question.png\"></a>"));
    connect(m_infoButton, SIGNAL(linkActivated(const QString&)), this, SLOT(aboutLinkActivated(const QString&)));
    vl->addWidget(m_infoButton, false, Qt::AlignRight);
    hl->addWidget(widget, m_settings != 0 ? 1 : 0);
    if (m_settings != 0)
        hl->addWidget(m_settings, 0, alignment);

    hl->setContentsMargins(content_margin, window_border, content_margin, content_margin);
    vl->setContentsMargins(window_border, window_border, window_border, window_border);

    QHBoxLayout* themeLayout = useThemeLayout ? createThemeLayout() : 0;
    if (themeLayout != 0)
    {
        themeLayout->setContentsMargins(content_margin, title_magin - window_border, content_margin, 0);
        vl->addLayout(themeLayout);
    }
    else
        hl->setContentsMargins(content_margin, title_magin, content_margin, content_margin);

    vl->addLayout(hl, true);
    widget->setFocus();
}

#ifdef Q_OS_ANDROID
void DemoMainWindow::copyAssetFile(const QString& path, const QString& fileName)
{
   if (!QFileInfo::exists(path + "/" + fileName))
   {
       QFile sqlfile("assets:/" + fileName);
       Q_ASSERT(sqlfile.exists());
       sqlfile.copy(path + "/" + fileName);
       QFile::setPermissions(path + "/" + fileName, QFile::WriteOwner | QFile::ReadOwner);
   }
}
#endif

ColorButton* DemoMainWindow::createButton(MainTheme theme)
{
    ColorButton* button = new ColorButton(Qt::white, this);
    button->setColor(convertToColor(theme));
    connect(button, SIGNAL(clicked()), this, SLOT(colorButtonClicked()));
    m_buttons.insert(theme, button);
    return button;
}

QHBoxLayout* DemoMainWindow::createThemeLayout()
{
    QHBoxLayout* themeLayout = new QHBoxLayout();
    themeLayout->setSizeConstraint(QLayout::SetFixedSize);
    themeLayout->addSpacing(0);

    ColorButton* button = createButton(THEME_1);
    themeLayout->addWidget(button);
    themeLayout->addSpacing(button->sizeHint().width() / 2);

    button = createButton(THEME_2);
    themeLayout->addWidget(button);
    themeLayout->addSpacing(button->sizeHint().width() / 2);

    button = createButton(THEME_3);
    themeLayout->addWidget(button);
    themeLayout->addSpacing(button->sizeHint().width() / 2);

    button = createButton(THEME_4);
    themeLayout->addWidget(button);
    themeLayout->addSpacing(button->sizeHint().width() / 2);

    button = createButton(THEME_5);
    themeLayout->addWidget(button);
    themeLayout->addSpacing(button->sizeHint().width() / 2);

    QLabel* themeDescription = new QLabel(this);
    QPalette palette = themeDescription->palette();
    palette.setColor(QPalette::WindowText, Qt::white);
    themeDescription->setPalette(palette);
    themeDescription->setWordWrap(true);
    
    QString text = descriptionText();
    if (text.isEmpty())
        text = tr("Select color to change tone of the main grid's elements (icons, backgrouds, captions and etc.).\
 Please note, you can replace any icons of the grid to better fit for your application style. For more details, refer to GridThemeManager class description of the documentation.");

    themeDescription->setText(text);
    themeLayout->addWidget(themeDescription, 1);

    return themeLayout;
}

Qt::GlobalColor DemoMainWindow::convertToColor(MainTheme id) const
{
    switch (id)
    {
        case THEME_1 :
            return Qt::darkRed;
        case THEME_2:
            return Qt::darkMagenta;
        case THEME_3:
            return Qt::darkGray;
        case THEME_4:
            return Qt::darkGreen;
        case THEME_5:
            return Qt::darkCyan;
        default:
            Q_ASSERT(false);
            break;
    };
    return (Qt::GlobalColor)- 1;
}

DemoMainWindow::MainTheme DemoMainWindow::convertToTheme(Qt::GlobalColor color) const
{
    switch (color)
    {
        case Qt::darkRed:
            return THEME_1;
        case Qt::darkMagenta:
            return THEME_2;
        case Qt::darkGray:
            return THEME_3;
        case Qt::darkGreen:
            return THEME_4;
        case Qt::darkCyan:
            return THEME_5;
        default:
            Q_ASSERT(false);
            break;
    };
    return (MainTheme)-1;
}

DemoMainWindow::MainTheme DemoMainWindow::convertToTheme(const QColor& color) const
{
    if (color == Qt::darkRed)
        return THEME_1;
    else if (color == Qt::darkMagenta)
        return THEME_2;
    else if (color == Qt::darkGray)
        return THEME_3;
    else if (color == Qt::darkGreen)
        return THEME_4;
    else if (color == Qt::darkCyan)
        return THEME_5;
    return (MainTheme)-1;
}

ColorButton* DemoMainWindow::buttomByTheme(MainTheme id) const
{
    return m_buttons.value(id);
}

QHBoxLayout* DemoMainWindow::createStyleSetting()
{
    QHBoxLayout* ret = new QHBoxLayout();
    QLabel* label = new QLabel(this);
    label->setText(tr("Style:"));
    ret->addWidget(label);
    QComboBox* comboBox = new QComboBox();
    connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(styleChanged(int)));
    comboBox->addItem(tr("Default"), DefaultStyleSetting);
    comboBox->addItem(tr("Windows 7 Scenic"), Windows7ScenicStyleSetting);
    comboBox->addItem(tr("Office 2016 Colorfull"), Office2016ColorfulStyleSetting);
    comboBox->addItem(tr("Office 2016 DarkGray"), Office2016BDarkGrayStyleSetting);
    comboBox->addItem(tr("Office 2016 Black"), Office2016BlackStyleSetting);
    comboBox->addItem(tr("Adobe Photoshop White"), AdobePhotoshopLightGrayStyleSetting);
    comboBox->addItem(tr("Adobe Photoshop DarkGray"), AdobePhotoshopDarkGrayStyleSetting);
    comboBox->addItem(tr("Visual Sudio 2019 Blue"), VisualSudio2019BlueStyleSetting);
    comboBox->addItem(tr("Visual Sudio 2019 Dark"), VisualSudio2019DarkStyleSetting);
    comboBox->addItem(tr("Fluent White"), FluentLightStyleSetting);
    comboBox->addItem(tr("Fluent Dark"), FluentDarkStyleSetting);
    ret->addWidget(comboBox);
    return ret;
}

#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
static QRect qtn_marginsRemoved(const QRect& rc, const QMargins& margins)
{
    return QRect(QPoint(rc.left() + margins.left(), rc.top() + margins.top()),
        QPoint(rc.right() - margins.right(), rc.bottom() - margins.bottom()));
}
#endif

void DemoMainWindow::paintEvent(QPaintEvent* event)
{
    const int title_magin = qtn_DPIScaled(IMAGE_TITLE, this);
    const int window_border = qtn_DPIScaled(WINDOW_BORDER, this);
    const int content_border = qtn_DPIScaled(CONTENT_BORDER, this);
    static QPixmap logo = QPixmap(QStringLiteral(":/res/qtitanlogo64x64.png"));
    static QPixmap header = QPixmap(QStringLiteral(":/res/qtitanheader.png"));
    
    QPainter painter(this);
    painter.setClipRegion(event->region());
    QRect bounded(QPoint(0, 0), size());
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    bounded = QRect(QPoint(0, 0), bounded.marginsRemoved(contentsMargins()).size());
#else
    bounded = QRect(QPoint(0, 0), qtn_marginsRemoved(bounded, contentsMargins()).size());
#endif
    painter.translate(contentsMargins().left(), contentsMargins().top());
    QRect r = bounded;
    r.setHeight(title_magin);

    QPixmap background = header.scaledToHeight(title_magin, Qt::SmoothTransformation);
    painter.fillRect(r, background);
    painter.drawPixmap(window_border, content_border, logo);
 
    r.setTop(r.height());
    r.setHeight(bounded.size().height() - r.height());
    painter.fillRect(r, QColor(0x191919));

    QFont f = painter.font();
    f.setPointSize(18);
    f.setBold(true);
    painter.setFont(f);
    painter.setPen(QColor(0xFFFFFFFF));
    QRect textRect = bounded;
    textRect.setHeight(title_magin);
    textRect.adjust(logo.width() + window_border * 2, content_border, window_border, window_border);
    painter.drawText(textRect, m_productName + QStringLiteral(" ") + m_version);
}

void DemoMainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    const int title_magin = qtn_DPIScaled(IMAGE_TITLE, this);
    const int content_border = qtn_DPIScaled(CONTENT_BORDER, this);
 
    m_material->setGeometry(QRect(QPoint(content_border, title_magin),
        size() - QSize(content_border * 2, title_magin + content_border)));
}
