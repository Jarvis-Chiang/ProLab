/********************************************************************************
** Form generated from reading UI file 'RefSurfBasedSlice_RefPlane.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFSURFBASEDSLICE_REFPLANE_H
#define UI_REFSURFBASEDSLICE_REFPLANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RefSurfBasedSlice_RefPlane
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ImportRefPlane;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *RefSurfBasedSlice_RefPlane)
    {
        if (RefSurfBasedSlice_RefPlane->objectName().isEmpty())
            RefSurfBasedSlice_RefPlane->setObjectName(QString::fromUtf8("RefSurfBasedSlice_RefPlane"));
        RefSurfBasedSlice_RefPlane->resize(400, 603);
        verticalLayout = new QVBoxLayout(RefSurfBasedSlice_RefPlane);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(RefSurfBasedSlice_RefPlane);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_ImportRefPlane = new QPushButton(widget);
        pushButton_ImportRefPlane->setObjectName(QString::fromUtf8("pushButton_ImportRefPlane"));

        horizontalLayout->addWidget(pushButton_ImportRefPlane);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 535, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(RefSurfBasedSlice_RefPlane);

        QMetaObject::connectSlotsByName(RefSurfBasedSlice_RefPlane);
    } // setupUi

    void retranslateUi(QWidget *RefSurfBasedSlice_RefPlane)
    {
        RefSurfBasedSlice_RefPlane->setWindowTitle(QCoreApplication::translate("RefSurfBasedSlice_RefPlane", "Form", nullptr));
        pushButton_ImportRefPlane->setText(QCoreApplication::translate("RefSurfBasedSlice_RefPlane", "\345\257\274\345\205\245\345\237\272\345\207\206\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RefSurfBasedSlice_RefPlane: public Ui_RefSurfBasedSlice_RefPlane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFSURFBASEDSLICE_REFPLANE_H
