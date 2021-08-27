#include "avrDigitalPin.h"


// Constructor
avrDigitalPin::avrDigitalPin(pinName_t pinNumber,
                       pinMode_t Mode)
    : _pinNumber(pinNumber),
      _isOutput(false)
{
    // Update the output pin flag.
    if (Mode == avrDigitalPin::OUTPUT)
        _isOutput = true;

    // Configure the pin.
    pinMode(pinNumber, avrDigitalPin::Mode);
}                       


// For Output digitalPins:

// Set the pin state to high or low.
void avrDigitalPin::setState(uint8_t pinState)
{
    if (_isOutput)
        digitalWrite(_pinNumber, pinState);
}


// Toggle the current pin state.
void avrDigitalPin::toggleState()
{
    if (_isOutput)
        digitalWrite(_pinNumber, !digitalRead(_pinNumber));
}


// For Input and Output Pins.

// Read the pin state.
uint8_t avrDigitalPin::getState()
{
    return digitalRead(_pinNumber);
}
