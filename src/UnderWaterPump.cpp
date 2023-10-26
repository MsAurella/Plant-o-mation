#include "UnderWaterPump.hpp"
#include <Arduino.h>

UnderWaterPump::UnderWaterPump(int pin) : pin(pin), pumpState(PumpState::OFF)
{
    pinMode(pin, OUTPUT);
}

void UnderWaterPump::on()
{
    // todo assert pin is set
    digitalWrite(pin, HIGH);
    pumpState = PumpState::ON;
}

void UnderWaterPump::off()
{
    // todo assert pin is set
    digitalWrite(pin, LOW);
    pumpState = PumpState::OFF;
}

bool UnderWaterPump::isPumpOn() const{
    if (pumpState== PumpState::ON){
        return true;
    } else if (pumpState== PumpState::OFF){
        return false;
    }
    //todo check no third state
    return false;
}
