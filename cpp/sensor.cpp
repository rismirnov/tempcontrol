#include "sensor.h"

Sensor::Sensor()
{

}

void Sensor::setAddress(int address) {
    _address = address;
}
int Sensor::data() const {
    return _data;
}
