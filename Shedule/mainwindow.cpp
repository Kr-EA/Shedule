#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "alertWindow.h"
#include "tdialog.h"
#include"confirmaction.h"
#include"UIDgenerator.h"
#include "setsubjects.h"
#include<iostream>
#include<vector>
#include<QDebug>
#include<QFile>
#include<QFileInfo>
#include<QRadioButton>
#include<QTextStream>
#include <QKeyEvent>
#include"groupcreator.h"

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
    groupDataSetup();
    ui->searchInput->setVisible(false);
    ui->searchTeacherLine->setVisible(false);
    ui->returnAllSubjects->setVisible(false);
    ui->searchGroupLine->setVisible(false);
    this->setWindowTitle(QString::fromStdString("Шедуля"));

    connect(this, &MainWindow::itemChanged, this, &MainWindow::checkItem);
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
    subCreator.uids = this->uids;
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
    this->uids.push_back(subCreator.log.mid(0, 6));
}


void MainWindow::on_addTeacherButton_clicked()
{
    ui->teachersData->setSortingEnabled(false);
    ui->sortTeacherButton->setText("Сортировка (преподаватели): ВЫКЛ");
    tDialog* teacherCreator = new tDialog();
    teacherCreator->uids = this->uids;
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
    this->uids.push_back(QString::fromStdString(teacherCreator->log).mid(0, 6));
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
            for (int k = 1; k < temp.size(); k++){
                if (k == 4){
                    QTableWidgetItem *tableItem = new QTableWidgetItem();
                    tableItem->setData(Qt::EditRole, temp[k].toInt());
                    ui->teachersData->setItem(i, k-1, tableItem);
                }
                else if (k == 5){
                    QRadioButton* showSubjects = new QRadioButton();
                    ui->teachersData->setCellWidget(i, k-1, showSubjects);
                    connect(showSubjects, &QRadioButton::clicked, this, [&, showSubjects, temp](){
                        if (showSubjects->isChecked()){
                            ui->subjectsData->setSortingEnabled(false);
                            ui->sortSubjectDataButton->setText("Сортировка (предметы): ВЫКЛ");
                            subjectDataSetup();
                            checkedRow = i;
                            ui->returnAllSubjects->setVisible(true);
                            toggleAllRows(false, ui->subjectsData, subjectData);
                            for (int z = 5; z < temp.size()-2; z+=4){
                                QString tempLine = temp[z] + " " + temp[z+1] + " " + temp[z+2] + " " + temp[z+3];
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
                else if (k == 6){
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
                    ui->teachersData->setCellWidget(i, k-1, deleter);
                }
                else if (k == 7){
                    QPushButton* addButton = new QPushButton("Добавить предмет");
                    QFont temp = addButton->font();
                    temp.setPointSize(10);
                    addButton->setFont(temp);
                    connect(addButton, &QPushButton::clicked, this, [&, addButton, i, size](){
                        teacherDataSetup();
                        toggleAllRows(true, ui->subjectsData, subjectData);
                        ui->returnAllSubjects->setVisible(false);
                        if (size < 26){
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
                            alertWindow alert;
                            alert.setAlertInfo(QString::fromStdString("Число предметов у преподавателя уже 5. \n Пожалейте человека!"));
                            alert.setModal(true);
                            alert.exec();
                            alert.setVisible(true);
                        }
                    });
                    ui->teachersData->setCellWidget(i, k-1, addButton);
                }
                else if (k < 5) {
                    std::replace(temp[k].begin(), temp[k].end(), '_', ' ');
                    QTableWidgetItem *tableItem = new QTableWidgetItem(temp[k]);
                    std::replace(temp[k].begin(), temp[k].end(), ' ', '_');
                    ui->teachersData->setItem(i, k-1, tableItem);
                }
            }
        }
    }
    ui->teachersData->blockSignals(false);
}

void MainWindow::groupDataSetup(){
    ui->groups->setColumnCount(groups.size());
    ui->groups->setRowCount(1);
    ui->groups->setRowHeight(0, ui->groups->height());
    int counter = 0;

    for (QTableWidget* group : groups){
        ui->groups->setColumnWidth(counter, 950);
        ui->groups->setCellWidget(0, counter, group);
        counter++;
    }
}
void MainWindow::saveGroupData(){
    groupData.clear();
    for (QTableWidget* group : groups){
        QString data;
        data = generateUID(uids) + "@";
        data += group->item(0, 0)->text() + "@{";
        std::replace(data.begin(), data.end(), ' ', '_');
        QList<QTableWidget*> temp = group->findChildren<QTableWidget*>();
        for (int i = 0; i < 6; i++) {
            QString temp1;
            QString temp2;
            QString tempSubjectName;
            QString tempTeacherName;
            data += "[";
            for (int j = 1; j < 5; j++) {
                QString tempData;
                tempSubjectName = temp[i]->cellWidget(j, 0)->layout()->itemAt(0)->widget()->property("currentText").toString();
                tempTeacherName = temp[i]->cellWidget(j, 0)->layout()->itemAt(1)->widget()->property("currentText").toString();

                temp1 = tempSubjectName + ":" + tempTeacherName;

                tempSubjectName = temp[i]->cellWidget(j, 1)->layout()->itemAt(0)->widget()->property("currentText").toString();
                tempTeacherName = temp[i]->cellWidget(j, 1)->layout()->itemAt(1)->widget()->property("currentText").toString();

                temp2 = tempSubjectName + ":" + tempTeacherName;

                if (temp1 == temp2){
                    if (j == 4){
                        tempData = temp1 + "|~)";
                    }
                    else {
                        tempData = temp1 + "|~),";
                    }
                }
                else {
                    if (j == 4){
                        tempData = temp1 + "|" + temp2 + ")";
                    }
                    else {
                        tempData = temp1 + "|" + temp2 + "),";
                    }
                }
                data += "(" + tempData;
            }
            if (i != 5){
                data += "];";
            }
            else {
                data += "]";
            }
        }
        data += "}";
        groupData.push_back(data);
    }
    saveData("Groups.txt", groupData);
}

void MainWindow::subjectDataSetup(){

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
            for (int k = 1; k < 5; k++){
                if (k == 3){
                    QTableWidgetItem *tableItem = new QTableWidgetItem();
                    tableItem->setData(Qt::EditRole, temp[k].toInt());
                    ui->subjectsData->setItem(i, k-1, tableItem);
                }
                else if (k == 4){
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
                    ui->subjectsData->setCellWidget(i, k-1, deleter);
                }
                else{
                    std::replace(temp[k].begin(), temp[k].end(), '_', ' ');
                    QTableWidgetItem *tableItem = new QTableWidgetItem(temp[k]);
                    ui->subjectsData->setItem(i, k-1, tableItem);
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
        QString temp = QString::fromStdString(subjectData[i].mid(0, 6).toStdString() + " " + name + " " +  ui->subjectsData->item(i, 1)->text().toStdString() + " " + ui->subjectsData->item(i,  2)->text().toStdString());
        subjectData[i] = temp;
    }
    saveData(QString("Subjects.txt"), subjectData);

    for (int i = 0; i < teacherData.size(); i++){
        QStringList line = teacherData[i].split(u' ', Qt::SkipEmptyParts);
        string uid = line[0].toStdString();
        string name = ui->teachersData->item(i, 0)->text().toStdString();
        std::replace(name.begin(), name.end(), ' ', '_');
        string lastname = ui->teachersData->item(i, 1)->text().toStdString();
        std::replace(lastname.begin(), lastname.end(), ' ', '_');
        string surname = ui->teachersData->item(i, 2)->text().toStdString();
        std::replace(surname.begin(), surname.end(), ' ', '_');
        string rating = ui->teachersData->item(i, 3)->text().toStdString();
        string temp = uid + " " + name + " " + lastname + " " + surname + " " + rating + " ";
        for (int j = 5; j < line.size()-3; j+=4){
            temp += line[j].toStdString() + " " + line[j+1].toStdString() + " " + line[j+2].toStdString() + " " + line[j+3].toStdString();
            if (j != line.size()-4){
                temp += " ";
            }
        }
        teacherData[i] = QString::fromStdString(temp);
        saveData("Teachers.txt", teacherData);
    }

    saveData(QString("Teachers.txt"), teacherData);
    saveGroupData();
}

void MainWindow::checkItem(itemCoordinates coords, QString senderName){
    ui->searchInput->clear();
    toggleAllRows(true, ui->subjectsData, subjectData);

    if (coords.y == 1){
        if (ui->subjectsData->item(coords.x, coords.y)->text() != "Лекция" && ui->subjectsData->item(coords.x, coords.y)->text() != "Практика"){
            alertWindow alert;
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
            alertWindow alert;
            alert.setAlertInfo(QString::fromStdString("Некорректный ввод \n Ожидалось число от 0 до 172"));
            alert.setModal(true);
            alert.exec();
            alert.setVisible(true);
            QStringList temp = subjectData[coords.x].split(u' ');
            ui->subjectsData->item(coords.x, coords.y)->setText(temp[3]);
        }
    }

    if (coords.y == 3){
        if (ui->teachersData->item(coords.x, coords.y)->text().toInt() <= 0 || ui->teachersData->item(coords.x, coords.y)->text().toInt() > 100){
            alertWindow alert;
            alert.setAlertInfo(QString::fromStdString("Некорректный ввод \n Ожидалось число от 0 до 100"));
            alert.setModal(true);
            alert.exec();
            alert.setVisible(true);
            QStringList temp = teacherData[coords.x].split(u' ');
            ui->teachersData->item(coords.x, coords.y)->setText(temp[4]);
        }
    }
    if (senderName == "Subject"){
        QStringList subject = subjectData[coords.x].split(u' ', Qt::SkipEmptyParts);
        QString oldSubject = subjectData[coords.x];
        QString temp = subjectData[coords.x].replace(subject[coords.y+1], ui->subjectsData->item(coords.x, coords.y)->text());
        for (int i = 0; i < teacherData.size(); i++){
            teacherData[i] = teacherData[i].replace(oldSubject, temp);
        }
        teacherDataSetup();
    }
}

void MainWindow::on_subjectsData_cellChanged(int row, int column)
{
    itemCoordinates coords;
    coords.x = row;
    coords.y = column;
    emit itemChanged(coords, "Subject");
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
    emit itemChanged(coords, "Teacher");
}


void MainWindow::on_expandAndCollapse_clicked()
{
    if (ui->expandAndCollapse->text() == "Развернуть")
    {
        ui->expandAndCollapse->setText("Свернуть");
        ui->teachersAndSubjects->setVisible(false);
        ui->groupMenu->setVisible(false);
        ui->saveData->setVisible(false);
        ui->groups->setRowHeight(0, ui->groups->height()*3.14);
    }
    else {
        ui->expandAndCollapse->setText("Развернуть");
        ui->teachersAndSubjects->setVisible(true);
        ui->groupMenu->setVisible(true);
        ui->saveData->setVisible(true);
        ui->groups->setRowHeight(0, ui->groups->height());
    }   
}


void MainWindow::on_searchGroup_clicked()
{
    if (ui->searchGroupLine->isVisible()){
        ui->searchGroupLine->clear();
        ui->searchGroupLine->setVisible(false);
        for (int i = 0; i < groups.size(); i++){
            ui->groups->showColumn(i);
        }
    }
    else{
        ui->searchGroupLine->setVisible(true);
    }
}


void MainWindow::on_addGroup_clicked()
{
    groupCreator* adder = new groupCreator();
    adder->subjects = subjectData;
    adder->teachers = teacherData;
    adder->setup();
    adder->setModal(true);
    adder->setVisible(true);
    //adder->showFullScreen();
    adder->exec();
    if (adder->isWindowWorkFinishedCorrectly){
        groups.push_back(adder->data);
        groupDataSetup();
    }
}


void MainWindow::on_searchGroupLine_textEdited(const QString &arg1)
{
    if (arg1.size() != 0){
        for (int i = 0; i < groups.size(); i++){
            for (int j = 0; j < groups[i]->item(0, 0)->text().size()-arg1.length()+1; j++){
                if (groups[i]->item(0,0)->text().mid(j, arg1.size()) == arg1){
                    ui->groups->showColumn(i);
                    break;
                }
                else {
                    ui->groups->hideColumn(i);
                }
            }
        }
    }
    else {
        for (int i = 0; i < groups.size(); i++){
            ui->groups->showColumn(i);
        }
    }
}

