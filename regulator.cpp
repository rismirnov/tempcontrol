#include "regulator.h"

Regulator::Regulator() {}

void Regulator::setSetpoint(float setpoint) {
    this->setpoint = setpoint;
}

float Regulator::getError() {
    return error;
}
/*
int Regulator::getControlPercent() {
    return round(value / setpoint * 100);
}
*/