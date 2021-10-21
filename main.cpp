#include <iostream>

#include "Performance/fanManager.hpp"
#include "Performance/temperatureMonitor.hpp"

int main(){

//  Performance::FanManager *mgr = new Performance::FanManager(0,1<<7,110,180);
  Performance::TemperatureMonitor *tm = new Performance::TemperatureMonitor();

  tm->monitor_temperature_file();

  delete tm;

  return 0;
};