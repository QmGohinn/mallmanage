#ifndef LOGINUI_H
#define LOGINUI_H

#include <QDialog>
#include <_APL/UserAdd/useradddlg.h>

namespace Ui {
class loginUI;
}

class loginUI : public QDialog
{
    Q_OBJECT

public:
    explicit loginUI(QWidget *parent = nullptr);
    ~loginUI();

    UserAddDlg* m_useraddDlg = nullptr;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::loginUI *ui;
};

#endif // LOGINUI_H
