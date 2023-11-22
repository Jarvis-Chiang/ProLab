#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "DemoRibbonWindow.h"
#include <QPlainTextEdit>

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
        qsize.setWidth(300);
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
        ERROR
    };

    explicit MainWindow(QWidget* parent = Q_NULL);
    virtual ~MainWindow();
private:
    void creatConnect();
    void creatHomeButton(RibbonPage* page);
    void creatCadButton(RibbonPage* page);
    void creatCaeButton(RibbonPage* page);
    void creatCamButton(RibbonPage* page);
    void creatDockWindows();
    void creatTreeItem(QDockWidget* treeDock);

    void addLog(QPlainTextEdit* logtext, const QString& message, LOGLEVAL level);

private slots:
    void openFile();
    // add page
    void creatOprPage(QDockWidget* dock);

protected:

    // action
    QAction* m_newFile;
    QAction* m_addDock;

    // button
    QToolButton* button1;

    // Widget
    QDockWidget* treeDock;
    QDockWidget* logDock;
    QDockWidget* oprDock;
    QWidget* graphWidget;      
    QWidget* treeItem;

    // log textbrowser 
    QPlainTextEdit* LogText;

    // opr page
    RibbonPage* cadOpr;

private:
    Q_DISABLE_COPY(MainWindow)
};

#endif // MAINWINDOW_H

