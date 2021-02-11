#include "temperature_sensor.h"

TemperatureSensor::TemperatureSensor()
{
    // GPIO where the DS18B20 is connected to GPIO 4
    oneWire = OneWire(4);
    sensors = DallasTemperature(&oneWire);
}

void TemperatureSensor::measure()
{
    sensors.requestTemperatures();
    data = sensors.getTempCByIndex(0);
}