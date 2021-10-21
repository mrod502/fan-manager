#include <iostream>
#include <unistd.h>
#include "fanManager.hpp"
#include <functional>
#include <algorithm>
#include <wiringPi.h>

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
    

    set_temperature_change_handler(std::bind(
      FanManager::handle_temperature_change,this,std::placeholders::_1
    ));
  };

  void FanManager::handle_temperature_change(int t){

  };

  unsigned int FanManager::get_fan_speed(int t){
    int tRange = maxTemp - thresholdTemp;
    int speedRange = maxSpeed - baseSpeed;
    int extraSpeed = (speedRange * (t - thresholdTemp)) / (maxTemp - thresholdTemp);

    return baseSpeed + std::min<int>(std::max<int>(0,extraSpeed),speedRange);
  };

  void FanManager::set_pwm_intensity(int i){
    pwmWrite(PWM_pin, i);
  };

};