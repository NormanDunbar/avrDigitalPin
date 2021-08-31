/*
 * Example sketch using the "avrDigitalPins" library.
 * 
 * Norman Dunbar
 * 26 August 2021.
 */

// Include the library header.
#include "avrDigitalPin.h"

// Create a digitalPin connected to the built in LED
// and configure it as output.
avrDigitalPin ledPin(pinD13, pinOUTPUT);

void setup() {
    // No setup specifically required, but quick
    // flash the LED a couple of times "manually".
    for (byte x = 0; x < 5; x++) {
        ledPin.setState(pinHIGH);
        delay(250);
        ledPin.setState(pinLOW);
        delay(100);
    }

    // Delay before starting the loop.
    delay(1500);
}

void loop() {
    // Flash the pin every second.
    ledPin.toggleState();
    delay(1000);
}

