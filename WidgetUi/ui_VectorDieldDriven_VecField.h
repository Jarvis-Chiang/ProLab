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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
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
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_ImportVecField;
    QPushButton *pushButton_GeneFromCtrlPnt;
    QPushButton *pushButton_AddCtrlPnt;
    QPushButton *pushButton_ExprtVecField;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *VectorDieldDriven_VecField)
    {
        if (VectorDieldDriven_VecField->objectName().isEmpty())
            VectorDieldDriven_VecField->setObjectName(QString::fromUtf8("VectorDieldDriven_VecField"));
        VectorDieldDriven_VecField->resize(400, 300);
        horizontalLayout = new QHBoxLayout(VectorDieldDriven_VecField);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(VectorDieldDriven_VecField);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_ImportVecField = new QPushButton(widget);
        pushButton_ImportVecField->setObjectName(QString::fromUtf8("pushButton_ImportVecField"));

        verticalLayout->addWidget(pushButton_ImportVecField);

        pushButton_GeneFromCtrlPnt = new QPushButton(widget);
        pushButton_GeneFromCtrlPnt->setObjectName(QString::fromUtf8("pushButton_GeneFromCtrlPnt"));

        verticalLayout->addWidget(pushButton_GeneFromCtrlPnt);

        pushButton_AddCtrlPnt = new QPushButton(widget);
        pushButton_AddCtrlPnt->setObjectName(QString::fromUtf8("pushButton_AddCtrlPnt"));

        verticalLayout->addWidget(pushButton_AddCtrlPnt);

        pushButton_ExprtVecField = new QPushButton(widget);
        pushButton_ExprtVecField->setObjectName(QString::fromUtf8("pushButton_ExprtVecField"));

        verticalLayout->addWidget(pushButton_ExprtVecField);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(widget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(VectorDieldDriven_VecField);

        QMetaObject::connectSlotsByName(VectorDieldDriven_VecField);
    } // setupUi

    void retranslateUi(QWidget *VectorDieldDriven_VecField)
    {
        VectorDieldDriven_VecField->setWindowTitle(QCoreApplication::translate("VectorDieldDriven_VecField", "Form", nullptr));
        pushButton_ImportVecField->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\345\257\274\345\205\245\346\226\271\345\220\221\345\234\272", nullptr));
        pushButton_GeneFromCtrlPnt->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\347\224\261\346\216\247\345\210\266\347\202\271\347\224\237\346\210\220", nullptr));
        pushButton_AddCtrlPnt->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\346\267\273\345\212\240\346\216\247\345\210\266\347\202\271", nullptr));
        pushButton_ExprtVecField->setText(QCoreApplication::translate("VectorDieldDriven_VecField", "\345\257\274\345\207\272\346\226\271\345\220\221\345\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VectorDieldDriven_VecField: public Ui_VectorDieldDriven_VecField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VECTORDIELDDRIVEN_VECFIELD_H
