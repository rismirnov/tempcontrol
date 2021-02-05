#ifndef MONITOR_H
#define MONITOR_H
#include "settings.h"
#include <math.h>
#include <algorithm>

class Room
{
friend class Monitor;
private:
    int m_supremum = 0;
    int m_infimum = 0;
    int m_controlTime = 0;

public:
    Room() {}
    
    int getSupremum() { return m_supremum; }
    int getInfimum() { return m_infimum; }
    int getControlTime() { return m_controlTime; }
    
};

class Monitor
{
public:
    enum MonitorStatus {Init, Identification, Worked};
private:
    MonitorStatus m_status;
    int m_numSensors = 0;
    const Settings* m_settings;
    const Sensor* m_sensors;
    Regulator* m_regulator;
    const Clock* m_clock;

    const int CONTROL_PRECISION = 0.2; // точность 20 %
    int* m_temperatures = nullptr;
    int m_index = 0;
    int m_numSamples = 0;
    
    int getSample();
    void identification();
    bool isEconomTime();
public:
    Room room;
    
    Monitor();
    Monitor(const Monitor& monitor) = delete;

    void work();
    void setRegulator(Regulator* regulator);
    void setClock(const Clock* clock);
    void setSensors(const Sensor* sensors, short numSensors);
    void setSettings(const Settings* settings);

    MonitorStatus getStatus();
};

#endif // MONITOR_H
