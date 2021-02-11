#include "monitor.h"

Monitor::Monitor()
{
}

bool Monitor::isEconomTime()
{
    unsigned int currentTime = clock->getTime();
    if (settings->startTime < currentTime && currentTime < settings->endTime)
        return true;
    else
        return false;
}

void Monitor::calculateControlMode()
{
    if (isEconomTime())
        regulator->setSetpoint(settings->economTemp);
    else
        regulator->setSetpoint(settings->comfortTemp);
}

void Monitor::setRegulator(Regulator *regulator)
{
    this->regulator = regulator;
}

void Monitor::setClock(const Clock *clock)
{
    this->clock = clock;
}

void Monitor::setSettings(const Settings *settings)
{
    this->settings = settings;
}