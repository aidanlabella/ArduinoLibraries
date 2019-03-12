#pragma once
#include <diode.h>
#include <pwmDeviceGroup.h>
#include <StandardCplusplus.h>
#include <digitalOutput.h>
#include <string>
#include <vector>

using namespace std;

class segDisplayRGB{
	private:
		pwmDevice *r1, *r2, *b1, *b2, *g1, *g2;
		Diode a, b, c, d, e, f, g;
		pwmDeviceGroup anodeGroup1, anodeGroup2, anodes, cathodes;
		void displayDigit(int);
	public:
		segDisplayRGB(int _a, int _b, int _c, int _d, int _e, int _f,
					  int _g, int rg1, int rg2, int bg1, int bg2, int gg1, int gg2);
	    void reset();
		void setLeftColor(string color);
		void setRightColor(string color);
		void displayNum(int num,int);
		void setAnodeGroup2(bool);
		void setAnodeGroup1(bool);
		void resetCathodes();
		void setBrightness(int);
		bool pause(int time);
};
