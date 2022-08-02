#include <iostream>

#include "./Fan/Manager.hpp"
#include "./Temperature/Monitor.hpp"
extern "C"
{
#include "../WiringPi/wiringPi/wiringPi.h"
}
const int PWM_pin = 1;
void setPWMWidth(int i)
{
  pwmWrite(PWM_pin, i);
};

int main()
{
  wiringPiSetup();
  Fan::Manager *fm = new Fan::Manager(0, 1024, 4000, 7000);
  fm->manage(setPWMWidth);
  delete fm;
  return 0;
};