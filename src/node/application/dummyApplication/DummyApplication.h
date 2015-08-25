/****************************************************************************
 *  Copyright: Università di Pisa  2013			                    *
 *  Author(s): Alessandro Pischedda                                         *
 *                                                                          *
 ****************************************************************************/

/*
 * This application do nothing.
 */

#ifndef _DummyApplication_H_
#define _DummyApplication_H_

#include "VirtualApplication.h"
#include <fstream>

#include <vector>
#include <map>
#include <string>

using namespace std;



class DummyApplication:public VirtualApplication {
 private:
	

	simtime_t outOfEnergy;

 protected:
	virtual void startup();
	void finishSpecific();
	
	void fromNetworkLayer(ApplicationPacket *, const char *, double, double);
	void timerFiredCallback(int);
	void handleSensorReading(SensorReadingMessage *);
};

#endif	
