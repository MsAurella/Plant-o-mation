// testing
#include <Arduino.h>

#define PIN_MOISTURE 36
#define MOISTURE_MIN 1000 // wet
#define MOISTURE_MAX 3000 // dry

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int raw_moisture = analogRead(PIN_MOISTURE);
    Serial.println("Hello world!");
    Serial.println(raw_moisture);
    delay(1000);
}
