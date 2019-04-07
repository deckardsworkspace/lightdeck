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

/**
 * Objects
 */
LdAdj adj;                     ///< Adjustment values
LdDisplay disp;                  ///< LCD
LdMidi mid;                      ///< MIDI

/**
 * Buttons
 */
LdBtn nextAdjBtn(PIN_BTN_ADJUP); ///< Adjustment selection button 1
LdBtn prevAdjBtn(PIN_BTN_ADJDN); ///< Adjustment selection button 2
LdBtn undoBtn(PIN_BTN_UNDO);     ///< Undo adjustment button

void setup() {
    disp.welcome();
    mid.begin();
}

void loop() {
    disp.update(adj.getString(), adj.getPrevStr(), adj.getNextStr());

    // Buttons
    if (prevAdjBtn.pressed()) adj.prevAdj();
    if (nextAdjBtn.pressed()) adj.nextAdj();
    if (undoBtn.pressed()) mid.sendNote(MID_CHAN_UNDO);
}
