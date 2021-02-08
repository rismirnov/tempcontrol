#ifndef CLOCK_H
#define CLOCK_H
#pragma once

class Clock
{
private:
    int time;
    int period;
    int timer = 0;
    int interval = 0;
    void (*callback)() = nullptr;
public:
    Clock();
    
    const int MAX_TIME = 86400000;
    int getTime() const;
    int getInterval() const;
    void setTime(int time);
    void setPeriod(int period);
    void setInterval(int interval, void (*callback)());
    void tick();
};

#endif // CLOCK_H
