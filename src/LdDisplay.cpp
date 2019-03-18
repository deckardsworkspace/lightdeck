#include "Arduino.h"
#include <LiquidCrystal.h>
#include <LdDisplay.h>
#include <LdConst.h>

LdDisplay::LdDisplay() {
    _selectedAdj = "";
    _val = "";

    _RS = PIN_LCD_RS;
    _EN = PIN_LCD_EN;
    _D4 = PIN_LCD_D4;
    _D5 = PIN_LCD_D5;
    _D6 = PIN_LCD_D6;
    _D7 = PIN_LCD_D7;

    _LCD = new LiquidCrystal(_RS, _EN, _D4, _D5, _D6, _D7);
    _LCD -> begin(16, 2);
    _LCD -> noAutoscroll();
};

void LdDisplay::displayTime() {
    int secs = millis() / 1000;

    // Print on row 2 col 5
    _LCD -> setCursor(4, 1);

    // Show minutes
    int sec = secs % 60;
    _LCD -> print(secs / 60);

    // Show colon every other second
    if (sec % 2 == 0)
        _LCD -> print(":");
    else
        _LCD -> print(" ");

    // Show seconds
    String seconds = String(sec);
    if (sec < 10) {
        seconds = "0" + seconds;
    }
    _LCD -> print(seconds);
};

void LdDisplay::update(String selectedAdj) {
    if (_selectedAdj != selectedAdj) {
        // Clear top row
        _LCD -> setCursor(0, 0);
        _LCD -> print("                ");

        // Display new adjustment
        _LCD -> setCursor(0, 0);
        _LCD -> print(selectedAdj);

        // Store new adjustment
        _selectedAdj = selectedAdj;
    }
};

void LdDisplay::updateValue(String val) {
    if (_val != val) {
        // Clear bottom row
        _LCD -> setCursor(0, 1);
        _LCD -> print("                ");

        // Display new value, right-aligned
        _LCD -> setCursor(16 - val.length(), 1);
        _LCD -> print(val);

        // Store new value
        _val = val;
    }
}

void LdDisplay::welcome() {
    // Show welcome message
    _LCD -> clear();
    _LCD -> setCursor(3, 0);
    _LCD -> print("Welcome to");
    _LCD -> setCursor(3, 1);
    _LCD -> print("Lightdeck.");
    delay(1000);
    _LCD -> clear();
};
