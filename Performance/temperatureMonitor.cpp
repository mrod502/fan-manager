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


  void TemperatureMonitor::set_temperature_change_handler(std::function<void(int)> fn){
    callback = fn;
  };

  void TemperatureMonitor::monitor_temperature_file(){

    std::ifstream temperatureFile;
    std::string line;
    int curTemp = 0;

    while (true) {
      temperatureFile.open("/sys/class/thermal/thermal_zone0/temp");
      std::getline(temperatureFile, line);
      temperatureFile.close();
      curTemp = std::stoi(line);
      if (curTemp != temperature->load()){
        temperature->store(curTemp);
        callback(temperature->load());
      };
      sleep(1);
    };
  };

  void TemperatureMonitor::default_callback(int v){
    std::cout << "Temperature is " << v * 0.001 << " C\n";
  };



};
