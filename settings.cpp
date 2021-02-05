#include "settings.h"

Settings::Settings()
{

}

void Settings::setStartTime(unsigned int startTime) {
    m_startTime = startTime;
}

void Settings::setEndTime(unsigned int endTime) {
    m_endTime = endTime;
}

void Settings::setEconomTemp(short economTemp) {
    m_economTemp = economTemp;
}

void Settings::setComfortTemp(short comfortTemp) {
    m_comfortTemp = comfortTemp;
}
