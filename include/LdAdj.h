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
    void reset();
    int get(int);
    int *getArray();
    int getChoice();
    String getAdj();
    void prevAdj();
    void nextAdj();
    void setAdj(int);
    int update(int, bool);

private:
    int _adj_len, _choice, *_values;
};

#endif
