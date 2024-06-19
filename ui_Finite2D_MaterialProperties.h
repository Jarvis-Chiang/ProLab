/********************************************************************************
** Form generated from reading UI file 'Finite2D_MaterialProperties.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINITE2D_MATERIALPROPERTIES_H
#define UI_FINITE2D_MATERIALPROPERTIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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

class Ui_Finite2D_MaterialProperties
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *MaterialSetWidget;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *sameButton;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_Yang;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_Poission;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addMaterial_1;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_10;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *differentButton;
    QSpacerItem *horizontalSpacer_8;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *importElasticityMatrixButton;
    QSpacerItem *horizontalSpacer_7;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_8;
    QListWidget *listWidget;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *importMaterialVectorField;
    QSpacerItem *horizontalSpacer_10;
    QListWidget *listWidget_2;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *addMaterial_2;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Finite2D_MaterialProperties)
    {
        if (Finite2D_MaterialProperties->objectName().isEmpty())
            Finite2D_MaterialProperties->setObjectName(QString::fromUtf8("Finite2D_MaterialProperties"));
        Finite2D_MaterialProperties->resize(1232, 944);
        verticalLayout = new QVBoxLayout(Finite2D_MaterialProperties);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        MaterialSetWidget = new QGroupBox(Finite2D_MaterialProperties);
        MaterialSetWidget->setObjectName(QString::fromUtf8("MaterialSetWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MaterialSetWidget->sizePolicy().hasHeightForWidth());
        MaterialSetWidget->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(MaterialSetWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_9 = new QWidget(MaterialSetWidget);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        horizontalLayout_9 = new QHBoxLayout(widget_9);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        groupBox_2 = new QGroupBox(widget_9);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(400, 0));
        groupBox_2->setMaximumSize(QSize(400, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sameButton = new QCheckBox(widget);
        sameButton->setObjectName(QString::fromUtf8("sameButton"));

        horizontalLayout_2->addWidget(sameButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(groupBox_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_Yang = new QLineEdit(widget_2);
        lineEdit_Yang->setObjectName(QString::fromUtf8("lineEdit_Yang"));

        horizontalLayout->addWidget(lineEdit_Yang);


        verticalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(groupBox_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_Poission = new QLineEdit(widget_3);
        lineEdit_Poission->setObjectName(QString::fromUtf8("lineEdit_Poission"));

        horizontalLayout_3->addWidget(lineEdit_Poission);


        verticalLayout_2->addWidget(widget_3);

        widget_6 = new QWidget(groupBox_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        addMaterial_1 = new QPushButton(widget_6);
        addMaterial_1->setObjectName(QString::fromUtf8("addMaterial_1"));

        horizontalLayout_5->addWidget(addMaterial_1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout_2->addWidget(widget_6);


        horizontalLayout_9->addWidget(groupBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout_4->addWidget(widget_9);

        widget_10 = new QWidget(MaterialSetWidget);
        widget_10->setObjectName(QString::fromUtf8("widget_10"));
        horizontalLayout_10 = new QHBoxLayout(widget_10);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        groupBox_3 = new QGroupBox(widget_10);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setMinimumSize(QSize(400, 0));
        groupBox_3->setMaximumSize(QSize(400, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget_4 = new QWidget(groupBox_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        differentButton = new QCheckBox(widget_4);
        differentButton->setObjectName(QString::fromUtf8("differentButton"));

        horizontalLayout_4->addWidget(differentButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout_3->addWidget(widget_4);

        widget_5 = new QWidget(groupBox_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_6 = new QHBoxLayout(widget_5);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        importElasticityMatrixButton = new QPushButton(widget_5);
        importElasticityMatrixButton->setObjectName(QString::fromUtf8("importElasticityMatrixButton"));

        horizontalLayout_6->addWidget(importElasticityMatrixButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);


        verticalLayout_3->addWidget(widget_5);

        widget_8 = new QWidget(groupBox_3);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        horizontalLayout_8 = new QHBoxLayout(widget_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        listWidget = new QListWidget(widget_8);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout_8->addWidget(listWidget);


        verticalLayout_3->addWidget(widget_8);

        widget_11 = new QWidget(groupBox_3);
        widget_11->setObjectName(QString::fromUtf8("widget_11"));
        horizontalLayout_11 = new QHBoxLayout(widget_11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        importMaterialVectorField = new QPushButton(widget_11);
        importMaterialVectorField->setObjectName(QString::fromUtf8("importMaterialVectorField"));

        horizontalLayout_11->addWidget(importMaterialVectorField);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_10);


        verticalLayout_3->addWidget(widget_11);

        listWidget_2 = new QListWidget(groupBox_3);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));

        verticalLayout_3->addWidget(listWidget_2);

        widget_7 = new QWidget(groupBox_3);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        horizontalLayout_7 = new QHBoxLayout(widget_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        addMaterial_2 = new QPushButton(widget_7);
        addMaterial_2->setObjectName(QString::fromUtf8("addMaterial_2"));

        horizontalLayout_7->addWidget(addMaterial_2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);


        verticalLayout_3->addWidget(widget_7);


        horizontalLayout_10->addWidget(groupBox_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);


        verticalLayout_4->addWidget(widget_10);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout->addWidget(MaterialSetWidget);


        retranslateUi(Finite2D_MaterialProperties);

        QMetaObject::connectSlotsByName(Finite2D_MaterialProperties);
    } // setupUi

    void retranslateUi(QWidget *Finite2D_MaterialProperties)
    {
        Finite2D_MaterialProperties->setWindowTitle(QCoreApplication::translate("Finite2D_MaterialProperties", "Form", nullptr));
        MaterialSetWidget->setTitle(QCoreApplication::translate("Finite2D_MaterialProperties", "\346\235\220\346\226\231\350\256\276\347\275\256", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Finite2D_MaterialProperties", "\345\220\204\345\220\221\345\220\214\346\200\247", nullptr));
        sameButton->setText(QCoreApplication::translate("Finite2D_MaterialProperties", "\345\220\204\351\241\271\345\220\214\346\200\247\346\235\220\346\226\231", nullptr));
        label->setText(QCoreApplication::translate("Finite2D_MaterialProperties", "\346\235\250\346\260\217\346\250\241\351\207\217\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Finite2D_MaterialProperties", "  \346\263\212\346\235\276\346\257\224\357\274\232", nullptr));
        addMaterial_1->setText(QCoreApplication::translate("Finite2D_MaterialProperties", "\346\267\273\345\212\240\346\235\220\346\226\231", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Finite2D_MaterialProperties", "\345\220\204\345\220\221\345\274\202\346\200\247", nullptr));
        differentButton->setText(QCoreApplication::translate("Finite2D_MaterialProperties", "\345\220\204\351\241\271\345\274\202\346\200\247\346\235\220\346\226\231", nullptr));
        importElasticityMatrixButton->setText(QCoreApplication::translate("Finite2D_MaterialProperties", "\345\257\274\345\205\245\345\274\271\346\200\247\347\237\251\351\230\265", nullptr));
        importMaterialVectorField->setText(QCoreApplication::translate("Finite2D_MaterialProperties", "\345\257\274\345\205\245\346\235\220\346\226\231\346\226\271\345\220\221\345\234\272", nullptr));
        addMaterial_2->setText(QCoreApplication::translate("Finite2D_MaterialProperties", "\346\267\273\345\212\240\346\235\220\346\226\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Finite2D_MaterialProperties: public Ui_Finite2D_MaterialProperties {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINITE2D_MATERIALPROPERTIES_H
