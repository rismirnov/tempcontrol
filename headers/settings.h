#ifndef SETTINGS_H
#define SETTINGS_H
#pragma once

#include "regulator.h"
#include "clock.h"
#include "motor.h"
#include "sensor.h"

class Settings
{

friend class Monitor;

private:
    unsigned int startTime;
    unsigned int endTime;
    Regulator* regulator;
    const Clock* clock;
    const Motor* motor;
    const Sensor* sensors;
    short length;
    short econom;
    short comfort;

public:
    Settings();
    void setStartTime(unsigned int start);
    void setEndTime(unsigned int end);
    void setRegulator(Regulator* r);
    void setClock(const Clock* c);
    void setMotor(const Motor* m);
    void setSensors(const Sensor* s, short len);
    void setEconom(short e);
    void setComfort(short c);

};

#endif // SETTINGS_H
