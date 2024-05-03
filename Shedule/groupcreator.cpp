#include "groupcreator.h"
#include "ui_groupcreator.h"
#include<QTableWidgetItem>
#include<QPushButton>
#include<QComboBox>
#include <QDebug>

groupCreator::groupCreator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::groupCreator)
{
    ui->setupUi(this);
}

groupCreator::~groupCreator()
{
    delete ui;
}

void groupCreator::setup() {
    ui->group->setSpan(0, 0, 1, 2);
    for (int i = 0; i < 3; i++){
        ui->group->setColumnWidth(i, (this->width()-55)/3);
    }
    for (int i = 0; i < 6; i++){
        ui->group->setRowHeight(i, (this->height()-65)/6);
    }
    this->setWindowTitle(QString::fromStdString("Cоздание группы"));
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText("Числитель");
    ui->group->setItem(1, 0, item);
    item = new QTableWidgetItem;
    item->setText("Знаменатель");
    ui->group->setItem(1, 1, item);
    ui->group->horizontalHeader()->setVisible(false);
    item = new QTableWidgetItem;

    for (int i = 2; i < 6; i++){
        // QWidget

        // ui->group->setItem(i, 0, subTable);

        QComboBox* dropDown = new QComboBox();
        dropDown->addItems(QStringList::fromVector(subjects));
        ui->group->setCellWidget(i, 0, dropDown);
        dropDown = new QComboBox();
        dropDown->addItems(QStringList::fromVector(subjects));
        ui->group->setCellWidget(i, 1, dropDown);

        QPushButton* mergeAndSplit = new QPushButton("Объединить");
        connect(mergeAndSplit, &QPushButton::clicked, this, [&, mergeAndSplit, i](){
            if(mergeAndSplit->text() == "Объединить"){
                mergeAndSplit->setText("Разъеденить");
                ui->group->setSpan(i, 0, 1, 2);
            }
            else {
                mergeAndSplit->setText("Объединить");
                ui->group->setSpan(i, 0, 1, 1);
                item = new QTableWidgetItem;
                item->setText(ui->group->item(i, 0)->text());
                ui->group->setItem(i, 1, item);
            }
        });
        ui->group->setCellWidget(i, 2, mergeAndSplit);
    }
}


void groupCreator::on_confirmButton_clicked()
{
    this->data = ui->group;
    this->setVisible(false);
}

void groupCreator::on_cancelButton_clicked()
{
    this->setVisible(false);
}

