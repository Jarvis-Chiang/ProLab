#ifndef QTN_DEMOMAINWINDOW_H
#define QTN_DEMOMAINWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QAction>
#include <QAbstractButton>
#include <QHBoxLayout>
#include <QApplication>
#include <QFileInfo>

#include "QtitanBase.h"

class TitleBarCaption : public QLabel
{
    Q_OBJECT
public:
    explicit TitleBarCaption(const QString& productName, const QString& version, const QString& caption);
    ~TitleBarCaption() override;
protected:
    void mousePressEvent(QMouseEvent* event) override;
    protected Q_SLOTS:
    void setLink(const QString& link)
    { m_link = link; }
private:
    QString m_link;
private:
    Q_DISABLE_COPY(TitleBarCaption)
};

class DemoMainWindow : public QWidget
{
    Q_OBJECT
public:

    enum MainTheme
    {
        THEME_0 = -1,
        THEME_1 = Qt::darkRed,
        THEME_2 = Qt::darkMagenta,
        THEME_3 = Qt::darkGray,
        THEME_4 = Qt::darkGreen,
        THEME_5 = Qt::darkCyan,
    };

    enum StyleSetting
    {
        DefaultStyleSetting = 0,
        Windows7ScenicStyleSetting,
        Office2016ColorfulStyleSetting,
        Office2016BDarkGrayStyleSetting,
        Office2016BlackStyleSetting,
        AdobePhotoshopLightGrayStyleSetting,
        AdobePhotoshopDarkGrayStyleSetting,
        VisualSudio2019BlueStyleSetting,
        VisualSudio2019DarkStyleSetting,
        FluentLightStyleSetting,
        FluentDarkStyleSetting
    };
public:
    explicit DemoMainWindow(const QString& productName, const QString& version, const QString& caption = QString());
    WindowTitleBar* titleBar() const;
    void setDemoWidget(QWidget* widget, QWidget* settings, Qt::Alignment alignment = Qt::AlignTop, bool useThemeLayout = true);
#ifdef Q_OS_ANDROID
    void copyAssetFile(const QString& path, const QString& fileName);
#endif
protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual QHBoxLayout* createThemeLayout();
    ColorButton* createButton(MainTheme theme);
    Qt::GlobalColor convertToColor(MainTheme id) const;
    MainTheme convertToTheme(Qt::GlobalColor color) const;
    MainTheme convertToTheme(const QColor& color) const;
    ColorButton* buttomByTheme(MainTheme id) const;
    QHBoxLayout* createStyleSetting();
protected slots:
    void aboutLinkActivated(const QString& link);
    void colorButtonClicked();
    void styleChanged(int index);
    virtual void setShadeColor(const QColor& color) { Q_UNUSED(color);  }
    virtual void setThemeColor(const MainTheme& theme) { Q_UNUSED(theme); }
    virtual QString descriptionText() const { return QString(); }
    void showCompanyWebSite();
private:
    QLabel* m_infoButton;
    QWidget* m_settings;
    QString m_productName;
    QString m_version;
    QMap<MainTheme, ColorButton*> m_buttons;
    MaterialWidget* m_material;
private:
    Q_DISABLE_COPY(DemoMainWindow)
};

inline qreal qtn_rand(qreal min, qreal max)
{
    qreal minVal = qMin(min, max);
    qreal maxVal = qMax(min, max);
    return (maxVal - minVal) * qreal(rand()) / RAND_MAX + minVal;
}

#endif //QTN_DEMOMAINWINDOW_H

