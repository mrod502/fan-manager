#pragma once

namespace Performance {
  class TemperatureMonitor{

  public:
    double get_temperature();
    void monitor_temperature(void(*callback)(double));
    void monitor_temperature_file();

  };
};