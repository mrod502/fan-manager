#include <iostream>
#include <fstream>
#include <unistd.h>
#include <atomic>
#include "./temperatureMonitor.hpp"

namespace Performance {
  TemperatureMonitor::TemperatureMonitor(){
    temperature = new std::atomic<int>(INT32_MIN);
    callback = TemperatureMonitor::default_callback;
  };

  TemperatureMonitor::~TemperatureMonitor(){
    delete temperature;
  };

  void TemperatureMonitor::set_change_handler(std::function<void(int)> fn){
    callback = fn;
  };

  void TemperatureMonitor::monitor_temperature(){
    while (true) {
      int curTemp = get_temperature();
      if (curTemp != temperature->load()){
        temperature->store(curTemp);
        callback(temperature->load());
      };
      sleep(1);
    };
  };

  int TemperatureMonitor::get_temperature(){
    std::ifstream temperatureFile;
    std::string line;
    temperatureFile.open("/sys/class/thermal/thermal_zone0/temp");
    std::getline(temperatureFile, line);
    temperatureFile.close();
    return std::stoi(line);
  };

  void TemperatureMonitor::default_callback(int v){
    std::cout << "Temperature is " << v * 0.001 << " C\n";
  };
};
