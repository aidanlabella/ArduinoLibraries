#include "analogInput.h"

analogInput::analogInput(int pinnum):
		Device(pinnum)
{
	pinMode(pin, INPUT);
}
int analogInput::getState()
{
	return analogRead(pin);
}
