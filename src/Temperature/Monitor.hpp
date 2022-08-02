#pragma once
#include <atomic>
#include <functional>

namespace Temperature
{
  class Monitor
  {

  public:
    Monitor();
    ~Monitor();
    void set_change_handler(std::function<void(int)>);
    void monitor_temperature();
    int get_temperature();

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
