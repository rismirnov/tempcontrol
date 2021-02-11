#include "clock.h"

Clock::Clock()
{
}

void Clock::tick()
{
    time += period;
    if (time > MAX_TIME)
    {
        time = time - MAX_TIME;
    }

    timer -= period;
    if (timer <= 0)
    {
        timer = interval;
        if (callback != nullptr)
        {
            callback();
        }
    }
}

void Clock::setTime(int time)
{
    this->time = time;
}

void Clock::setPeriod(int period)
{
    this->period = period;
}

void Clock::setInterval(int interval, void (*callback)())
{
    this->interval = interval;
    this->timer = interval;
    this->callback = callback;
}

int Clock::getInterval() const
{
    return interval;
}

int Clock::getPeriod() const
{
    return period;
}

int Clock::getTime() const
{
    return time;
}
