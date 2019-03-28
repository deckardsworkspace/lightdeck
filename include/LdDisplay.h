#ifndef LD_DISPLAY_H
#define LD_DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class LdDisplay {
public:
    LdDisplay();
    void update(String, String, String);
    void welcome();

private:
    LiquidCrystal *_LCD;
    String _selectedAdj, _val;

    void dispCentered(String, int);
};

#endif
