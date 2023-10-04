#pragma once

// #include <arduino.h>

class CapacitiveSoilMoistureSensor {

  public:
    CapacitiveSoilMoistureSensor(int pin, int minSensorValue, int maxSensorValue);
    int getSensorValue();

  private:
    int  pin;
    int             minSensorValue;
    int             maxSensorValue;
};
