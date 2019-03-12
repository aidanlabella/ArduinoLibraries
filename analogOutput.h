#pragma once

#include "Arduino.h"
#include "devices.h"

class analogOutput : public singlePinDevice
{
	public:
		analogOutput(int pinnnum);
		void setState(int state);
};

analogOutput::analogOutput(int pinnum):
singlePinDevice(pinnum)
{
	pinMode(pin, OUTPUT);
}
void analogOutput::setState(int state)
{
	analogWrite(pin,state);
}