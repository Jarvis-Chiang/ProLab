/********************************************************************************
** Form generated from reading UI file 'RefSurfBasedSlice_PathPlan.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFSURFBASEDSLICE_PATHPLAN_H
#define UI_REFSURFBASEDSLICE_PATHPLAN_H

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

class Ui_RefSurfBasedSlice_PathPlan
{
public:
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
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

    void setupUi(QWidget *RefSurfBasedSlice_PathPlan)
    {
        if (RefSurfBasedSlice_PathPlan->objectName().isEmpty())
            RefSurfBasedSlice_PathPlan->setObjectName(QString::fromUtf8("RefSurfBasedSlice_PathPlan"));
        RefSurfBasedSlice_PathPlan->resize(632, 907);
        horizontalLayout_9 = new QHBoxLayout(RefSurfBasedSlice_PathPlan);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        widget = new QWidget(RefSurfBasedSlice_PathPlan);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
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


        verticalLayout_3->addWidget(groupBox);

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

        widget_10 = new QWidget(groupBox_2);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_7 = new QHBoxLayout(widget_10);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(widget_10);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        lineEdit_Interval = new QLineEdit(widget_10);
        lineEdit_Interval->setObjectName(QString::fromUtf8("lineEdit_Interval"));

        horizontalLayout_7->addWidget(lineEdit_Interval);


        verticalLayout->addWidget(widget_10);


        verticalLayout_3->addWidget(groupBox_2);

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


        verticalLayout_3->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(20, 405, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_9->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        retranslateUi(RefSurfBasedSlice_PathPlan);

        QMetaObject::connectSlotsByName(RefSurfBasedSlice_PathPlan);
    } // setupUi

    void retranslateUi(QWidget *RefSurfBasedSlice_PathPlan)
    {
        RefSurfBasedSlice_PathPlan->setWindowTitle(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", "\346\255\243\344\272\244\346\240\205\346\240\274\350\267\257\345\276\204", nullptr));
        radioButton->setText(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", "\346\255\243\344\272\244\346\240\205\346\240\274\350\267\257\345\276\204", nullptr));
        label->setText(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", "\346\240\205\346\240\274\345\256\275\345\272\246X\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", "\346\240\205\346\240\274\345\256\275\345\272\246Y\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", " \350\267\257\345\276\204\345\256\275\345\272\246\357\274\232", nullptr));
        label_AngleX->setText(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", "\344\270\216X\350\275\264\345\244\271\350\247\222\357\274\232", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", "\344\271\213\345\255\227\345\241\253\345\205\205\350\267\257\345\276\204", nullptr));
        radioButton_2->setText(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", "\344\271\213\345\255\227\345\241\253\345\205\205\350\267\257\345\276\204", nullptr));
        label_5->setText(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", " \350\267\257\345\276\204\345\256\275\345\272\246\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", "\344\270\216X\350\275\264\345\244\271\350\247\222\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", " \346\217\222\345\200\274\351\227\264\351\232\224\357\274\232", nullptr));
        pushButton_GenePath->setText(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", "\347\224\237\346\210\220\350\267\257\345\276\204", nullptr));
        pushButton_ExprtPath->setText(QCoreApplication::translate("RefSurfBasedSlice_PathPlan", "\345\257\274\345\207\272\350\267\257\345\276\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RefSurfBasedSlice_PathPlan: public Ui_RefSurfBasedSlice_PathPlan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFSURFBASEDSLICE_PATHPLAN_H
