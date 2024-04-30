#include "nonono.h"
#include "ui_nonono.h"

NoNoNo::NoNoNo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NoNoNo)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Предупреждение"));
}

NoNoNo::~NoNoNo()
{
    delete ui;
}

void NoNoNo::setAlertInfo(QString text){
    ui->label_2->setText(text);
}

void NoNoNo::on_pushButton_2_clicked()
{
    this->setVisible(false);
}

