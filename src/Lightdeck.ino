/**
 * @file      Lightdeck.ino
 * @brief     yes
 * @author    Jared Dantis, 2019
 * @author    Ben Trew, 2018
 * @copyright GPLv3 (see README.md and LICENSE)
 */

#include <MIDI.h>
#include <LdAdjustments.h>
#include <LdAdjSelBtn.h>
#include <LdConst.h>
#include <LdDisplay.h>
#include <LdOnceBtn.h>
#include <LdValue.h>

/**
 * Objects
 */
LdDisplay disp;        ///< LCD
LdValue value;         ///< Adjustment buttons/encoders
LdAdjSelBtn adjBtn;    ///< Adjustment selection button
LdOnceBtn rstBtn(PIN_BTN_RESET);     ///< Reset adjustments button
LdOnceBtn undoBtn(PIN_BTN_UNDO);     ///< Undo adjustment button

struct MIDISettings : public midi::DefaultSettings {
    static const long BaudRate = 115200;
};
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MIDISettings);

void setup() {
    MIDI.begin(MIDI_CHANNEL_OMNI);
    MIDI.setHandleControlChange(onControlChange);
    MIDI.setHandleSystemReset(onSystemReset);
    disp.welcome();
}

void loop() {
    MIDI.read();
    int choice = adjBtn.getChoice(),
        val = value.update(choice);

    sendCtrlChange(choice, val);
    disp.updateAdj(adjBtn.monitor());
    disp.updateValue(String(val));

    if (rstBtn.monitor()) sendNote(MID_CHAN_RESET);
    if (undoBtn.monitor()) sendNote(MID_CHAN_UNDO);
}

/***** Begin MIDI logic *****/
int _ctrl = 1, _val = 64;

void sendCtrlChange(int choice, int val) {
    if (!(_val == val && _ctrl == (choice + 1))) {
        _ctrl = choice + 1;
        _val = val;
        MIDI.sendControlChange(_ctrl, _val, MID_CHAN_DEFAULT);
    }
}

void sendNote(int chan) {
    long start = millis();
    MIDI.sendNoteOn(MID_NOTE_DEFAULT, MID_VEL_DEFAULT, chan);
    if (millis() - start > 1000)
        MIDI.sendNoteOff(MID_NOTE_DEFAULT, MID_VEL_DEFAULT, chan);
}

void onControlChange(byte chan, byte num, byte val) {
    int choice = chan - 1;

    if (adjBtn.getChoice() != choice || value.get(choice) != val) {
        value.set(choice, val);
        adjBtn.setChoice(choice);
    }
}

void onSystemReset() {
    value.reset();
}
