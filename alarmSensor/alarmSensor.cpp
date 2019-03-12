#include "alarmSensor.h"

alarmSensor::alarmSensor(int pin, int thresh):
    analogInput(pin),threshold(thresh){}

bool alarmSensor::isActivated()
{
    return ((analogInput::getState())>=threshold);
}
