/********************************************************************************
** Form generated from reading UI file 'MaterialSetWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATERIALSETWIDGET_H
#define UI_MATERIALSETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MeterialSetWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *ok;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_6;
    QTextEdit *textEdit;

    void setupUi(QWidget *MeterialSetWidget)
    {
        if (MeterialSetWidget->objectName().isEmpty())
            MeterialSetWidget->setObjectName(QString::fromUtf8("MeterialSetWidget"));
        MeterialSetWidget->resize(388, 351);
        verticalLayout = new QVBoxLayout(MeterialSetWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(MeterialSetWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        widget_3 = new QWidget(tab);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_2 = new QVBoxLayout(widget_3);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(widget_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(7, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        lineEdit_2 = new QLineEdit(widget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(widget_2);

        widget_6 = new QWidget(widget_3);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_3 = new QHBoxLayout(widget_6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        ok = new QPushButton(widget_6);
        ok->setObjectName(QString::fromUtf8("ok"));

        horizontalLayout_3->addWidget(ok);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout_2->addWidget(widget_6);


        verticalLayout_3->addWidget(widget_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget_4 = new QWidget(tab_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        widget_5 = new QWidget(widget_4);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton = new QPushButton(widget_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_4->addWidget(widget_5);

        textEdit = new QTextEdit(widget_4);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_4->addWidget(textEdit);


        verticalLayout_5->addWidget(widget_4);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_6->addWidget(tabWidget);


        verticalLayout->addWidget(groupBox);


        retranslateUi(MeterialSetWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MeterialSetWidget);
    } // setupUi

    void retranslateUi(QWidget *MeterialSetWidget)
    {
        MeterialSetWidget->setWindowTitle(QApplication::translate("MeterialSetWidget", "MaterialSetWidget", nullptr));
        groupBox->setTitle(QApplication::translate("MeterialSetWidget", "\346\235\220\346\226\231\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("MeterialSetWidget", "\346\235\250\346\260\217\346\250\241\351\207\217\357\274\232", nullptr));
        label_2->setText(QApplication::translate("MeterialSetWidget", "\346\263\212\346\235\276\346\257\224\357\274\232", nullptr));
        ok->setText(QApplication::translate("MeterialSetWidget", "\347\241\256\345\256\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MeterialSetWidget", "\345\220\204\345\220\221\345\220\214\346\200\247\346\235\220\346\226\231", nullptr));
        pushButton->setText(QApplication::translate("MeterialSetWidget", "\345\257\274\345\205\245\345\274\271\346\200\247\347\237\251\351\230\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MeterialSetWidget", "\345\220\204\351\241\271\345\274\202\346\200\247\346\235\220\346\226\231", nullptr));
    } // retranslateUi

};

namespace Ui_Material {
    class MeterialSetWidget: public Ui_MeterialSetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATERIALSETWIDGET_H
