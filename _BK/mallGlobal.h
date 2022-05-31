#ifndef MALLGLOBAL_H
#define MALLGLOBAL_H

#include <QMap>

class mallGloval
{
public:
    mallGloval();
    ~mallGloval();

public:
    static void sysInit();
    static QMap<QString, QString> g_userPWD;


};


#endif // MALLGLOBAL_H
