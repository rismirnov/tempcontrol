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
    unsigned int m_startTime;
    unsigned int m_endTime;
    short m_economTemp;
    short m_comfortTemp;

public:
    Settings();
    void setStartTime(unsigned int start);
    void setEndTime(unsigned int end);
    void setEconomTemp(short e);
    void setComfortTemp(short c);

};

#endif // SETTINGS_H
