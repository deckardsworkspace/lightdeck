/**
 * @file      Lightdeck.cpp
 * @brief     Main Lightdeck sketch file (contains setup() and loop())
 * @author    Jared Dantis, 2019
 * @author    Ben Trew, 2018
 * @copyright GPLv3 (see README.md and LICENSE)
 */

#include <Arduino.h>
#include <LdAdj.h>
#include <LdBtn.h>
#include <LdConst.h>
#include <LdMidi.h>
#include <Rotary.h>

/**
 * Functions
 */
void onEncoderRotate();
void onEncoderReset();

/**
 * Objects
 */
LdAdj adj;                       ///< Adjustment matrix
LdMidi mid;                      ///< MIDI communication

/**
 * Buttons
 */
LdBtn prevBtn(PIN_BTN_PREV);     ///< Prev photo button
LdBtn nextBtn(PIN_BTN_NEXT);     ///< Next photo button
LdBtn flagBtn(PIN_BTN_FLAG);     ///< Flag photo button
LdBtn undoBtn(PIN_BTN_UNDO);     ///< Undo button

/**
 * Rotary encoder
 */
LdBtn encReset(PIN_ENC_SW);      ///< Click button
Rotary* encoder;

void setup() {
    mid.begin();

    // Init encoder
    encoder = new Rotary(PIN_ENC_CLK, PIN_ENC_DT);
    attachInterrupt(0, onEncoderRotate, CHANGE);
    attachInterrupt(1, onEncoderRotate, CHANGE);
}

void loop() {
    // Current adjustment
    adj.update();

    // Buttons
    if (prevBtn.pressed()) mid.sendNote(MID_CHAN_PREV, MID_NOTE_ADJRESET);
    if (nextBtn.pressed()) mid.sendNote(MID_CHAN_NEXT, MID_NOTE_ADJRESET);
    if (flagBtn.pressed()) mid.sendNote(MID_CHAN_FLAG, MID_NOTE_ADJRESET);
    if (undoBtn.pressed()) mid.sendNote(MID_CHAN_UNDO, MID_NOTE_ADJRESET);
    if (encReset.pressed()) onEncoderReset();
}

void onEncoderRotate() {
    int num = adj.getNum();
    unsigned char result = encoder -> process();

    if (result == DIR_CW)
        mid.sendAdjustment(num, 127);  // Increment on clockwise
    else if (result == DIR_CCW)
        mid.sendAdjustment(num, 1);    // Decrement on counterclockwise
}

void onEncoderReset() {
    int num = adj.getNum();
    mid.sendNote(num + 2, MID_NOTE_ENCRESET);
}
