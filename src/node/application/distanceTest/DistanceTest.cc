/****************************************************************************
 *  Copyright: National ICT Australia,  2007 - 2011                         *
 *  Developed at the ATP lab, Networked Systems research theme              *
 *  Author(s): Dimosthenis Pediaditakis, Yuriy Tselishchev                  *
 *  This file is distributed under the terms in the attached LICENSE file.  *
 *  If you do not find this file, copies can be found by writing to:        *
 *                                                                          *
 *      NICTA, Locked Bag 9013, Alexandria, NSW 1435, Australia             *
 *      Attention:  License Inquiry.                                        *
 *                                                                          *
 ****************************************************************************/

#include "DistanceTest.h"

Define_Module(DistanceTest);

void DistanceTest::startup()
{
	maxSampleInterval = ((double)par("maxSampleInterval")) / 1000.0;
	minSampleInterval = ((double)par("minSampleInterval")) / 1000.0;
	currSentSampleSN = 0;
	randomBackoffIntervalFraction = genk_dblrand(0);
	sentOnce = false;
	if (!isSink)
		setTimer(REQUEST_SAMPLE, minSampleInterval);
}

void DistanceTest::timerFiredCallback(int index)
{
	switch (index) {

		case REQUEST_SAMPLE:{
			requestSensorReading();
			setTimer(REQUEST_SAMPLE, minSampleInterval);
			break;
		}
	}
}

void DistanceTest::fromNetworkLayer(ApplicationPacket * genericPacket,
		 const char *source, double rssi, double lqi)
{
	
	DistanceTestDataPacket *rcvPacket = check_and_cast<DistanceTestDataPacket*>(genericPacket);
	DistanceReportData theData = rcvPacket->getExtraData();
	if (isSink)
		trace() << "Sink received from: \n\tNodeID"<<theData.nodeID <<"\n\tx : " << theData.locX << "\n\ty : " << theData.locY;
}

void DistanceTest::handleSensorReading(SensorReadingMessage * rcvReading)
{

	if(isSink)
		return;

	double sensValue = rcvReading->getSensedValue();
	trace() << "Sensed = " << sensValue;
	
	DistanceReportData tmpData;
	tmpData.nodeID = (unsigned short)self;
	tmpData.locX = mobilityModule->getLocation().x;
	tmpData.locY = mobilityModule->getLocation().y;
	
	DistanceTestDataPacket *packet2Net = new DistanceTestDataPacket("Value reporting pck", APPLICATION_PACKET);
	packet2Net->setExtraData(tmpData);
	packet2Net->setData(sensValue);
	packet2Net->setSequenceNumber(currSentSampleSN);
	currSentSampleSN++;
	
	toNetworkLayer(packet2Net, "0");
	sentOnce = true;
}

