#pragma once

#include "analogInput.h"

class microphone : public analogInput
{
	private:
		const int DEBOUNCE_TIME=50;//debounce time
		const int DEBOUNCE_THRESH=75;//the amount the reading is allowed to change after debounce time
		int threshold;//threshold for values
	public:
		microphone(int pinnum, int thresh);
		int pinNumber(){return pin;};
		int numOfTaps(int interval);
		bool wasTapped();
};

