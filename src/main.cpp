#include <iostream>

#include "Performance/fanManager.hpp"
#include "Performance/temperatureMonitor.hpp"
extern "C"{
#include <wiringPi.h>
}
const int PWM_pin = 1;
void setPWMWidth(int i){
  pwmWrite(PWM_pin, i);
};

int main(){
  wiringPiSetup();
  Performance::FanManager *fm = new Performance::FanManager(0, 1024, 4000, 7000);
  fm->manage(setPWMWidth);
  delete fm;
  return 0;
};