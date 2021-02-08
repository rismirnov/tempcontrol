#include "monitor.h"

Monitor::Monitor()
{
}

bool Monitor::isEconomTime() {
    unsigned int currentTime = clock->getTime();
    unsigned int deltaTime = settings->endTime; // - controlTime;

    if(settings->startTime < currentTime && currentTime < deltaTime) {
            return true;
    }
     return false;
}

void Monitor::identification() {
    // Записан массив отсчетов за сутки
}

void Monitor::work() {
    identification();

    if(isEconomTime()) {
        regulator->setValue(settings->economTemp);
    } else {
        regulator->setValue(settings->comfortTemp);
    }
}

void Monitor::setRegulator(Regulator* regulator) {
    this->regulator = regulator;
}

void Monitor::setClock(const Clock* clock) {
    this->clock = clock;
}

void Monitor::setSettings(const Settings* settings) {
    this->settings = settings;
}

void Monitor::subscribe(void(*observer)(Room room)) {
    this->observer = observer;
}