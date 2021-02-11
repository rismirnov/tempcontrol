#include "settings.h"

Settings::Settings()
{
}

void Settings::setStartTime(int startTime)
{
    if (startTime >= LOW_TIME_LIMIT)
    {
        this->startTime = startTime;
    }
}

void Settings::setEndTime(int endTime)
{
    if (this->endTime <= HIGH_TIME_LIMIT)
    {
        this->endTime = endTime;
    }
}

void Settings::setEconomTemp(short economTemp)
{
    if (this->economTemp >= LOW_TEMP_LIMIT)
    {
        this->economTemp = economTemp;
    }
}

void Settings::setComfortTemp(short comfortTemp)
{
    if (this->comfortTemp <= HIGH_TEMP_LIMIT)
    {
        this->comfortTemp = comfortTemp;
    }
}

int Settings::getStartTime()
{
    return startTime;
}

int Settings::getEndTime()
{
    return endTime;
}

short Settings::getEconomTemp()
{
    return economTemp;
}

short Settings::getComfortTemp()
{
    return comfortTemp;
}