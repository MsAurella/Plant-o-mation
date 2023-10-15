#include "UnderWaterPump.hpp"
#include <Arduino.h>

UnderWaterPump::UnderWaterPump(int pin) : pin(pin)
{
    pinMode (pin, OUTPUT);
}

void UnderWaterPump::on()
{
    // todo assert pin is set
    digitalWrite(pin, HIGH);
}

void UnderWaterPump::off(){
    // todo assert pin is set
    digitalWrite(pin, LOW);
}


