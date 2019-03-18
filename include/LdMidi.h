#ifndef LD_MIDI_H
#define LD_MIDI_H

#include "Arduino.h"
#include <MIDI.h>

class LdMidi {
public:
    LdMidi();
    void begin(void onCC(byte, byte, byte), void onSR(void));
    void read();
    void sendMsg(int choice, int val);
    void sendNote(int chan);

private:
    int _num, _val, _chan;
    struct MIDISettings;
};

#endif
