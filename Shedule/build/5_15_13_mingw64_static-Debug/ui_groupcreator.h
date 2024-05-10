/********************************************************************************
** Form generated from reading UI file 'groupcreator.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCREATOR_H
#define UI_GROUPCREATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_groupCreator
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *group;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *groupCreator)
    {
        if (groupCreator->objectName().isEmpty())
            groupCreator->setObjectName(QString::fromUtf8("groupCreator"));
        groupCreator->resize(994, 988);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(groupCreator->sizePolicy().hasHeightForWidth());
        groupCreator->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("GOST type A"));
        groupCreator->setFont(font);
        verticalLayout = new QVBoxLayout(groupCreator);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        verticalLayout->setContentsMargins(-1, 11, -1, 11);
        group = new QTableWidget(groupCreator);
        if (group->columnCount() < 2)
            group->setColumnCount(2);
        if (group->rowCount() < 7)
            group->setRowCount(7);
        group->setObjectName(QString::fromUtf8("group"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(group->sizePolicy().hasHeightForWidth());
        group->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("GOST type A"));
        font1.setPointSize(14);
        group->setFont(font1);
        group->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        group->setGridStyle(Qt::PenStyle::SolidLine);
        group->setRowCount(7);
        group->setColumnCount(2);

        verticalLayout->addWidget(group);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        confirmButton = new QPushButton(groupCreator);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setFont(font1);

        horizontalLayout_2->addWidget(confirmButton);

        cancelButton = new QPushButton(groupCreator);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setFont(font1);

        horizontalLayout_2->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(groupCreator);

        QMetaObject::connectSlotsByName(groupCreator);
    } // setupUi

    void retranslateUi(QDialog *groupCreator)
    {
        groupCreator->setWindowTitle(QCoreApplication::translate("groupCreator", "Dialog", nullptr));
        confirmButton->setText(QCoreApplication::translate("groupCreator", "\320\236\320\272", nullptr));
        cancelButton->setText(QCoreApplication::translate("groupCreator", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class groupCreator: public Ui_groupCreator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCREATOR_H
