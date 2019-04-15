#ifndef LD_CONST_H
#define LD_CONST_H

#include <Arduino.h>

// Number of available adjustments
#define ADJ_NUM           8

/**
 * Button handling
 */

// Duration for debouncing button inputs
#define DEBOUNCE_INTERVAL 50

// Time to wait before activating a button hold event
#define HOLD_DELAY       500

// Interval between repeats from a held button
#define HOLD_INTERVAL    50

// Time to wait before sending a NoteOff
#define NOTE_OFF_DELAY   100


/**
 * MIDI & serial
 */

// Baud rate for Serial and MIDI
#define SERIAL_BAUD_RATE 115200

// MIDI constants
#define MID_VEL_DEFAULT   64
#define MID_NOTE_DEFAULT  64
#define MID_NOTE_ENCRESET 127

// MIDI channels
#define MID_CHAN_ADJ     1
#define MID_CHAN_PREV    2
#define MID_CHAN_NEXT    3
#define MID_CHAN_FLAG    4
#define MID_CHAN_UNDO    5
#define MID_CHAN_RESET   6


/**
 * Pins
 */

// Function buttons
#define PIN_BTN_PREV     A0
#define PIN_BTN_NEXT     A2
#define PIN_BTN_FLAG     A4
#define PIN_BTN_UNDO     A5

// Rotary encoder
#define PIN_ENC_DT       2
#define PIN_ENC_CLK      3
#define PIN_ENC_SW       4

#endif
