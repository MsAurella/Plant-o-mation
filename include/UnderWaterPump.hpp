#pragma once

class UnderWaterPump {
  enum class PumpState { ON, OFF };

public:
  UnderWaterPump(int pin);
  void on();
  void off();
  bool isPumpOn() const;

private:
  int pin;
  PumpState pumpState;
};
