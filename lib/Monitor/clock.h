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
    const int MAX_TIME = 86400000;

    Clock();

    void tick();

    void setTime(int time);
    void setPeriod(int period);
    void setInterval(int interval, void (*callback)());

    int getTime() const;
    int getInterval() const;
    int getPeriod() const;
};

#endif // CLOCK_H
