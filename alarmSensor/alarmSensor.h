#pragma once
#include <analogInput.h>

class alarmSensor : public analogInput{
    protected:
        int threshold;//threshold that analog read will register
    public:
        alarmSensor(int,int);
        bool isActivated();
        int pinNumber(){return pin;}

};
