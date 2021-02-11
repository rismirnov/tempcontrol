#ifndef SENSOR_H
#define SENSOR_H
#pragma once

class Sensor
{
protected:
    float data;
    int address;

public:
    Sensor();
    void setAddress(int address);
    int getData() const;
    virtual void measure() = 0;
};

#endif // SENSOR_H
