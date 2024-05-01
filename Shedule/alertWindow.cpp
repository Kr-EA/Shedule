#include "alertWindow.h"
#include "ui_alertWindow.h"

alertWindow::alertWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NoNoNo)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString("Предупреждение"));
}

alertWindow::~alertWindow()
{
    delete ui;
}

void alertWindow::setAlertInfo(QString text){
    ui->label_2->setText(text);
}

void alertWindow::on_pushButton_2_clicked()
{
    this->setVisible(false);
}

