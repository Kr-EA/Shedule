#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "nonono.h"
#include "tdialog.h"
#include"confirmaction.h"
#include "setsubjects.h"
#include<iostream>
#include<vector>
#include<QDebug>
#include<QFile>
#include<QFileInfo>
#include<QRadioButton>
#include<QTextStream>
#include <QKeyEvent>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadData(QString("Subjects.txt"), subjectData);
    loadData(QString("Teachers.txt"), teacherData);
    if (subjectData.size() == 0){
        ui->addTeacherButton->setEnabled(false);
    }
    subjectDataSetup();
    teacherDataSetup();
    ui->searchInput->setVisible(false);
    ui->searchTeacherLine->setVisible(false);
    ui->returnAllSubjects->setVisible(false);
    this->setWindowTitle(QString::fromStdString("Шедуля"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addSubjectButton_clicked()
{
    ui->subjectsData->setSortingEnabled(false);
    ui->sortSubjectDataButton->setText("Сортировка (предметы): ВЫКЛ");
    Dialog subCreator;
    subCreator.savedData = &subjectData;
    subCreator.setModal(true);
    subCreator.exec();
    if (subCreator.isWindowCalled){
        subjectData.push_back(subCreator.log);
        ui->addTeacherButton->setEnabled(true);
        subCreator.isWindowCalled = false;
    }
    saveData(QString("Subjects.txt"), subjectData);
    subjectDataSetup();
}


void MainWindow::on_addTeacherButton_clicked()
{
    ui->teachersData->setSortingEnabled(false);
    ui->sortTeacherButton->setText("Сортировка (преподаватели): ВЫКЛ");
    tDialog* teacherCreator = new tDialog();
    teacherCreator->dialogChild = new setSubjects();
    connect(teacherCreator->dialogChild, &setSubjects::subjectsListReadySignal, teacherCreator, &tDialog::subjectsListSlot);
    teacherCreator->setModal(true);
    teacherCreator->load(subjectData);
    teacherCreator->exec();
    if (teacherCreator->isWindowCalled){
        teacherData.push_back(QString::fromStdString(teacherCreator->log));
        teacherCreator->isWindowCalled = false;
    }
    teacherCreator->dialogChild->setVisible(false);
    saveData(QString("Teachers.txt"), teacherData);
    teacherDataSetup();
}

void MainWindow::saveData(const QString& path, QVector<QString>& data){
    QFile temp (path);
    temp.resize(0);
    for (QString str : data){
        if (temp.open(QIODevice::Append | QIODevice::Text)){
            QTextStream out(&temp);
            out << str + "\n";
        }
        temp.close();
    }
}

void MainWindow::loadData(const QString& path, QVector<QString>& data){
    QFile temp (path);
    if (temp.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&temp);
        while (!in.atEnd()) {
            QString line = in.readLine();
            data.push_back(line);
        }
    }
    temp.close();
}

void MainWindow::teacherDataSetup(){
    ui->teachersData->setAlternatingRowColors(true);
    connect(this, &MainWindow::itemChanged, this, &MainWindow::checkItem);
    ui->teachersData->blockSignals(true);
    ui->teachersData->setColumnCount(7);
    ui->teachersData->setRowCount(teacherData.size());
    ui->teachersData->verticalHeader()->setVisible(false);
    ui->teachersData->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList header = {"Имя", "Фамилия",  "Отчество", "Рейтинг", "Предметы", "", "", ""};
    ui->teachersData->setHorizontalHeaderLabels(header);
    if (teacherData.size() != 0){
        for (int i = 0; i < teacherData.size(); i++){
            QString currentLine = teacherData[i];
            QStringList temp = currentLine.split(u' ', Qt::SkipEmptyParts);
            int size = temp.size();
            for (int k = 0; k < temp.size(); k++){
                if (k == 3){
                    QTableWidgetItem *tableItem = new QTableWidgetItem();
                    tableItem->setData(Qt::EditRole, temp[k].toInt());
                    ui->teachersData->setItem(i, k, tableItem);
                }
                else if (k == 4){
                    QRadioButton* showSubjects = new QRadioButton();
                    ui->teachersData->setCellWidget(i, k, showSubjects);
                    connect(showSubjects, &QRadioButton::clicked, this, [&, showSubjects, temp](){
                        if (showSubjects->isChecked()){
                            ui->subjectsData->setSortingEnabled(false);
                            ui->sortSubjectDataButton->setText("Сортировка (предметы): ВЫКЛ");
                            subjectDataSetup();
                            checkedRow = i;
                            ui->returnAllSubjects->setVisible(true);
                            toggleAllRows(false, ui->subjectsData, subjectData);
                            for (int z = 4; z < temp.size()-2; z+=3){
                                QString tempLine = temp[z] + " " + temp[z+1] + " " + temp[z+2];
                                tempLine.replace("\n", "");
                                for (int q = 0; q < subjectData.size(); q++){
                                    if (subjectData[q] == tempLine){
                                        ui->subjectsData->showRow(q);
                                    }
                                }
                            }
                        }
                    });
                }
                else if (k == 5){
                    QPushButton* deleter = new QPushButton("Удалить");
                    connect(deleter, &QPushButton::clicked, this, [&, deleter, i](){
                        confirmAction allowAction;
                        allowAction.setModal(true);
                        allowAction.setVisible(true);
                        allowAction.setCallback([&, deleter, i](){
                            toggleAllRows(true, ui->subjectsData, subjectData);
                            ui->teachersData->removeRow(i);
                            ui->returnAllSubjects->setVisible(false);
                            teacherData.remove(i);
                            teacherDataSetup();
                        });
                        allowAction.exec();
                    });
                    ui->teachersData->setCellWidget(i, k, deleter);
                }
                else if (k == 6){
                    QPushButton* addButton = new QPushButton("Добавить предмет");
                    connect(addButton, &QPushButton::clicked, this, [&, addButton, i, size](){
                        teacherDataSetup();
                        toggleAllRows(true, ui->subjectsData, subjectData);
                        ui->returnAllSubjects->setVisible(false);
                        if (size < 19){
                            setSubjects* adder = new setSubjects();
                            adder->setAmount(1);
                            QVector<QString> choices;
                            for (QString data : subjectData){
                                if (teacherData[i].indexOf(data) == -1){
                                    choices.push_back(data);
                                }
                            }
                            adder->setup(choices);
                            adder->setModal(true);
                            adder->setVisible(true);
                            adder->exec();
                            teacherData[i] += " " + adder->subjectToAdd;
                            teacherDataSetup();
                        }
                        else {
                            NoNoNo alert;
                            alert.setAlertInfo(QString::fromStdString("Число предметов у преподавателя уже 5. \n Пожалейте человека!"));
                            alert.setModal(true);
                            alert.exec();
                            alert.setVisible(true);
                        }
                    });
                    ui->teachersData->setCellWidget(i, k, addButton);
                }
                else if (k < 4) {
                    std::replace(temp[k].begin(), temp[k].end(), '_', ' ');
                    QTableWidgetItem *tableItem = new QTableWidgetItem(temp[k]);
                    std::replace(temp[k].begin(), temp[k].end(), ' ', '_');
                    ui->teachersData->setItem(i, k, tableItem);
                }
            }
        }
    }
    ui->teachersData->blockSignals(false);
}

void MainWindow::subjectDataSetup(){
    connect(this, &MainWindow::itemChanged, this, &MainWindow::checkItem);
    ui->subjectsData->setAlternatingRowColors(true);
    ui->subjectsData->blockSignals(true);
    ui->subjectsData->setColumnCount(4);
    ui->subjectsData->setRowCount(subjectData.size());
    ui->subjectsData->verticalHeader()->setVisible(false);
    ui->subjectsData->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QStringList header = {"Название предмета", "Тип предмета",  "Количество часов", ""};
    ui->subjectsData->setHorizontalHeaderLabels(header);
    if (subjectData.size() != 0){
        for (int i = 0; i < subjectData.size(); i++){
            QString currentLine = subjectData[i];
            QStringList temp = currentLine.split(u' ', Qt::SkipEmptyParts);
            for (int k = 0; k < 4; k++){
                if (k == 2){
                    QTableWidgetItem *tableItem = new QTableWidgetItem();
                    tableItem->setData(Qt::EditRole, temp[k].toInt());
                    ui->subjectsData->setItem(i, k, tableItem);
                }
                else if (k == 3){
                    QPushButton* deleter = new QPushButton("Удалить");
                    connect(deleter, &QPushButton::clicked, this, [&, deleter, i](){
                        confirmAction allowAction;
                        allowAction.setModal(true);
                        allowAction.setVisible(true);
                        allowAction.setCallback([&, deleter, i](){
                            ui->subjectsData->removeRow(i);
                            int index{};
                            for (QString teacherLine : teacherData){
                                QStringList tempLine = teacherLine.split(u' ', Qt::SkipEmptyParts);
                                if (tempLine.length() == 7){
                                    if (tempLine[4] + " " + tempLine[5] + " " + tempLine[6] == subjectData[i]){
                                        confirmAction allowAction2;
                                        allowAction2.setModal(true);
                                        allowAction2.setConfirmLabel(QString("У преподавателя \n%1 %2 %3 \nв списке предметов нет ни одного предмета. \nУдалить его из списка? ").arg(tempLine[0], tempLine[1], tempLine[2]));
                                        allowAction2.setVisible(true);
                                        allowAction2.setCallback([&](){
                                            qDebug() << teacherData[index];
                                            teacherData.remove(index);
                                            index--;
                                        });
                                        allowAction2.exec();
                                    }
                                }
                                index++;
                            }
                            subjectData.remove(i);
                            teacherDataSetup();
                            subjectDataSetup();
                            ui->searchInput->clear();
                            toggleAllRows(true, ui->subjectsData, subjectData);
                            if (subjectData.size() == 0){
                                ui->addTeacherButton->setEnabled(false);
                            }
                        });
                        allowAction.exec();
                    });
                    ui->subjectsData->setCellWidget(i, k, deleter);
                }
                else{
                    std::replace(temp[k].begin(), temp[k].end(), '_', ' ');
                    QTableWidgetItem *tableItem = new QTableWidgetItem(temp[k]);
                    ui->subjectsData->setItem(i, k, tableItem);
                }
            }
        }
    }
    ui->subjectsData->blockSignals(false);
}

void MainWindow::on_sortSubjectDataButton_clicked()
{
    if (ui->subjectsData->isSortingEnabled()){
        ui->sortSubjectDataButton->setText("Сортировка (предметы): ВЫКЛ");
        ui->subjectsData->setSortingEnabled(false);
        subjectDataSetup();
    }
    else {
        ui->sortSubjectDataButton->setText("Сортировка (предметы): ВКЛ");
        ui->subjectsData->setSortingEnabled(true);
    }
}

void MainWindow::on_saveData_clicked()
{
    for (int i = 0; i < subjectData.size(); i++){
        string name = ui->subjectsData->item(i, 0)->text().toStdString();
        std::replace(name.begin(), name.end(), ' ', '_');
        QString temp = QString::fromStdString(name + " " +  ui->subjectsData->item(i, 1)->text().toStdString() + " " + ui->subjectsData->item(i,  2)->text().toStdString());
        subjectData[i] = temp;
    }
    saveData(QString("Subjects.txt"), subjectData);

    saveData(QString("Teachers.txt"), teacherData);
}

void MainWindow::checkItem(itemCoordinates coords){

    ui->searchInput->clear();
    toggleAllRows(true, ui->subjectsData, subjectData);

    if (coords.y == 1){
        if (ui->subjectsData->item(coords.x, coords.y)->text() != "Лекция" && ui->subjectsData->item(coords.x, coords.y)->text() != "Практика"){
            NoNoNo alert;
            alert.setAlertInfo(QString::fromStdString("Некорректный ввод \n Ожидался ввод <<Лекция>> или <<Практика>>"));
            alert.setModal(true);
            alert.exec();
            alert.setVisible(true);
            QStringList temp = subjectData[coords.x].split(u' ');
            ui->subjectsData->item(coords.x, coords.y)->setText(temp[1]);
        }
    }

    if (coords.y == 2){
        if (ui->subjectsData->item(coords.x, coords.y)->text().toInt() <= 0 || ui->subjectsData->item(coords.x, coords.y)->text().toInt() > 172){
            NoNoNo alert;
            alert.setAlertInfo(QString::fromStdString("Некорректный ввод \n Ожидалось число от 0 до 172"));
            alert.setModal(true);
            alert.exec();
            alert.setVisible(true);
            QStringList temp = subjectData[coords.x].split(u' ');
            ui->subjectsData->item(coords.x, coords.y)->setText(temp[2]);
        }
    }

    if (coords.y == 3){
        if (ui->teachersData->item(coords.x, coords.y)->text().toInt() <= 0 || ui->teachersData->item(coords.x, coords.y)->text().toInt() > 100){
            NoNoNo alert;
            alert.setAlertInfo(QString::fromStdString("Некорректный ввод \n Ожидалось число от 0 до 100"));
            alert.setModal(true);
            alert.exec();
            alert.setVisible(true);
            QStringList temp = teacherData[coords.x].split(u' ');
            ui->teachersData->item(coords.x, coords.y)->setText(temp[3]);
        }
    }
}

void MainWindow::on_subjectsData_cellChanged(int row, int column)
{
    itemCoordinates coords;
    coords.x = row;
    coords.y = column;
    emit itemChanged(coords);
}

void MainWindow::on_searchSubjectDataButton_clicked()
{
    if(ui->searchInput->isVisible()){
        ui->searchInput->setVisible(false);
        ui->searchInput->clear();
        toggleAllRows(true, ui->subjectsData, subjectData);
    }
    else{
        ui->searchInput->setVisible(true);
        toggleAllRows(true, ui->subjectsData, subjectData);
    }
}

void MainWindow::toggleAllRows(bool flag, QTableWidget* data, QVector<QString> &dataArray) {
    for (int i = 0; i < dataArray.size(); i++){
        if (flag) {
            data->showRow(i);
        }
        else {
            data->hideRow(i);
        }
    }
}

void MainWindow::on_searchInput_textEdited(const QString &input)
{
    if (input.length() > 0){
        QString inputData = input.toLower();
        for (int i = 0; i < subjectData.size(); i++){
            if (input.length() <= ui->subjectsData->item(i, 0)->text().length()){
                bool isMatch = !ui->subjectsData->item(i, 1)->text().mid(0, inputData.length()).toLower().compare(inputData);

                if (isMatch) {
                    ui->subjectsData->showRow(i);
                    continue;
                }
                else {
                    bool isCorrect = false;

                    if (input.length() > subjectData[i].length()) {
                        isCorrect = false;
                    }
                    else {
                        for (int j = 0; j < subjectData[i].length() - input.length() + 1; j++) {
                            if (subjectData[i].mid(j, input.length()).toLower() == inputData) {
                                isCorrect = true;
                                break;
                            }
                        }
                    }

                    if (isCorrect) {
                        ui->subjectsData->showRow(i);
                    }
                    else {
                        ui->subjectsData->hideRow(i);
                    }
                }
            }
            else {
                ui->subjectsData->hideRow(i);
            }
        }
    }
    else {
        toggleAllRows(true, ui->subjectsData, subjectData);
    }
}


void MainWindow::on_returnAllSubjects_clicked()
{
    teacherDataSetup();
    toggleAllRows(true, ui->subjectsData, subjectData);
    ui->returnAllSubjects->setVisible(false);
}

void MainWindow::on_sortTeacherButton_clicked()
{
    if (ui->teachersData->isSortingEnabled()){
        ui->sortTeacherButton->setText("Сортировка (преподаватели): ВЫКЛ");
        ui->teachersData->setSortingEnabled(false);
        teacherDataSetup();
    }
    else {
        ui->sortTeacherButton->setText("Сортировка (преподаватели): ВКЛ");
        ui->teachersData->setSortingEnabled(true);
    }
}


void MainWindow::on_searchTeacherButton_clicked()
{
    if(ui->searchTeacherLine->isVisible()){
        ui->searchTeacherLine->setVisible(false);
        ui->searchTeacherLine->clear();
        toggleAllRows(true, ui->teachersData, teacherData);
    }
    else{
        ui->searchTeacherLine->setVisible(true);
        toggleAllRows(true, ui->teachersData, teacherData);
    }
}

void MainWindow::on_searchTeacherLine_textChanged(const QString &arg1)
{
    if (arg1.length() > 0)
    {
        QString inputData = arg1.toLower();
        for (int i = 0; i < teacherData.size(); i++){
            QStringList temp = teacherData[i].split(u' ', Qt::SkipEmptyParts);
            int len = temp[0].length() + temp[1].length() + temp[2].length() + temp[3].length();
            for (int j = 0; j < len - arg1.length() + 1; j++) {
                if (teacherData[i].mid(j, arg1.length()).toLower() == inputData) {
                    ui->teachersData->showRow(i);
                    break;
                }
                else{
                    ui->teachersData->hideRow(i);
                }
            }
        }
    }
    else
    {
        toggleAllRows(true, ui->teachersData, teacherData);
    }
}


void MainWindow::on_teachersData_cellChanged(int row, int column)
{
    itemCoordinates coords;
    coords.x = row;
    coords.y = column;
    emit itemChanged(coords);
}

