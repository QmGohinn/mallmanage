#ifndef MALLMANAGEMAINFORM_H
#define MALLMANAGEMAINFORM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class mallmanageMainForm; }
QT_END_NAMESPACE

class mallmanageMainForm : public QMainWindow
{
    Q_OBJECT

public:
    mallmanageMainForm(QWidget *parent = nullptr);
    ~mallmanageMainForm();

private:
    Ui::mallmanageMainForm *ui;
};
#endif // MALLMANAGEMAINFORM_H
