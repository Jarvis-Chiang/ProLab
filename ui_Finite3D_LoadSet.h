/********************************************************************************
** Form generated from reading UI file 'Finite3D_LoadSet.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINITE3D_LOADSET_H
#define UI_FINITE3D_LOADSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Finite3D_LoadSet
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QListWidget *listWidget;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_del;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_12;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_23;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_13;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_24;
    QLabel *label_10;
    QLineEdit *lineEdit_x0;
    QSpacerItem *horizontalSpacer_25;
    QWidget *widget_14;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_26;
    QLabel *label_11;
    QLineEdit *lineEdit_y0;
    QSpacerItem *horizontalSpacer_27;
    QWidget *widget_15;
    QHBoxLayout *horizontalLayout_16;
    QSpacerItem *horizontalSpacer_28;
    QLabel *label_12;
    QLineEdit *lineEdit_z0;
    QSpacerItem *horizontalSpacer_29;
    QPushButton *pushButton_add;
    QSpacerItem *horizontalSpacer_30;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Finite3D_LoadSet)
    {
        if (Finite3D_LoadSet->objectName().isEmpty())
            Finite3D_LoadSet->setObjectName(QString::fromUtf8("Finite3D_LoadSet"));
        Finite3D_LoadSet->resize(561, 940);
        verticalLayout = new QVBoxLayout(Finite3D_LoadSet);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Finite3D_LoadSet);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        listWidget = new QListWidget(groupBox_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_4->addWidget(listWidget);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_del = new QPushButton(groupBox_3);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));

        horizontalLayout_2->addWidget(pushButton_del);


        verticalLayout_4->addWidget(groupBox_3);


        horizontalLayout->addWidget(groupBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_7->addWidget(widget);

        widget_12 = new QWidget(groupBox);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        horizontalLayout_13 = new QHBoxLayout(widget_12);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_23);

        groupBox_5 = new QGroupBox(widget_12);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy2);
        groupBox_5->setMinimumSize(QSize(276, 0));
        verticalLayout_3 = new QVBoxLayout(groupBox_5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_13 = new QWidget(groupBox_5);
        widget_13->setObjectName(QString::fromUtf8("widget_13"));
        horizontalLayout_14 = new QHBoxLayout(widget_13);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_24);

        label_10 = new QLabel(widget_13);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_14->addWidget(label_10);

        lineEdit_x0 = new QLineEdit(widget_13);
        lineEdit_x0->setObjectName(QString::fromUtf8("lineEdit_x0"));

        horizontalLayout_14->addWidget(lineEdit_x0);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_25);


        verticalLayout_3->addWidget(widget_13);

        widget_14 = new QWidget(groupBox_5);
        widget_14->setObjectName(QString::fromUtf8("widget_14"));
        horizontalLayout_15 = new QHBoxLayout(widget_14);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_26);

        label_11 = new QLabel(widget_14);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_15->addWidget(label_11);

        lineEdit_y0 = new QLineEdit(widget_14);
        lineEdit_y0->setObjectName(QString::fromUtf8("lineEdit_y0"));

        horizontalLayout_15->addWidget(lineEdit_y0);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_27);


        verticalLayout_3->addWidget(widget_14);

        widget_15 = new QWidget(groupBox_5);
        widget_15->setObjectName(QString::fromUtf8("widget_15"));
        horizontalLayout_16 = new QHBoxLayout(widget_15);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_28);

        label_12 = new QLabel(widget_15);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_16->addWidget(label_12);

        lineEdit_z0 = new QLineEdit(widget_15);
        lineEdit_z0->setObjectName(QString::fromUtf8("lineEdit_z0"));

        horizontalLayout_16->addWidget(lineEdit_z0);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_29);


        verticalLayout_3->addWidget(widget_15);

        pushButton_add = new QPushButton(groupBox_5);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        verticalLayout_3->addWidget(pushButton_add);


        horizontalLayout_13->addWidget(groupBox_5);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_30);


        verticalLayout_7->addWidget(widget_12);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        verticalLayout->addWidget(groupBox);


        retranslateUi(Finite3D_LoadSet);

        QMetaObject::connectSlotsByName(Finite3D_LoadSet);
    } // setupUi

    void retranslateUi(QWidget *Finite3D_LoadSet)
    {
        Finite3D_LoadSet->setWindowTitle(QCoreApplication::translate("Finite3D_LoadSet", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Finite3D_LoadSet", "\350\275\275\350\215\267\350\256\276\347\275\256", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Finite3D_LoadSet", "\350\275\275\350\215\267\351\241\266\347\202\271", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Finite3D_LoadSet", "\346\223\215\344\275\234", nullptr));
        pushButton_del->setText(QCoreApplication::translate("Finite3D_LoadSet", "\345\210\240\351\231\244", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Finite3D_LoadSet", "\350\275\275\350\215\267\345\244\247\345\260\217", nullptr));
        label_10->setText(QCoreApplication::translate("Finite3D_LoadSet", "X\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("Finite3D_LoadSet", "Y\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("Finite3D_LoadSet", "Z\357\274\232", nullptr));
        pushButton_add->setText(QCoreApplication::translate("Finite3D_LoadSet", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Finite3D_LoadSet: public Ui_Finite3D_LoadSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINITE3D_LOADSET_H
