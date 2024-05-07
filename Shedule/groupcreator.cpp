#include "groupcreator.h"
#include "ui_groupcreator.h"
#include<QTableWidgetItem>
#include<QPushButton>
#include<QComboBox>
#include"alertWindow.h"
#include <QDebug>
#include<string>

using namespace std;

groupCreator::groupCreator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::groupCreator)
{
    ui->setupUi(this);
    days = {"П\nО\nН\nЕ\nД\nЕ\nЛ\nЬ\nН\nИ\nК", "В\nТ\nО\nР\nН\nИ\nК", "С\nР\nЕ\nД\nА", "Ч\nЕ\nТ\nВ\nЕ\nР\nГ", "П\nЯ\nТ\nН\nИ\nЦ\nА", "С\nУ\nБ\nБ\nО\nТ\nА"};
}

groupCreator::~groupCreator()
{
    delete ui;
}

QComboBox* groupCreator::setupTeacherComboBox(QString subject, QVector<QString> teachers){
    QComboBox* dropDownTeachers = new QComboBox();
    QVector<QString> correctTeachers{};
    for (QString teacher : teachers){
        if (teacher.toStdString().find(subject.toStdString()) != 18446744073709551615){
            correctTeachers.push_back(teacher);
        }
    }
    QStringList teacherVars = QStringList::fromVector(correctTeachers);
    dropDownTeachers->addItems(teacherVars);
    return dropDownTeachers;
}

void groupCreator::setup() {
    ui->group->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->group->setColumnWidth(1, 800);
    ui->group->verticalHeader()->setVisible(false);
    ui->group->horizontalHeader()->setVisible(false);
    QTableWidgetItem* item = new QTableWidgetItem;
    for (int i = 1; i < days.size()+1; i++){
        item = new QTableWidgetItem;
        item->setText(days[i-1]);
        ui->group->setItem(i, 0, item);
    }

    ui->group->setSpan(0, 0, 1, 4);
    for (int i = 1; i < 7; i++){
        ui->group->setRowHeight(i, (this->height()+1500)/6);
    }


    this->setWindowTitle(QString::fromStdString("Cоздание группы"));

    for (int z = 1; z < 7; z++){
        QTableWidget* day = new QTableWidget;
        day->setColumnCount(3);
        day->setColumnWidth(0, 300);
        day->setColumnWidth(1, 300);
        day->setColumnWidth(2, 150);
        day->setRowCount(5);
        for (int i = 0; i < 5; i++){
            day->setRowHeight(i, (this->height()+1490)/30);
        }
        item = new QTableWidgetItem;
        item->setText("Числитель");
        day->setItem(0, 0, item);
        item = new QTableWidgetItem;
        item->setText("Знаменатель");
        day->setItem(0, 1, item);
        day->horizontalHeader()->setVisible(false);
        item = new QTableWidgetItem;
        for (int i = 1; i < 5; i++){
            for (int j = 0; j < 2; j++){
                QGridLayout* pairSelection = new QGridLayout;

                QComboBox* dropDownSubjects = new QComboBox();

                QVector<QString> vars = subjects;
                vars.push_back(QString::fromStdString("-"));
                QStringList subjectVariants = QStringList::fromVector(vars);
                dropDownSubjects->addItems(subjectVariants);

                dropDownSubjects->setProperty("currentText", "-");
                QComboBox* dropDownTeachers = new QComboBox;
                dropDownTeachers = setupTeacherComboBox(dropDownSubjects->property("currentText").toString(), teachers);
                pairSelection->addWidget(dropDownSubjects, 0, 0);
                pairSelection->addWidget(dropDownTeachers, 1, 0);
                QWidget* tableItem = new QWidget();
                tableItem->setLayout(pairSelection);

                day->setCellWidget(i, j, tableItem);

                connect(dropDownSubjects, &QComboBox::currentTextChanged, this, [this, dropDownSubjects, pairSelection, i, j, day](){
                    QGridLayout* temp = new QGridLayout;
                    QComboBox*  newDropDownTeachers = new QComboBox();
                    newDropDownTeachers = setupTeacherComboBox(dropDownSubjects->property("currentText").toString(), teachers);

                    temp->addWidget(dropDownSubjects, 0,  0);
                    temp->addWidget(newDropDownTeachers, 1, 0);

                    QWidget* tableItem = new QWidget();
                    tableItem->setLayout(temp);
                    day->setCellWidget(i, j, tableItem);
                });
            }
            QPushButton* mergeAndSplit = new QPushButton("Объединить");
            connect(mergeAndSplit, &QPushButton::clicked, this, [&, mergeAndSplit, i, day](){
                if(mergeAndSplit->text() == "Объединить"){
                    mergeAndSplit->setText("Разъеденить");
                    day->blockSignals(true);
                    day->cellWidget(i, 1)->setVisible(false);
                    day->setSpan(i, 0, 1, 2);
                    day->cellWidget(i, 0)->setFixedSize(day->cellWidget(i, 0)->width()*2, day->cellWidget(i, 0)->height());
                    day->blockSignals(false);
                }
                else {
                    mergeAndSplit->setText("Объединить");
                    day->cellWidget(i, 1)->setVisible(true);
                    day->cellWidget(i, 0)->setFixedSize(day->cellWidget(i, 0)->width()/2, day->cellWidget(i, 0)->height());
                    day->setSpan(i, 0, 1, 1);
                }
            });
            day->setCellWidget(i, 2, mergeAndSplit);
        }
        ui->group->setCellWidget(z, 1, day);
    }
}


void groupCreator::on_confirmButton_clicked()
{
    if (ui->group->item(0, 0)){
        if (ui->group->item(0, 0)->text().length() != 0){
            this->data = ui->group;
            this->setVisible(false);
            isWindowWorkFinishedCorrectly = true;
        }
        else {
            alertWindow alert;
            alert.setAlertInfo(QString::fromStdString("Пустой ввод"));
            alert.setModal(true);
            alert.exec();
            alert.setVisible(true);
        }
    }
    else {
        alertWindow alert;
        alert.setAlertInfo(QString::fromStdString("Пустой ввод"));
        alert.setModal(true);
        alert.exec();
        alert.setVisible(true);
    }
}

void groupCreator::on_cancelButton_clicked()
{
    this->setVisible(false);
}

