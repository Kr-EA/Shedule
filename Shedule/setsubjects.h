#ifndef SETSUBJECTS_H
#define SETSUBJECTS_H

#include <QDialog>
#include <QVector>
#include <string>
#include<QComboBox>
#include<QLabel>

using namespace std;

namespace Ui {
class setSubjects;
}

class setSubjects : public QDialog
{
    Q_OBJECT

public:
    QString subjectToAdd;
    explicit setSubjects(QWidget *parent = nullptr);
    ~setSubjects();
    int amount;
    void setAmount(int);
    void setup(QVector<QString>);
    bool isPropertyExist(QVector<QString> &arrayToSearch, QString &searchingProperty);

private slots:
    void on_cancel_clicked();

    void on_confirm_clicked();

signals:
    subjectsListReadySignal(QVector<QString>);

private:
    Ui::setSubjects *ui;
    QVector<QString> data;
    QVector<QComboBox*> boxes;
    QVector<QLabel*> labels;


};

#endif // SETSUBJECTS_H
