#include "clock.h"

Clock::Clock()
{

}

int Clock::getTime() const {
    return m_time;
}

void Clock::setTime(int milsec) {
    m_time = milsec;
}

void Clock::setPeriod(int milsec) {
    m_period = milsec;
}

void Clock::tick() {
    m_time += m_period;
    if(m_time > MAX_TIME) {
        m_time = m_time - MAX_TIME;
    }

    m_timer -= m_period;
    if(m_timer <= 0) {
       m_timer = m_interval;
       if(m_callback != nullptr) {
            m_callback();
       }
    }
}

void Clock::setInterval(int _interval, void (*_callback)()) {
    m_interval = _interval;
    m_timer = _interval;
    m_callback = _callback;
}

int Clock::getInterval() const {
    return m_interval;
}
