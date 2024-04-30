#include "setsubjects.h"
#include "ui_setsubjects.h"
#include "tdialog.h"
#include "nonono.h"
#include<QComboBox>
#include<QDebug>
#include<QVector>
#include<QString>

using namespace std;

setSubjects::setSubjects(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::setSubjects)
{
    ui->setupUi(this);
    boxes.push_back(ui->setSub1);
    boxes.push_back(ui->setSub2);
    boxes.push_back(ui->setSub3);
    boxes.push_back(ui->setSub4);
    boxes.push_back(ui->setSub5);
    labels.push_back(ui->sub1);
    labels.push_back(ui->sub2);
    labels.push_back(ui->sub3);
    labels.push_back(ui->sub4);
    labels.push_back(ui->sub5);

    this->setWindowTitle(QString::fromStdString("Выбор предметов"));
}

void setSubjects::setAmount(int value){
    this->amount = value;
}

void setSubjects::setup(QVector<QString> subjects){
    for (int i = 0; i < 5; i++){
        boxes[i]->setVisible(true);
        labels[i]->setVisible(true);
    }
    for (int i = amount; i < 5; i++){
        boxes[i]->setVisible(false);
        labels[i]->setVisible(false);
    }
    for (int i = 0; i < amount; i++){
        for (QString str: subjects){
            boxes[i]->addItem(str);
        }
    }
}

setSubjects::~setSubjects()
{
    delete ui;
}

void setSubjects::on_cancel_clicked()
{
    this->setVisible(false);
}

bool setSubjects::isPropertyExist(QVector<QString> &arrayToSearch, QString &searchingProperty) {
    for (QString property : arrayToSearch) {
        if (property == searchingProperty) {
            return true;
        }
    }

    return false;
}

void setSubjects::on_confirm_clicked()
{
    QVector<QString> tempData;
    bool flag = true;
    for (int i = 0; i < amount; i++) {
        if (i == 0){
            subjectToAdd = boxes[i]->currentText();
        }
        QString property = boxes[i]->currentText();

        if (!isPropertyExist(tempData, property)) {
            tempData.push_back(property);
        }
        else {
            NoNoNo alert;
            alert.setAlertInfo(QString::fromStdString("Введены одинаковые предметы"));
            alert.setModal(true);
            alert.exec();
            alert.setVisible(true);
            flag = false;
            break;
        }
    }

    if (flag) {
        this->setVisible(false);
        emit subjectsListReadySignal(tempData);
    }
}

