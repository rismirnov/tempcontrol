#ifndef MOTOR_H
#define MOTOR_H
#pragma once

class Motor
{
public:
    Motor();
    virtual void drive(int input) = 0;
};

#endif // MOTOR_H
