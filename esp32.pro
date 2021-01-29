TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        clock.cpp \
        example.cpp \
        monitor.cpp \
        motor.cpp \
        pid.cpp \
        regulator.cpp \
        sensor.cpp \
        settings.cpp

HEADERS += \
    clock.h \
    control.h \
    monitor.h \
    motor.h \
    pid.h \
    regulator.h \
    sensor.h \
    settings.h
