#ifndef LD_ADJ_H
#define LD_ADJ_H

#include <Arduino.h>
#include <Bounce2.h>

// Possible adjustments
extern String ADJ[];
extern int ADJ_LEN;

class LdAdj {
public:
    LdAdj();
    int getNum();
    String getNextStr();
    String getPrevStr();
    String getString();
    void prevAdj();
    void nextAdj();

private:
    int _adj_len, _choice, *_values;
};

#endif
