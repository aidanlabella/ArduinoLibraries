#pragma once
#include "digitalInput.h"

digitalInput::digitalInput(int pinnum):
Device(pinnum)
{
	pinMode(pin, INPUT);
}
bool digitalInput::getState()
{
	return digitalRead(pin);
}