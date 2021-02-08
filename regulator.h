#ifndef REGULATOR_H
#define REGULATOR_H
#include "motor.h"
#pragma once

class Regulator {
protected:
    float value = 0;
    Motor* motor;
public:
    static int CONTROL_PRECISION;
    
    Regulator();
    // уставка
    void setValue(float value);
    // регулирование
    virtual void control(float y) = 0;
    void setMotor(Motor* motor);

};


#endif // REGULATOR_H
