#include "monitor.h"

Monitor::Monitor()
{
}

int Monitor::getSample() {
    int tempMean = 0;
    for(int i = 0; i < m_numSensors; i++) {
        tempMean += m_sensors[0].getData();
    }
    tempMean = round(tempMean / m_numSensors);
    if(m_index == m_numSamples) {
         m_index = 0;
    }
    m_temperatures[m_index++] = tempMean;
    return tempMean; 
}

bool Monitor::isEconomTime() {
    unsigned int currentTime = m_clock->getTime();
    unsigned int deltaTime = m_settings->m_endTime - room.m_controlTime;

    if(m_settings->m_startTime < currentTime && currentTime < deltaTime) {
            return true;
    }
     return false;
}

void Monitor::identification() {
    // Записан массив отсчетов за сутки
    if(m_index == 0) {
    auto minSample = std::min_element(m_temperatures, m_temperatures + m_numSensors);
    auto maxSample = std::max_element(minSample, m_temperatures + m_numSensors);

    room.m_supremum = *minSample;
    room.m_infimum = *maxSample;

    if(m_settings->m_economTemp > room.m_infimum) {
        minSample = std::find_if(minSample + 1, m_temperatures + m_numSensors, [this](int i){
            return i > m_settings->m_economTemp;
        });
        minSample--;
    } else {
        // заданная уставка эконом температуры недостижима (исключение)
        throw 1;
    }
    
    if(m_settings->m_comfortTemp < room.m_supremum) {
        maxSample = std::find_if(minSample + 1, m_temperatures + m_numSensors, [this](int i){
            return i > m_settings->m_comfortTemp;
        });
        maxSample--;
    } else {
        // заданная уставка комфорт температуры недостижима (исключение)
        throw 2;
    }

    int minIndex = std::distance(m_temperatures, minSample);
    int maxIndex = std::distance(m_temperatures, maxSample);

    room.m_controlTime = (maxIndex - minIndex) * m_clock->getInterval();
    }
}

void Monitor::work() {
    int tempMean = getSample();
    identification();

    if(isEconomTime()) {
        m_regulator->setValue(m_settings->m_economTemp);
    } else {
        m_regulator->setValue(m_settings->m_comfortTemp);
    }

    m_regulator->control(tempMean);
}

Monitor::MonitorStatus Monitor::getStatus() {
    return m_status;
}

void Monitor::setRegulator(Regulator* regulator) {
    m_regulator = regulator;
}

void Monitor::setClock(const Clock* clock) {
    m_clock = clock;

    if(m_temperatures != nullptr) {
        delete[] m_temperatures;
    }
    // массив отсчетов
    m_temperatures = new int[m_numSamples];
    m_numSamples = m_clock->MAX_TIME / m_clock->getInterval();
}

void Monitor::setSensors(const Sensor *sensors, short numSensors) {
    m_sensors = sensors;
    m_numSensors = numSensors;
}

void Monitor::setSettings(const Settings* settings) {
    m_settings = settings;
}