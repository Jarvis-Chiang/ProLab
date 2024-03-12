/********************************************************************************
** Form generated from reading UI file 'OffsetPath_SurfaceMesh.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OFFSETPATH_SURFACEMESH_H
#define UI_OFFSETPATH_SURFACEMESH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OffsetPath_SurfaceMesh
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_ImportTriMesh;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *OffsetPath_SurfaceMesh)
    {
        if (OffsetPath_SurfaceMesh->objectName().isEmpty())
            OffsetPath_SurfaceMesh->setObjectName(QString::fromUtf8("OffsetPath_SurfaceMesh"));
        OffsetPath_SurfaceMesh->resize(400, 300);
        horizontalLayout = new QHBoxLayout(OffsetPath_SurfaceMesh);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(OffsetPath_SurfaceMesh);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_ImportTriMesh = new QPushButton(widget);
        pushButton_ImportTriMesh->setObjectName(QString::fromUtf8("pushButton_ImportTriMesh"));

        verticalLayout->addWidget(pushButton_ImportTriMesh);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(OffsetPath_SurfaceMesh);

        QMetaObject::connectSlotsByName(OffsetPath_SurfaceMesh);
    } // setupUi

    void retranslateUi(QWidget *OffsetPath_SurfaceMesh)
    {
        OffsetPath_SurfaceMesh->setWindowTitle(QCoreApplication::translate("OffsetPath_SurfaceMesh", "Form", nullptr));
        pushButton_ImportTriMesh->setText(QCoreApplication::translate("OffsetPath_SurfaceMesh", "\345\257\274\345\205\245\344\270\211\350\247\222\347\275\221\346\240\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OffsetPath_SurfaceMesh: public Ui_OffsetPath_SurfaceMesh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OFFSETPATH_SURFACEMESH_H
