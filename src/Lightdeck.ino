/**
 * @file      Lightdeck.ino
 * @brief     yes
 * @author    Jared Dantis, 2019
 * @author    Ben Trew, 2018
 * @copyright GPLv3 (see README.md and LICENSE)
 */

#include <LdAdj.h>
#include <LdConst.h>
#include <LdDisplay.h>
#include <LdMidi.h>
#include <LdBtn.h>
#include <LdHoldBtn.h>

/**
 * Objects
 */
LdAdj value;                     ///< Adjustment values
LdDisplay disp;                  ///< LCD
LdMidi mid;                      ///< MIDI

/**
 * Buttons
 */
LdBtn nextAdjBtn(PIN_BTN_ADJUP); ///< Adjustment selection button 1
LdBtn prevAdjBtn(PIN_BTN_ADJDN); ///< Adjustment selection button 2
LdBtn undoBtn(PIN_BTN_UNDO);     ///< Undo adjustment button
LdHoldBtn decBtn(PIN_BTN_MINUS); ///< Adjustment decrement button
LdHoldBtn incBtn(PIN_BTN_PLUS);  ///< Adjustment increment button

void setup() {
    disp.welcome();
    mid.begin(value.getArray());
}

void loop() {
    mid.read();
    disp.updateAdj(value.getAdj());
    disp.updateValue(String(value.get(value.getChoice())));

    // Buttons
    decBtn.pressed(onDecBtnPressed);
    incBtn.pressed(onIncBtnPressed);
    if (prevAdjBtn.pressed()) value.prevAdj();
    if (nextAdjBtn.pressed()) value.nextAdj();
    if (undoBtn.pressed()) mid.sendNote(MID_CHAN_UNDO);
}

void onDecBtnPressed() {
    int num = value.getChoice();
    mid.sendControlChange(num, value.update(num, false));
}

void onIncBtnPressed() {
    int num = value.getChoice();
    mid.sendControlChange(num, value.update(num, true));
}
