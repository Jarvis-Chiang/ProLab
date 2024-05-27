/********************************************************************************
** Form generated from reading UI file 'VectorDieldDriven_PathPara.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VECTORDIELDDRIVEN_PATHPARA_H
#define UI_VECTORDIELDDRIVEN_PATHPARA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VectorDieldDriven_PathPara
{
public:
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label;
    QLineEdit *lineEdit_PathWidth;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_2;
    QLineEdit *lineEdit_Interval;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_GenePath;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *VectorDieldDriven_PathPara)
    {
        if (VectorDieldDriven_PathPara->objectName().isEmpty())
            VectorDieldDriven_PathPara->setObjectName(QString::fromUtf8("VectorDieldDriven_PathPara"));
        VectorDieldDriven_PathPara->resize(551, 452);
        horizontalLayout_3 = new QHBoxLayout(VectorDieldDriven_PathPara);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        widget = new QWidget(VectorDieldDriven_PathPara);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_PathWidth = new QLineEdit(widget_2);
        lineEdit_PathWidth->setObjectName(QString::fromUtf8("lineEdit_PathWidth"));

        horizontalLayout->addWidget(lineEdit_PathWidth);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_Interval = new QLineEdit(widget_3);
        lineEdit_Interval->setObjectName(QString::fromUtf8("lineEdit_Interval"));

        horizontalLayout_2->addWidget(lineEdit_Interval);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        pushButton_GenePath = new QPushButton(widget_4);
        pushButton_GenePath->setObjectName(QString::fromUtf8("pushButton_GenePath"));

        horizontalLayout_4->addWidget(pushButton_GenePath);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout->addWidget(widget_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        retranslateUi(VectorDieldDriven_PathPara);

        QMetaObject::connectSlotsByName(VectorDieldDriven_PathPara);
    } // setupUi

    void retranslateUi(QWidget *VectorDieldDriven_PathPara)
    {
        VectorDieldDriven_PathPara->setWindowTitle(QCoreApplication::translate("VectorDieldDriven_PathPara", "Form", nullptr));
        label->setText(QCoreApplication::translate("VectorDieldDriven_PathPara", "\350\267\257\345\276\204\345\256\275\345\272\246\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("VectorDieldDriven_PathPara", "\346\217\222\345\200\274\351\227\264\351\232\224\357\274\232", nullptr));
        pushButton_GenePath->setText(QCoreApplication::translate("VectorDieldDriven_PathPara", "\347\224\237\346\210\220\350\267\257\345\276\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VectorDieldDriven_PathPara: public Ui_VectorDieldDriven_PathPara {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VECTORDIELDDRIVEN_PATHPARA_H
