#ifndef LD_DISPLAY_H
#define LD_DISPLAY_H

#include "Arduino.h"
#include <LiquidCrystal.h>

class LdDisplay {
public:
    LdDisplay();
    void displayTime();
    void update(String selectedAdj);
    void update2nd(String string);
    void updateValue(String val);
    void welcome();

private:
    int _RS, _EN, _D4, _D5, _D6, _D7;
    LiquidCrystal *_LCD;
    String _selectedAdj, _val;
};

#endif
