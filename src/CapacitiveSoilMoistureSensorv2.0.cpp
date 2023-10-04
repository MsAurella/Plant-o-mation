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

float CapacitiveSoilMoistureSensor::getMoisturePercentage()
{
    // todo assert pmin, max is set
    int calibratedSensorValue = getSensorValue();
     Serial.println("calsensval"+ calibratedSensorValue);

    float percentage = calibratedSensorValue/(maxSensorValue-minSensorValue)*100;
    Serial.println(percentage);

    // todo warning if <0 or >100
    if (percentage < 0 ){
        percentage = 0;
    } else if (percentage >=100 ) {
        percentage = 100;
    }
    return percentage;
}