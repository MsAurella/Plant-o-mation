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

void setup()
{
    Serial.begin(9600);
    pinMode (27, INPUT_PULLUP);
}

void loop()
{
    // Serial.println("reading moistureSensor: " + String(moistureSensor.getSensorValue()));
    // Serial.println("Which is a moisture percentage of: " + String(moistureSensor.getMoisturePercentage()));

    bool button_not_pressed = digitalRead(DIGITAL_IN);
    if (button_not_pressed) {
        Serial.println("Pump OFF");
        pump.off();
    } else {
        Serial.println("Pump ON");
        pump.on();
    }



    delay(100);
}
