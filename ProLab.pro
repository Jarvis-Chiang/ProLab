QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# QTITANDIR路径
QTITANDIR = E:\Qt\Developer Machines\QtitanRibbon6.5.0

include($$QTITANDIR\src\shared\qtitanstyle.pri)
include($$QTITANDIR\src\shared\qtitanfastinfoset.pri)
include($$QTITANDIR\src\shared\qtitanribbon.pri)

DESTDIR = $$quote($$PWD\build\Debug)

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

#RESOURCES += res.qrc

include($$PWD/third_part/ribbon/aboutdialog/aboutdialog.pri)
include($$PWD/third_part/ribbon/DemoRibbonWindow/DemoRibbonWindow.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
