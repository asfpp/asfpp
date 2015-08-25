/****************************************************************************
 *  Copyright: National ICT Australia,  2007 - 2011                         *
 *  Developed at the ATP lab, Networked Systems research theme              *
 *  Author(s): Yuriy Tselishchev                                            *
 *  This file is distributed under the terms in the attached LICENSE file.  *
 *  If you do not find this file, copies can be found by writing to:        *
 *                                                                          *
 *      NICTA, Locked Bag 9013, Alexandria, NSW 1435, Australia             *
 *      Attention:  License Inquiry.                                        *
 *                                                                          *
 ****************************************************************************/

#ifndef _RoomMonitoring_H_
#define _RoomMonitoring_H_

#include "VirtualApplication.h"
#include "RoomMonitoringPacket_m.h"
#include <fstream>

#include <vector>
#include <map>
#include <string>

#define REPORT_PACKET_NAME "Room monitoring report packet"

using namespace std;

struct report_info {
	int source;
	int seq;
	vector<int> parts;
};

enum RoomMonitoringTimers {
	REQUEST_SAMPLE = 1,
	CALCULATE_AVERAGE = 2,
};

class RoomMonitoring:public VirtualApplication {
 private:
	int reportTreshold;
	double sampleInterval;
	int sampleSize;

	simtime_t outOfEnergy;

	int currSampleSN;
	int routingLevel;
	vector<report_info> report_info_table;

	string reportDestination;
	
	int numSensors; // number of sensing nodes in the network
	double averageInterval; // amount of seconds between two consecutive average calculations (in seconds)
	double* sampleBucket; // sums of values sensed by nodes during the current average window
	int averagesComputations; // DEBUG variable
	int* clusterSamplesCount; // number of samples per cluster in the current average window
	
	/* TODO Make this dinamically configurable (see RoomMonitoring.cc) */
	map<int,int> clustersMembership;  // In each pair <x,y>, x is a nodeID, and y is entry of 'clusterSamples' referred to its cluster
	vector< vector<int> > sensorClusters; // Each vector is a cluster, and contains the IDs of its members
	
	/* Calculate averages every 'sampleInterval' seconds and write them to output files */
	void calculateAverages();

 protected:
	virtual void startup();
	void finishSpecific();
	void send2NetworkDataPacket(const char *destID, const char *pcktID, int data, int pckSeqNumber, int size);
	int updateReportTable(int src, int seq);
	void fromNetworkLayer(ApplicationPacket *, const char *, double, double);
	void timerFiredCallback(int);
	void handleSensorReading(SensorReadingMessage *);
};

#endif				// _RoomMonitoring_H_
