#pragma once

#include "Arduino.h"
#include <diode.h>
#include <potentiometer.h>

class rgbLED{
	protected:
		Diode *rLED, *gLED, *bLED;
	public:
		rgbLED(Diode*, Diode*, Diode*);
		void colorCycle(int);
		void adjRed(Potentiometer*);
		void adjGreen(Potentiometer*);
		void adjBlue(Potentiometer*);
		void turnOff();
};
