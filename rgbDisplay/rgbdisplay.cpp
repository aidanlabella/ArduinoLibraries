#include "rgbdisplay.h"

segDisplayRGB::segDisplayRGB(int _a, int _b, int _c, int _d, int _e, int _f,
							 int _g, int rg1, int rg2, int bg1, int bg2, int gg1, int gg2):
							 a(_a,true),b(_b,true),c(_c,true),d(_d,true),e(_e,true),f(_f,true),
							 g(_g,true)
{
	r1 = new Diode(rg1,true);
	r2 = new Diode(rg2,true);
	b1 = new Diode(bg1,true);
	b2 = new Diode(bg2,true);
	g1 = new Diode(gg1,true);
	g2 = new Diode(gg2,true);
	cathodes.add(&a);
	cathodes.add(&b);
	cathodes.add(&c);
	cathodes.add(&d);
	cathodes.add(&e);
	cathodes.add(&f);
	cathodes.add(&g);
	anodes.add(r1);
	anodes.add(r2);
	anodes.add(b1);
	anodes.add(b2);
	anodes.add(g1);
	anodes.add(g2);
}

void segDisplayRGB::reset()
{
	cathodes.setAll(false);
	anodes.setAll(true);
}
void segDisplayRGB::resetCathodes()
{
	cathodes.setAll(false);
}
void segDisplayRGB::setAnodeGroup1(bool st)
{
	anodeGroup1.setAll(st);
}
void segDisplayRGB::setAnodeGroup2(bool st)
{
	anodeGroup2.setAll(st);
}
void segDisplayRGB::setBrightness(int bright)
{
	anodeGroup1.setMaxState(bright);
}
void segDisplayRGB::setRightColor(string color)
{
	anodeGroup1.removeAll();
	if(color=="blue")
		anodeGroup1.add(b2);
	if(color=="red")
		anodeGroup1.add(r2);
	if(color=="green")
		anodeGroup1.add(g2);
	if(color=="purple")
	{
		anodeGroup1.add(r2);
		anodeGroup1.add(b2);
	}
	if(color=="yellow")
    {
        anodeGroup1.add(r2);
        anodeGroup1.add(g2);
    }
    if(color=="turquoise")
    {
        anodeGroup1.add(b2);
        anodeGroup1.add(g2);
    }
    if(color=="white")
    {
        anodeGroup1.add(r2);
        anodeGroup1.add(b2);
        anodeGroup1.add(g2);
    }
}

void segDisplayRGB::setLeftColor(string color)
{
	anodeGroup2.removeAll();
	if(color=="blue")
		anodeGroup2.add(b1);
	if(color=="red")
		anodeGroup2.add(r1);
	if(color=="green")
		anodeGroup2.add(g1);
	if(color=="purple")
	{
		anodeGroup2.add(r1);
		anodeGroup2.add(b1);
	}
	if(color=="yellow")
    {
        anodeGroup2.add(r1);
        anodeGroup2.add(g1);
    }
    if(color=="turquoise")
    {
        anodeGroup2.add(b1);
        anodeGroup2.add(g1);
    }
    if(color=="white")
    {
        anodeGroup2.add(r1);
        anodeGroup2.add(b1);
        anodeGroup2.add(g1);
    }
}
void segDisplayRGB::displayDigit(int num)
{
	bool state = true;
	switch(num)
	{
		case 0:
			a.setState(state);
			f.setState(state);
			e.setState(state);
			d.setState(state);
			c.setState(state);
			b.setState(state);
			break;
		case 1:
			b.setState(state);
			c.setState(state);
			break;
		case 2:
			a.setState(state);
			b.setState(state);
			g.setState(state);
	     	e.setState(state);
			d.setState(state);
			break;
		case 3:
		    a.setState(state);
			b.setState(state);
			g.setState(state);
			c.setState(state);
			d.setState(state);
			break;
		case 4:
			f.setState(state);
			g.setState(state);
			b.setState(state);
			c.setState(state);
			break;
		case 5:
			a.setState(state);
			f.setState(state);
			g.setState(state);
			c.setState(state);
			d.setState(state);
			break;
		case 6:
			a.setState(state);
			f.setState(state);
			g.setState(state);
			e.setState(state);
			c.setState(state);
			d.setState(state);
		break;
			case 7:
			a.setState(state);
			b.setState(state);
			c.setState(state);
			break;
		case 8:
			a.setState(state);
			b.setState(state);
			c.setState(state);
			d.setState(state);
			e.setState(state);
			f.setState(state);
			g.setState(state);
			break;
		case 9:
			a.setState(state);
			f.setState(state);
			g.setState(state);
			b.setState(state);
			c.setState(state);
			break;
		default:
			g.setState(state);
			break;
	}
}
bool segDisplayRGB::pause(int time)//returns true if code is paused for time
{
	unsigned long start = millis();
	while(true)
	{
		if(millis()-start>=time)
			return true;
	}
}

void segDisplayRGB::displayNum(int num, int dur)
{
	this->reset();
	bool digit = false;
	if(num>=0 && num<10)
	{
		anodeGroup1.setAll(0);
		this->displayDigit(num);
		this->pause(dur);
	}
	else if(num>=10 && num<100)
	{
		int leftDigit=num/10;
		int rightDigit=num%10;
		unsigned long milStart = millis();
		while(millis()-milStart<=dur)
		{
			if(digit)
			{
				anodeGroup1.setAll(false);
				anodeGroup2.setAll(true);
				this->displayDigit(rightDigit);
			}
			else
			{
				anodeGroup1.setAll(true);
				anodeGroup2.setAll(false);
				this->displayDigit(leftDigit);
			}
			digit=!digit;
			this->reset();
		}
	}
}
