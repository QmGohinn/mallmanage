#include <_BK/mallGlobal.h>

/// Global Param Define Start
QMap<QString, QString> mallGloval::g_userPWD;
QVector<Goods> mallGloval::g_currentGood;
QVector<Goods> mallGloval::g_eatGood;
QVector<Goods> mallGloval::g_clothGood;
QVector<Goods> mallGloval::g_phoneGood;
int mallGloval::g_orderID = 1;
float mallGloval::g_sellTotal = 0;
/// Global Param Define End

void mallGloval::sysInit()
{
    g_userPWD.insert("admin", "123456");

    Goods _phone("HUAWEI P40", 4000, 5400, 200);
    Goods _cloth("时尚女装", 200, 600, 130);
    Goods _eatthing("三只松鼠零食", 4.0, 6.0, 400);

    g_currentGood.push_back(_phone);
    g_phoneGood.push_back(_phone);
    g_currentGood.push_back(_cloth);
    g_clothGood.push_back(_cloth);
    g_currentGood.push_back(_eatthing);
    g_eatGood.push_back(_eatthing);
}


