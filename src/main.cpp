// testing
#include "Button.hpp"
#include "CapacitiveSoilMoistureSensorv2.0.hpp"
#include "Plant.hpp"
#include "UnderWaterPump.hpp"
#include <Arduino.h>
#include <vector>

// FIREBEETLE
// #define ANALOG_READ_MOISTURE 36
#define MOISTURE_MIN 1000 // wet
#define MOISTURE_MAX 3000 // dry

// #define DIGITAL_WRITE_PUMP 4

// #define DIGITAL_IN_BUTTON 27

// ESP WROOM
// #define LED_PIN 2
#define ANALOG_READ_MOISTURE 13
#define DIGITAL_IN_BUTTON 0
#define DIGITAL_WRITE_PUMP 26

auto moistureSensor = CapacitiveSoilMoistureSensor(ANALOG_READ_MOISTURE,
                                                   MOISTURE_MIN, MOISTURE_MAX);
auto pump = UnderWaterPump(DIGITAL_WRITE_PUMP);
auto button = Button(DIGITAL_IN_BUTTON);

auto Linsey = Plant("Linsey", pump, moistureSensor);

void setup() {
  Serial.begin(115200);
  // ESPWROOM
  // pinMode(LED_PIN, OUTPUT);
  pinMode(ANALOG_READ_MOISTURE, INPUT);
}

void loop() {
  if (button.isSystemSwitchedOn()) {
    Serial.print(">percentage:");
    Serial.println(moistureSensor.getMoisturePercentage());
    //   Linsey.waterIfRequired();
    // } else {
    //   Linsey.shutDown();
    pump.off();
  } else {
    pump.on();
    Serial.println("off");
  }
  // delay(100);
  // turn the LED on (HIGH is the voltage level)
  // Serial.println("Blink");
  // wait for a second
  // turn the LED off by making the voltage LOW
  // wait for a second
  delay(100);
}
