#include "potentiometer.h"

Potentiometer::Potentiometer(int p, int lower, int upper):
		analogInput(p),scaleLower(lower),scaleUpper(upper){}
	
int Potentiometer::getState()//returns scaled state of potentiometer
{
	return map(analogInput::getState(),0,this->defUpperBound,this->scaleLower,this->scaleUpper);
}

int Potentiometer::getRawState()
{
	return analogInput::getState();
}

string Potentiometer::toString()
{
	return pin+" state:"+super::getState();
}