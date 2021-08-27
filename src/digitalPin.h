#ifndef DIGITALPIN_H
#define DIGITALPIN_H

#include "Arduino.h"
#include <stdint.h>

/* 
 * A library to implement a digitalPin class for the Arduino IDE.
 * This class is designed only for the IDE, but can be used unchanged
 * by PlatformIO provided that the project using it, is using the 
 * Arduino Framework and has this defined in the platformio.ini file.
 * 
 * Norman Dunbar
 * 26 August 2021.
 */

class avrDigitalPin {

public:
    // Typedef for the pin modes.
    typedef enum pinMode : uint8_t {
        INPUT,
        INPUT_PULLUP,
        OUTPUT
    } pinMode_t;


    // Typedef for pin names. Covers Arduin and AVR naming.
    typedef enum pinName : uint8_t  {
        D0 = 0,
        D1,
        D2,
        D3,
        D4,
        D5,
        D6,
        D7,
        D8,
        D9,
        D10,
        D11,
        D12,
        D13,
        D14,
        D15,
        D16,
        D17,
        D18,
        D19,
        A0 = D14,
        A1,
        A2,
        A3,
        A4,
        A5,
        PD0 = D0,
        PD1,
        PD2,
        PD3,
        PD4,
        PD5,
        PD6,
        PD7,
        PC0 = A0,
        PC1,
        PC2,
        PC3,
        PC4,
        PC5,
        PB0 = D8,
        PB1,
        PB2,
        PB3,
        PB4,
        PB5
    } pinName_t;


    // Typedef for the pin states.
    typedef enum pinState : uint8_t {
        LOW = 0,
        HIGH
    } pinState_t;


    // Constructor.
    digitalPin(pinMode_t pinNumber,
               pinNames_t Mode);

    // There is no destructor as a digitalPin should never go out of scope.
    // Famous last words?


    // For Output digitalPins:
    void setState(uint8_t pinState);
    void toggleState();

    // For Input and Output Pins
    uint8_t getState();

private:

    // The Arduino pin number. This is 0 through 13,
    // A0 through A5 which can be referenced as 14
    // through 19 too.
    uint8_t _pinNumber;

    // Flag to indicate if this is an output pin.
    bool _isOutput;
};


#endif // DIGITALPIN_H