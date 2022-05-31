#include "loginui.h"
#include "ui_loginui.h"

#include <QMessageBox>
#include <_BK/mallGlobal.h>

loginUI::loginUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginUI)
{
    ui->setupUi(this);
    ui->lineEdit->setText("admin");
    ui->lineEdit_2->setText("123456");
}

loginUI::~loginUI()
{
    delete ui;
}

/// 登录界面取消按钮
void loginUI::on_pushButton_2_clicked()
{
    QDialog::reject();
}

/// 登录界面登录按钮
void loginUI::on_pushButton_clicked()
{
    if(ui->lineEdit->text().compare("") == 0 || ui->lineEdit_2->text().compare("") == 0){
        QMessageBox::critical(this, "警 告", "账号和密码不能为空!", "知道了");
        return;
    }

    QString _inputUserName = ui->lineEdit->text();
    QString _inputPWD = ui->lineEdit_2->text();

    if(mallGloval::g_userPWD.find(_inputUserName) == mallGloval::g_userPWD.end()){
        QMessageBox::critical(this, "警 告", "此用户不存在!", "知道了");
        return;
    }
    else{
        if(mallGloval::g_userPWD.find(_inputUserName).value().compare(_inputPWD) != 0){
            QMessageBox::critical(this, "警 告", "账号和密码不匹配!", "知道了");
            return;
        }
        else{
            QDialog::accept();
            return;
        }
    }
}
