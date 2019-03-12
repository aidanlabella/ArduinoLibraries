#include "Buzzer.h"

Buzzer::Buzzer(int pinnum):pwmDevice(pinnum)
{
    //ctor
}
void Buzzer::buzz(int freq, int dur)
{
    tone(pin, freq, dur);
}
