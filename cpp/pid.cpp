#include "pid.h"

PID::PID()
{

}

int PID::control(float y) {
       float error = y - _value;
       float out = _kp * error + _kp * _kd * (error - _error) / _period;

       if(out < 0) {
           out = 0;
       }

       if(out > 255) {
           out = 255;
       }

       _error = error;
       return out;
}
