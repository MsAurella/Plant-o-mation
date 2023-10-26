#pragma once

class Button
{
public:
    Button(int pin);
    bool isSystemSwitchedOn();
    bool readSensor();

private:
    int pin;
    bool switchedOn;
    bool lastButton;
};
