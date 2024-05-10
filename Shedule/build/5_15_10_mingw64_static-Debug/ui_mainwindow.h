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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QWidget *teachersAndSubjects;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *searchSubjectDataButton;
    QLineEdit *searchInput;
    QPushButton *sortSubjectDataButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *subjectsData;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *addSubjectButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *searchTeacherButton;
    QLineEdit *searchTeacherLine;
    QPushButton *sortTeacherButton;
    QPushButton *returnAllSubjects;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *teachersData;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addTeacherButton;
    QPushButton *expandAndCollapse;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *groups;
    QWidget *groupMenu;
    QGridLayout *gridLayout;
    QPushButton *searchGroup;
    QLineEdit *searchGroupLine;
    QPushButton *addGroup;
    QPushButton *saveData;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1261, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("GOST type A"));
        font.setPointSize(14);
        MainWindow->setFont(font);
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
        teachersAndSubjects = new QWidget(centralwidget);
        teachersAndSubjects->setObjectName(QString::fromUtf8("teachersAndSubjects"));
        horizontalLayout = new QHBoxLayout(teachersAndSubjects);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        searchSubjectDataButton = new QPushButton(teachersAndSubjects);
        searchSubjectDataButton->setObjectName(QString::fromUtf8("searchSubjectDataButton"));

        horizontalLayout_6->addWidget(searchSubjectDataButton);

        searchInput = new QLineEdit(teachersAndSubjects);
        searchInput->setObjectName(QString::fromUtf8("searchInput"));

        horizontalLayout_6->addWidget(searchInput);

        sortSubjectDataButton = new QPushButton(teachersAndSubjects);
        sortSubjectDataButton->setObjectName(QString::fromUtf8("sortSubjectDataButton"));

        horizontalLayout_6->addWidget(sortSubjectDataButton);


        verticalLayout_2->addLayout(horizontalLayout_6);

        scrollArea = new QScrollArea(teachersAndSubjects);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 552, 180));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        subjectsData = new QTableWidget(scrollAreaWidgetContents_2);
        subjectsData->setObjectName(QString::fromUtf8("subjectsData"));
        subjectsData->setGridStyle(Qt::PenStyle::SolidLine);
        subjectsData->setColumnCount(0);
        subjectsData->horizontalHeader()->setHighlightSections(false);
        subjectsData->verticalHeader()->setHighlightSections(false);

        verticalLayout_5->addWidget(subjectsData);

        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_2->addWidget(scrollArea);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        addSubjectButton = new QPushButton(teachersAndSubjects);
        addSubjectButton->setObjectName(QString::fromUtf8("addSubjectButton"));

        horizontalLayout_7->addWidget(addSubjectButton);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        searchTeacherButton = new QPushButton(teachersAndSubjects);
        searchTeacherButton->setObjectName(QString::fromUtf8("searchTeacherButton"));

        horizontalLayout_5->addWidget(searchTeacherButton);

        searchTeacherLine = new QLineEdit(teachersAndSubjects);
        searchTeacherLine->setObjectName(QString::fromUtf8("searchTeacherLine"));

        horizontalLayout_5->addWidget(searchTeacherLine);

        sortTeacherButton = new QPushButton(teachersAndSubjects);
        sortTeacherButton->setObjectName(QString::fromUtf8("sortTeacherButton"));

        horizontalLayout_5->addWidget(sortTeacherButton);


        verticalLayout->addLayout(horizontalLayout_5);

        returnAllSubjects = new QPushButton(teachersAndSubjects);
        returnAllSubjects->setObjectName(QString::fromUtf8("returnAllSubjects"));

        verticalLayout->addWidget(returnAllSubjects);

        scrollArea_2 = new QScrollArea(teachersAndSubjects);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 648, 140));
        verticalLayout_6 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        teachersData = new QTableWidget(scrollAreaWidgetContents_3);
        teachersData->setObjectName(QString::fromUtf8("teachersData"));
        teachersData->horizontalHeader()->setHighlightSections(false);
        teachersData->verticalHeader()->setHighlightSections(false);

        verticalLayout_6->addWidget(teachersData);

        scrollArea_2->setWidget(scrollAreaWidgetContents_3);

        verticalLayout->addWidget(scrollArea_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        addTeacherButton = new QPushButton(teachersAndSubjects);
        addTeacherButton->setObjectName(QString::fromUtf8("addTeacherButton"));

        horizontalLayout_4->addWidget(addTeacherButton);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(teachersAndSubjects);

        expandAndCollapse = new QPushButton(centralwidget);
        expandAndCollapse->setObjectName(QString::fromUtf8("expandAndCollapse"));

        verticalLayout_3->addWidget(expandAndCollapse);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groups = new QTableWidget(widget);
        groups->setObjectName(QString::fromUtf8("groups"));
        groups->horizontalHeader()->setVisible(false);
        groups->horizontalHeader()->setHighlightSections(true);
        groups->verticalHeader()->setVisible(false);
        groups->verticalHeader()->setHighlightSections(true);

        horizontalLayout_3->addWidget(groups);

        groupMenu = new QWidget(widget);
        groupMenu->setObjectName(QString::fromUtf8("groupMenu"));
        gridLayout = new QGridLayout(groupMenu);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        searchGroup = new QPushButton(groupMenu);
        searchGroup->setObjectName(QString::fromUtf8("searchGroup"));

        gridLayout->addWidget(searchGroup, 1, 0, 1, 1);

        searchGroupLine = new QLineEdit(groupMenu);
        searchGroupLine->setObjectName(QString::fromUtf8("searchGroupLine"));

        gridLayout->addWidget(searchGroupLine, 1, 1, 1, 1);

        addGroup = new QPushButton(groupMenu);
        addGroup->setObjectName(QString::fromUtf8("addGroup"));

        gridLayout->addWidget(addGroup, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(groupMenu);


        verticalLayout_3->addWidget(widget);

        saveData = new QPushButton(centralwidget);
        saveData->setObjectName(QString::fromUtf8("saveData"));

        verticalLayout_3->addWidget(saveData);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1261, 29));
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
        searchSubjectDataButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\277\321\200\320\265\320\264\320\274\320\265\321\202", nullptr));
        sortSubjectDataButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260 (\320\277\321\200\320\265\320\264\320\274\320\265\321\202\321\213): \320\222\320\253\320\232\320\233", nullptr));
        addSubjectButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\321\200\320\265\320\264\320\274\320\265\321\202", nullptr));
        searchTeacherButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        sortTeacherButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260 (\320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\320\270): \320\222\320\253\320\232\320\233", nullptr));
        returnAllSubjects->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\320\265 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\321\213", nullptr));
        addTeacherButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        expandAndCollapse->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        searchGroup->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\263\321\200\321\203\320\277\320\277\321\203", nullptr));
        addGroup->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\263\321\200\321\203\320\277\320\277\321\203", nullptr));
        saveData->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
