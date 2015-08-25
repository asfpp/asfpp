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

#include "RoomMonitoring.h"

Define_Module(RoomMonitoring);

void RoomMonitoring::calculateAverages()
{
	
	int numClusters;
	int clusterSize;
	int totalSamples;
	double roomAverage;
	double* clusterAverages;
	ofstream outputFile;
	string outputFileName;
	char indexes[] = {'1','2','3','4','5','6','7'}; // TODO This has to be improved!
	
	numClusters = sensorClusters.size();
	clusterSize = numSensors / numClusters;
	clusterAverages = new double[numClusters];
  
	roomAverage = 0;
	totalSamples = 0;
	
	for (int i = 0; i < numClusters; i++)
	  clusterAverages[i] = 0;
	
	/* Cluster avarages calculation */
	for (int i = 0; i < numClusters; i++) {
	  for (int j = 0; j < clusterSize; j++) {
	    int index = sensorClusters[i][j];
	    clusterAverages[i] += sampleBucket[index-1];
	    roomAverage += sampleBucket[index-1];
	  }
	  clusterAverages[i] /= clusterSamplesCount[i];
	  totalSamples += clusterSamplesCount[i];
	}
	
	/* Write cluster avarages on output files */
	for (int i = 0; i < numClusters; i++) {
	  string suffix (indexes, i, 1);
	  outputFileName.assign("cluster" + suffix + ".txt");
	  outputFile.open(outputFileName.c_str(), ios::app);
	  
	  if(!outputFile) 
	    opp_error("Error opening file %s", outputFileName.c_str());
	  
	  trace() << "cluster, writing on file " << outputFileName << " cluster " << i << " average " << clusterAverages[i];
	  outputFile << (int)(simTime().dbl()) << " " << clusterAverages[i] << '\n';
	  
	  outputFileName.assign("");
	  outputFile.close();
	  
	}
	
	/* Whole room average */
	roomAverage /= totalSamples;
	outputFileName.assign("room.txt");
	outputFile.open(outputFileName.c_str(), ios::app);
	
	if(!outputFile) 
	  opp_error("Error opening file %s", outputFileName.c_str());
	
	trace() << "writing on file " << outputFileName << " room average " << roomAverage;
	outputFile << (int)(simTime().dbl()) << " " << roomAverage << '\n';
	
	outputFileName = "";
	outputFile.close();
	
	/* Clear the cluster sample counters */
	for (int i = 0; i < numClusters; i++)
	    clusterSamplesCount[i] = 0;
	
	/* Clear all sample buckets */
	for (int i = 0; i < numSensors; i++)
	  sampleBucket[i] = 0;
	
	delete clusterAverages;
  
}

void RoomMonitoring::startup()
{
	reportTreshold = par("reportTreshold");
	sampleInterval = (double)par("sampleInterval") / 1000;
	reportDestination = par("reportDestination").stringValue();
	
	/* Average calculation setting */
	/* TODO Make this dinamically configurable */
	
	if (isSink) {
	  
	  int numClusters;
	  int clusterSize = 6; // number of nodes per cluster
	  vector<int> vectorClusterIDs;
	  
	  numSensors = (getParentModule() -> getParentModule() -> par("numNodes"));
	  numSensors--; // Do not include the sink node
	  numClusters = numSensors / clusterSize;
	  averageInterval = par("averageInterval");
	  averagesComputations = 0;
	  clusterSamplesCount = new int[numClusters];
	  sampleBucket = new double[numSensors];
	  
	  for (int i = 0; i < numClusters; i++)
	    clusterSamplesCount[i] = 0;
	    
	  for (int i = 0; i < numSensors; i++)
	    sampleBucket[i] = 0;
	  
	  sensorClusters.clear();
	  int sensorIDs1[] = {1,2,7,8,13,14};
	  int sensorIDs2[] = {3,4,9,10,15,16};
	  int sensorIDs3[] = {5,6,11,12,17,18};
	  
	  vectorClusterIDs.clear();
	  vectorClusterIDs.assign(sensorIDs1, sensorIDs1 + clusterSize);
	  sensorClusters.push_back(vectorClusterIDs);
	  
	  vectorClusterIDs.clear();
	  vectorClusterIDs.assign(sensorIDs2, sensorIDs2 + clusterSize);
	  sensorClusters.push_back(vectorClusterIDs);
	  
	  vectorClusterIDs.clear();
	  vectorClusterIDs.assign(sensorIDs3, sensorIDs3 + clusterSize);
	  sensorClusters.push_back(vectorClusterIDs);
	  
	  for (int i = 0; i < numClusters; i++)
	    for (int j = 0; j < clusterSize; j++)
	      clustersMembership.insert(pair<int,int>(sensorClusters[i][j],i));
	    
	
	}
	
	/* *************************** */
	
	currSampleSN = 1;
	outOfEnergy = 0;

	report_info_table.clear();

	if (!isSink)
		setTimer(REQUEST_SAMPLE, sampleInterval);
	
	if (isSink) {
		averagesComputations++;
		setTimer(CALCULATE_AVERAGE, averageInterval);
		trace() << "Timer has been started. Trigger expected at " << averageInterval * averagesComputations;
	}
	
}

