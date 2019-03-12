#include "pwmDevice.h"

pwmDevice::pwmDevice(int pin):super(pin)
{
	pinMode(this->pin, OUTPUT);
}

pwmDevice::pwmDevice(int pin, bool initstate):
	super(pin), state(initstate)
{
	pinMode(this->pin, OUTPUT);
}

void pwmDevice::setState(bool state)
{
	digitalWrite(pin, state);
	this->state = state;
}

void pwmDevice::setState(int state)
{
	analogWrite(pin, state);
	state >= 1 ? this->state = true : this->state = false;
}

bool pwmDevice::getState()
{
	return state;
}

bool pwmDevice::toggleState()
{
	state = !state;
	this->setState(state);
	return state;
}