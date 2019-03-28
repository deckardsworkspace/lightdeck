#include <Arduino.h>
#include <MIDI.h>
#include <LdAdj.h>
#include <LdConst.h>
#include <LdMidi.h>

struct MIDISettings : public midi::DefaultSettings {
    static const long BaudRate = SERIAL_BAUD_RATE;
};
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MIDISettings);

LdMidi::LdMidi() {
    // stub
};

void LdMidi::begin() {
    // Create MIDI instance
    MIDI.begin(MIDI_CHANNEL_OMNI);
};

void LdMidi::sendAdjustment(int num, int val) {
    MIDI.sendControlChange(num, val, MID_CHAN_ADJ);
};

void LdMidi::sendNote(int chan) {
    MIDI.sendNoteOn(MID_NOTE_DEFAULT, MID_VEL_DEFAULT, chan);
    delay(NOTE_OFF_DELAY);
    MIDI.sendNoteOff(MID_NOTE_DEFAULT, MID_VEL_DEFAULT, chan);
};
