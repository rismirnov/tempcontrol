#include "sensor.h"

Sensor::Sensor()
{

}

void Sensor::setAddress(int address) {
    m_address = address;
}
int Sensor::getData() const {
    return m_data;
}
