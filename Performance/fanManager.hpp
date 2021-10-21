#pragma once

namespace Performance {
  class FanManager
  {

    public:
      FanManager(unsigned char base_speed, unsigned char max_speed, double threshold_temp, double max_temp);

      void manage(unsigned char polling_interval);

    protected:
      unsigned char baseSpeed;
      unsigned char maxSpeed;
      unsigned char currentSpeed;
      double thresholdTemp;
      double maxTemp;
    
    private:
      void set_fan_speed(unsigned char);
    

  };
};
