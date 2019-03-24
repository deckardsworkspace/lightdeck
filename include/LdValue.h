#ifndef LD_VALUE_H
#define LD_VALUE_H

#include <Arduino.h>
#include <Bounce2.h>

class LdValue {
public:
    LdValue();
    void reset();
    int *getArray();
    int update(int choice);

private:
    // Debouncers
    Bounce _deb_dec, _deb_inc;

    // Adjustment
    int _adj_len, _choice;

    // Position
    int *_pos;
};

#endif
