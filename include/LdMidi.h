#ifndef LD_MIDI_H
#define LD_MIDI_H

#include <Arduino.h>
#include <LdValue.h>

class LdMidi {
public:
    LdMidi();
    void begin(int*);
    static void onControlChange(byte, byte, byte);
    void read();
    void sendControlChange(int, int);
    void sendNote(int);

private:
    int _ctrl, _val;
    static int *_values;
};

#endif
