#ifndef QTN_DEMORIBBONWINDOW_H
#define QTN_DEMORIBBONWINDOW_H

#include <QIconEngine>
#include <QPainter>

#include <DevMachines/QtitanBase>
#include <DevMachines/QtitanRibbon>
#include <DevMachines/QtitanFastInfoset>
#include <DevMachines/QtitanStyle>

class FaceIcon : public QIconEngine
{
public:
    FaceIcon(const QPixmap& facePixmap)
        : QIconEngine(), m_face() {
        int s = qMin(facePixmap.width(), facePixmap.height());
        QRect pictureRect = QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, QSize(s, s), QRect(QPoint(), facePixmap.size()));
        m_face = facePixmap.copy(pictureRect);
    }
#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
    QString iconName() override
#else
    QString iconName() const override
#endif
    {
        return QIconEngine::iconName();
    }

    QPixmap pixmap(const QSize& size, QIcon::Mode mode, QIcon::State state) override
    {
        QPixmap pm(size);
        pm.fill(Qt::transparent);
        {
            QPainter p(&pm);
            paint(&p, QRect(QPoint(0, 0), size), mode, state);
        }
        return pm;
    }

    void paint(QPainter* painter, const QRect& rect, QIcon::Mode mode, QIcon::State state) override
    {
        Q_UNUSED(mode);
        Q_UNUSED(state);
        painter->save();
        painter->setPen(Qt::NoPen);
        painter->setRenderHint(QPainter::Antialiasing, true);
        int s = qMin(rect.width(), rect.height());
        QRect paintRect = QStyle::alignedRect(Qt::LeftToRight, Qt::AlignCenter, QSize(s, s), rect);
        QPixmap pixmap = m_face.scaled(paintRect.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        painter->setBrush(pixmap);
        painter->translate(paintRect.topLeft());
        painter->drawEllipse(QRect(0, 0, paintRect.width(), paintRect.height()));
        painter->restore();
    }

    QIconEngine* clone() const override {
        return new FaceIcon(m_face);
    }
    static QIcon createIcon(const QPixmap& facePixmap) {
        return QIcon(new FaceIcon(facePixmap));
    }
private:
    QPixmap m_face;
};

class DemoRibbonWindow : public RibbonMainWindow
{
  Q_OBJECT
public:
    enum ImagesId
    {
        Image_New,
        Image_Open,
        Image_Save,
        Image_SaveAs,
        Image_Clipboard,
        Image_Close,
        Image_Cut,
        Image_Undo,
        Image_Redo,
        Image_Print,
    };
    explicit DemoRibbonWindow(QWidget* parent = Q_NULL);
    void readSettings();
    void writeSettings();
    static QIcon createIcon(ImagesId id, bool onlyLarge = false);
    static QIcon createIcon(const QString& smallIcon, const QString& largeIcon);
    void setStyleByName(const QString& name);
    void setBackgroundByName(const QString& name);
    QString backgroundName() const;
    QAction* autoSaveAction() const;
    void addSearchBar();
protected Q_SLOTS:
    void switchUser();
    void displayOptions();
    void showHelp(const QString& text);
    virtual void about();
    void styleChanged(QAction* action);
    void backgroundChanged(QAction* action);
    void animationEnabled(bool);
    void simplifiedModeEnabled(bool checked);
    void setTitleGroupsVisible(bool);
    void maximizeToggle();
    void minimizationChangedIcon(bool minimized);
    void showQuickAccessCustomizeMenu(QMenu* menu);
    void switchQuickAccessBarPosition();
    void setNativeScrollBars(bool);
    void setNativeDialogs(bool);
    void fontChanged(QAction* action);
    void tabBarPositionChanged(QAction* action);
    void searchBarChanged(QAction* action);
    void switchLayoutDirection();
    virtual void showRibbonContextMenu(QMenu* menu, QContextMenuEvent* event);
    void saveToXML();
    void loadFromXML();
    void customize();
private:
    void createOptions();
    void updateStyleActions();
protected:
    QString m_defaultStyle;
    QString m_styleName;
    bool m_loggingIn;
    QMenu* m_optionsMenu;
    QMenu* m_backgroundMenu;
    QMenu* m_styleMenu;

    QAction* m_switchUserAction;
    QAction* m_autoSaveAction;
    QAction* m_animationAction;
    QAction* m_simplifiedModeAction;

    QAction* m_actionNativeScrollBars;
    QAction* m_actionNativeDialogs;

    QAction* m_customizeAction;
    QAction* m_minimizeAction;
    QAction* m_showBelowAction;
    QAction* m_showAboveAction;

    QAction* m_actionMinimal;
    QAction* m_actionNormal;
    QAction* m_actionMedium;
    QAction* m_actionLarge;
    QAction* m_actionExLarge;

    QAction* m_tabBarTopAction;
    QAction* m_tabBarBottomAction;

    QAction* m_searchBarCentralAction;
    QAction* m_searchBarCompactAction;
    QAction* m_searchBarHddenAction;

#if QTN_ACTION_RTL
    QAction* m_actionRTL;
#endif
    QFont m_defaultFont;
private:
    Q_DISABLE_COPY(DemoRibbonWindow)
};

void setDefaultWidgetGeometry(QWidget* wd, int factor = 3);

#endif // QTN_DEMORIBBONWINDOW_H
