#include <Arduino.h>
#include <Bounce2.h>
#include <LdBtn.h>
#include <LdConst.h>

LdBtn::LdBtn(int pin) {
    _debouncer = Bounce();
    _debouncer.attach(pin, INPUT_PULLUP);
    _debouncer.interval(DEBOUNCE_INTERVAL);
    _onHoldFired = false;
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
            if (!_onHoldFired) {
                onHold();
                _onHoldFired = true;
            }
        } else {
            onPress();
            _onHoldFired = false;
        }
    }
};
