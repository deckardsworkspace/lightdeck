#ifndef LD_MIDI_H
#define LD_MIDI_H

#include <Arduino.h>

class LdMidi {
public:
    LdMidi();
    void begin();
    void read();
    void sendAdjustment(int, int);
    void sendNote(int, int);
};

#endif
