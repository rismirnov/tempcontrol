#ifndef CLOCK_H
#define CLOCK_H
#pragma once

class Clock
{
private:
    int m_time;
    int m_period;
    int m_timer = 0;
    int m_interval = 0;
    void (*m_callback)() = nullptr;
public:
    Clock();
    
    const int MAX_TIME = 86400000;
    int getTime() const;
    int getInterval() const;
    void setTime(int milsec);
    void setPeriod(int milsec);
    void setInterval(int interval, void (*callback)());
    void tick();
};

#endif // CLOCK_H
