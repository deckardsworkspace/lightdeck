#include <Arduino.h>
#include <LdAdjustments.h>

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

unsigned int ADJ_LEN = sizeof(ADJ) / sizeof(ADJ[0]);
