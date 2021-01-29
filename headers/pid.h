#ifndef PID_H
#define PID_H
#include "regulator.h"

class PID: public Regulator {
private:
    int _kp = 0;
    int _kd = 0;
    float _error = 0;
    int _period = 0;
public:

    PID();

    void setPeriod(int period) {
        _period = period;
    }

    void setProp(int kp) {
        _kp = kp;
    }

    void setDiff(int kd) {
        _kd = kd;
    }

    int control(float y) override;
};

#endif // PID_H
