#ifndef SETTINGS_H
#define SETTINGS_H
#pragma once

#define LOW_TEMP_LIMIT 5
#define HIGHT_TEMP_LIMIT 25

#define LOW_TIME_LIMIT 0
#define HIGHT_TIME_LIMIT 86400000

class Settings
{

friend class Monitor;

private:
    int startTime;
    int endTime;
    short economTemp;
    short comfortTemp;

public:
    Settings();
    void setStartTime(int start);
    void setEndTime(int end);
    void setEconomTemp(short e);
    void setComfortTemp(short c);
};

#endif // SETTINGS_H
