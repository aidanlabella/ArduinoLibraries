#pragma once


#include "pwmDevice.h"
#include <StandardCplusplus.h>
#include <vector>

using namespace std;

enum boardType{
	leonardo,
	uno
};

class pwmDeviceGroup{
	private:
		bool state;
		int maxState;
		vector<pwmDevice*> items;
		void pause(int time);
	public:
		pwmDeviceGroup();
		pwmDevice* elementAt(int index);
		bool isEmpty();
		int length();
		void add(pwmDevice *newDev);
	    void setAll(bool set);
		void setAll(int set);
		void flash(int iterations, unsigned int delayTime);
		void alternateFlash(int iterations, unsigned int delaytime);
		void fadeUp(int delayTime);
		void fadeDown(int delayTime);
		void setMaxState(int);
		void twoWayCycle(int delayTime);
		void cycle(int delayTime);
		void cycle(int delayTime, int state);
		void cycleCont(int delayTime, int iterations);
		void fade(int delayTime);
		bool toggleSelect(int e, int time);
		void removeAll();
};

