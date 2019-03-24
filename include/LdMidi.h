#ifndef LD_MIDI_H
#define LD_MIDI_H

#include <Arduino.h>
#include <LdValue.h>

class LdMidi {
public:
    LdMidi();
    void begin(int*);
    void read();
    void sendControlChange(int, int);
    void sendNote(int);

private:
    int _lastNum, _lastVal, *_values;
    void onControlChange(byte, byte, byte);
};

#endif
