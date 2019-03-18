#ifndef LD_UNDO_BTN
#define LD_UNDO_BTN

#include "Arduino.h"
#include "LdBtn.h"
#include "LdConst.h"

class LdUndoBtn : public LdBtn {
public:
    LdUndoBtn();
    bool monitor();
};

#endif
