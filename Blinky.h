#ifndef BLINKY_H
#define BLINKY_H

#include <Arduino.h>
 
class Blinky 
{
    public:
        Blinky();
        void setupLed(byte pin);
        void blink();
    
    private:
        static const byte _maxLeds = 10; //max number of pins that can be configured for blinking LEDs
        byte _led[_maxLeds]; //pins that were configured for blinking LEDs
        byte _ledCount = 0; //how many LEDs are configured
        unsigned int _interval[_maxLeds]; //duration of the next on- or off-phase
        unsigned long _previousMillis[_maxLeds]; //timestamp when state of LED was changed the last time
        boolean _firstBlink[_maxLeds]; //true if it is this the first on-phase, false if it is the second
        boolean _ledState[_maxLeds]; //is the LED LOW (off) or HIGH (on)
};

#endif
 
