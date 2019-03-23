#ifndef LD_ADJ_SEL_BTN_H
#define LD_ADJ_SEL_BTN_H

#include "Arduino.h"
#include "LdBtn.h"

class LdAdjSelBtn : public LdBtn {
public:
    LdAdjSelBtn();
    String monitor();
    int getChoice();
    void setChoice(int choice);

private:
    // Selection
    String *_adj;
    unsigned int _adj_len, _choice;
};

#endif
