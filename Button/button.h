#pragma once

#include "Arduino.h"
#include <digitalInput.h>

class Button : public digitalInput
{
	private:
		typedef digitalInput super;
		const int DEBOUNCE_DELAY = 50;
		bool prevState;
	public:
		Button(int pinnum);
		bool stateHasChanged();
		bool wasPressed(int time);
		int pinNumber(){return pin;}
		string toString();
};

