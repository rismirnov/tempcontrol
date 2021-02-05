#ifndef REGULATOR_H
#define REGULATOR_H
#include "motor.h"
#pragma once

class Regulator {
protected:
    float m_value = 0;
    int m_deadband = 0;
    Motor* m_motor;
public:
    Regulator();
    // уставка
    void setValue(float value);
    // регулирование
    virtual void control(float y) = 0;
    void setDeadband(int deadband);
    void setMotor(Motor* motor);

};

#endif // REGULATOR_H
