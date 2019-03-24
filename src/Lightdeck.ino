/**
 * @file      Lightdeck.ino
 * @brief     yes
 * @author    Jared Dantis, 2019
 * @author    Ben Trew, 2018
 * @copyright GPLv3 (see README.md and LICENSE)
 */

#include <LdAdjustments.h>
#include <LdAdjSelBtn.h>
#include <LdConst.h>
#include <LdDisplay.h>
#include <LdMidi.h>
#include <LdOnceBtn.h>
#include <LdValue.h>

/**
 * Objects
 */
LdMidi mid;            ///< MIDI
LdDisplay disp;        ///< LCD
LdValue value;         ///< Adjustment buttons/encoders
LdAdjSelBtn adjBtn;    ///< Adjustment selection button
LdOnceBtn rstBtn(PIN_BTN_RESET);     ///< Reset adjustments button
LdOnceBtn undoBtn(PIN_BTN_UNDO);     ///< Undo adjustment button

void setup() {
    disp.welcome();
    mid.begin(value.getArray());
}

void loop() {
    mid.read();
    int num = adjBtn.getChoice(),
        val = value.update(num);

    mid.sendControlChange(num, val);
    disp.updateAdj(adjBtn.monitor());
    disp.updateValue(String(val));

    if (rstBtn.monitor()) {
        value.reset();
        mid.sendNote(MID_CHAN_RESET);
    }
    if (undoBtn.monitor()) mid.sendNote(MID_CHAN_UNDO);
}
