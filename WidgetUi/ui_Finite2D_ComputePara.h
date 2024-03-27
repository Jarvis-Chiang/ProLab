/********************************************************************************
** Form generated from reading UI file 'Finite2D_ComputePara.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINITE2D_COMPUTEPARA_H
#define UI_FINITE2D_COMPUTEPARA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Finite2D_ComputePara
{
public:
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox_ThreadNum;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_StartCompute;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Finite2D_ComputePara)
    {
        if (Finite2D_ComputePara->objectName().isEmpty())
            Finite2D_ComputePara->setObjectName(QString::fromUtf8("Finite2D_ComputePara"));
        Finite2D_ComputePara->resize(400, 739);
        horizontalLayout_3 = new QHBoxLayout(Finite2D_ComputePara);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(102, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        widget = new QWidget(Finite2D_ComputePara);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox_ThreadNum = new QSpinBox(widget_2);
        spinBox_ThreadNum->setObjectName(QString::fromUtf8("spinBox_ThreadNum"));

        horizontalLayout->addWidget(spinBox_ThreadNum);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_StartCompute = new QPushButton(widget_3);
        pushButton_StartCompute->setObjectName(QString::fromUtf8("pushButton_StartCompute"));

        horizontalLayout_2->addWidget(pushButton_StartCompute);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addWidget(widget_3);

        verticalSpacer = new QSpacerItem(20, 609, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(widget);

        horizontalSpacer_3 = new QSpacerItem(102, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        retranslateUi(Finite2D_ComputePara);

        QMetaObject::connectSlotsByName(Finite2D_ComputePara);
    } // setupUi

    void retranslateUi(QWidget *Finite2D_ComputePara)
    {
        Finite2D_ComputePara->setWindowTitle(QCoreApplication::translate("Finite2D_ComputePara", "Form", nullptr));
        label->setText(QCoreApplication::translate("Finite2D_ComputePara", "\347\272\277\347\250\213\346\225\260\351\207\217\357\274\232", nullptr));
        pushButton_StartCompute->setText(QCoreApplication::translate("Finite2D_ComputePara", "\345\274\200\345\247\213\350\256\241\347\256\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Finite2D_ComputePara: public Ui_Finite2D_ComputePara {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINITE2D_COMPUTEPARA_H
