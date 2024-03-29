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
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QPushButton *pushButton_ImportVecField;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_AddCtrlPnt;
    QPushButton *pushButton_GeneFromCtrlPnt;
    QPushButton *pushButton_ExprtVecField;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *VectorDieldDriven_VecField)
    {
        if (VectorDieldDriven_VecField->objectName().isEmpty())
            VectorDieldDriven_VecField->setObjectName(QString::fromUtf8("VectorDieldDriven_VecField"));
        VectorDieldDriven_VecField->resize(680, 784);
        horizontalLayout = new QHBoxLayout(VectorDieldDriven_VecField);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(VectorDieldDriven_VecField);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
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


        verticalLayout_3->addWidget(groupBox_2);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_2->addWidget(radioButton_2);

        pushButton_AddCtrlPnt = new QPushButton(groupBox);
        pushButton_AddCtrlPnt->setObjectName(QString::fromUtf8("pushButton_AddCtrlPnt"));
        pushButton_AddCtrlPnt->setEnabled(false);
        pushButton_AddCtrlPnt->setCheckable(false);

        verticalLayout_2->addWidget(pushButton_AddCtrlPnt);

        pushButton_GeneFromCtrlPnt = new QPushButton(groupBox);
        pushButton_GeneFromCtrlPnt->setObjectName(QString::fromUtf8("pushButton_GeneFromCtrlPnt"));
        pushButton_GeneFromCtrlPnt->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_GeneFromCtrlPnt);

        pushButton_ExprtVecField = new QPushButton(groupBox);
        pushButton_ExprtVecField->setObjectName(QString::fromUtf8("pushButton_ExprtVecField"));
        pushButton_ExprtVecField->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_ExprtVecField);


        verticalLayout_3->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(VectorDieldDriven_VecField);
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_ImportVecField, SLOT(setEnabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_AddCtrlPnt, SLOT(setDisabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_ExprtVecField, SLOT(setDisabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_GeneFromCtrlPnt, SLOT(setDisabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_AddCtrlPnt, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_ExprtVecField, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_GeneFromCtrlPnt, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_ImportVecField, SLOT(setDisabled(bool)));

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
        pushButton_AddCtrlPnt->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\346\267\273\345\212\240\346\216\247\345\210\266\347\202\271", nullptr));
        pushButton_GeneFromCtrlPnt->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\347\224\261\346\216\247\345\210\266\347\202\271\347\224\237\346\210\220", nullptr));
        pushButton_ExprtVecField->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\345\257\274\345\207\272\346\226\271\345\220\221\345\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VectorDieldDriven_VecField: public Ui_VectorDieldDriven_VecField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VECTORDIELDDRIVEN_VECFIELD_H
