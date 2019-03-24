#include <Arduino.h>
#include <Bounce2.h>
#include <LdAdjustments.h>
#include <LdConst.h>
#include <LdValue.h>

LdValue::LdValue() {
    _choice = 0;
    _adj_len = ADJ_LEN;

    // Init buttons
    _deb_dec = Bounce();
    _deb_inc = Bounce();
    _deb_dec.attach(PIN_BTN_MINUS, INPUT_PULLUP);
    _deb_inc.attach(PIN_BTN_PLUS, INPUT_PULLUP);
    _deb_dec.interval(DEBOUNCE_INTERVAL);
    _deb_inc.interval(DEBOUNCE_INTERVAL);

    // Init pos array to middle of MIDI range
    _pos = new int[_adj_len];
    for (int i = 0; i < _adj_len; i++)
        _pos[i] = 64;
};

void LdValue::reset() {
    for (unsigned int i = 0; i < sizeof(_pos); i++)
        _pos[i] = 64;
};

int *LdValue::getArray() {
    return _pos;
};

int LdValue::update(int choice) {
    // Check if new adjustment type
    if (_choice != choice) {
        _choice = choice;
    }

    // Update left button (-) state
    _deb_dec.update();
    bool holdDec = _deb_dec.read() == HIGH && _deb_dec.duration() > HOLD_DELAY;
    if (_deb_dec.fell() || holdDec) {
        _pos[_choice]--;
        if (holdDec)
            delay(HOLD_INTERVAL);

        if (_pos[_choice] <= 0)
            _pos[_choice] = 0;
    }

    // Update right button (+) state
    _deb_inc.update();
    bool holdInc = _deb_inc.read() == HIGH && _deb_inc.duration() > HOLD_DELAY;
    if (_deb_inc.fell() || holdInc) {
        _pos[_choice]++;
        if (holdInc)
            delay(HOLD_INTERVAL);

        if (_pos[_choice] >= 127)
            _pos[_choice] = 127;
    }

    // Return new value
    return _pos[_choice];
};
