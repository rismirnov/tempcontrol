#include "regulator.h"

Regulator::Regulator()
{

}

void Regulator::setValue(float value) {
    m_value = value;
}

void Regulator::setDeadband(int deadband) {
    m_deadband = deadband;
}

void Regulator::setMotor(Motor* motor) {
    m_motor = motor;
}
