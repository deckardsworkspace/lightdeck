/**
 * @file      Lightdeck.ino
 * @brief     yes
 * @author    Jared Dantis, 2019
 * @author    Ben Trew, 2018
 * @copyright GPLv3 (see README.md and LICENSE)
 */

#include <LdAdj.h>
#include <LdAdjSelBtn.h>
#include <LdConst.h>
#include <LdDisplay.h>
#include <LdMidi.h>
#include <LdResetBtn.h>
#include <LdUndoBtn.h>
#include <LdValue.h>

LdMidi mid;            ///< MIDI communication
LdDisplay disp;        ///< LCD
LdAdjSelBtn adjBtn;    ///< Function selection button
LdResetBtn rstBtn;     ///< Reset adjustments button
LdUndoBtn undoBtn;     ///< Undo adjustment button
LdValue value;         ///< Adjustment buttons/encoders

void onRcvCC(byte chan, byte num, byte val) {
    Serial.print("Received: ");
    Serial.print(chan);
    Serial.print(num);
    Serial.println(val);
    value.set(chan - 1, val);
};

void onReset() {
    for (int i = 0; i < ADJ_LEN; i++)
        value.reset(i);
};

void setup() {
    Serial.begin(115200);
    mid.begin(onRcvCC, onReset);
    disp.welcome();
}

void loop() {
    int choice = adjBtn.getChoice(),
        val = value.update(choice);

    // TODO - fix MIDI spam
    // mid.read();
    mid.sendMsg(choice, val);

    disp.update(adjBtn.monitor());
    disp.updateValue(String(val));

    if (rstBtn.monitor())
        mid.sendNote(MID_CHAN_RESET);

    if (undoBtn.monitor())
        mid.sendNote(MID_CHAN_UNDO);
}
