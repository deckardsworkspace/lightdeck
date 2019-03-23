#ifndef LD_DISPLAY_H
#define LD_DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class LdDisplay {
public:
    LdDisplay();
    void updateAdj(String selectedAdj);
    void updateValue(String val);
    void welcome();

private:
    LiquidCrystal *_LCD;
    String _selectedAdj, _val;
};

#endif
