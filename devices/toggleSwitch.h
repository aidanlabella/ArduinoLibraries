#pragma once

#include "digitalInput.h"

class toggleSwitch : public digitalInput
{
	public:
		toggleSwitch(int pinnum);
		int pinNumber(){return pin;}
		bool isOn();
		bool isOff();
};

toggleSwitch::toggleSwitch(int pinnum):
	digitalInput(pinnum){}
	
bool toggleSwitch::isOn()
{
	return digitalInput::getState();
}

bool toggleSwitch::isOff()
{
	return !this->isOn();
}