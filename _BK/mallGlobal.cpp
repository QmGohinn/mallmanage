#include <_BK/mallGlobal.h>

/// Global Param Define Start
QMap<QString, QString> mallGloval::g_userPWD;
/// Global Param Define End

void mallGloval::sysInit()
{
    g_userPWD.insert("admin", "123456");
}


