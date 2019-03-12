#include "microphone.h"

microphone::microphone(int pinnum, int thresh):
	analogInput(pinnum),threshold(thresh){}//constructor - calls analogInput superclass for pinnum

//returns number of taps in the given interval
//preconditon: @param interval is >0;
int microphone::numOfTaps(int interval)
{
	int count = 0;
	long milStart=millis();
	while(millis()-milStart<=interval)
	{
		if(this->wasTapped())//only increment counter if speaker was tapped
			count++;
	}
	return count;
}
//returns true if a reading is within the limits (60)
bool microphone::wasTapped()
{
	int debounceState = 0;
	int initState=analogInput::getState();//read inital state
	long milStart=millis();//millis start timestamp
	while(millis()-milStart>=0)//start loop
	{
		if(millis()-milStart>=DEBOUNCE_TIME)
		{
			debounceState = analogInput::getState();//set debounce state after delay
			if(initState>=threshold)//only check if the reading is within the interval
				return (initState-debounceState<=DEBOUNCE_THRESH||initState-debounceState>=DEBOUNCE_THRESH);
			else
				return false;
		}
	}
}
