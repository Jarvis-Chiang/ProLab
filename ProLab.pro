QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# QTITANDIR路径
QTITANDIR = D:\Project_3D_Slice\Qt\QtitanRibbon6.5.0

include($$QTITANDIR\src\shared\qtitanstyle.pri)
include($$QTITANDIR\src\shared\qtitanfastinfoset.pri)
include($$QTITANDIR\src\shared\qtitanribbon.pri)

#Osg库的路径
OSGDIR = $$PWD\third_part\OpenSceneGraph-3.6.5-VC2019-64-Debug

#PCL库的路径
PCLDIR = $$PWD\third_part\PCL

#FORM文件的路径
FORMDIR = $$PWD\WidgetUi

INCLUDEPATH += $$PWD\third_part\OpenSceneGraph-3.6.5-VC2019-64-Debug\include
INCLUDEPATH += $$PWD\third_part\libigl\libigl-src
INCLUDEPATH +=  $$PWD\third_part\eigen3
INCLUDEPATH += $$PWD\third_part\PCL\include

LIBS += -L$$OSGDIR/lib \ 
    -losgd \
    -losgDBd \
    -losgGAd \
    -losgQt5d \
    -losgViewerd \
    -losgUtild\
    -losgManipulatord\
    -losgFXd

LIBS += -L$$PCLDIR/lib \
	-lpcl_kdtreed

DESTDIR = $$quote($$PWD\build\Debug)

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    TopoOptimizeWidget.cpp\
    Interpolation.cpp

HEADERS += \
    mainwindow.h \
    TopoOptimizeWidget.h\
    Global.h \
    Interpolation.h

FORMS += $$files($$FORMDIR/*.ui)


#RESOURCES += res.qrc

include($$PWD/third_part/ribbon/aboutdialog/aboutdialog.pri)
include($$PWD/third_part/ribbon/DemoRibbonWindow/DemoRibbonWindow.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
