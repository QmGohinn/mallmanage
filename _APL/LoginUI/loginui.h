#ifndef LOGINUI_H
#define LOGINUI_H

#include <QDialog>

namespace Ui {
class loginUI;
}

class loginUI : public QDialog
{
    Q_OBJECT

public:
    explicit loginUI(QWidget *parent = nullptr);
    ~loginUI();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::loginUI *ui;
};

#endif // LOGINUI_H
