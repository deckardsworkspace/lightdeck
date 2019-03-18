#ifndef LD_RESET_BTN
#define LD_RESET_BTN

#include "Arduino.h"
#include "LdBtn.h"
#include "LdConst.h"

class LdResetBtn : public LdBtn {
public:
    LdResetBtn();
    bool monitor();
};

#endif
