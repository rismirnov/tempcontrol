#include "settings.h"

Settings::Settings()
{

}

void Settings::setStartTime(int startTime) {
    if(startTime >= LOW_TIME_LIMIT) {
        this->startTime = startTime;
    }
}

void Settings::setEndTime(int endTime) {
    if(this->endTime <= HIGHT_TIME_LIMIT) {
        this->endTime = endTime;
    }
}

void Settings::setEconomTemp(short economTemp) {
    if(this->economTemp >= LOW_TEMP_LIMIT) {
        this->economTemp = economTemp;
    }
}

void Settings::setComfortTemp(short comfortTemp) {
    if(this->comfortTemp <= HIGHT_TEMP_LIMIT) {
        this->comfortTemp = comfortTemp;
    }
}