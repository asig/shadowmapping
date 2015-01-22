//////////////////////////////////////////////////////////////////////////////////////////
//	TIMER.cpp
//	Functions for timer class
//	Downloaded from: www.paulsprojects.net
//	Created:	20th July 2002
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////

#include "TIMER.h"

#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

long getTimeMs() {	
    timespec spec;
    clock_gettime(CLOCK_REALTIME, &spec);
    return  spec.tv_sec * 1000 + round(spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds   
}

void TIMER::Reset()
{
	startTime=(double)getTimeMs();
}

double TIMER::GetTime()
{
	if(isPaused)
		return pauseTime-startTime;
	else
		return ((double)getTimeMs())-startTime;
}

void TIMER::Pause()
{
	//Only pause if currently unpaused
	if(isPaused)
		return;

	isPaused=true;
	pauseTime=(double)getTimeMs();
}

void TIMER::Unpause()
{
	//Only unpause if currently paused
	if(!isPaused)
		return;

	isPaused=false;

	//Update start time to reflect pause
	startTime+=((double)getTimeMs()-pauseTime);
}