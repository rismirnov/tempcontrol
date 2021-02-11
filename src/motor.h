#ifndef MOTOR_H
#define MOTOR_H
#include "Arduino.h"
#pragma once

class Motor
{
public:
    Motor();
    void drive(bool input);
};

#endif // MOTOR_H
