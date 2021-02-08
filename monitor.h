#ifndef MONITOR_H
#define MONITOR_H
#include "settings.h"
#include <math.h>
#include <algorithm>

class Room
{
public:
    int HIGHT_LIMIT = 0;
    int LOW_LIMIT = 0;
    int CONTROL_TIME = 0;
    Room() {}
    
};

class Monitor
{

private:
    const Settings* settings;
    Regulator* regulator;
    const Clock* clock;
    void(*observer)(Room room);
  
    void identification();
    bool isEconomTime();
    int getTemperature();
public:
    Room room;
    
    Monitor();
    Monitor(const Monitor& monitor) = delete;

    void work();
    void setRegulator(Regulator* regulator);
    void setClock(const Clock* clock);
    void setSettings(const Settings* settings);
    void subscribe(void(*observer)(Room room));
};

#endif // MONITOR_H
