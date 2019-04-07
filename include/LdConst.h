#ifndef LD_CONST_H
#define LD_CONST_H

#include <Arduino.h>

// Baud rate for Serial and MIDI
#define SERIAL_BAUD_RATE 115200

// Duration for debouncing button inputs
#define DEBOUNCE_INTERVAL 50

// Time to wait before activating a button hold event
#define HOLD_DELAY 500

// Interval between repeats from a held button
#define HOLD_INTERVAL 50

// Time to wait before sending a NoteOff
#define NOTE_OFF_DELAY 100

// Encoder pins
#define PIN_ENC_SW 8
#define PIN_ENC_DT 9
#define PIN_ENC_CLK 10

// Button pins
#define PIN_BTN_ADJDN 11
#define PIN_BTN_ADJUP 12
#define PIN_BTN_UNDO 13

// MIDI constants
#define MID_VEL_DEFAULT 64
#define MID_NOTE_DEFAULT 127
#define MID_CHAN_UNDO 1
#define MID_CHAN_ADJ 2

#endif
