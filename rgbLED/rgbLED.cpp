#pragma once
#include "rgbLED.h"

rgbLED::rgbLED(Diode *_rLED, Diode *_gLED, Diode *_bLED):
			   rLED(_rLED),gLED(_gLED),bLED(_bLED){}

void rgbLED::colorCycle(int interval)
{
	rLED->fade(interval);
	gLED->fade(interval);
	rLED->fade(interval);
	bLED->fade(interval);
	gLED->fade(interval);
	bLED->fade(interval);
}

void rgbLED::adjRed(Potentiometer *pot)
{
	rLED->setState(pot->getState());
}

void rgbLED::adjGreen(Potentiometer *pot)
{
	gLED->setState(pot->getState());
}

void rgbLED::adjBlue(Potentiometer *pot)
{
	bLED->setState(pot->getState());
}

void rgbLED::turnOff()
{
    rLED->setState(false);
    gLED->setState(false);
    bLED->setState(false);
}
