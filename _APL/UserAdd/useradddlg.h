#ifndef USERADDDLG_H
#define USERADDDLG_H

#include <QDialog>

namespace Ui {
class UserAddDlg;
}

class UserAddDlg : public QDialog
{
    Q_OBJECT

public:
    explicit UserAddDlg(QWidget *parent = nullptr);
    ~UserAddDlg();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::UserAddDlg *ui;
};

#endif // USERADDDLG_H
