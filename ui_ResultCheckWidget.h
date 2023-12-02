/********************************************************************************
** Form generated from reading UI file 'ResultCheckWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTCHECKWIDGET_H
#define UI_RESULTCHECKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResultCheckWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_21;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_31;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QSpacerItem *horizontalSpacer_32;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_20;
    QSpacerItem *horizontalSpacer_39;
    QPushButton *generateDensityFieldBotton_4;
    QSpacerItem *horizontalSpacer_40;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_37;
    QPushButton *generateStressFieldBotton_4;
    QSpacerItem *horizontalSpacer_38;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_33;
    QPushButton *generateBiasFieldBotton_4;
    QSpacerItem *horizontalSpacer_34;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_18;
    QSpacerItem *horizontalSpacer_35;
    QPushButton *generateVectorFieldBotton_4;
    QSpacerItem *horizontalSpacer_36;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ResultCheckWidget)
    {
        if (ResultCheckWidget->objectName().isEmpty())
            ResultCheckWidget->setObjectName(QString::fromUtf8("ResultCheckWidget"));
        ResultCheckWidget->resize(358, 356);
        verticalLayout_3 = new QVBoxLayout(ResultCheckWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(ResultCheckWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        horizontalLayout_21 = new QHBoxLayout(groupBox);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_6 = new QHBoxLayout(widget_2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_31);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        lineEdit_4 = new QLineEdit(widget_2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_6->addWidget(lineEdit_4);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_32);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_20 = new QHBoxLayout(widget_3);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        horizontalSpacer_39 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_39);

        generateDensityFieldBotton_4 = new QPushButton(widget_3);
        generateDensityFieldBotton_4->setObjectName(QString::fromUtf8("generateDensityFieldBotton_4"));

        horizontalLayout_20->addWidget(generateDensityFieldBotton_4);

        horizontalSpacer_40 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_40);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_19 = new QHBoxLayout(widget_4);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalSpacer_37 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_37);

        generateStressFieldBotton_4 = new QPushButton(widget_4);
        generateStressFieldBotton_4->setObjectName(QString::fromUtf8("generateStressFieldBotton_4"));

        horizontalLayout_19->addWidget(generateStressFieldBotton_4);

        horizontalSpacer_38 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_38);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(widget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_17 = new QHBoxLayout(widget_5);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_33);

        generateBiasFieldBotton_4 = new QPushButton(widget_5);
        generateBiasFieldBotton_4->setObjectName(QString::fromUtf8("generateBiasFieldBotton_4"));

        horizontalLayout_17->addWidget(generateBiasFieldBotton_4);

        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_34);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(widget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_18 = new QHBoxLayout(widget_6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalSpacer_35 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_35);

        generateVectorFieldBotton_4 = new QPushButton(widget_6);
        generateVectorFieldBotton_4->setObjectName(QString::fromUtf8("generateVectorFieldBotton_4"));

        horizontalLayout_18->addWidget(generateVectorFieldBotton_4);

        horizontalSpacer_36 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_36);


        verticalLayout->addWidget(widget_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_21->addWidget(widget);


        verticalLayout_3->addWidget(groupBox);


        retranslateUi(ResultCheckWidget);

        QMetaObject::connectSlotsByName(ResultCheckWidget);
    } // setupUi

    void retranslateUi(QWidget *ResultCheckWidget)
    {
        ResultCheckWidget->setWindowTitle(QApplication::translate("ResultCheckWidget", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("ResultCheckWidget", "\347\273\223\346\236\234\346\237\245\347\234\213", nullptr));
        label_4->setText(QApplication::translate("ResultCheckWidget", "\344\270\264\347\225\214\345\200\274\357\274\232", nullptr));
        generateDensityFieldBotton_4->setText(QApplication::translate("ResultCheckWidget", "\347\224\237\346\210\220\345\257\206\345\272\246\345\234\272", nullptr));
        generateStressFieldBotton_4->setText(QApplication::translate("ResultCheckWidget", "\347\224\237\346\210\220\345\272\224\345\212\233\345\234\272", nullptr));
        generateBiasFieldBotton_4->setText(QApplication::translate("ResultCheckWidget", "\347\224\237\346\210\220\344\275\215\347\247\273\345\234\272", nullptr));
        generateVectorFieldBotton_4->setText(QApplication::translate("ResultCheckWidget", "\347\224\237\346\210\220\345\220\221\351\207\217\345\234\272", nullptr));
    } // retranslateUi

};

namespace Ui_Result {
    class ResultCheckWidget: public Ui_ResultCheckWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTCHECKWIDGET_H
