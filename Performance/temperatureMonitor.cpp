#include <iostream>
#include <unistd.h>
#include <sys/inotify.h>
#include <sys/types.h>
#include <errno.h>

#include "./temperatureMonitor.hpp"


#define EVENT_SIZE  ( sizeof (struct inotify_event) )
#define BUF_LEN     ( 1024 * ( EVENT_SIZE + 16 ) )

namespace Performance {
  void TemperatureMonitor::monitor_temperature(void(*callback)(double)){

  };

  void TemperatureMonitor::monitor_temperature_file(){
    int length, i = 0;
    int fd;
    int wd;
    char buffer[BUF_LEN];

    fd = inotify_init();

    wd = inotify_add_watch(fd, "/sys/class/thermal/thermal_zone0/temp", IN_MODIFY);

    while (true){
    length = read(fd, buffer, BUF_LEN);
      struct inotify_event *event = ( struct inotify_event * ) &buffer[ i ];

      if (event->len){
        std::cout << "found something\n";
        if (event->mask & IN_MODIFY){
          std::cout << "modified\n";
          std::cout << buffer<<std::endl;
        };
      };
    };
  };
};