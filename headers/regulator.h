#ifndef REGULATOR_H
#define REGULATOR_H
#pragma once

class Regulator {
protected:
    float _value = 0;
public:
    Regulator();
    // уставка
    void setValue(float value) {
        _value = value;
    }
    // регулирование
    virtual int control(float y) = 0;

};

#endif // REGULATOR_H
