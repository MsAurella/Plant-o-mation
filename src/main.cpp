// testing
#include <Arduino.h>
#include "CapacitiveSoilMoistureSensorv2.0.hpp"
#include "UnderWaterPump.hpp"
#include "Button.hpp"
#include "Plant.hpp"
#include <vector>

// FIREBEETLE
#define ANALOG_READ_MOISTURE 36
#define MOISTURE_MIN 1000 // wet
#define MOISTURE_MAX 3000 // dry

#define DIGITAL_WRITE_PUMP 4

#define DIGITAL_IN_BUTTON 27

// ESP WROOM
#define LED_PIN 2

auto moistureSensor = CapacitiveSoilMoistureSensor(ANALOG_READ_MOISTURE, MOISTURE_MIN, MOISTURE_MAX);
auto pump = UnderWaterPump(DIGITAL_WRITE_PUMP);
auto button = Button(DIGITAL_IN_BUTTON);

auto Linsey = Plant("Linsey", pump, moistureSensor);

void setup()
{
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    // if (button.isSystemSwitchedOn())
    // {
    //     Linsey.waterIfRequired();
    // }
    // else
    // {
    //     Linsey.shutDown();
    // }
      // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_PIN, HIGH);
  Serial.println("Blink");
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_PIN, LOW);
   // wait for a second
  delay(1000);

    delay(100);
}
