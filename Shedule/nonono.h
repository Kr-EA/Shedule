#ifndef NONONO_H
#define NONONO_H

#include <QDialog>

namespace Ui {
class NoNoNo;
}

class NoNoNo : public QDialog
{
    Q_OBJECT

public:
    void setAlertInfo(QString);
    explicit NoNoNo(QWidget *parent = nullptr);
    ~NoNoNo();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::NoNoNo *ui;
};

#endif // NONONO_H
