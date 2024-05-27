/********************************************************************************
** Form generated from reading UI file 'RefSurfBasedSlice_PrinZone.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFSURFBASEDSLICE_PRINZONE_H
#define UI_REFSURFBASEDSLICE_PRINZONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RefSurfBasedSlice_PrinZone
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_GenePriZoneMesh;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_ImportPriZoneMesh;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *RefSurfBasedSlice_PrinZone)
    {
        if (RefSurfBasedSlice_PrinZone->objectName().isEmpty())
            RefSurfBasedSlice_PrinZone->setObjectName(QString::fromUtf8("RefSurfBasedSlice_PrinZone"));
        RefSurfBasedSlice_PrinZone->resize(400, 557);
        verticalLayout = new QVBoxLayout(RefSurfBasedSlice_PrinZone);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(RefSurfBasedSlice_PrinZone);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(126, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        radioButton = new QRadioButton(widget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout->addWidget(radioButton);

        horizontalSpacer_2 = new QSpacerItem(125, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(RefSurfBasedSlice_PrinZone);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_GenePriZoneMesh = new QPushButton(widget_2);
        pushButton_GenePriZoneMesh->setObjectName(QString::fromUtf8("pushButton_GenePriZoneMesh"));

        horizontalLayout_2->addWidget(pushButton_GenePriZoneMesh);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(RefSurfBasedSlice_PrinZone);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton_ImportPriZoneMesh = new QPushButton(widget_3);
        pushButton_ImportPriZoneMesh->setObjectName(QString::fromUtf8("pushButton_ImportPriZoneMesh"));

        horizontalLayout_3->addWidget(pushButton_ImportPriZoneMesh);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(RefSurfBasedSlice_PrinZone);

        QMetaObject::connectSlotsByName(RefSurfBasedSlice_PrinZone);
    } // setupUi

    void retranslateUi(QWidget *RefSurfBasedSlice_PrinZone)
    {
        RefSurfBasedSlice_PrinZone->setWindowTitle(QCoreApplication::translate("RefSurfBasedSlice_PrinZone", "Form", nullptr));
        radioButton->setText(QCoreApplication::translate("RefSurfBasedSlice_PrinZone", "\350\200\203\350\231\221\346\233\262\351\235\242\346\224\257\346\222\221", nullptr));
        pushButton_GenePriZoneMesh->setText(QCoreApplication::translate("RefSurfBasedSlice_PrinZone", "\347\224\237\346\210\220\346\211\223\345\215\260\345\237\237\347\275\221\346\240\274", nullptr));
        pushButton_ImportPriZoneMesh->setText(QCoreApplication::translate("RefSurfBasedSlice_PrinZone", "\345\257\274\345\205\245\346\211\223\345\215\260\345\237\237\347\275\221\346\240\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RefSurfBasedSlice_PrinZone: public Ui_RefSurfBasedSlice_PrinZone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFSURFBASEDSLICE_PRINZONE_H
