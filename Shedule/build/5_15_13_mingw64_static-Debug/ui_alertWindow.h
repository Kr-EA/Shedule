/********************************************************************************
** Form generated from reading UI file 'alertWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALERTWINDOW_H
#define UI_ALERTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NoNoNo
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;

    void setupUi(QDialog *NoNoNo)
    {
        if (NoNoNo->objectName().isEmpty())
            NoNoNo->setObjectName(QString::fromUtf8("NoNoNo"));
        NoNoNo->resize(400, 300);
        QFont font;
        font.setFamily(QString::fromUtf8("GOST type A"));
        font.setPointSize(14);
        NoNoNo->setFont(font);
        verticalLayout = new QVBoxLayout(NoNoNo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(NoNoNo);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("GOST type A"));
        font1.setPointSize(36);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(NoNoNo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("GOST type A"));
        font2.setPointSize(21);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);

        pushButton_2 = new QPushButton(NoNoNo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(NoNoNo);

        QMetaObject::connectSlotsByName(NoNoNo);
    } // setupUi

    void retranslateUi(QDialog *NoNoNo)
    {
        NoNoNo->setWindowTitle(QCoreApplication::translate("NoNoNo", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NoNoNo", "\320\222\320\275\320\270\320\274\320\260\320\275\320\270\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("NoNoNo", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("NoNoNo", "\320\236\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoNoNo: public Ui_NoNoNo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALERTWINDOW_H
