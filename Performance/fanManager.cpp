#include <iostream>
#include <unistd.h>
#include "./fanManager.hpp"

namespace Performance {

    FanManager::FanManager(unsigned char base_speed, unsigned char max_speed, double threshold_temp, double max_temp){
      baseSpeed = base_speed;
      maxSpeed = max_speed;
      thresholdTemp = threshold_temp;
      maxTemp = max_temp;
      currentSpeed = 0;
    };

    void FanManager::manage(unsigned char polling_interval){

      while (true) {

        std::cout << "managing..."<<std::endl;
        sleep(polling_interval);
      };

    };
  
    void FanManager::set_fan_speed(unsigned char){

    };
};