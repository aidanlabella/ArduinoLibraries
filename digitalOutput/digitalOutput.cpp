#pragma once
#include "digitalOutput.h"

digitalOutput::digitalOutput(int pinnum):
singlePinDevice(pinnum)
{
	pinMode(pin, OUTPUT);
}
void digitalOutput::setState(bool state)
{
	digitalWrite(pin,state);
}
