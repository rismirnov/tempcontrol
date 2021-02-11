#include "motor.h"

Motor::Motor()
{
}

void Motor::drive(bool relayState)
{
    // Motor is connected to GPIO 14
    digitalWrite(14, relayState);
}