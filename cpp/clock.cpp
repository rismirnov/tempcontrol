#include "clock.h"

Clock::Clock()
{

}

unsigned int Clock::getTime() const {
    return _time;
}

void Clock::setTime(unsigned int milsec) {
    _time = milsec;
}

void Clock::setPeriod(short milsec) {
    _period = milsec;
}

void Clock::tick() {
    _time += _period;
}
