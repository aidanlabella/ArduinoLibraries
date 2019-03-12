#pragma once

#include "digitalOutput.h"
#include <StandardCplusplus.h>
#include <vector>

using namespace std;

class digitalOutputGroup{
	private:
		vector<digitalOutput*> devices;
	public:
		digitalOutputGroup() {};
		digitalOutput* elementAt(int index);
		void add(digitalOutput *newItem);
		void setAll(bool state);
		void removeAll();
		bool isEmpty(){return (devices.size()<=0);}
};
