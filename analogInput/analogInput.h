#pragma once

#include "Arduino.h"
#include "../device/device.h"

class analogInput : public Device
{
	public:
		analogInput(int pinnum);
		int getState();
};
