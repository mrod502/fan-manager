#include <iostream>

#include "Performance/fanManager.hpp"
#include "Performance/temperatureMonitor.hpp"

int main(){

//  Performance::FanManager *mgr = new Performance::FanManager(0,1<<7,110,180);
  Performance::FanManager *tm = new Performance::FanManager(0, 1024, 40, 70);

  tm->manage();

  delete tm;

  return 0;
};