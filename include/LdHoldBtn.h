#ifndef LD_HOLD_BTN_H
#define LD_HOLD_BTN_H

#include <Arduino.h>
#include <LdBtn.h>

class LdHoldBtn : public LdBtn {
public:
    LdHoldBtn(int pin) : LdBtn(pin) {};
    void monitor(void(*f)(void));
};

#endif
