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

void LdDisplay::dispCentered(String str, int row) {
    // Display centered
    int length = str.length();
    int offset = length / 2;
    if (length % 2 == 0) offset--;
    _LCD -> setCursor(7 - offset, row);
    _LCD -> print(str);
};

void LdDisplay::updateAdj(String selectedAdj) {
    if (_selectedAdj != selectedAdj) {
        // Clear top row and print arrows
        _LCD -> setCursor(0, 0);
        _LCD -> write((byte)0);
        _LCD -> print("              ");
        _LCD -> write((byte)1);

        // Display new adjustment, centered
        dispCentered(selectedAdj, 0);

        // Store new adjustment
        _selectedAdj = selectedAdj;
    }
};

void LdDisplay::updateValue(String val) {
    if (_val != val) {
        // Clear buttom row
        _LCD -> setCursor(0, 1);
        _LCD -> print("                ");

        // Display new value, centered
        dispCentered(val, 1);

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
