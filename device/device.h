#pragma once

#include "Arduino.h"
#include <StandardCplusplus.h>
#include <string>

using namespace std;

class Device
{
protected:
	int pin;
public:
	Device(int pinnum):pin(pinnum){}
	int pinNumber(){return pin;}
	virtual string toString() = 0;
};