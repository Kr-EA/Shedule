#ifndef TDIALOG_H
#define TDIALOG_H

#include <QDialog>
#include"setsubjects.h"

namespace Ui {
class tDialog;
}

class tDialog : public QDialog
{
    Q_OBJECT

public:
    explicit tDialog(QWidget *parent = nullptr);
    ~tDialog();
    bool isWindowCalled = false;
    string log;
    QVector<QString> data;
    setSubjects* dialogChild;
    void load(QVector<QString>);

private slots:
    void on_ratingSetter_valueChanged(int value);

    void on_cancel_clicked();

    void on_confirm_clicked();

public slots:
    void subjectsListSlot(QVector<QString> tempData);

private:
    Ui::tDialog *ui;
};

#endif // TDIALOG_H
