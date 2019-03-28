#include <Arduino.h>
#include <LdAdj.h>
#include <LdConst.h>

String ADJ[] = {
    // Must not exceed 14 characters
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

String LdAdj::getNextStr() {
    if (_choice == ADJ_LEN - 1)
        return ADJ[0].substring(0, 4);
    return ADJ[_choice + 1].substring(0, 4);
};

String LdAdj::getPrevStr() {
    if (_choice == 0)
        return ADJ[ADJ_LEN - 1].substring(0, 4);
    return ADJ[_choice - 1].substring(0, 4);
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
