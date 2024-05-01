#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    QVector<QString> uids;
    QString log;
    QVector<QString> *savedData;
    bool isWindowCalled = false;
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:

    void on_cancel_clicked();

    void on_confirm_clicked();

    void on_hoursSetter_valueChanged(int value);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
