#include <Arduino.h>
#include <MIDI.h>
#include <LdAdjustments.h>
#include <LdMidi.h>
#include <LdConst.h>
#include <LdValue.h>

struct MIDISettings : public midi::DefaultSettings {
    static const long BaudRate = SERIAL_BAUD_RATE;
};
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, MIDISettings);

LdMidi::LdMidi() {
    _lastNum = 1;
    _lastVal = 64;
    _values = new int[ADJ_LEN];
    Serial.begin(SERIAL_BAUD_RATE);
};

void LdMidi::begin(int *values) {
    _values = values;

    // Create MIDI instance
    MIDI.begin(MIDI_CHANNEL_OMNI);
}

void LdMidi::onControlChange(byte chan, byte num, byte val) {
    int choice = chan - 1;

    if (_values[choice] != val) {
        if (val < 0)
            _values[choice] = 0;
        else if (val > 127)
            _values[choice] = 127;
        else
            _values[choice] = val;
    }
};

void LdMidi::read() {
    if (MIDI.read()) {
        byte type = MIDI.getType();
        int d1 = MIDI.getData1(), d2 = MIDI.getData2();

        switch (type) {
            case midi::ControlChange:
                onControlChange(MIDI.getChannel(), d1, d2);
                //break;
            default:
                Serial.println("[mid] msg t=" + String(type)
                    + ", d1=" + String(d1) + ", d2=" + String(d2));
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
    long start = millis();
    MIDI.sendNoteOn(MID_NOTE_DEFAULT, MID_VEL_DEFAULT, chan);
    if (millis() - start > 1000)
        MIDI.sendNoteOff(MID_NOTE_DEFAULT, MID_VEL_DEFAULT, chan);
};
