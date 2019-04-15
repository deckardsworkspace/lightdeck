#include <Arduino.h>
#include <Bounce2.h>
#include <LdBtn.h>
#include <LdConst.h>

LdBtn::LdBtn(int pin) {
    _debouncer = Bounce();
    _debouncer.attach(pin, INPUT_PULLUP);
    _debouncer.interval(DEBOUNCE_INTERVAL);
};

bool LdBtn::pressed() {
    _debouncer.update();
    return _debouncer.fell();
};

void LdBtn::pressed(void(*onPress)(void), void(*onHold)(void)) {
    _debouncer.update();
    bool isHeld = _debouncer.read() == LOW && _debouncer.duration() > HOLD_DELAY;
    if (_debouncer.fell() || isHeld) {
        if (isHeld) {
            onHold();
            delay(HOLD_INTERVAL);
        } else
            onPress();
    }
};
