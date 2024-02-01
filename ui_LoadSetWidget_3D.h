/********************************************************************************
** Form generated from reading UI file 'LoadSetWidget_3D.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADSETWIDGET_3D_H
#define UI_LOADSETWIDGET_3D_H

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

class Ui_LoadSetWidget_3D
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
    QPushButton *pushButton_plane;
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
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QLineEdit *lineEdit_x1;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_2;
    QLineEdit *lineEdit_y1;
    QSpacerItem *horizontalSpacer_8;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_4;
    QLineEdit *lineEdit_z1;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *pushButton_add_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *LoadSetWidget)
    {
        if (LoadSetWidget->objectName().isEmpty())
            LoadSetWidget->setObjectName(QString::fromUtf8("LoadSetWidget"));
        LoadSetWidget->resize(1114, 821);
        verticalLayout = new QVBoxLayout(LoadSetWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(LoadSetWidget);
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

        pushButton_plane = new QPushButton(groupBox_3);
        pushButton_plane->setObjectName(QString::fromUtf8("pushButton_plane"));

        horizontalLayout_2->addWidget(pushButton_plane);


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

        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        groupBox_4 = new QGroupBox(widget_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy2.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy2);
        groupBox_4->setMinimumSize(QSize(276, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_3 = new QWidget(groupBox_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lineEdit_x1 = new QLineEdit(widget_3);
        lineEdit_x1->setObjectName(QString::fromUtf8("lineEdit_x1"));

        horizontalLayout_3->addWidget(lineEdit_x1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(groupBox_4);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_5 = new QHBoxLayout(widget_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        lineEdit_y1 = new QLineEdit(widget_4);
        lineEdit_y1->setObjectName(QString::fromUtf8("lineEdit_y1"));

        horizontalLayout_5->addWidget(lineEdit_y1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(groupBox_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_7 = new QHBoxLayout(widget_5);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);

        label_4 = new QLabel(widget_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_7->addWidget(label_4);

        lineEdit_z1 = new QLineEdit(widget_5);
        lineEdit_z1->setObjectName(QString::fromUtf8("lineEdit_z1"));

        horizontalLayout_7->addWidget(lineEdit_z1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);


        verticalLayout_2->addWidget(widget_5);

        pushButton_add_2 = new QPushButton(groupBox_4);
        pushButton_add_2->setObjectName(QString::fromUtf8("pushButton_add_2"));

        verticalLayout_2->addWidget(pushButton_add_2);


        horizontalLayout_4->addWidget(groupBox_4);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_7->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        verticalLayout->addWidget(groupBox);


        retranslateUi(LoadSetWidget);

        QMetaObject::connectSlotsByName(LoadSetWidget);
    } // setupUi

    void retranslateUi(QWidget *LoadSetWidget)
    {
        LoadSetWidget->setWindowTitle(QCoreApplication::translate("LoadSetWidget", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("LoadSetWidget", "\350\276\271\347\225\214\346\235\241\344\273\266", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("LoadSetWidget", "\350\275\275\350\215\267\351\241\266\347\202\271", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("LoadSetWidget", "\346\223\215\344\275\234", nullptr));
        pushButton_del->setText(QCoreApplication::translate("LoadSetWidget", "\345\210\240\351\231\244", nullptr));
        pushButton_plane->setText(QCoreApplication::translate("LoadSetWidget", "\345\210\207\345\271\263\351\235\242", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("LoadSetWidget", "\350\275\275\350\215\267\345\244\247\345\260\217", nullptr));
        label_10->setText(QCoreApplication::translate("LoadSetWidget", "X\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("LoadSetWidget", "Y\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("LoadSetWidget", "Z\357\274\232", nullptr));
        pushButton_add->setText(QCoreApplication::translate("LoadSetWidget", "\346\267\273\345\212\240", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("LoadSetWidget", "\347\233\270\345\257\271\350\275\275\350\215\267\345\244\247\345\260\217", nullptr));
        label->setText(QCoreApplication::translate("LoadSetWidget", "X\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("LoadSetWidget", "Y\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("LoadSetWidget", "Z\357\274\232", nullptr));
        pushButton_add_2->setText(QCoreApplication::translate("LoadSetWidget", "\346\267\273\345\212\240", nullptr));
    } // retranslateUi

};

namespace Ui_LoadSet_3D {
    class LoadSetWidget_3D : public Ui_LoadSetWidget_3D {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADSETWIDGET_3D_H
