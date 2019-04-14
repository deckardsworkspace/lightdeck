#ifndef LD_ADJ_H
#define LD_ADJ_H

#include <Arduino.h>
#include <LdBtn.h>

class LdAdj {
public:
    LdAdj();
    int getNum();
    void update();

private:
    int _choice;
    LdBtn* _btns;
};

#endif