void RoomMonitoring::timerFiredCallback(int timer)
{
	switch (timer) {

		case REQUEST_SAMPLE:{
			setTimer(REQUEST_SAMPLE, sampleInterval);
			requestSensorReading();
			break;
		}

		case CALCULATE_AVERAGE:{
			calculateAverages();
			averagesComputations++;
			trace() << "next computation expected at " << averageInterval * averagesComputations;
			setTimer(CALCULATE_AVERAGE, averageInterval);
			break;
		}
		
	}
}

void RoomMonitoring::fromNetworkLayer(ApplicationPacket * rcvPacket,
			const char *source, double rssi, double lqi)
{
	string packetName(rcvPacket->getName());

	double data = rcvPacket->getData();
	int sequenceNumber = rcvPacket->getSequenceNumber();

	if (packetName.compare(REPORT_PACKET_NAME) == 0) {
		// this is report packet which contains sensor reading information
		// NOTE that sourceNodeID field is used to store source address instead of using char *source
		// this is done because some routing and flooding is done on the application layer
		// and source address will not always correctly represent the author of the sensed data
		
		RoomMonitoringDataPacket* datapkt = check_and_cast<RoomMonitoringDataPacket*>(rcvPacket);
		int sourceNodeID = datapkt->getSourceNodeID();
		
		trace() << "-> Received report from " << sourceNodeID;

		if (updateReportTable(sourceNodeID, sequenceNumber)) {
			// forward the packet only if we broadcast reports and this is a new (unseen) report
			// updateReportTable returns 0 for duplicate packets
			if (!isSink) {
				trace() << "-> APPLICATION LAYER : RELAY";
				toNetworkLayer(rcvPacket->dup(), reportDestination.c_str());
			}
			/* The sink has just received an original report */
			else {
			  
				/* DEBUG output */
				trace () << "[" << sourceNodeID << "]" << "Original report received by the sink from node " << sourceNodeID << " SN " << sequenceNumber << " Sensed value is " << data;
				
				/* Update the source bucket associated to the source node */
				sampleBucket[sourceNodeID - 1] += data;
				
				/* Update the number or samples associated to this node's cluster */
				int clusterIndex = clustersMembership[sourceNodeID];
				clusterSamplesCount[clusterIndex]++;
				
	
			}
		}

	} else {
		trace() << "unknown packet received: [" << packetName << "]";
	}
}

void RoomMonitoring::handleSensorReading(SensorReadingMessage * sensorMsg)
{
	string sensType(sensorMsg->getSensorType());
	double sensValue = sensorMsg->getSensedValue();

	if (isSink) {
		trace() << "Sink recieved SENSOR_READING (while it shouldnt) "
		    << sensValue << " (int)" << (int)sensValue;
		return;
	}

	if (sensValue < reportTreshold) {
		trace() << "Sensed value " << sensValue << " is less than the treshold ("
			<< reportTreshold << "), discarding";
		return;
	}

	int x = mobilityModule->getLocation().x;
	int y = mobilityModule->getLocation().y;
	
	trace() << "Sending report packet, sequence number " << currSampleSN << " Value " << sensValue << " x " << x << " y " << y;
	RoomMonitoringDataPacket *newPkt = new RoomMonitoringDataPacket("Room monitoring pkt", APPLICATION_PACKET);
	newPkt->setName(REPORT_PACKET_NAME);
	newPkt->setData(sensValue);
	newPkt->setSourceNodeID((unsigned short)self);
	newPkt->setSequenceNumber(currSampleSN);
	newPkt->setByteLength(sizeof(sensValue));
	toNetworkLayer(newPkt, reportDestination.c_str());
	currSampleSN++;
}

void RoomMonitoring::finishSpecific()
{
	if (isSink) {
		declareOutput("Report reception");
		for (int i = 0; i < (int)report_info_table.size(); i++) {
			collectOutput("Report reception", report_info_table[i].source,
					"Success", report_info_table[i].parts.size());
			collectOutput("Report reception", report_info_table[i].source,
					"Fail", report_info_table[i].seq - report_info_table[i].parts.size());
		}
		calculateAverages();
		delete clusterSamplesCount;
		delete sampleBucket;
		clustersMembership.clear();
		sensorClusters.clear();
	}
}

int RoomMonitoring::updateReportTable(int src, int seq)
{
	int pos = -1;
	for (int i = 0; i < (int)report_info_table.size(); i++) {
		if (report_info_table[i].source == src)
			pos = i;
	}

	if (pos == -1) {
		report_info newInfo;
		newInfo.source = src;
		newInfo.parts.clear();
		newInfo.parts.push_back(seq);
		newInfo.seq = seq;
		report_info_table.push_back(newInfo);
	} else {
		for (int i = 0; i < (int)report_info_table[pos].parts.size(); i++) {
			if (report_info_table[pos].parts[i] == seq)
				return 0;
		}
		report_info_table[pos].parts.push_back(seq);
		if (seq > report_info_table[pos].seq) {
			report_info_table[pos].seq = seq;
		}
	}
	return 1;
}
