// testing
#include <Arduino.h>
#include "CapacitiveSoilMoistureSensorv2.0.hpp"
#include "UnderWaterPump.hpp"

#define ANALOG_READ_MOISTURE 36
#define MOISTURE_MIN 1000 // wet
#define MOISTURE_MAX 3000 // dry

#define DIGITAL_WRITE_PUMP 4

#define DIGITAL_IN 27

auto moistureSensor = CapacitiveSoilMoistureSensor(ANALOG_READ_MOISTURE, MOISTURE_MIN, MOISTURE_MAX);
auto pump = UnderWaterPump(DIGITAL_WRITE_PUMP);
bool isOff = true;
bool start = false;
bool lastButton = true;

void setup()
{
    Serial.begin(9600);
    pinMode(27, INPUT_PULLUP);
}

void loop()
{
    bool button_not_pressed = digitalRead(DIGITAL_IN);
    if (!button_not_pressed && lastButton != button_not_pressed)
    {
        start = !start;
        Serial.print("Switching system to: ");
        Serial.println(start);
    }
    lastButton = button_not_pressed;

    if (start)
    {
        auto moisturePercentage = moistureSensor.getMoisturePercentage();
        Serial.println("Plant has a moisture percentage of: " + String(moisturePercentage));

        if (moisturePercentage < 40)
        {
            if (isOff)
            {
                Serial.println("Pump to ON, DDOOOORRRRSSTTTTT!!!!!");
                isOff = false;
                pump.on();
            }
        }
        else
        {
            if (!isOff)
            {
                Serial.println("Pump to OFF, is al nat genoeg hiero");
                isOff = true;
                pump.off();
            }
        }
    }
    else
    {
        pump.off();
        isOff = true;
    }
    delay(100);
}
