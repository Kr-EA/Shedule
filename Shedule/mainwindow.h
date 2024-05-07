#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTableWidgetItem>
#include <QDialog>
#include<filesystem>
#include<QFile>
#include "dialog.h"
#include<QRadioButton>
#include "tdialog.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    struct itemCoordinates{
        int x{};
        int y{};
    };

public:
    QVector<QString> uids;
    QVector<QTableWidget*> groups;
    QVector<QString> groupData;
    QVector<QString> subjectData;
    QVector<QString> teacherData;
    MainWindow(QWidget *parent = nullptr);
    void saveData(const QString&, QVector<QString>&);
    void loadData(const QString&, QVector<QString>&);
    int checkedRow;
    void subjectDataSetup();
    void groupDataSetup();
    void teacherDataSetup();
    void saveGroupData();
    ~MainWindow();

private slots:
    void on_addSubjectButton_clicked();

    void on_addTeacherButton_clicked();

    void on_sortSubjectDataButton_clicked();

    void on_saveData_clicked();

    void checkItem(itemCoordinates, QString);

    void on_subjectsData_cellChanged(int row, int column);

    void toggleAllRows(bool, QTableWidget*, QVector<QString>&);

    void on_searchSubjectDataButton_clicked();

    void on_searchInput_textEdited(const QString &arg1);

    void on_returnAllSubjects_clicked();

    void on_sortTeacherButton_clicked();

    void on_searchTeacherButton_clicked();

    void on_searchTeacherLine_textChanged(const QString &arg1);

    void on_teachersData_cellChanged(int row, int column);

    void on_expandAndCollapse_clicked();

    void on_searchGroup_clicked();

    void on_addGroup_clicked();

    void on_searchGroupLine_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;

signals:
    void itemChanged(itemCoordinates, QString);
};

#endif // MAINWINDOW_H
