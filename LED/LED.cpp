#pragma once
#include "LED.h"


LED::LED(int pinnum, int initstate):
super(pinnum, initstate>=1)
{
}
LED::LED(int pinnum, bool initstate):
			super(pinnum, initstate)
{
	super::setState(initstate);
}

LED::LED(int pinnum):super(pinnum, false)//ctor
{
}
void LED::flash(int iterations, int delayTime)
{
	iterations*=2;
	long startMil=millis();
	while(iterations>0)
	{
		if(millis()-startMil>=delayTime)
		{
			state=!state;
			this->setState(state);
			startMil=millis();
			iterations--;
		}
	}
}
void LED::fadeUp(int delayTime)
{
	for(int i = 0; i<256; i++)
	{
		super::setState(i);
		delay(delayTime);
	}
}
void LED::fadeDown(int delayTime)
{
	for(int j = 255; j>=0; j--)
	{
		super::setState(j);
		delay(delayTime);
	}
}
void LED::crossFade(int iterations, int delayTime, LED &other)
{
	if(iterations>0)
	{
		int j = 255;
		for(int i = 0; i<256; i++)
		{
			this->setState(i);
			other.setState(j);
			delay(delayTime);
			j--;
		}
		j=255;
		for(int i = 0; i<256; i++)
		{
			this->setState(j);
			other.setState(i);
			delay(delayTime);
			j--;
		}
	}
	else
		return;
	this->crossFade(iterations-1, delayTime, other);
}
void LED::fade(int delayTime)//fade for chamelion program
{
	if(state)
		this->fadeUp(delayTime);
	else
		this->fadeDown(delayTime);
	state = !state;
}
void LED::lidarSim(int pulseRate)//test radar detector lidar detection
{
	long sMil = millis();
	while(millis()-sMil<=1000)
	{
		this->pulse();
		delay(1000/pulseRate);
	}
}

void LED::toggleState()
{
    super::setState(state);
    state=!state;
}
void LED::alternateFlash(LED &other, int iterations, int delaytime)
{
	iterations*=2;
	this->setState(true);
	other.setState(false);
	for(int i = iterations; i>=0; --i)
	{
		long sMil = millis();
		while(millis()-sMil>=0)
		{
			if(millis()-sMil>=delaytime)
			{
				this->toggleState();
				other.toggleState();
				break;
			}
		}
	}
}
void LED::displayStates(vector<int> &vals, int dTime)
{
	for(int i = 0; i<vals.size(); i++)
	{
		super::setState(vals[i]);
		delay(dTime);
	}
}
void LED::pulse()
{
	this->setState(false);
	this->setState(true);
	this->setState(false);
}
string LED::toString()
{
	return pin+" state:"+super::getState();
}
