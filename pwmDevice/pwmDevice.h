#pragma once

#include <StandardCplusplus.h>
#include <device.h>
#include "Arduino.h"

class pwmDevice : public Device{
private:
	typedef Device super;
protected:
	bool state;
public:
	pwmDevice(int pin);
	pwmDevice(int pin, bool initstate);
	void setState(bool state);
	void setState(int state);
	bool getState();
	bool toggleState();
};