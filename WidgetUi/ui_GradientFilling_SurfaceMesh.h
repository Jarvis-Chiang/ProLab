/********************************************************************************
** Form generated from reading UI file 'GradientFilling_SurfaceMesh.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADIENTFILLING_SURFACEMESH_H
#define UI_GRADIENTFILLING_SURFACEMESH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GradientFilling_SurfaceMesh
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ImportTriMesh;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *GradientFilling_SurfaceMesh)
    {
        if (GradientFilling_SurfaceMesh->objectName().isEmpty())
            GradientFilling_SurfaceMesh->setObjectName(QString::fromUtf8("GradientFilling_SurfaceMesh"));
        GradientFilling_SurfaceMesh->resize(458, 495);
        verticalLayout = new QVBoxLayout(GradientFilling_SurfaceMesh);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(GradientFilling_SurfaceMesh);
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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(GradientFilling_SurfaceMesh);

        QMetaObject::connectSlotsByName(GradientFilling_SurfaceMesh);
    } // setupUi

    void retranslateUi(QWidget *GradientFilling_SurfaceMesh)
    {
        GradientFilling_SurfaceMesh->setWindowTitle(QCoreApplication::translate("GradientFilling_SurfaceMesh", "Form", nullptr));
        pushButton_ImportTriMesh->setText(QCoreApplication::translate("GradientFilling_SurfaceMesh", "\345\257\274\345\205\245\344\270\211\350\247\222\347\275\221\346\240\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GradientFilling_SurfaceMesh: public Ui_GradientFilling_SurfaceMesh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADIENTFILLING_SURFACEMESH_H
