#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class Morse{
public:
    Morse(int pin);
    void dot();
    void dash();
    void w_space();
    void c_space();
private:
    int _pin;
};

#endif
