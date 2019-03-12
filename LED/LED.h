#pragma once
/**
 * @author Aidan LaBella
 * @
 */



#include <pwmDevice.h>
#include <StandardCplusplus.h>
#include <string>
#include <vector>
#include "Arduino.h"

#define MINUTE 60000//for ms/delay()

using namespace std;

class LED : public pwmDevice
{
private:
	typedef pwmDevice super;
	void pulse();
public:
	LED(int pinnum, int initstate);//ctor
	LED(int pinnum, bool initstate);//ctor
	LED(int pinnum);//ctor
	void fadeUp(int delayTime);
	void fadeDown(int delayTime);
	void fade(int delayTime);
	void toggleState();
	void crossFade(int iterations, int delayTime, LED &other);
	void flash(int iterations, int delayTime);
	void displayStates(vector<int> &vals, int dTime);
	void alternateFlash(LED &other, int iterations, int delaytime);
	void lidarSim(int pulseRate);
	string toString();
};