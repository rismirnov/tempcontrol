#include "regulator.h"

Regulator::Regulator()
{

}

void Regulator::setValue(float value) {
    this->value = value;
}

void Regulator::setMotor(Motor* motor) {
    this->motor = motor;
}
