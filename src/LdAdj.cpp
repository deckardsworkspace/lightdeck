#include <Arduino.h>
#include <LdAdj.h>
#include <LdBtn.h>
#include <LdConst.h>

LdAdj::LdAdj() {
    _choice = 0;

    // Init button objects
    _btns = new LdBtn[ADJ_NUM] {11, 9, 7, 5, 12, 10, 8, 6};
};

int LdAdj::getNum() {
    return _choice;
};

void LdAdj::update() {
    for (int i = 0; i < ADJ_NUM; i++) {
        if (_btns[i].pressed())
            _choice = i;
    }
};
