#include "pwmDeviceGroup.h"

pwmDevice* pwmDeviceGroup::elementAt(int index)
{
	return items[index];
}
pwmDeviceGroup::pwmDeviceGroup()
{
	state=false;
	maxState=255;
}
void pwmDeviceGroup::pause(int time)
{
	unsigned long sMil = millis();
	while(millis()-sMil>=0){
		if(millis()-sMil>=time)
			return;
	}
}
int pwmDeviceGroup::length()
{
	return items.size();
}
bool pwmDeviceGroup::isEmpty()
{
	return (items.size() <= 0);
}
void pwmDeviceGroup::add(pwmDevice *newDev)
{
	items.push_back(newDev);
}	
void pwmDeviceGroup::setAll(bool set)
{
	if(!this->isEmpty())
	{
		for(int i = 0; i<items.size(); i++)
			items[i]->setState(set);//must call superclass for boolean
	}
}
void pwmDeviceGroup::setMaxState(int st)
{
	maxState=st;
}
void pwmDeviceGroup::cycle(int delayTime)
{
	for(int i = 0; i<this->items.size(); ++i)
	{
		items[i]->setState(true);
		this->pause(delayTime);
		items[i]->setState(false);
	}
}
void pwmDeviceGroup::cycle(int delayTime, int state)
{
	for(int i = 0; i<this->items.size(); ++i)
	{
		items[i]->setState(state);
		this->pause(delayTime);
		items[i]->setState(state);
	}
}
void pwmDeviceGroup::twoWayCycle(int delayTime)
{
	for(int i = 0; i<this->items.size(); ++i)
	{
		items[i]->setState(true);
		this->pause(delayTime);
		items[i]->setState(false);
	}
	for(int i = this->items.size()-2; i>0; --i)
	{
		items[i]->setState(true);
		this->pause(delayTime);
		items[i]->setState(false);
	}
}
void pwmDeviceGroup::cycleCont(int delayTime, int iterations)
{
	if(iterations<=0)
		return;
	else{
		cycle(delayTime);
		cycleCont(delayTime, iterations-1);
	}

}
void pwmDeviceGroup::setAll(int set)
{
	if(!this->isEmpty())
	{
		for(int i = 0; i<items.size(); i++)
		{
			if(set>maxState)
				items[i]->setState(maxState);
			else
				items[i]->setState(set);
		}
	}
}
void pwmDeviceGroup::flash(int iterations, unsigned int delayTime)
{
	if (iterations <= 0 || this->isEmpty())
		return;
	iterations*=2;
	for(int i = iterations; i>=0; --i)
	{
		long startMil = millis();
		while(millis()-startMil>=0)
		{
			if(millis()-startMil>=delayTime)
			{
				this->setAll(state);
				state=!state;
				break;
			}
		}
	}
}	
void pwmDeviceGroup::alternateFlash(int iterations, unsigned int delayTime)
{
	if(!this->isEmpty())
	{
		iterations*=2;
		for(int i = iterations; i>=0; --i)
		{
			long int startMil = millis();
			while (millis() - startMil >= 0)
			{
				if(millis()-startMil>=delayTime){
					for (int i = 0; i < items.size(); i++)
					{
						if (i % 2 == 0)
							items[i]->setState(state);
						else
							items[i]->setState(!state);
					}
					state = !state;
					break;
				}
			}
		}
	}
}
void pwmDeviceGroup::fadeUp(int delayTime)
{
	for(int i = 0; i<256; i++)
	{
		this->setAll(i);
		delay(delayTime);
	}
}
void pwmDeviceGroup::fadeDown(int delayTime)
{
	for(int j = 255; j>=0; j--)
	{
		this->setAll(j);
		delay(delayTime);
	}
}
void pwmDeviceGroup::fade(int delayTime)//fade for chamelion program
{
	if(state)
		this->fadeUp(delayTime);
	else
		this->fadeDown(delayTime);
	state = !state;
}
bool pwmDeviceGroup::toggleSelect(int e, int time)
{
	if(this->items.size()>e){
		items[e]->setState(true);
		this->pause(time);
		items[e]->setState(false);
		return true;
	}else
		return false;
}
void pwmDeviceGroup::removeAll()
{
	if(!this->isEmpty())
	{
		for(int i = items.size(); i>0; --i)
			items.erase(i);
	}
}