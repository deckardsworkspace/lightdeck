#include <Arduino.h>
#include <LdAdj.h>
#include <LdConst.h>

String ADJ[] = {
    // Must not exceed 14 characters
    "Temperature",
    "Tint",
    "Exposure",
    "Contrast",
    "Highlights",
    "Shadows",
    "Whites",
    "Blacks",
    "Clarity",
    "Dehaze",
    "Vibrance",
    "Saturation"
};

int ADJ_LEN = sizeof(ADJ) / sizeof(ADJ[0]);

LdAdj::LdAdj() {
    // Init pos array to middle of MIDI range
    _values = new int[ADJ_LEN];
    for (int i = 0; i < ADJ_LEN; i++)
        _values[i] = 64;
};

String LdAdj::getString() {
    return ADJ[_choice];
};

int LdAdj::getNum() {
    return _choice;
};

void LdAdj::prevAdj() {
    _choice--;
    if (_choice <= 0)
        _choice = ADJ_LEN - 1;
};

void LdAdj::nextAdj() {
    _choice++;
    if (_choice >= ADJ_LEN)
        _choice = 0;
};
