#pragma once
#include <atomic>
#include <functional>
namespace Performance {
  class TemperatureMonitor{

  public:
    TemperatureMonitor();
    ~TemperatureMonitor();
    double get_temperature();
    void set_temperature_change_handler(std::function<void(int)>);
    void monitor_temperature_file();
    
  private:
    std::atomic<int> *temperature;
    std::function<void(int)> callback;
    int max_temp;
    int threshold_temp;
    unsigned int fan_baseline;
    unsigned int fan_max;
    static void default_callback(int);

  };
};