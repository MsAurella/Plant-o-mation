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

// auto Linsey = Plant();
// std::vector<Plant> familie; 

void setup()
{
    Serial.begin(9600);
    // pinMode(27, INPUT_PULLUP);
    // familie.emplace_back(Linsey);
}

void loop()
{

    if (button.isSystemSwitchedOn())
    {
        auto moisturePercentage = moistureSensor.getMoisturePercentage();
        // Serial.println("Plant has a moisture percentage of: " + String(moisturePercentage));

        if (moisturePercentage < 40)
        {
            if (!pump.isPumpOn())
            {
                Serial.println("Pump to ON, DDOOOORRRRSSTTTTT!!!!!");
                pump.on();
            }
        }
        else
        {
            if (pump.isPumpOn())
            {
                Serial.println("Pump to OFF, is al nat genoeg hiero");
                pump.off();
            }
        }
    }
    else
    {
        pump.off();
    }
    delay(100);
}
