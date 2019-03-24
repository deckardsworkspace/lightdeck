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
    _lastNum = 1;
    _lastVal = 64;
    _values = new int[ADJ_LEN];
};

void LdMidi::begin(int *values) {
    _values = values;

    // Create MIDI instance
    MIDI.begin(MIDI_CHANNEL_OMNI);
};

void LdMidi::onControlChange(byte chan, byte num, byte val) {
    if (_values[chan] != val) {
        if (val < 0)
            _values[chan] = 0;
        else if (val > 127)
            _values[chan] = 127;
        else
            _values[chan] = val;
    }
};

void LdMidi::read() {
    if (MIDI.read()) {
        byte type = MIDI.getType();
        int d1 = MIDI.getData1(), d2 = MIDI.getData2();

        switch (type) {
            case midi::ControlChange:
                onControlChange(MIDI.getChannel(), d1, d2);
                break;
        }
    }
};

void LdMidi::sendControlChange(int num, int val) {
    if (!(_lastNum == num && _lastVal == val)) {
        _lastNum = num;
        _lastVal = val;
        MIDI.sendControlChange(num, val, MID_CHAN_DEFAULT);
    }
};

void LdMidi::sendNote(int chan) {
    MIDI.sendNoteOn(MID_NOTE_DEFAULT, MID_VEL_DEFAULT, chan);
    delay(NOTE_OFF_DELAY);
    MIDI.sendNoteOff(MID_NOTE_DEFAULT, MID_VEL_DEFAULT, chan);
};
