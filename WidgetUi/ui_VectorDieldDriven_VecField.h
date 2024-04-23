/********************************************************************************
** Form generated from reading UI file 'VectorDieldDriven_VecField.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VECTORDIELDDRIVEN_VECFIELD_H
#define UI_VECTORDIELDDRIVEN_VECFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VectorDieldDriven_VecField
{
public:
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QPushButton *pushButton_ImportVecField;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_AddCtrlPnt;
    QPushButton *pushButton_ImportCtrlPntsField;
    QPushButton *pushButton_ExprtAnchorField;
    QPushButton *pushButton_ClearCtrlPnts;
    QPushButton *pushButton_GeneFromCtrlPnt;
    QPushButton *pushButton_ExprtVecField;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_ClearVecField;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox_TriModel;
    QCheckBox *checkBox_AnF;
    QCheckBox *checkBox_VecF;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *VectorDieldDriven_VecField)
    {
        if (VectorDieldDriven_VecField->objectName().isEmpty())
            VectorDieldDriven_VecField->setObjectName(QString::fromUtf8("VectorDieldDriven_VecField"));
        VectorDieldDriven_VecField->resize(680, 784);
        horizontalLayout_2 = new QHBoxLayout(VectorDieldDriven_VecField);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget = new QWidget(VectorDieldDriven_VecField);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton = new QRadioButton(groupBox_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        verticalLayout->addWidget(radioButton);

        pushButton_ImportVecField = new QPushButton(groupBox_2);
        pushButton_ImportVecField->setObjectName(QString::fromUtf8("pushButton_ImportVecField"));
        pushButton_ImportVecField->setCheckable(false);

        verticalLayout->addWidget(pushButton_ImportVecField);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_3->addWidget(radioButton_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_AddCtrlPnt = new QPushButton(groupBox_3);
        pushButton_AddCtrlPnt->setObjectName(QString::fromUtf8("pushButton_AddCtrlPnt"));
        pushButton_AddCtrlPnt->setEnabled(false);
        pushButton_AddCtrlPnt->setCheckable(false);

        verticalLayout_2->addWidget(pushButton_AddCtrlPnt);

        pushButton_ImportCtrlPntsField = new QPushButton(groupBox_3);
        pushButton_ImportCtrlPntsField->setObjectName(QString::fromUtf8("pushButton_ImportCtrlPntsField"));
        pushButton_ImportCtrlPntsField->setEnabled(false);
        pushButton_ImportCtrlPntsField->setCheckable(false);

        verticalLayout_2->addWidget(pushButton_ImportCtrlPntsField);

        pushButton_ExprtAnchorField = new QPushButton(groupBox_3);
        pushButton_ExprtAnchorField->setObjectName(QString::fromUtf8("pushButton_ExprtAnchorField"));
        pushButton_ExprtAnchorField->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_ExprtAnchorField);

        pushButton_ClearCtrlPnts = new QPushButton(groupBox_3);
        pushButton_ClearCtrlPnts->setObjectName(QString::fromUtf8("pushButton_ClearCtrlPnts"));
        pushButton_ClearCtrlPnts->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_ClearCtrlPnts);


        verticalLayout_3->addWidget(groupBox_3);

        pushButton_GeneFromCtrlPnt = new QPushButton(groupBox);
        pushButton_GeneFromCtrlPnt->setObjectName(QString::fromUtf8("pushButton_GeneFromCtrlPnt"));
        pushButton_GeneFromCtrlPnt->setEnabled(false);

        verticalLayout_3->addWidget(pushButton_GeneFromCtrlPnt);

        pushButton_ExprtVecField = new QPushButton(groupBox);
        pushButton_ExprtVecField->setObjectName(QString::fromUtf8("pushButton_ExprtVecField"));
        pushButton_ExprtVecField->setEnabled(false);

        verticalLayout_3->addWidget(pushButton_ExprtVecField);


        verticalLayout_5->addWidget(groupBox);

        groupBox_4 = new QGroupBox(widget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout = new QHBoxLayout(groupBox_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_ClearVecField = new QPushButton(groupBox_4);
        pushButton_ClearVecField->setObjectName(QString::fromUtf8("pushButton_ClearVecField"));

        horizontalLayout->addWidget(pushButton_ClearVecField);


        verticalLayout_5->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(widget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        checkBox_TriModel = new QCheckBox(groupBox_5);
        checkBox_TriModel->setObjectName(QString::fromUtf8("checkBox_TriModel"));
        checkBox_TriModel->setEnabled(false);
        checkBox_TriModel->setChecked(true);

        verticalLayout_4->addWidget(checkBox_TriModel);

        checkBox_AnF = new QCheckBox(groupBox_5);
        checkBox_AnF->setObjectName(QString::fromUtf8("checkBox_AnF"));
        checkBox_AnF->setEnabled(false);
        checkBox_AnF->setChecked(true);

        verticalLayout_4->addWidget(checkBox_AnF);

        checkBox_VecF = new QCheckBox(groupBox_5);
        checkBox_VecF->setObjectName(QString::fromUtf8("checkBox_VecF"));
        checkBox_VecF->setEnabled(false);
        checkBox_VecF->setChecked(true);

        verticalLayout_4->addWidget(checkBox_VecF);


        verticalLayout_5->addWidget(groupBox_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        retranslateUi(VectorDieldDriven_VecField);
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_ImportVecField, SLOT(setEnabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_AddCtrlPnt, SLOT(setDisabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_ExprtVecField, SLOT(setDisabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_GeneFromCtrlPnt, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_AddCtrlPnt, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_ExprtVecField, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_GeneFromCtrlPnt, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_ImportVecField, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_ImportCtrlPntsField, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_ClearCtrlPnts, SLOT(setEnabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_ImportCtrlPntsField, SLOT(setDisabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_ClearCtrlPnts, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_ExprtAnchorField, SLOT(setEnabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_ExprtAnchorField, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(VectorDieldDriven_VecField);
    } // setupUi

    void retranslateUi(QWidget *VectorDieldDriven_VecField)
    {
        VectorDieldDriven_VecField->setWindowTitle(QCoreApplication::translate("VectorDieldDriven_VecField", "Form", nullptr));
        groupBox_2->setTitle(QString());
        radioButton->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\350\207\252\345\212\250", nullptr));
        pushButton_ImportVecField->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\345\257\274\345\205\245\346\226\271\345\220\221\345\234\272", nullptr));
        groupBox->setTitle(QString());
        radioButton_2->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\346\211\213\345\212\250", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("VectorDieldDriven_VecField", "\351\224\232\345\220\221\351\207\217\345\234\272\347\274\226\350\276\221", nullptr));
        pushButton_AddCtrlPnt->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\346\267\273\345\212\240\351\224\232\345\220\221\351\207\217", nullptr));
        pushButton_ImportCtrlPntsField->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\345\257\274\345\205\245\351\224\232\345\220\221\351\207\217\345\234\272", nullptr));
        pushButton_ExprtAnchorField->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\345\257\274\345\207\272\351\224\232\345\220\221\351\207\217\345\234\272", nullptr));
        pushButton_ClearCtrlPnts->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\346\270\205\347\251\272\351\224\232\345\220\221\351\207\217\345\234\272", nullptr));
        pushButton_GeneFromCtrlPnt->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\347\224\261\351\224\232\345\220\221\351\207\217\345\234\272\347\224\237\346\210\220\346\226\271\345\220\221\345\234\272", nullptr));
        pushButton_ExprtVecField->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\345\257\274\345\207\272\346\226\271\345\220\221\345\234\272", nullptr));
        groupBox_4->setTitle(QString());
        pushButton_ClearVecField->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\346\270\205\347\251\272\346\226\271\345\220\221\345\234\272", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("VectorDieldDriven_VecField", "\346\230\276\347\244\272/\351\232\220\350\227\217", nullptr));
        checkBox_TriModel->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\344\270\211\350\247\222\347\275\221\346\240\274\346\250\241\345\236\213", nullptr));
        checkBox_AnF->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\351\224\232\345\220\221\351\207\217\345\234\272", nullptr));
        checkBox_VecF->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\345\220\221\351\207\217\345\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VectorDieldDriven_VecField: public Ui_VectorDieldDriven_VecField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VECTORDIELDDRIVEN_VECFIELD_H
