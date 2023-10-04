#include "CapacitiveSoilMoistureSensorv2.0.hpp"
#include <Arduino.h>

CapacitiveSoilMoistureSensor::CapacitiveSoilMoistureSensor(int pin, int minSensorValue, int maxSensorValue) : pin(pin),
                                                                                                              minSensorValue(minSensorValue),
                                                                                                              maxSensorValue(maxSensorValue)
{
}

int CapacitiveSoilMoistureSensor::getSensorValue()
{
    // todo assert pin is set
    return analogRead(pin);
}