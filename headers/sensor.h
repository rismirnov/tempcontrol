#ifndef SENSOR_H
#define SENSOR_H
#pragma once

class Sensor
{
protected:
    int _data;
    int _address;
public:
    Sensor();
    void setAddress(int address);
    int data() const;
    virtual void measure() = 0;
};

#endif // SENSOR_H
