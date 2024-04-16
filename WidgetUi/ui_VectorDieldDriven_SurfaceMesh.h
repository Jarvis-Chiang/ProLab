/********************************************************************************
** Form generated from reading UI file 'VectorDieldDriven_SurfaceMesh.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VECTORDIELDDRIVEN_SURFACEMESH_H
#define UI_VECTORDIELDDRIVEN_SURFACEMESH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VectorFieldDriven_SurfaceMesh
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ImportTriMesh;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_clear;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *VectorFieldDriven_SurfaceMesh)
    {
        if (VectorFieldDriven_SurfaceMesh->objectName().isEmpty())
            VectorFieldDriven_SurfaceMesh->setObjectName(QString::fromUtf8("VectorFieldDriven_SurfaceMesh"));
        VectorFieldDriven_SurfaceMesh->resize(387, 392);
        verticalLayout = new QVBoxLayout(VectorFieldDriven_SurfaceMesh);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(VectorFieldDriven_SurfaceMesh);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_ImportTriMesh = new QPushButton(widget);
        pushButton_ImportTriMesh->setObjectName(QString::fromUtf8("pushButton_ImportTriMesh"));

        horizontalLayout->addWidget(pushButton_ImportTriMesh);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(VectorFieldDriven_SurfaceMesh);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_clear = new QPushButton(widget_2);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));

        horizontalLayout_2->addWidget(pushButton_clear);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(VectorFieldDriven_SurfaceMesh);

        QMetaObject::connectSlotsByName(VectorFieldDriven_SurfaceMesh);
    } // setupUi

    void retranslateUi(QWidget *VectorFieldDriven_SurfaceMesh)
    {
        VectorFieldDriven_SurfaceMesh->setWindowTitle(QCoreApplication::translate("VectorFieldDriven_SurfaceMesh", "Form", nullptr));
        pushButton_ImportTriMesh->setText(QCoreApplication::translate("VectorFieldDriven_SurfaceMesh", "\345\257\274\345\205\245\344\270\211\350\247\222\347\275\221\346\240\274", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("VectorFieldDriven_SurfaceMesh", "\346\270\205\347\251\272\347\275\221\346\240\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VectorFieldDriven_SurfaceMesh: public Ui_VectorFieldDriven_SurfaceMesh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VECTORDIELDDRIVEN_SURFACEMESH_H
