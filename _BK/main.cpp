#include <_APL/MainForm/mallmanagemainform.h>
#include <_APL/LoginUI/loginui.h>
#include <_BK/mallGlobal.h>

#include <QApplication>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /// 系统初始化
    mallGloval::sysInit();
    /// 登录界面
    loginUI _loginUI;
    if(_loginUI.exec() != QDialog::Accepted){
        return 0;
    }
    QThread::sleep(1);
    /// 登录验证成功进入主界面
    mallmanageMainForm w;
    w.show();
    return a.exec();
}
