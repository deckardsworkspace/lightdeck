#include "Arduino.h"
#include <LdAdj.h>
#include <LdConst.h>
#include <LdMidi.h>
#include <LdValue.h>
#include <MIDI.h>

struct MIDISettings : public midi::DefaultSettings {
    static const long BaudRate = 115200;
};
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MIDISettings);

LdMidi::LdMidi() {
    _num = 70;
    _val = 64;
    _chan = 1;
};

void LdMidi::begin(void onCC(byte, byte, byte), void onSR(void)) {
    MIDI.begin(MIDI_CHANNEL_OMNI);
    MIDI.setHandleControlChange(onCC);
    MIDI.setHandleSystemReset(onSR);
};

void LdMidi::read() {
    MIDI.read();
};

void LdMidi::sendMsg(int choice, int val) {
    if (!((_val == val) && (_chan == choice + 1))) {
        _num = choice + 70;
        _val = val;
        _chan = choice + 1;
        MIDI.sendControlChange(_num, _val, _chan);
    }
};

void LdMidi::sendNote(int chan) {
    MIDI.sendNoteOn(MID_NOTE_DEFAULT, MID_VEL_DEFAULT, chan);
};
