#include "sensor.h"
#include <OneWire.h>
#include <DallasTemperature.h>

class TemperatureSensor : public Sensor
{
private:
    OneWire oneWire;
    DallasTemperature sensors;

public:
    TemperatureSensor();
    void measure() override;
};