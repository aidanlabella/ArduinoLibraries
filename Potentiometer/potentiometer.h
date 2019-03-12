#pragma once
#include <analogInput.h>

class Potentiometer : public analogInput
{
	protected:
		const int defUpperBound = 1023;
		int scaleLower, scaleUpper;
		typedef analogInput super;//java-style superclass reference
	public:
		Potentiometer(int, int, int);
		int getState();
		int getRawState();
		string toString();
};