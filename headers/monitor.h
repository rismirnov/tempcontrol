#ifndef MONITOR_H
#define MONITOR_H
#include "settings.h"
#include "math.h"

class Monitor
{
public:
    enum MonitorStatus {Started, Stopped, Econom, Comfort, Calibration, Worked};
private:
    const Settings* settings;
    MonitorStatus _status;
    // Regulation time variables;
    unsigned int regulationTime = 0;
    short _prevTemp = 0;
    short _startTime = 0;
public:
    Monitor() = delete;
    Monitor(const Monitor& m) = delete;
    Monitor(const Settings* s);

    void start();
    void stop();
    void work();
    void calibration();
    MonitorStatus status();
};

#endif // MONITOR_H
