/********************************************************************************
** Form generated from reading UI file 'tdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TDIALOG_H
#define UI_TDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_tDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *teacherLastnameLabel;
    QLineEdit *teacherLastnameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *teacherNameEdit;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *teacherSurnameLabel;
    QLineEdit *teacherSurnameEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *ratingLabel;
    QSlider *ratingSetter;
    QHBoxLayout *horizontalLayout_5;
    QLabel *amountOfSubjectsLabel;
    QSpinBox *amountOfSubjectsSetter;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QDialog *tDialog)
    {
        if (tDialog->objectName().isEmpty())
            tDialog->setObjectName(QString::fromUtf8("tDialog"));
        tDialog->resize(580, 300);
        verticalLayout = new QVBoxLayout(tDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        teacherLastnameLabel = new QLabel(tDialog);
        teacherLastnameLabel->setObjectName(QString::fromUtf8("teacherLastnameLabel"));

        horizontalLayout->addWidget(teacherLastnameLabel);

        teacherLastnameEdit = new QLineEdit(tDialog);
        teacherLastnameEdit->setObjectName(QString::fromUtf8("teacherLastnameEdit"));

        horizontalLayout->addWidget(teacherLastnameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        teacherNameEdit = new QLabel(tDialog);
        teacherNameEdit->setObjectName(QString::fromUtf8("teacherNameEdit"));

        horizontalLayout_2->addWidget(teacherNameEdit);

        lineEdit_2 = new QLineEdit(tDialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        teacherSurnameLabel = new QLabel(tDialog);
        teacherSurnameLabel->setObjectName(QString::fromUtf8("teacherSurnameLabel"));

        horizontalLayout_3->addWidget(teacherSurnameLabel);

        teacherSurnameEdit = new QLineEdit(tDialog);
        teacherSurnameEdit->setObjectName(QString::fromUtf8("teacherSurnameEdit"));

        horizontalLayout_3->addWidget(teacherSurnameEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        ratingLabel = new QLabel(tDialog);
        ratingLabel->setObjectName(QString::fromUtf8("ratingLabel"));

        horizontalLayout_4->addWidget(ratingLabel);

        ratingSetter = new QSlider(tDialog);
        ratingSetter->setObjectName(QString::fromUtf8("ratingSetter"));
        ratingSetter->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_4->addWidget(ratingSetter);

        horizontalLayout_4->setStretch(0, 10);
        horizontalLayout_4->setStretch(1, 40);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        amountOfSubjectsLabel = new QLabel(tDialog);
        amountOfSubjectsLabel->setObjectName(QString::fromUtf8("amountOfSubjectsLabel"));

        horizontalLayout_5->addWidget(amountOfSubjectsLabel);

        amountOfSubjectsSetter = new QSpinBox(tDialog);
        amountOfSubjectsSetter->setObjectName(QString::fromUtf8("amountOfSubjectsSetter"));
        amountOfSubjectsSetter->setMinimum(1);
        amountOfSubjectsSetter->setMaximum(5);

        horizontalLayout_5->addWidget(amountOfSubjectsSetter);

        horizontalLayout_5->setStretch(0, 10);
        horizontalLayout_5->setStretch(1, 20);

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        confirm = new QPushButton(tDialog);
        confirm->setObjectName(QString::fromUtf8("confirm"));

        horizontalLayout_6->addWidget(confirm);

        cancel = new QPushButton(tDialog);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout_6->addWidget(cancel);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(tDialog);

        QMetaObject::connectSlotsByName(tDialog);
    } // setupUi

    void retranslateUi(QDialog *tDialog)
    {
        tDialog->setWindowTitle(QCoreApplication::translate("tDialog", "Dialog", nullptr));
        teacherLastnameLabel->setText(QCoreApplication::translate("tDialog", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        teacherNameEdit->setText(QCoreApplication::translate("tDialog", "\320\230\320\274\321\217 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        teacherSurnameLabel->setText(QCoreApplication::translate("tDialog", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\217:", nullptr));
        ratingLabel->setText(QCoreApplication::translate("tDialog", "\320\240\320\265\320\271\321\202\320\270\320\275\320\263:", nullptr));
        amountOfSubjectsLabel->setText(QCoreApplication::translate("tDialog", "\320\247\320\270\321\201\320\273\320\276 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\320\276\320\262:", nullptr));
        confirm->setText(QCoreApplication::translate("tDialog", "\320\236\320\272", nullptr));
        cancel->setText(QCoreApplication::translate("tDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tDialog: public Ui_tDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TDIALOG_H
