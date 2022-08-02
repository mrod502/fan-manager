#pragma once
#include "../Temperature/Monitor.hpp"
#include <functional>

namespace Fan
{
  class Manager : public Temperature::Monitor
  {

  public:
    Manager(unsigned int, unsigned int, int, int);

    void manage(std::function<void(int)>);

  protected:
    unsigned int baseSpeed;
    unsigned int maxSpeed;
    int thresholdTemp;
    int maxTemp;

  private:
    void handle_temperature_change(int);
    unsigned int get_fan_speed(int);
  };
};
