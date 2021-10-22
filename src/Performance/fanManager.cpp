#include <iostream>
#include <unistd.h>
#include "fanManager.hpp"
#include <functional>
#include <algorithm>


const int PWM_pin = 1;

namespace Performance {
  FanManager::FanManager(unsigned int base_speed, unsigned int max_speed, int threshold_temp, int max_temp){
    if (base_speed >1024){
      throw "base_speed must be in [0,1024]";
    };
    if (max_speed >1024){
      throw "max_speed must be in [0,1024]";
    };
    if (maxTemp <= thresholdTemp){
      throw "maxTemp must be greater than threshold temp";
    };

    baseSpeed = base_speed;
    maxSpeed = max_speed;
    thresholdTemp = threshold_temp;
    maxTemp = max_temp;
  };

  void FanManager::manage(std::function<void(int)> f){
    while (true){
      int temp = get_temperature();
      f(get_fan_speed(temp));
      sleep(1);
    };
  };

  void FanManager::handle_temperature_change(int t){
    FanManager::set_pwm_intensity(get_fan_speed(t));
  };

  unsigned int FanManager::get_fan_speed(int t){
    int tRange = maxTemp - thresholdTemp;
    int speedRange = maxSpeed - baseSpeed;
    int extraSpeed = (speedRange * (t - thresholdTemp)) / (maxTemp - thresholdTemp);

    return baseSpeed + std::min<int>(std::max<int>(0, extraSpeed), speedRange);
  };

};