#ifndef GROUPCREATOR_H
#define GROUPCREATOR_H
#include<QTableWidget>
#include <QDialog>
#include <QVector>
#include<QComboBox>
#include <QString>

namespace Ui {
class groupCreator;
}

class groupCreator : public QDialog
{
    Q_OBJECT

public:
    QVector<QString> days;
    QWidget* tempWidget{};
    bool isWindowWorkFinishedCorrectly{};
    QTableWidget* data;
    QVector<QString> subjects;
    QVector<QString> teachers;
    void setupTeacherComboBox(QString, QVector<QString>, QComboBox*);
    explicit groupCreator(QWidget *parent = nullptr);
    ~groupCreator();
    void setup();

private slots:

    void on_confirmButton_clicked();
    void on_cancelButton_clicked();

private:
    bool mergingData[6][4]{};
    Ui::groupCreator *ui;
};

#endif // GROUPCREATOR_H
