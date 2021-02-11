#ifndef RELAY_H
#define RELAY_H

#include "regulator.h"

class Relay : public Regulator
{
public:
    Relay();
    bool control(float value);
};

#endif // RELAY_H
