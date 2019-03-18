#include "Arduino.h"
#include <LdAdj.h>

String ADJ[] = {
    // Must not exceed 16 characters
    "Temperature",
    "Tint",
    "Exposure",
    "Contrast",
    "Highlights",
    "Shadows",
    "Whites",
    "Blacks",
    "Clarity",
    "Dehaze",
    "Vibrance",
    "Saturation"
};

int ADJ_LEN = sizeof(ADJ) / sizeof(ADJ[0]);
