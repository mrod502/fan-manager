#include <iostream>

#include "Performance/fanManager.hpp"
#include "Performance/temperatureMonitor.hpp"
#include <wiringPi.h>

const int PWM_pin = 1;
void setPWMWidth(int w){
  pwmWrite(PWM_pin, i);
};


int main(){

//  Performance::FanManager *mgr = new Performance::FanManager(0,1<<7,110,180);
  Performance::FanManager *fm = new Performance::FanManager(0, 1024, 40, 70);

  fm->manage(setPWMWidth);

  delete tm;

  return 0;
};