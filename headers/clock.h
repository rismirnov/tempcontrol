#ifndef CLOCK_H
#define CLOCK_H
#pragma once

class Clock
{
private:
    unsigned int _time;
    short _period;
public:
    Clock();
    unsigned int getTime() const;
    void setTime(unsigned int milsec);
    void setPeriod(short milsec);
    void tick();
};

#endif // CLOCK_H
