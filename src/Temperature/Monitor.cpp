#include <iostream>
#include <fstream>
#include <unistd.h>
#include <atomic>
#include "./Monitor.hpp"

namespace Temperature
{
  Monitor::Monitor()
  {
    temperature = new std::atomic<int>(INT32_MIN);
    callback = Monitor::default_callback;
  };

  Monitor::~Monitor()
  {
    delete temperature;
  };

  void Monitor::set_change_handler(std::function<void(int)> fn)
  {
    callback = fn;
  };

  void Monitor::monitor_temperature()
  {
    while (true)
    {
      int curTemp = get_temperature();
      if (curTemp != temperature->load())
      {
        temperature->store(curTemp);
        callback(temperature->load());
      };
      sleep(1);
    };
  };

  int Monitor::get_temperature()
  {
    std::ifstream temperatureFile;
    std::string line;
    temperatureFile.open("/sys/class/thermal/thermal_zone0/temp");
    std::getline(temperatureFile, line);
    temperatureFile.close();
    return std::stoi(line);
  };

  void Monitor::default_callback(int v)
  {
    std::cout << "Temperature is " << v * 0.001 << " C\n";
  };
};
