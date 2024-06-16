#pragma once

#include "CapacitiveSoilMoistureSensorv2.0.hpp"
#include "UnderWaterPump.hpp"
#include <string>

class Plant {

public:
  Plant(std::string name, UnderWaterPump &pump,
        CapacitiveSoilMoistureSensor &moistureSensor); // replace with interface
  void waterIfRequired();
  void shutDown();

private:
  bool needsWatering();
  void turnWateringOn();
  void turnWateringOff();
  int minimalMoisturePercentage;
  std::string name;
  UnderWaterPump pump;
  CapacitiveSoilMoistureSensor moistureSensor;
};
