#ifndef MALLGLOBAL_H
#define MALLGLOBAL_H

#include <QMap>
#include <_BK/GoodsClass.h>

class mallGloval
{
public:
    mallGloval();
    ~mallGloval();

public:
    static void sysInit();
    static QMap<QString, QString> g_userPWD;
    static QVector<Goods> g_currentGood;
    static QVector<Goods> g_eatGood;
    static QVector<Goods> g_clothGood;
    static QVector<Goods> g_phoneGood;
    static float g_sellTotal;
    static int g_orderID;
};


#endif // MALLGLOBAL_H
