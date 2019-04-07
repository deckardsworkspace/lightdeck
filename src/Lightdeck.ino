/**
 * @file      Lightdeck.ino
 * @brief     yes
 * @author    Jared Dantis, 2019
 * @author    Ben Trew, 2018
 * @copyright GPLv3 (see README.md and LICENSE)
 */

#include <LdAdj.h>
#include <LdConst.h>
#include <LdMidi.h>
#include <LdBtn.h>
#include <Rotary.h>

/**
 * Objects
 */
LdAdj adj;                     ///< Adjustment values
LdMidi mid;                      ///< MIDI

/**
 * Buttons
 */
LdBtn nextAdjBtn(PIN_BTN_ADJUP); ///< Adjustment selection button 1
LdBtn prevAdjBtn(PIN_BTN_ADJDN); ///< Adjustment selection button 2
LdBtn undoBtn(PIN_BTN_UNDO);     ///< Undo adjustment button

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
    // Buttons
    if (encReset.pressed()) onEncoderReset();
    if (prevAdjBtn.pressed()) adj.prevAdj();
    if (nextAdjBtn.pressed()) adj.nextAdj();
    if (undoBtn.pressed()) mid.sendNote(MID_CHAN_UNDO);
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
    mid.sendNote(num + 2);
}
