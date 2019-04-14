#include <Arduino.h>
#include <MIDI.h>
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

void LdMidi::sendNote(int chan, int note) {
    MIDI.sendNoteOn(note, MID_VEL_DEFAULT, chan);
    delay(NOTE_OFF_DELAY);
    MIDI.sendNoteOff(note, MID_VEL_DEFAULT, chan);
};
