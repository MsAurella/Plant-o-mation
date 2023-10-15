#pragma once

class UnderWaterPump
{

public:
  UnderWaterPump(int pin);
  void on();
  void off();

private:
  int pin;
};
