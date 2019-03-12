#pragma once

#include "pwmDevice.h"
#include <StandardCplusplus.h>
#include <vector>

using namespace std;

class Speaker : public pwmDevice
{
	public:
		Speaker(int pinnum);
		void playTone(int tne, int dur);
		void playSong(vector<int> *notes, vector<int> *durations);
		void stopTone();
		int pinNumber(){return pin;}
};

