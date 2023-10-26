#pragma once

#include "UnderWaterPump.hpp"
#include "CapacitiveSoilMoistureSensorv2.0.hpp"
#include <string>

class Plant
{

public:
    Plant(std::string name, UnderWaterPump &pump, CapacitiveSoilMoistureSensor &moistureSensor); // replace with interface
    bool needsWatering();
    void turnWateringOn();
    void turnWateringOff();

private:
    int minimalMoisturePercentage;
    std::string name;
    UnderWaterPump pump;
    CapacitiveSoilMoistureSensor moistureSensor;
};
