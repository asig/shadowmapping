//////////////////////////////////////////////////////////////////////////////////////////
//	FPS_COUNTER.cpp
//	Functions for Frames per second counter class
//	Downloaded from: www.paulsprojects.net
//	Created:	20th July 2002
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////
#include "FPS_COUNTER.h"
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

void FPS_COUNTER::Update(void)
{
	++frames;

	//If a second has passed
	double ms = timer.GetTime();
	if(ms>1000) {
		float secs = ms/1000.0;	
		fps=frames/secs;	//update the number of frames per second
		timer.Reset();
		frames=0;					//reset fps for this second
	}
}