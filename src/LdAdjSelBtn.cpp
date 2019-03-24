#include <Arduino.h>
#include <Bounce2.h>
#include <LdAdjustments.h>
#include <LdAdjSelBtn.h>
#include <LdConst.h>

LdAdjSelBtn::LdAdjSelBtn() {
    // Store adjustments
    _choice = 0;
    _adj_len = ADJ_LEN;
    _adj = new String[ADJ_LEN];
    _adj = ADJ;

    // Init debouncer
    _debouncer = Bounce();
    _debouncer.attach(PIN_BTN_MODE, INPUT_PULLUP);
    _debouncer.interval(DEBOUNCE_INTERVAL);
};

String LdAdjSelBtn::monitor() {
    // Read current pin state
    _debouncer.update();

    // Switch mode if past debounce delay
    if (_debouncer.fell()) {
        _choice++;

        if (_choice >= _adj_len)
            _choice = 0;
    }

    return _adj[_choice];
};

void LdAdjSelBtn::setChoice(int choice) {
    _choice = choice;
}

int LdAdjSelBtn::getChoice() {
    return _choice;
};
