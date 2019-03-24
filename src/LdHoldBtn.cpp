#include <Arduino.h>
#include <Bounce2.h>
#include <LdConst.h>
#include <LdHoldBtn.h>

void LdHoldBtn::monitor(void(*f)(void)) {
    _debouncer.update();
    bool isHeld = _debouncer.read() == HIGH && _debouncer.duration() > HOLD_DELAY;
    if (_debouncer.fell() || isHeld) {
        f();
        if (isHeld) delay(HOLD_INTERVAL);
    }
};
