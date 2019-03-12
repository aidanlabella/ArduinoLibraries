#include "speaker.h"

Speaker::Speaker(int pinnum):
pwmDevice(pinnum){}//call superclass constuctor
void Speaker::playTone(int tne, int dur)//play tone using arduino tone method
{
	tone(this->pin, tne, dur);
}
//Precondition: size of durations[] is equal to size of notes[]
//@param szOfArr is the size of both arrays, as they are =
void Speaker::playSong(vector <int> *notes, vector<int> *durations)//play song for loop
{
	int dur;//durations
	if(notes->size()!=durations->size())
		return;
	for(int i = 0; i<notes->size(); i++)
	{
		dur = 1000/durations->at(i);
		this->playTone(notes->at(i),dur);
		delay((double)dur*1.3);//delay scaled
		this->stopTone();
	}
}
void Speaker::stopTone()//stops tone from playing
{
	noTone(this->pin);
}
