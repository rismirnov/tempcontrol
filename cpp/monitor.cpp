#include "monitor.h"

Monitor::Monitor(const Settings* s):settings(s)
{
    calibration();
}

void Monitor::start() {

}

void Monitor::stop() {

}

void Monitor::calibration() {
    _status = MonitorStatus::Calibration;
}

void Monitor::work() {

    int tempMean = 0;
    for(int i = 0; i < settings->length; i++) {
        tempMean += settings->sensors[0].data();
    }
    tempMean = round(tempMean / settings->length);

    unsigned int currentTime = settings->clock->getTime();

    if(_status == MonitorStatus::Calibration) {

        // TODO

    } else {
        unsigned int deltaTime = currentTime < settings->endTime - regulationTime;

        if(settings->startTime < currentTime && currentTime < deltaTime) {
        // Econom
            _status = MonitorStatus::Econom;
            settings->regulator->setValue(settings->econom);
        } else {
        // Comfort
            _status = MonitorStatus::Comfort;
            settings->regulator->setValue(settings->comfort);
        }
     }

    settings->regulator->control(tempMean);
}

Monitor::MonitorStatus Monitor::status() {
    return _status;
}
