#pragma once

// #include <arduino.h>

class CapacitiveSoilMoistureSensor {

  public:
    CapacitiveSoilMoistureSensor(int pin, int minSensorValue, int maxSensorValue);
    int getSensorValue();
    float getMoisturePercentage();

  private:
    int  pin;
    int             minSensorValue;
    int             maxSensorValue;
};
