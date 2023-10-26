#include "Button.hpp"
#include <Arduino.h>

Button::Button(int pin) : pin(pin)
{
    pinMode(pin, INPUT_PULLUP);

    switchedOn = false;
    lastButton = true;
}

bool Button::readSensor(){
    return digitalRead(pin);
}

bool Button::isSystemSwitchedOn()
{
    bool button_not_pressed = readSensor();
    if (!button_not_pressed && lastButton != button_not_pressed)
    {
        switchedOn = !switchedOn;
        Serial.print("Switching system to: ");
        Serial.println(switchedOn);
    }
    lastButton = button_not_pressed;
    return switchedOn;
}
