#include "Plant.hpp"
#include <Arduino.h>

Plant::Plant(std::string name,
             UnderWaterPump &pump,
             CapacitiveSoilMoistureSensor &moistureSensor) : name(name), pump(pump), moistureSensor(moistureSensor), minimalMoisturePercentage(40) {}

bool Plant::needsWatering()
{
    auto moisturePercentage = moistureSensor.getMoisturePercentage();
    return (moisturePercentage < minimalMoisturePercentage);
}

void Plant::turnWateringOn()
{
    if (!pump.isPumpOn())
    {
        Serial.println(("Plant " + name + " switches the pump ON, DDOOOORRRRSSTTTTT!!!!!").c_str());
        pump.on();
    }
}
void Plant::turnWateringOff()
{
    if (pump.isPumpOn())
    {
        Serial.println(("Plant " + name + " switches the pump OFF, ground is sufficently saturated.").c_str());
        pump.off();
    }
}
