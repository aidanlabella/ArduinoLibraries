#pragma once

#include "Arduino.h"
#include "../generalDevice/devices.h"

class digitalOutput : public singlePinDevice
{
	public:
		digitalOutput(int pinnum);
		void setState(bool state);

};
