#include <Arduino.h>
#include <LdAdj.h>
#include <LdConst.h>

String ADJ[] = {
    // Must not exceed 16 characters
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

int LdAdj::get(int i) {
    return _values[i];
};

String LdAdj::getAdj() {
    return ADJ[_choice];
};

int LdAdj::getChoice() {
    return _choice;
};

int *LdAdj::getArray() {
    return _values;
};

void LdAdj::nextAdj() {
    _choice++;
    if (_choice >= ADJ_LEN)
        _choice = 0;
};

void LdAdj::reset() {
    for (unsigned int i = 0; i < sizeof(_values); i++)
        _values[i] = 64;
};

int LdAdj::update(int choice, bool direction) {
    if (_choice != choice)
        _choice = choice;

    // Increment or decrement based on direction
    if (direction) {
        _values[choice]++;
        if (_values[choice] >= 127)
            _values[choice] = 127;
    } else {
        _values[choice]--;
        if (_values[choice] <= 0)
            _values[choice] = 0;
    }

    // Return new value
    return _values[choice];
};
