/********************************************************************************
** Form generated from reading UI file 'VecFieldBasedSlice_PathPlan.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VECFIELDBASEDSLICE_PATHPLAN_H
#define UI_VECFIELDBASEDSLICE_PATHPLAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VecFieldBasedSlice_PathPlan
{
public:
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_GridWidthX;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_GridWidthY;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_PathWidth;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_AngleX;
    QLineEdit *lineEdit_AngleX;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_2;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_PathWidth_2;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *lineEdit_AngleX_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_8;
    QLineEdit *lineEdit_PathWidth_3;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *lineEdit_Interval;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_GenePath;
    QPushButton *pushButton_ExprtPath;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *VecFieldBasedSlice_PathPlan)
    {
        if (VecFieldBasedSlice_PathPlan->objectName().isEmpty())
            VecFieldBasedSlice_PathPlan->setObjectName(QString::fromUtf8("VecFieldBasedSlice_PathPlan"));
        VecFieldBasedSlice_PathPlan->resize(400, 917);
        horizontalLayout_9 = new QHBoxLayout(VecFieldBasedSlice_PathPlan);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(52, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        widget = new QWidget(VecFieldBasedSlice_PathPlan);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout_2->addWidget(radioButton);

        widget_4 = new QWidget(groupBox);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout = new QHBoxLayout(widget_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_GridWidthX = new QLineEdit(widget_4);
        lineEdit_GridWidthX->setObjectName(QString::fromUtf8("lineEdit_GridWidthX"));

        horizontalLayout->addWidget(lineEdit_GridWidthX);


        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(groupBox);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_GridWidthY = new QLineEdit(widget_5);
        lineEdit_GridWidthY->setObjectName(QString::fromUtf8("lineEdit_GridWidthY"));

        horizontalLayout_2->addWidget(lineEdit_GridWidthY);


        verticalLayout_2->addWidget(widget_5);

        widget_6 = new QWidget(groupBox);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_3 = new QHBoxLayout(widget_6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_PathWidth = new QLineEdit(widget_6);
        lineEdit_PathWidth->setObjectName(QString::fromUtf8("lineEdit_PathWidth"));

        horizontalLayout_3->addWidget(lineEdit_PathWidth);


        verticalLayout_2->addWidget(widget_6);

        widget_7 = new QWidget(groupBox);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_4 = new QHBoxLayout(widget_7);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_AngleX = new QLabel(widget_7);
        label_AngleX->setObjectName(QString::fromUtf8("label_AngleX"));

        horizontalLayout_4->addWidget(label_AngleX);

        lineEdit_AngleX = new QLineEdit(widget_7);
        lineEdit_AngleX->setObjectName(QString::fromUtf8("lineEdit_AngleX"));

        horizontalLayout_4->addWidget(lineEdit_AngleX);


        verticalLayout_2->addWidget(widget_7);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        widget_8 = new QWidget(groupBox_2);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(widget_8);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        lineEdit_PathWidth_2 = new QLineEdit(widget_8);
        lineEdit_PathWidth_2->setObjectName(QString::fromUtf8("lineEdit_PathWidth_2"));

        horizontalLayout_5->addWidget(lineEdit_PathWidth_2);


        verticalLayout->addWidget(widget_8);

        widget_9 = new QWidget(groupBox_2);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_6 = new QHBoxLayout(widget_9);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(widget_9);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        lineEdit_AngleX_2 = new QLineEdit(widget_9);
        lineEdit_AngleX_2->setObjectName(QString::fromUtf8("lineEdit_AngleX_2"));

        horizontalLayout_6->addWidget(lineEdit_AngleX_2);


        verticalLayout->addWidget(widget_9);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_11 = new QWidget(groupBox_3);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_10 = new QHBoxLayout(widget_11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_8 = new QLabel(widget_11);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_10->addWidget(label_8);

        lineEdit_PathWidth_3 = new QLineEdit(widget_11);
        lineEdit_PathWidth_3->setObjectName(QString::fromUtf8("lineEdit_PathWidth_3"));

        horizontalLayout_10->addWidget(lineEdit_PathWidth_3);


        verticalLayout_3->addWidget(widget_11);


        verticalLayout_4->addWidget(groupBox_3);

        widget_10 = new QWidget(widget);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_7 = new QHBoxLayout(widget_10);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(widget_10);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lineEdit_Interval = new QLineEdit(widget_10);
        lineEdit_Interval->setObjectName(QString::fromUtf8("lineEdit_Interval"));

        horizontalLayout_7->addWidget(lineEdit_Interval);


        verticalLayout_4->addWidget(widget_10);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_8 = new QHBoxLayout(widget_2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_GenePath = new QPushButton(widget_2);
        pushButton_GenePath->setObjectName(QString::fromUtf8("pushButton_GenePath"));

        horizontalLayout_8->addWidget(pushButton_GenePath);

        pushButton_ExprtPath = new QPushButton(widget_2);
        pushButton_ExprtPath->setObjectName(QString::fromUtf8("pushButton_ExprtPath"));

        horizontalLayout_8->addWidget(pushButton_ExprtPath);


        verticalLayout_4->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(20, 339, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_9->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(51, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        retranslateUi(VecFieldBasedSlice_PathPlan);

        QMetaObject::connectSlotsByName(VecFieldBasedSlice_PathPlan);
    } // setupUi

    void retranslateUi(QWidget *VecFieldBasedSlice_PathPlan)
    {
        VecFieldBasedSlice_PathPlan->setWindowTitle(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", "\346\255\243\344\272\244\346\240\205\346\240\274\350\267\257\345\276\204", nullptr));
        radioButton->setText(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", "\346\255\243\344\272\244\346\240\205\346\240\274\350\267\257\345\276\204", nullptr));
        label->setText(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", "\346\240\205\346\240\274\345\256\275\345\272\246X\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", "\346\240\205\346\240\274\345\256\275\345\272\246Y\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", " \350\267\257\345\276\204\345\256\275\345\272\246\357\274\232", nullptr));
        label_AngleX->setText(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", "\344\270\216X\350\275\264\345\244\271\350\247\222\357\274\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", "\344\271\213\345\255\227\345\241\253\345\205\205\350\267\257\345\276\204", nullptr));
        radioButton_2->setText(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", "\344\271\213\345\255\227\345\241\253\345\205\205\350\267\257\345\276\204", nullptr));
        label_5->setText(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", " \350\267\257\345\276\204\345\256\275\345\272\246\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", "\344\270\216X\350\275\264\345\244\271\350\247\222\357\274\232", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", "\346\226\271\345\220\221\345\234\272\351\251\261\345\212\250\350\267\257\345\276\204", nullptr));
        label_8->setText(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", " \350\267\257\345\276\204\345\256\275\345\272\246\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", " \346\217\222\345\200\274\351\227\264\351\232\224\357\274\232", nullptr));
        pushButton_GenePath->setText(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", "\347\224\237\346\210\220\350\267\257\345\276\204", nullptr));
        pushButton_ExprtPath->setText(QCoreApplication::translate("VecFieldBasedSlice_PathPlan", "\345\257\274\345\207\272\350\267\257\345\276\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VecFieldBasedSlice_PathPlan: public Ui_VecFieldBasedSlice_PathPlan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VECFIELDBASEDSLICE_PATHPLAN_H
