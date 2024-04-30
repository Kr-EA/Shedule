#include "confirmaction.h"
#include "ui_confirmaction.h"
#include<functional>

confirmAction::confirmAction(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::confirmAction)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Подтверждение"));
}

void confirmAction::setConfirmLabel(QString text)
{
    ui->label_2->setText(text);
}
confirmAction::~confirmAction()
{
    delete ui;
}

void confirmAction::on_no_clicked()
{
    this->setVisible(false);
}

void confirmAction::setCallback(Func method)
{
    callback = method;
}

void confirmAction::on_yes_clicked()
{
    this->setVisible(false);
    callback();
}

