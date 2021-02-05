#ifndef RELAY_H
#define RELAY_H

#include "regulator.h"
#include <cmath>

class Relay : public Regulator
{
public:
    Relay();
    void control(float y) override;
};

#endif // RELAY_H
