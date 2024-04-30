/********************************************************************************
** Form generated from reading UI file 'setsubjects.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETSUBJECTS_H
#define UI_SETSUBJECTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_setSubjects
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *subject1;
    QHBoxLayout *layout;
    QLabel *sub1;
    QComboBox *setSub1;
    QHBoxLayout *subject2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *sub2;
    QComboBox *setSub2;
    QHBoxLayout *subject3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *sub3;
    QComboBox *setSub3;
    QHBoxLayout *subject4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *sub4;
    QComboBox *setSub4;
    QHBoxLayout *subject5;
    QHBoxLayout *horizontalLayout_11;
    QLabel *sub5;
    QComboBox *setSub5;
    QHBoxLayout *exit;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QDialog *setSubjects)
    {
        if (setSubjects->objectName().isEmpty())
            setSubjects->setObjectName(QString::fromUtf8("setSubjects"));
        setSubjects->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(setSubjects);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        subject1 = new QHBoxLayout();
        subject1->setObjectName(QString::fromUtf8("subject1"));
        layout = new QHBoxLayout();
        layout->setObjectName(QString::fromUtf8("layout"));
        sub1 = new QLabel(setSubjects);
        sub1->setObjectName(QString::fromUtf8("sub1"));

        layout->addWidget(sub1);

        setSub1 = new QComboBox(setSubjects);
        setSub1->setObjectName(QString::fromUtf8("setSub1"));
        setSub1->setInsertPolicy(QComboBox::InsertPolicy::InsertAtBottom);

        layout->addWidget(setSub1);

        layout->setStretch(0, 10);
        layout->setStretch(1, 50);

        subject1->addLayout(layout);


        verticalLayout_2->addLayout(subject1);

        subject2 = new QHBoxLayout();
        subject2->setObjectName(QString::fromUtf8("subject2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        sub2 = new QLabel(setSubjects);
        sub2->setObjectName(QString::fromUtf8("sub2"));

        horizontalLayout_8->addWidget(sub2);

        setSub2 = new QComboBox(setSubjects);
        setSub2->setObjectName(QString::fromUtf8("setSub2"));

        horizontalLayout_8->addWidget(setSub2);

        horizontalLayout_8->setStretch(0, 10);
        horizontalLayout_8->setStretch(1, 50);

        subject2->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(subject2);

        subject3 = new QHBoxLayout();
        subject3->setObjectName(QString::fromUtf8("subject3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        sub3 = new QLabel(setSubjects);
        sub3->setObjectName(QString::fromUtf8("sub3"));

        horizontalLayout_9->addWidget(sub3);

        setSub3 = new QComboBox(setSubjects);
        setSub3->setObjectName(QString::fromUtf8("setSub3"));

        horizontalLayout_9->addWidget(setSub3);

        horizontalLayout_9->setStretch(0, 10);
        horizontalLayout_9->setStretch(1, 50);

        subject3->addLayout(horizontalLayout_9);


        verticalLayout_2->addLayout(subject3);

        subject4 = new QHBoxLayout();
        subject4->setObjectName(QString::fromUtf8("subject4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        sub4 = new QLabel(setSubjects);
        sub4->setObjectName(QString::fromUtf8("sub4"));

        horizontalLayout_10->addWidget(sub4);

        setSub4 = new QComboBox(setSubjects);
        setSub4->setObjectName(QString::fromUtf8("setSub4"));

        horizontalLayout_10->addWidget(setSub4);

        horizontalLayout_10->setStretch(0, 10);
        horizontalLayout_10->setStretch(1, 50);

        subject4->addLayout(horizontalLayout_10);


        verticalLayout_2->addLayout(subject4);

        subject5 = new QHBoxLayout();
        subject5->setObjectName(QString::fromUtf8("subject5"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        sub5 = new QLabel(setSubjects);
        sub5->setObjectName(QString::fromUtf8("sub5"));

        horizontalLayout_11->addWidget(sub5);

        setSub5 = new QComboBox(setSubjects);
        setSub5->setObjectName(QString::fromUtf8("setSub5"));

        horizontalLayout_11->addWidget(setSub5);

        horizontalLayout_11->setStretch(0, 10);
        horizontalLayout_11->setStretch(1, 50);

        subject5->addLayout(horizontalLayout_11);


        verticalLayout_2->addLayout(subject5);

        exit = new QHBoxLayout();
        exit->setObjectName(QString::fromUtf8("exit"));
        confirm = new QPushButton(setSubjects);
        confirm->setObjectName(QString::fromUtf8("confirm"));

        exit->addWidget(confirm);

        cancel = new QPushButton(setSubjects);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        exit->addWidget(cancel);


        verticalLayout_2->addLayout(exit);


        retranslateUi(setSubjects);

        QMetaObject::connectSlotsByName(setSubjects);
    } // setupUi

    void retranslateUi(QDialog *setSubjects)
    {
        setSubjects->setWindowTitle(QCoreApplication::translate("setSubjects", "Dialog", nullptr));
        sub1->setText(QCoreApplication::translate("setSubjects", "\320\237\321\200\320\265\320\264\320\274\320\265\321\202 1", nullptr));
        setSub1->setCurrentText(QString());
        sub2->setText(QCoreApplication::translate("setSubjects", "\320\237\321\200\320\265\320\264\320\274\320\265\321\202 2", nullptr));
        sub3->setText(QCoreApplication::translate("setSubjects", "\320\237\321\200\320\265\320\264\320\274\320\265\321\202 3", nullptr));
        sub4->setText(QCoreApplication::translate("setSubjects", "\320\237\321\200\320\265\320\264\320\274\320\265\321\202 4", nullptr));
        sub5->setText(QCoreApplication::translate("setSubjects", "\320\237\321\200\320\265\320\264\320\274\320\265\321\202 5", nullptr));
        confirm->setText(QCoreApplication::translate("setSubjects", "\320\236\320\272", nullptr));
        cancel->setText(QCoreApplication::translate("setSubjects", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setSubjects: public Ui_setSubjects {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETSUBJECTS_H
