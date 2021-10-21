#pragma once
#include "temperatureMonitor.hpp"
#include <functional>
namespace Performance {
  class FanManager : public Performance::TemperatureMonitor
  {

    public:
      FanManager(unsigned int, unsigned int, int, int);

      void manage();

    protected:
      unsigned int baseSpeed;
      unsigned int maxSpeed;
      int thresholdTemp;
      int maxTemp;
    
    private:
      void handle_temperature_change(int);
      unsigned int get_fan_speed(int);
      static void set_pwm_intensity(int);

  };
};
