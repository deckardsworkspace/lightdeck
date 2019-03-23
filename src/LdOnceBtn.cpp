#include <Arduino.h>
#include <Bounce2.h>
#include <LdConst.h>
#include <LdOnceBtn.h>

LdOnceBtn::LdOnceBtn(int pin) {
    _debouncer = Bounce();
    _debouncer.attach(pin, INPUT_PULLUP);
    _debouncer.interval(DEBOUNCE_INTERVAL);
};

bool LdOnceBtn::monitor() {
    _debouncer.update();
    return _debouncer.fell();
};
