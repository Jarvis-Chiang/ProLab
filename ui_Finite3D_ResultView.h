/********************************************************************************
** Form generated from reading UI file 'Finite3D_ResultView.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINITE3D_RESULTVIEW_H
#define UI_FINITE3D_RESULTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Finite3D_ResultView
{
public:
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_GeneDisplaceField;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_GeneStressField;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_GeneStrainField;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *Finite3D_ResultView)
    {
        if (Finite3D_ResultView->objectName().isEmpty())
            Finite3D_ResultView->setObjectName(QString::fromUtf8("Finite3D_ResultView"));
        Finite3D_ResultView->resize(400, 765);
        horizontalLayout_4 = new QHBoxLayout(Finite3D_ResultView);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(81, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        widget = new QWidget(Finite3D_ResultView);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_GeneDisplaceField = new QPushButton(widget_2);
        pushButton_GeneDisplaceField->setObjectName(QString::fromUtf8("pushButton_GeneDisplaceField"));

        horizontalLayout->addWidget(pushButton_GeneDisplaceField);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_GeneStressField = new QPushButton(widget_3);
        pushButton_GeneStressField->setObjectName(QString::fromUtf8("pushButton_GeneStressField"));

        horizontalLayout_2->addWidget(pushButton_GeneStressField);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton_GeneStrainField = new QPushButton(widget_4);
        pushButton_GeneStrainField->setObjectName(QString::fromUtf8("pushButton_GeneStrainField"));

        horizontalLayout_3->addWidget(pushButton_GeneStrainField);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addWidget(widget_4);

        verticalSpacer = new QSpacerItem(20, 426, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_4->addWidget(widget);

        horizontalSpacer_8 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        retranslateUi(Finite3D_ResultView);

        QMetaObject::connectSlotsByName(Finite3D_ResultView);
    } // setupUi

    void retranslateUi(QWidget *Finite3D_ResultView)
    {
        Finite3D_ResultView->setWindowTitle(QCoreApplication::translate("Finite3D_ResultView", "Form", nullptr));
        pushButton_GeneDisplaceField->setText(QCoreApplication::translate("Finite3D_ResultView", "\347\224\237\346\210\220\344\275\215\347\247\273\345\234\272", nullptr));
        pushButton_GeneStressField->setText(QCoreApplication::translate("Finite3D_ResultView", "\347\224\237\346\210\220\345\272\224\345\212\233\345\234\272", nullptr));
        pushButton_GeneStrainField->setText(QCoreApplication::translate("Finite3D_ResultView", "\347\224\237\346\210\220\345\272\224\345\217\230\345\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Finite3D_ResultView: public Ui_Finite3D_ResultView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINITE3D_RESULTVIEW_H
