/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *searchSubjectDataButton;
    QPushButton *sortSubjectDataButton;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *addSubjectButton;
    QPushButton *removeSubjectButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *searchTeacherButton;
    QPushButton *sortTeacherButton;
    QLabel *teachersData;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addTeacherButton;
    QPushButton *removeTeacherButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(996, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        searchSubjectDataButton = new QPushButton(centralwidget);
        searchSubjectDataButton->setObjectName(QString::fromUtf8("searchSubjectDataButton"));

        horizontalLayout_6->addWidget(searchSubjectDataButton);

        sortSubjectDataButton = new QPushButton(centralwidget);
        sortSubjectDataButton->setObjectName(QString::fromUtf8("sortSubjectDataButton"));

        horizontalLayout_6->addWidget(sortSubjectDataButton);


        verticalLayout_2->addLayout(horizontalLayout_6);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        addSubjectButton = new QPushButton(centralwidget);
        addSubjectButton->setObjectName(QString::fromUtf8("addSubjectButton"));

        horizontalLayout_7->addWidget(addSubjectButton);

        removeSubjectButton = new QPushButton(centralwidget);
        removeSubjectButton->setObjectName(QString::fromUtf8("removeSubjectButton"));

        horizontalLayout_7->addWidget(removeSubjectButton);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        searchTeacherButton = new QPushButton(centralwidget);
        searchTeacherButton->setObjectName(QString::fromUtf8("searchTeacherButton"));

        horizontalLayout_5->addWidget(searchTeacherButton);

        sortTeacherButton = new QPushButton(centralwidget);
        sortTeacherButton->setObjectName(QString::fromUtf8("sortTeacherButton"));

        horizontalLayout_5->addWidget(sortTeacherButton);


        verticalLayout->addLayout(horizontalLayout_5);

        teachersData = new QLabel(centralwidget);
        teachersData->setObjectName(QString::fromUtf8("teachersData"));
        teachersData->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        verticalLayout->addWidget(teachersData);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        addTeacherButton = new QPushButton(centralwidget);
        addTeacherButton->setObjectName(QString::fromUtf8("addTeacherButton"));

        horizontalLayout_4->addWidget(addTeacherButton);

        removeTeacherButton = new QPushButton(centralwidget);
        removeTeacherButton->setObjectName(QString::fromUtf8("removeTeacherButton"));

        horizontalLayout_4->addWidget(removeTeacherButton);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 996, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        searchSubjectDataButton->setText(QCoreApplication::translate("MainWindow", "Search subject", nullptr));
        sortSubjectDataButton->setText(QCoreApplication::translate("MainWindow", "Sort subjects", nullptr));
        label_2->setText(QString());
        addSubjectButton->setText(QCoreApplication::translate("MainWindow", "Add subject", nullptr));
        removeSubjectButton->setText(QCoreApplication::translate("MainWindow", "Remove subject", nullptr));
        searchTeacherButton->setText(QCoreApplication::translate("MainWindow", "Search teacher", nullptr));
        sortTeacherButton->setText(QCoreApplication::translate("MainWindow", "Sort teachers", nullptr));
        teachersData->setText(QString());
        addTeacherButton->setText(QCoreApplication::translate("MainWindow", "Add teacher", nullptr));
        removeTeacherButton->setText(QCoreApplication::translate("MainWindow", "Remove teacher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
