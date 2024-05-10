/********************************************************************************
** Form generated from reading UI file 'confirmaction.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMACTION_H
#define UI_CONFIRMACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_confirmAction
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *yes;
    QPushButton *no;

    void setupUi(QDialog *confirmAction)
    {
        if (confirmAction->objectName().isEmpty())
            confirmAction->setObjectName(QString::fromUtf8("confirmAction"));
        confirmAction->resize(400, 300);
        QFont font;
        font.setFamily(QString::fromUtf8("GOST type A"));
        font.setPointSize(14);
        confirmAction->setFont(font);
        verticalLayout = new QVBoxLayout(confirmAction);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(confirmAction);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("GOST type A"));
        font1.setPointSize(36);
        font1.setBold(false);
        font1.setItalic(false);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(confirmAction);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        yes = new QPushButton(confirmAction);
        yes->setObjectName(QString::fromUtf8("yes"));

        horizontalLayout->addWidget(yes);

        no = new QPushButton(confirmAction);
        no->setObjectName(QString::fromUtf8("no"));

        horizontalLayout->addWidget(no);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 10);

        retranslateUi(confirmAction);

        QMetaObject::connectSlotsByName(confirmAction);
    } // setupUi

    void retranslateUi(QDialog *confirmAction)
    {
        confirmAction->setWindowTitle(QCoreApplication::translate("confirmAction", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("confirmAction", "\320\222\321\213 \321\203\320\262\320\265\321\200\320\265\320\275\321\213?", nullptr));
        label_2->setText(QString());
        yes->setText(QCoreApplication::translate("confirmAction", "\320\224\320\260", nullptr));
        no->setText(QCoreApplication::translate("confirmAction", "\320\235\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class confirmAction: public Ui_confirmAction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMACTION_H
