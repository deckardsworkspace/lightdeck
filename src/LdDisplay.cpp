#include <Arduino.h>
#include <LiquidCrystal.h>
#include <LdDisplay.h>
#include <LdConst.h>

/**
 * Custom characters
 */
byte leftArrow[8] = {
    0x02, 0x06, 0x0E, 0x1E,
    0x1E, 0x0E, 0x06, 0x02
};
byte rightArrow[8] = {
    0x08, 0x0C, 0x0E, 0x0F,
    0x0F, 0x0E, 0x0C, 0x08
};

LdDisplay::LdDisplay() {
    _selectedAdj = "";
    _val = "";

    _LCD = new LiquidCrystal(PIN_LCD_RS, PIN_LCD_EN,
        PIN_LCD_D4, PIN_LCD_D5, PIN_LCD_D6, PIN_LCD_D7);
    _LCD -> begin(16, 2);
    _LCD -> noAutoscroll();

    // Custom characters
    _LCD -> createChar(0, leftArrow);
    _LCD -> createChar(1, rightArrow);
};

void LdDisplay::update(String currAdj, String prevAdj, String nextAdj) {
    if (_selectedAdj != currAdj) {
        // Clear display
        _LCD -> clear();

        // Display new adjustment, centered
        int length = currAdj.length();
        int offset = length / 2;
        if (length % 2 == 0) offset--;
        _LCD -> setCursor(7 - offset, 0);
        _LCD -> print(currAdj);

        // Display arrows on bottom row
        _LCD -> setCursor(0, 1);
        _LCD -> write((byte)0);
        _LCD -> setCursor(15, 1);
        _LCD -> write((byte)1);

        // Display prev and next adjustments
        _LCD -> setCursor(1, 1);
        _LCD -> print(prevAdj);
        _LCD -> setCursor(11, 1);
        _LCD -> print(nextAdj);

        // Store new adjustment
        _selectedAdj = currAdj;
    }
};

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
