#ifndef LD_ONCE_BTN
#define LD_ONCE_BTN

#include "Arduino.h"
#include "LdBtn.h"
#include "LdConst.h"

class LdOnceBtn : public LdBtn {
public:
    LdOnceBtn(int pin);
    bool monitor();
};

#endif