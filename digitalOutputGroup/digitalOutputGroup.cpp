#include "digitalOutputGroup.h"

digitalOutput* digitalOutputGroup::elementAt(int index)
{
	return devices[index];
}
void digitalOutputGroup::add(digitalOutput *newItem)
{
	devices.push_back(newItem);
}
void digitalOutputGroup::setAll(bool state)
{
	if(devices.size()<=0)
		return;
	for(int i = 0; i<devices.size(); i++)
		devices[i]->setState(state);
}
void digitalOutputGroup::removeAll()
{
	if(!this->isEmpty())
	{
		for(int i = devices.size(); i>0; --i)
			devices.erase(i);
	}
}


		