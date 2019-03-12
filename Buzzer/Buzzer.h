#ifndef BUZZER_H
#define BUZZER_H

#include <pwmDevice.h>
#include "Arduino.h"

class Buzzer : public pwmDevice
{
    public:
        Buzzer(int);
        void buzz(int, int);
    protected:

    private:
};

#endif // BUZZER_H
