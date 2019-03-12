#pragma once

#include "../device/device.h"
#include "Arduino.h"

class digitalInput : public Device
{
	public:
		digitalInput(int);
		bool getState();	
		int pinNumber(){return pin;}
};