#include "settings.h"

Settings::Settings()
{

}

void Settings::setStartTime(unsigned int start) {
    startTime = start;
}

void Settings::setEndTime(unsigned int end) {
    endTime = end;
}

void Settings::setRegulator(Regulator* r) {
    regulator = r;
}

void Settings::setClock(const Clock* c) {
    clock = c;
}

void Settings::setMotor(const Motor* m) {
    motor = m;
}

void Settings::setSensors(const Sensor *ss, short len) {
    sensors = ss;
    length = len;
}


void Settings::setEconom(short e) {
    econom = e;
}

void Settings::setComfort(short c) {
    comfort = c;
}
