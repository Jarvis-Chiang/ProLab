/********************************************************************************
** Form generated from reading UI file 'RefSurfBasedSlice_ModMesh.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFSURFBASEDSLICE_MODMESH_H
#define UI_REFSURFBASEDSLICE_MODMESH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RefSurfBasedSlice_ModMesh
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ImportBoxMesh;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *RefSurfBasedSlice_ModMesh)
    {
        if (RefSurfBasedSlice_ModMesh->objectName().isEmpty())
            RefSurfBasedSlice_ModMesh->setObjectName(QString::fromUtf8("RefSurfBasedSlice_ModMesh"));
        RefSurfBasedSlice_ModMesh->resize(400, 689);
        verticalLayout = new QVBoxLayout(RefSurfBasedSlice_ModMesh);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(RefSurfBasedSlice_ModMesh);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_ImportBoxMesh = new QPushButton(widget);
        pushButton_ImportBoxMesh->setObjectName(QString::fromUtf8("pushButton_ImportBoxMesh"));

        horizontalLayout->addWidget(pushButton_ImportBoxMesh);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(RefSurfBasedSlice_ModMesh);

        QMetaObject::connectSlotsByName(RefSurfBasedSlice_ModMesh);
    } // setupUi

    void retranslateUi(QWidget *RefSurfBasedSlice_ModMesh)
    {
        RefSurfBasedSlice_ModMesh->setWindowTitle(QCoreApplication::translate("RefSurfBasedSlice_ModMesh", "Form", nullptr));
        pushButton_ImportBoxMesh->setText(QCoreApplication::translate("RefSurfBasedSlice_ModMesh", "\345\257\274\345\205\245\345\233\233\351\235\242\344\275\223\347\275\221\346\240\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RefSurfBasedSlice_ModMesh: public Ui_RefSurfBasedSlice_ModMesh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFSURFBASEDSLICE_MODMESH_H
