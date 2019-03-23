/**
 * @file      Lightdeck.ino
 * @brief     yes
 * @author    Jared Dantis, 2019
 * @author    Ben Trew, 2018
 * @copyright GPLv3 (see README.md and LICENSE)
 */

#include <MIDI.h>
#include <LdAdj.h>
#include <LdAdjSelBtn.h>
#include <LdConst.h>
#include <LdDisplay.h>
#include <LdResetBtn.h>
#include <LdUndoBtn.h>
#include <LdValue.h>

LdDisplay disp;        ///< LCD
LdAdjSelBtn adjBtn;    ///< Function selection button
LdResetBtn rstBtn;     ///< Reset adjustments button
LdUndoBtn undoBtn;     ///< Undo adjustment button
LdValue value;         ///< Adjustment buttons/encoders

const long SERIAL_BAUD = 115200;

struct MIDISettings : public midi::DefaultSettings {
    static const long BaudRate = SERIAL_BAUD;
};
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MIDISettings);

void setup() {
    Serial.begin(SERIAL_BAUD);
    MIDI.begin(MIDI_CHANNEL_OMNI);
    MIDI.setHandleControlChange(onControlChange);
    MIDI.setHandleSystemReset(onSystemReset);
    disp.welcome();
}

int lastChoice, lastVal;

void loop() {
    int _choice = adjBtn.getChoice(),
        _value = value.update(_choice);

    if (_choice != lastChoice || _value != lastVal) {
        lastChoice = _choice;
        lastVal = _value;
        sendCtrlChange(lastChoice, lastVal);
    }

    MIDI.read(MIDI_CHANNEL_OMNI);
    disp.updateAdj(adjBtn.monitor());
    disp.updateValue(String(lastVal));

    if (rstBtn.monitor())
        sendNote(MID_CHAN_RESET);

    if (undoBtn.monitor())
        sendNote(MID_CHAN_UNDO);
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
