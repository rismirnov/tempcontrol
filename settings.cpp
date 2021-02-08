#include "settings.h"

Settings::Settings()
{

}

void Settings::setStartTime(unsigned int startTime) {
    this->startTime = startTime;
}

void Settings::setEndTime(unsigned int endTime) {
    this->endTime = endTime;
}

void Settings::setEconomTemp(short economTemp) {
    this->economTemp = economTemp;
}

void Settings::setComfortTemp(short comfortTemp) {
    this->comfortTemp = comfortTemp;
}
