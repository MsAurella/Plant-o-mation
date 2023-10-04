#include "CapacitiveSoilMoistureSensorv2.0.hpp"
#include <Arduino.h>

CapacitiveSoilMoistureSensor::CapacitiveSoilMoistureSensor(int pin, int minSensorValue, int maxSensorValue) : pin(pin),
                                                                                                              minSensorValue(minSensorValue),
                                                                                                              maxSensorValue(maxSensorValue)
{
    // assert min < max
}

int CapacitiveSoilMoistureSensor::getSensorValue()
{
    // todo assert pin is set
    return analogRead(pin);
}

float CapacitiveSoilMoistureSensor::getMoisturePercentage()
{
    // todo assert pmin, max is set
    float calibratedSensorValue = getSensorValue()-minSensorValue;
    float percentage = calibratedSensorValue/(maxSensorValue-minSensorValue)*100;

    // todo warning if <0 or >100
    if (percentage < 0 ){
        percentage = 0;
    } else if (percentage >=100 ) {
        percentage = 100;
    }
    percentage = 100-percentage;
    return percentage;
}