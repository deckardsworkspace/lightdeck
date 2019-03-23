#ifndef LD_CONST_H
#define LD_CONST_H

// Debounce buttons over a 500ms period
extern const unsigned long DEBOUNCE_INTERVAL;

// Period of time to wait before triggering a hold event
extern const unsigned long HOLD_DELAY;

// Interval between repeated triggers during a hold event
extern const unsigned long HOLD_INTERVAL;

// LCD pins
extern const int PIN_LCD_RS;
extern const int PIN_LCD_EN;
extern const int PIN_LCD_D4;
extern const int PIN_LCD_D5;
extern const int PIN_LCD_D6;
extern const int PIN_LCD_D7;

// Button pins
extern const int PIN_BTN_UNDO;
extern const int PIN_BTN_RESET;
extern const int PIN_BTN_MINUS;
extern const int PIN_BTN_PLUS;
extern const int PIN_BTN_MODE;

// MIDI constants
extern const int MID_VEL_DEFAULT;
extern const int MID_NOTE_DEFAULT;
extern const int MID_CHAN_RESET;
extern const int MID_CHAN_UNDO;
extern const int MID_CHAN_DEFAULT;

#endif
