#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma execution_character_set("utf-8")

#include "DemoRibbonWindow.h"
//#include "OsgWidget.h"
#include "TopoOptimizeWidget.h"


#include <QTreeView>
#include <QPlainTextEdit>
#include <QStandardItemModel>

class myLogWidget : public QWidget
{
public:
    inline QSize sizeHint() const
    {
        QSize qsize;
        qsize.setHeight(50);
        return qsize;         // ����dock�Ĵ�С
    }
};
class myOprWidget : public QWidget
{
public:
    inline QSize sizeHint() const
    {
        QSize qsize;
        qsize.setWidth(200);
        return qsize;         // ����dock�Ĵ�С
    }
};

/* MainWindow */
class MainWindow : public DemoRibbonWindow
{
    Q_OBJECT
public:
    enum LOGLEVAL {
        INFO = 01,
        WARNNING,
        WRONG
    };

    explicit MainWindow(QWidget* parent = Q_NULL);
    virtual ~MainWindow();
private:
    void creatConnect();
    void creatHomeButton(RibbonPage* page);
    void creatStructureOptiButton(RibbonPage* page);
    void creatprocessPlanButton(RibbonPage* page);
    void creatCadButton(RibbonPage* page);
    void creatCaeButton(RibbonPage* page);
    void creatCamButton(RibbonPage* page);
    void creatDockWindows();

    void addLog(QPlainTextEdit* logtext, const QString& message, LOGLEVAL level);
    TopoOptimizeWidget* topoOptimizeWidget;



private slots:
    void openFile();
    // add page
    void creatOprPage(QDockWidget* dock);
    void topo2D();
    void topo3D();

    void on_vectorFieldDriven_trigged();
    void on_offset_trigged();
    void on_GradientFilling_trigged();
    void on_ReferenceSurfaceBased_trigged();
    void on_VectorFieldBased_trigged();

protected:

    // action
    QAction* m_newFile;
    QAction* m_addDock;
    QAction* m_Topo2D;
    QAction* m_Topo3D;

    QAction* m_VectorDriven;
    QAction* m_OffsetPath;
    QAction* m_GradientFilling;
    QAction* m_ReferenceSurfaceBased;
    QAction* m_VectorFieldBased;

    // button
    QToolButton* button1;

    // Widget
    QDockWidget* treeDock;
    QTreeView* treeView;
    QStandardItemModel model;
    QModelIndex selectedIndex;

    QDockWidget* logDock;
    QDockWidget* oprDock;
    QWidget* graphWidget;       // ��cpp�ļ��н�newһ��OSGwidget

    // log textbrowser 
    QPlainTextEdit* LogText;

    // opr page
    RibbonPage* cadOpr;

private:
    Q_DISABLE_COPY(MainWindow)
};

#endif // MAINWINDOW_H

