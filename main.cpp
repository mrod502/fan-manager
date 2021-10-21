#include <iostream>

#include "Performance/fanManager.hpp"
#include "Performance/temperatureMonitor.hpp"

#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 ∗ ( EVENT_SIZE + 16 ) )


int main(){

//  Performance::FanManager *mgr = new Performance::FanManager(0,1<<7,110,180);
  Performance::TemperatureMonitor tm = Performance::TemperatureMonitor();

  tm.monitor_temperature_file();


  return 0;
};