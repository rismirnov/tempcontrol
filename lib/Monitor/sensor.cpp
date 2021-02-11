#include "sensor.h"

Sensor::Sensor()
{
}

void Sensor::setAddress(int address)
{
    this->address = address;
}
int Sensor::getData() const
{
    return data;
}
