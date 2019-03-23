#include <LdConst.h>

// milliseconds
const unsigned long DEBOUNCE_INTERVAL = 50;
const unsigned long HOLD_DELAY = 500;
const unsigned long HOLD_INTERVAL = 50;

// LCD pins
const int PIN_LCD_D7 = 2;
const int PIN_LCD_D6 = 3;
const int PIN_LCD_D5 = 4;
const int PIN_LCD_D4 = 5;
const int PIN_LCD_EN = 11;
const int PIN_LCD_RS = 12;

// Button pins
const int PIN_BTN_RESET = 6;
const int PIN_BTN_UNDO = 7;
const int PIN_BTN_MODE = 8;
const int PIN_BTN_PLUS = 9;
const int PIN_BTN_MINUS = 10;

// MIDI constants
const int MID_VEL_DEFAULT = 64;
const int MID_NOTE_DEFAULT = 127;
const int MID_CHAN_RESET = 1;
const int MID_CHAN_UNDO = 2;
const int MID_CHAN_DEFAULT = 3;
