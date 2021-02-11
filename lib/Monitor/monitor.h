#define MONITOR_H

#include <math.h>
#include <algorithm>
#include "settings.h"
#include "regulator.h"
#include "clock.h"
#include "sensor.h"

class Monitor
{
private:
    const Settings *settings;
    Regulator *regulator;
    const Clock *clock;

    bool isEconomTime();

public:
    Monitor();
    Monitor(const Monitor &monitor) = delete;

    void calculateControlMode();
    void setRegulator(Regulator *regulator);
    void setClock(const Clock *clock);
    void setSettings(const Settings *settings);
};