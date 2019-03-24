#include <Arduino.h>
#include <MIDI.h>
#include <LdAdjustments.h>
#include <LdMidi.h>
#include <LdConst.h>
#include <LdValue.h>

struct MIDISettings : public midi::DefaultSettings {
    static const long BaudRate = 115200;
};
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MIDISettings);

int *LdMidi::_values = new int[ADJ_LEN];

LdMidi::LdMidi() {
    _ctrl = 1;
    _val = 64;
};

void LdMidi::begin(int *values) {
    _values = values;

    // Create MIDI instance
    MIDI.begin(MIDI_CHANNEL_OMNI);
    MIDI.setHandleControlChange(onControlChange);
}

void LdMidi::onControlChange(byte chan, byte num, byte val) {
    int choice = chan - 1;

    if (_values[choice] != val)
        _values[choice] = val;
};

void LdMidi::read() {
    MIDI.read();
};

void LdMidi::sendControlChange(int choice, int val) {
    if (!(_val == val && _ctrl == (choice + 1))) {
        _ctrl = choice + 1;
        _val = val;
        MIDI.sendControlChange(_ctrl, _val, MID_CHAN_DEFAULT);
    }
};

void LdMidi::sendNote(int chan) {
    long start = millis();
    MIDI.sendNoteOn(MID_NOTE_DEFAULT, MID_VEL_DEFAULT, chan);
    if (millis() - start > 1000)
        MIDI.sendNoteOff(MID_NOTE_DEFAULT, MID_VEL_DEFAULT, chan);
};
