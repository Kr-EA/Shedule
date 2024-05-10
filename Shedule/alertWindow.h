#ifndef ALERTWINDOW_H
#define ALERTWINDOW_H

#include <QDialog>

namespace Ui {
class NoNoNo;
}

class alertWindow : public QDialog
{
    Q_OBJECT

public:
    void setAlertInfo(QString);
    explicit alertWindow(QWidget *parent = nullptr);
    ~alertWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::NoNoNo *ui;
};

#endif // ALERTWINDOW_H
