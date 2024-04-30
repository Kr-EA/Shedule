/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *subjectTitleLabel;
    QLineEdit *subjectTitleEditor;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *subjectTypeLayout;
    QRadioButton *lectureRadio;
    QRadioButton *practiceRadio;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *hoursLabel;
    QSlider *hoursSetter;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(473, 234);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("GOST type A"));
        font.setPointSize(14);
        Dialog->setFont(font);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        subjectTitleLabel = new QLabel(widget);
        subjectTitleLabel->setObjectName(QString::fromUtf8("subjectTitleLabel"));
        subjectTitleLabel->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        horizontalLayout->addWidget(subjectTitleLabel);

        subjectTitleEditor = new QLineEdit(widget);
        subjectTitleEditor->setObjectName(QString::fromUtf8("subjectTitleEditor"));
        sizePolicy1.setHeightForWidth(subjectTitleEditor->sizePolicy().hasHeightForWidth());
        subjectTitleEditor->setSizePolicy(sizePolicy1);
        subjectTitleEditor->setMinimumSize(QSize(0, 0));
        subjectTitleEditor->setFrame(true);

        horizontalLayout->addWidget(subjectTitleEditor);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(Dialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        subjectTypeLayout = new QLabel(widget_2);
        subjectTypeLayout->setObjectName(QString::fromUtf8("subjectTypeLayout"));

        horizontalLayout_2->addWidget(subjectTypeLayout);

        lectureRadio = new QRadioButton(widget_2);
        lectureRadio->setObjectName(QString::fromUtf8("lectureRadio"));

        horizontalLayout_2->addWidget(lectureRadio);

        practiceRadio = new QRadioButton(widget_2);
        practiceRadio->setObjectName(QString::fromUtf8("practiceRadio"));

        horizontalLayout_2->addWidget(practiceRadio);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(Dialog);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        hoursLabel = new QLabel(widget_3);
        hoursLabel->setObjectName(QString::fromUtf8("hoursLabel"));

        horizontalLayout_3->addWidget(hoursLabel);

        hoursSetter = new QSlider(widget_3);
        hoursSetter->setObjectName(QString::fromUtf8("hoursSetter"));
        hoursSetter->setMaximum(172);
        hoursSetter->setValue(0);
        hoursSetter->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_3->addWidget(hoursSetter);

        horizontalLayout_3->setStretch(0, 40);
        horizontalLayout_3->setStretch(1, 90);

        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(Dialog);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        confirm = new QPushButton(widget_4);
        confirm->setObjectName(QString::fromUtf8("confirm"));

        horizontalLayout_4->addWidget(confirm);

        cancel = new QPushButton(widget_4);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout_4->addWidget(cancel);


        verticalLayout->addWidget(widget_4);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        subjectTitleLabel->setText(QCoreApplication::translate("Dialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\320\260:", nullptr));
        subjectTitleEditor->setInputMask(QString());
        subjectTitleEditor->setText(QString());
        subjectTitleEditor->setPlaceholderText(QCoreApplication::translate("Dialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\320\260", nullptr));
        subjectTypeLayout->setText(QCoreApplication::translate("Dialog", "\320\242\320\270\320\277 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\320\260", nullptr));
        lectureRadio->setText(QCoreApplication::translate("Dialog", "\320\233\320\265\320\272\321\206\320\270\321\217", nullptr));
        practiceRadio->setText(QCoreApplication::translate("Dialog", "\320\237\321\200\320\260\320\272\321\202\320\270\320\272\320\260", nullptr));
        hoursLabel->setText(QCoreApplication::translate("Dialog", "\320\247\320\270\321\201\320\273\320\276 \321\207\320\260\321\201\320\276\320\262: ", nullptr));
        confirm->setText(QCoreApplication::translate("Dialog", "\320\236\320\272", nullptr));
        cancel->setText(QCoreApplication::translate("Dialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
