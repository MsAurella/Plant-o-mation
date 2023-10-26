// testing
#include <Arduino.h>
#include "CapacitiveSoilMoistureSensorv2.0.hpp"
#include "UnderWaterPump.hpp"
#include "Button.hpp"
#include "Plant.hpp"
#include <vector>

#define ANALOG_READ_MOISTURE 36
#define MOISTURE_MIN 1000 // wet
#define MOISTURE_MAX 3000 // dry

#define DIGITAL_WRITE_PUMP 4

#define DIGITAL_IN_BUTTON 27

auto moistureSensor = CapacitiveSoilMoistureSensor(ANALOG_READ_MOISTURE, MOISTURE_MIN, MOISTURE_MAX);
auto pump = UnderWaterPump(DIGITAL_WRITE_PUMP);
auto button = Button(DIGITAL_IN_BUTTON);

auto Linsey = Plant("Linsey", pump, moistureSensor);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    if (button.isSystemSwitchedOn())
    {
        Linsey.waterIfRequired();
    }
    else
    {
        Linsey.shutDown();
    }
    delay(100);
}
