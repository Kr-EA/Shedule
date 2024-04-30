#include "dialog.h"
#include "ui_dialog.h"
#include "nonono.h"
#include<iostream>
#include<string>
#include<QFile>
#include<QDebug>

#include "mainwindow.h"

using namespace std;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Добавление предмета"));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_cancel_clicked()
{
    this->setVisible(false);
}

void Dialog::on_hoursSetter_valueChanged(int value)
{
    ui->hoursLabel->setText(QString("Число часов: %1").arg(value));
}

void Dialog::on_confirm_clicked()
{
    string subjectName;
    string subjectType;
    int hours{};

    subjectName  = ui->subjectTitleEditor->property("text").toString().toStdString();
    std::replace(subjectName.begin(), subjectName.end(), ' ', '_');

    if (ui->lectureRadio->isChecked()){
        subjectType = "Лекция";
    }
    else if(ui->practiceRadio->isChecked()){
        subjectType = "Практика";
    }
    hours = ui->hoursSetter->property("value").toInt();
    if (subjectName.length() != 0 && subjectType.length()  != 0 && hours != 0){
        for (QString temp : *savedData){
            QStringList separatedTemp;
            separatedTemp = temp.split(u' ', Qt::SkipEmptyParts);
            if (QString::fromStdString(subjectName).toLower() == separatedTemp[0].toLower() && QString::fromStdString(subjectType).toLower() == separatedTemp[1].toLower()){
                NoNoNo alert;
                alert.setAlertInfo(QString::fromStdString("Такой предмет уже есть"));
                alert.setModal(true);
                alert.exec();
                alert.setVisible(true);
                return;
            }
        }
        isWindowCalled = true;
        log = QString::fromStdString(subjectName) + " " + QString::fromStdString(subjectType) + " " + QString::number(hours);
        this->setVisible(false);
    }
    else {
        NoNoNo alert;
        alert.setAlertInfo(QString::fromStdString("Пустой ввод"));
        alert.setModal(true);
        alert.exec();
        alert.setVisible(true);
    }
}
