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

void groupCreator::setupTeacherComboBox(QString subject, QVector<QString> teachers, QComboBox* oldDropDownTeachers){
    oldDropDownTeachers->clear();
    QStringList teacherVars;
    QVector<QString> correctTeachers{};
    if (subject == "-"){
        oldDropDownTeachers->addItem("-");
    }
    for (QString teacher : teachers){
        if (teacher.toStdString().find(subject.toStdString()) != 18446744073709551615){
            correctTeachers.push_back(teacher);
        }
    }
    teacherVars = QStringList::fromVector(correctTeachers);
    oldDropDownTeachers->addItems(teacherVars);
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
                QComboBox* dropDownTeachers = new QComboBox();

                QVector<QString> vars = subjects;
                vars.push_back(QString::fromStdString("-"));
                QStringList subjectVariants = QStringList::fromVector(vars);
                dropDownSubjects->addItems(subjectVariants);

                dropDownSubjects->setProperty("currentText", "-");
                setupTeacherComboBox(dropDownSubjects->property("currentText").toString(), teachers, dropDownTeachers);

                connect(dropDownSubjects, &QComboBox::currentTextChanged, this, [this, dropDownSubjects, pairSelection, i, j, z, day, dropDownTeachers](){
                    QGridLayout* temp = new QGridLayout;
                    dropDownTeachers->blockSignals(true);
                    setupTeacherComboBox(dropDownSubjects->property("currentText").toString(), teachers, dropDownTeachers);
                    dropDownTeachers->blockSignals(false);

                    temp->addWidget(dropDownSubjects, 0,  0);
                    temp->addWidget(dropDownTeachers, 1, 0);

                    QWidget* tableItem = new QWidget();
                    tableItem->setLayout(temp);
                    day->setCellWidget(i, j, tableItem);

                    if (mergingData[z-1][i-1] && j != 1){
                        day->cellWidget(i, 1)->layout()->itemAt(0)->widget()->blockSignals(true);
                        day->cellWidget(i, 1)->layout()->itemAt(1)->widget()->blockSignals(true);

                        day->cellWidget(i, 1)->layout()->itemAt(0)->widget()->setProperty("currentText", day->cellWidget(i, 0)->layout()->itemAt(0)->widget()->property("currentText").toString());
                        day->cellWidget(i, 1)->layout()->itemAt(1)->widget()->setProperty("currentText", day->cellWidget(i, 0)->layout()->itemAt(1)->widget()->property("currentText").toString());

                        day->cellWidget(i, 1)->layout()->itemAt(0)->widget()->blockSignals(false);
                        day->cellWidget(i, 1)->layout()->itemAt(1)->widget()->blockSignals(false);
                    }
                });

                connect(dropDownTeachers, &QComboBox::currentTextChanged, this, [&, this, dropDownTeachers, pairSelection, i, j, z, day](){
                    if (mergingData[z-1][i-1] && j != 1){
                        day->blockSignals(true);
                        static_cast<QComboBox*>(day->cellWidget(i, 1)->layout()->itemAt(1)->widget())->clear();
                        setupTeacherComboBox(day->cellWidget(i, 0)->layout()->itemAt(0)->widget()->property("currentText").toString(), teachers, static_cast<QComboBox*>(day->cellWidget(i, 1)->layout()->itemAt(1)->widget()));
                        day->cellWidget(i, 1)->layout()->itemAt(1)->widget()->setProperty("currentText", day->cellWidget(i, 0)->layout()->itemAt(1)->widget()->property("currentText").toString());
                        day->blockSignals(false);
                        qDebug() << day->cellWidget(i, 0)->layout()->itemAt(1)->widget()->property("currentText");
                        qDebug() << day->cellWidget(i, 1)->layout()->itemAt(1)->widget()->property("currentText");
                    }
                });

                pairSelection->addWidget(dropDownSubjects, 0, 0);
                pairSelection->addWidget(dropDownTeachers, 1, 0);
                QWidget* tableItem = new QWidget();
                tableItem->setLayout(pairSelection);

                day->setCellWidget(i, j, tableItem);
            }
            QPushButton* mergeAndSplit = new QPushButton("Объединить");
            connect(mergeAndSplit, &QPushButton::clicked, this, [&, mergeAndSplit, i, day, z](){
                if(mergeAndSplit->text() == "Объединить"){
                    mergeAndSplit->setText("Разъеденить");
                    day->blockSignals(true);
                    mergingData[z-1][i-1] = true;
                    day->cellWidget(i, 0)->layout()->itemAt(0)->widget()->setProperty("currentText", "-");
                    day->cellWidget(i, 0)->layout()->itemAt(1)->widget()->setProperty("currentText", "-");
                    day->cellWidget(i, 1)->layout()->itemAt(0)->widget()->setProperty("currentText", day->cellWidget(i, 0)->layout()->itemAt(0)->widget()->property("currentText"));
                    day->cellWidget(i, 1)->layout()->itemAt(1)->widget()->setProperty("currentText", day->cellWidget(i, 0)->layout()->itemAt(1)->widget()->property("currentText"));
                    day->cellWidget(i, 1)->setVisible(false);
                    day->setSpan(i, 0, 1, 2);
                    day->cellWidget(i, 0)->setFixedSize(day->cellWidget(i, 0)->width()*2, day->cellWidget(i, 0)->height());
                    day->blockSignals(false);
                }
                else {
                    mergeAndSplit->setText("Объединить");
                    mergingData[z-1][i-1] = false;
                    day->setSpan(i, 0, 1, 1);
                    day->cellWidget(i, 0)->setFixedSize(day->cellWidget(i, 0)->width()/2, day->cellWidget(i, 0)->height());
                    day->cellWidget(i, 1)->setVisible(true);
                    day->cellWidget(i, 1)->layout()->itemAt(0)->widget()->setProperty("currentText", "-");
                    day->cellWidget(i, 1)->layout()->itemAt(1)->widget()->setProperty("currentText", "-");
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

