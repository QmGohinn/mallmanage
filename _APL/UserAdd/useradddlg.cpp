#include "useradddlg.h"
#include "ui_useradddlg.h"

#include <_BK/mallGlobal.h>
#include <QMessageBox>

UserAddDlg::UserAddDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserAddDlg)
{
    ui->setupUi(this);
}

UserAddDlg::~UserAddDlg()
{
    delete ui;
}

void UserAddDlg::on_pushButton_2_clicked()
{
    QDialog::reject();
}

void UserAddDlg::on_pushButton_clicked()
{
    QString _name = ui->lineEdit->text();
    QString _pwd1 = ui->lineEdit_2->text();
    QString _pwd2 = ui->lineEdit_3->text();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();

    if(_name.isEmpty() || _pwd1.isEmpty() || _pwd2.isEmpty()){
        QMessageBox::critical(this, "提示", "账号和密码不能为空!", tr("确定"));
        return;
    }

    if(_pwd1.compare(_pwd2)){
        QMessageBox::critical(this, "提示", "俩次输入密码不一致!", tr("确定"));
        return;
    }

    if(mallGloval::g_userPWD.find(_name) != mallGloval::g_userPWD.end()){
        QMessageBox::critical(this, "提示", "该用户已存在!!", tr("确定"));
        return;
    }
    else{
        mallGloval::g_userPWD.insert(_name, _pwd1);
        QMessageBox::information(this, "提示", QString("%1, 恭喜您注册成功!").arg(_name), tr("返回登录"));
        QDialog::accept();
    }
}
