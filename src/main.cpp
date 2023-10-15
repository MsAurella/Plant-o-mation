// testing
#include <Arduino.h>
#include "CapacitiveSoilMoistureSensorv2.0.hpp"
// #include "UnderWaterPump.hpp"

#define PIN_MOISTURE 36
#define MOISTURE_MIN 1000 // wet
#define MOISTURE_MAX 3000 // dry

#define PIN_POMP 4
#define DIGITAL_IN 27

auto moistureSensor = CapacitiveSoilMoistureSensor(PIN_MOISTURE, MOISTURE_MIN, MOISTURE_MAX);

void setup()
{
    Serial.begin(9600);
    pinMode (27, INPUT_PULLUP);
    pinMode (PIN_POMP, OUTPUT);
}

void loop()
{
    // Serial.println("reading moistureSensor: " + String(moistureSensor.getSensorValue()));
    // Serial.println("Which is a moisture percentage of: " + String(moistureSensor.getMoisturePercentage()));

    bool button_not_pressed = digitalRead(DIGITAL_IN);
    if (button_not_pressed) {
        Serial.println("Pump OFF");
        digitalWrite(PIN_POMP, LOW);
    } else {
        Serial.println("Pump ON");
        digitalWrite(PIN_POMP, HIGH);
    }



    delay(100);
}
