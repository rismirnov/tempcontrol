#ifndef REGULATOR_H
#define REGULATOR_H
#include "math.h"
#include "clock.h"
#pragma once

class Regulator {
protected:
    float setpoint = 0;
    float error = 0;
public:
    static int CONTROL_PRECISION;
    Regulator();
    
    //virtual int control(float value) = 0;

    void setSetpoint(float setpoint);
    float getError();
    float getSetpoint();

};


#endif // REGULATOR_H
