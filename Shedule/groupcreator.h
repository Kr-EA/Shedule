#ifndef GROUPCREATOR_H
#define GROUPCREATOR_H
#include<QTableWidget>
#include <QDialog>
#include <QVector>
#include <QString>

namespace Ui {
class groupCreator;
}

class groupCreator : public QDialog
{
    Q_OBJECT

public:
    QTableWidget* data;
    QVector<QString> subjects;
    explicit groupCreator(QWidget *parent = nullptr);
    ~groupCreator();

    void setup();

private slots:

    void on_confirmButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::groupCreator *ui;
};

#endif // GROUPCREATOR_H
