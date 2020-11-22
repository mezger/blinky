#include "Blinky.h"
Blinky blinky = Blinky();

void setup() {
  //setup builtin LED for blinky
  blinky.setupLed(LED_BUILTIN);
  //you can setup up to 10 pins for blinky
  //blinky.setupLed(5);
  //blinky.setupLed(7);

  //use noise on unconnected pin 0 to initialize random generator
  randomSeed(analogRead(0));
  
  blinky.on();
}

void loop() {
  //blink forever
  blinky.blink();
}

