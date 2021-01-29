#include "control.h"

//
#define SENSOR_LENGTH 4

using namespace TemperatureControl;

class TemperatureSensor : public Sensor {
public:
    TemperatureSensor() {}
    void measure() override {
        // Microprogram code;
    }
};

class MotorExample : public Motor {
public:
    MotorExample() {}
    void drive(int control) override {
        // Microprogram code;
    }
};

// Example code
/**************************************/
PID pid;
Clock c;
MotorExample m;
// Sensors array
TemperatureSensor sensors[SENSOR_LENGTH];
Settings settings;
Monitor monitor(&settings);

void init() {
    sensors[0].setAddress(0x25); // Your value instead 0x25
    /*  sensors[i].setAddress(0x25); */
    settings.setRegulator(&pid);
    settings.setMotor(&m);
    settings.setClock(&c);
    settings.setSensors(sensors, SENSOR_LENGTH);
    settings.setStartTime(1000); // Your value instead 1000
    settings.setEndTime(2000); // Your value  instead  2000
}

void loop() {
    sensors[0].measure();
    /*  sensors[i].measure(); */
    // c.setTime(current time in milsec)
    monitor.work();
}
