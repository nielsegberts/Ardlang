#include "pins_arduino.h"

int randomLed() {
    return random(2,10);
}

int randomState() {
    return random(0,2);
}
