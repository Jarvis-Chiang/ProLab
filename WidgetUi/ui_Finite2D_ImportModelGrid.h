/********************************************************************************
** Form generated from reading UI file 'Finite2D_ImportModelGrid.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINITE2D_IMPORTMODELGRID_H
#define UI_FINITE2D_IMPORTMODELGRID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Finite2D_ImportModelGrid
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Import2DModelMesh;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Finite2D_ImportModelGrid)
    {
        if (Finite2D_ImportModelGrid->objectName().isEmpty())
            Finite2D_ImportModelGrid->setObjectName(QString::fromUtf8("Finite2D_ImportModelGrid"));
        Finite2D_ImportModelGrid->resize(400, 300);
        verticalLayout = new QVBoxLayout(Finite2D_ImportModelGrid);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(Finite2D_ImportModelGrid);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Import2DModelMesh = new QPushButton(widget);
        pushButton_Import2DModelMesh->setObjectName(QString::fromUtf8("pushButton_Import2DModelMesh"));

        horizontalLayout->addWidget(pushButton_Import2DModelMesh);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 232, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Finite2D_ImportModelGrid);

        QMetaObject::connectSlotsByName(Finite2D_ImportModelGrid);
    } // setupUi

    void retranslateUi(QWidget *Finite2D_ImportModelGrid)
    {
        Finite2D_ImportModelGrid->setWindowTitle(QCoreApplication::translate("Finite2D_ImportModelGrid", "Form", nullptr));
        pushButton_Import2DModelMesh->setText(QCoreApplication::translate("Finite2D_ImportModelGrid", "\345\257\274\345\205\2452D\346\250\241\345\236\213\347\275\221\346\240\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Finite2D_ImportModelGrid: public Ui_Finite2D_ImportModelGrid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINITE2D_IMPORTMODELGRID_H
