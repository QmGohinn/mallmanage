#ifndef GOODSCLASS_H
#define GOODSCLASS_H

#include <QString>

class Goods{

public:
    Goods(QString _name, float _inputPrice, float _sellPrice, int _num)
        :m_name(_name), m_inputPrice(_inputPrice), m_sellPrice(_sellPrice), m_num(_num){
    };

    ~Goods(){
    };

public:
    QString m_name = "";
    float m_inputPrice = 0;
    float m_sellPrice = 0;
    int m_num = 0;

};

#endif // GOODSCLASS_H
