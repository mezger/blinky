#include "Blinky.h" 

void Blinky::setupLed(byte pin)
{
  pinMode(pin, OUTPUT);
  _led[_ledCount]=pin;
  _interval[_ledCount] = 0;
  _previousMillis[_ledCount] = 0;
  _firstBlink[_ledCount] = true;
  _ledState[_ledCount] = LOW;
  _ledCount++;
}


void Blinky::blink()
{
    if(_active)
    {
        unsigned long currentMillis = millis();
        
        for (int i = 0; i < _ledCount; i++) 
        {
            if (currentMillis - _previousMillis[i] > _interval[i]) 
            {
            _previousMillis[i] = currentMillis;   //save current time
        
            // toggle LED state
            _ledState[i] = !_ledState[i];
        
            // set interval from random values every time
            if(_ledState[i])
            {
                //duration ON
                _interval[i] = random(60,80);
            }
            else
            {
                //duration OFF
                if(_firstBlink[i])
                {
                _interval[i] = random(50,90);
                }
                else
                {
                _interval[i] = random(310,550);
                }
                _firstBlink[i] = !_firstBlink[i];
            }
        
            //write state to output pin
            digitalWrite(_led[i], _ledState[i]);
            }
        }
    }
}


void Blinky::on()
{
    _active = true;
}


void Blinky::off()
{
    _active = false;
    for (int i = 0; i < _ledCount; i++) 
    {  
        _interval[i] = 0;
        _previousMillis[i] = 0;
        _firstBlink[i] = true;
        _ledState[i] = LOW;
        digitalWrite(_led[i], _ledState[i]);
    }
}
