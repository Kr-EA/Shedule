#include "tdialog.h"
#include "ui_tdialog.h"
#include "nonono.h"
#include<string>
#include<QString>
#include<QVector>
#include<QDebug>
#include"setsubjects.h"

using namespace std;

tDialog::tDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Добавление преподавателя"));
}

tDialog::~tDialog()
{
    delete ui;
}

void tDialog::load(QVector<QString> loadableList){
    for (int i = 0; i < loadableList.size(); i++){
        data.push_back(loadableList[i]);
    }
    if (data.size() <= 5){
        ui->amountOfSubjectsSetter->setMaximum(data.size());
    }
    else {
        ui->amountOfSubjectsSetter->setMaximum(5);
    }
}

void tDialog::on_ratingSetter_valueChanged(int value)
{
   ui->ratingLabel->setText(QString("Рейтинг: %1").arg(value));
}

void tDialog::on_cancel_clicked()
{
    this->setVisible(false);
}

void tDialog::on_confirm_clicked()
{
    string surname = ui->teacherSurnameEdit->property("text").toString().toStdString();
    string name = ui->teacherNameEdit->property("text").toString().toStdString();
    string lastname = ui->teacherLastnameEdit->property("text").toString().toStdString();
    int rating = ui->ratingSetter->property("value").toInt();
    int amountOfSubjects = ui->amountOfSubjectsSetter->property("value").toInt();
    std::replace(lastname.begin(), lastname.end(), ' ',  '_');
    std::replace(name.begin(), name.end(), ' ',  '_');
    std::replace(surname.begin(), surname.end(), ' ',  '_') ;
    log = lastname + " " + name + " " + surname + " " + to_string(rating);
    if (surname.length() != 0 && name.length() != 0 && lastname.length() != 0 && amountOfSubjects != 0){
        dialogChild->setAmount(amountOfSubjects);
        dialogChild->setup(data);
        dialogChild->setModal(true);
        dialogChild->setVisible(true);
        dialogChild->exec();
    }
    else {
        NoNoNo alert;
        alert.setAlertInfo(QString::fromStdString("Пустой ввод"));
        alert.setModal(true);
        alert.exec();
        alert.setVisible(true);
    }
}

void tDialog::subjectsListSlot(QVector<QString> tempData) {
    this->setVisible(false);
    for (QString item : tempData) {
        log += " " + item.toStdString();
    }
    this->isWindowCalled = true;
}

