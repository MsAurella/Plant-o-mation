// testing
#include <Arduino.h>
#include "CapacitiveSoilMoistureSensorv2.0.hpp"

#define PIN_MOISTURE 36
#define MOISTURE_MIN 1000 // wet
#define MOISTURE_MAX 3000 // dry

auto moistureSensor = CapacitiveSoilMoistureSensor(PIN_MOISTURE, MOISTURE_MIN, MOISTURE_MAX);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("reading moistureSensor:");
    Serial.println(moistureSensor.getSensorValue());
    delay(1000);
}
