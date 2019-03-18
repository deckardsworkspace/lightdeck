#include "Arduino.h"
#include <Bounce2.h>
#include <LdConst.h>
#include <LdResetBtn.h>

LdResetBtn::LdResetBtn() {
    _debouncer = Bounce();
    _debouncer.attach(PIN_BTN_RESET, INPUT_PULLUP);
    _debouncer.interval(DEBOUNCE_INTERVAL);
};

bool LdResetBtn::monitor() {
    _debouncer.update();
    if (_debouncer.fell())
        return true;
    return false;
};
