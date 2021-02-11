#include "relay.h"

Relay::Relay() {}

bool Relay::control(float value)
{
    error = setpoint - value;
    if (fabsf(error) > CONTROL_PRECISION && error > 0)
        return 1;
    else
        return 0;
}
