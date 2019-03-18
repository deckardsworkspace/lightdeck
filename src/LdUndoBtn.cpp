#include "Arduino.h"
#include <Bounce2.h>
#include <LdConst.h>
#include <LdUndoBtn.h>

LdUndoBtn::LdUndoBtn() {
    _debouncer = Bounce();
    _debouncer.attach(PIN_BTN_UNDO, INPUT_PULLUP);
    _debouncer.interval(DEBOUNCE_INTERVAL);
};

bool LdUndoBtn::monitor() {
    _debouncer.update();
    if (_debouncer.fell())
        return true;
    return false;
};
