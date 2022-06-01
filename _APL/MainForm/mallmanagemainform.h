#ifndef MALLMANAGEMAINFORM_H
#define MALLMANAGEMAINFORM_H

#include <QMainWindow>
#include <_BK/GoodsClass.h>

QT_BEGIN_NAMESPACE
namespace Ui { class mallmanageMainForm; }
QT_END_NAMESPACE

class mallmanageMainForm : public QMainWindow
{
    Q_OBJECT

public:
    mallmanageMainForm(QWidget *parent = nullptr);
    ~mallmanageMainForm();

    void GoodsIntoTable(Goods _good);
    void updateCombox();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_comboBox_2_currentIndexChanged(int index);
    void on_comboBox_3_currentTextChanged(const QString &arg1);
    void on_spinBox_2_textChanged(const QString &arg1);
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::mallmanageMainForm *ui;
};
#endif // MALLMANAGEMAINFORM_H
