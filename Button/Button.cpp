#pragma once
#include "button.h"

Button::Button(int pinnum):
		digitalInput(pinnum)
{
    prevState=false;
}

bool Button::stateHasChanged()
{
    bool stateNow = digitalInput::getState();
    if(prevState != stateNow)
    {
        prevState=stateNow;
        return true;
    }
    else
        return false;
}

bool Button::wasPressed(int time)
{
    unsigned long outerStart = millis();
    while(millis()-outerStart<=time)
    {
        if(this->stateHasChanged())
        {
            unsigned long startMil = millis();
            while(millis()-startMil>=0)
            {
                if(millis()-startMil>=DEBOUNCE_DELAY)
                {
                    if(digitalInput::getState())
                    {
                        prevState=true;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

string Button::toString()
{
	return pin+" state:"+super::getState();
}