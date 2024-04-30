#ifndef CONFIRMACTION_H
#define CONFIRMACTION_H

#include <QDialog>

using namespace std;

namespace Ui {
class confirmAction;
}

class confirmAction : public QDialog
{
    Q_OBJECT

public:
    typedef function<void()> Func;
    Func callback;
    void setCallback(Func);
    void setConfirmLabel(QString);
    explicit confirmAction(QWidget *parent = nullptr);
    ~confirmAction();

private slots:
    void on_no_clicked();
    void on_yes_clicked();

private:
    Ui::confirmAction *ui;
};

#endif // CONFIRMACTION_H
