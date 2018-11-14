/****************************************************************************
*  Author(s): Alessandro Pischedda                                          *
*                                                                           *
*  This application is used in a cluster network  topology.  		    *
*  Hypothesis : 							    *
*	- TMAC								    *
*	- Multipath Rings routing					    *
*	- Clusters are isolated, i.e. they cannot "see" with each other     *
* 									    *
*  There are three kinds of nodes :					    *
*  	- sink	<- Multipath rings routing 				    *
*	- coordinator or cluster_head					    *
*	- cluster_node    						    *
* 									    *
*  Nodes in a cluster sense the enviroment and send their reports using     *
*  the broadcast network address. The cluster head receives and stores      *
*  them. Then, it periocally computes an average value using the stored     *
*  ones, and sends it to the sink.					    *
* 									    *
*  Cluster heads work in two possible ways:				    *
*									    *
*	- No authentication,	simply store received report messages	    *
*	- Authentication, 	they maintain a set of authorized nodes	    *
* 									    *
*  This can be specified in the omnetpp.ini (see Application.cluster_nodes) *
*  An empty string means no authenticatin. Otherwise, nodeIDs of authorized *
*  separated by a whitespace must be specified.				    *
*									    *
*  Example :								    *
*		SN.node[1].isCoordinator = true				    *
*		SN.node[1].Application.cluster_nodes = "4 5 6 7"	    *
*									    *
****************************************************************************/

#ifndef _CLUSTERAGGREGATOR_H_
#define _CLUSTERAGGREGATOR_H_

#include "VirtualApplication.h"
#include "ClusterAggregatorPacket_m.h"
#include "utils.h"
#include <fstream>
#include <math.h> // for floor() function
#include <vector>
#include <map>
#include <string>


using namespace std;

struct report_info {
	int source;
	int seq;
	vector<int> parts;
};

enum ClusterAggregatorTimers {
	REQUEST_SAMPLE = 1,
	CALCULATE_AVERAGE = 2,
};

class ClusterAggregator:public VirtualApplication {
 private:
	double sampleInterval;
	int sampleSize;
	int maxPayload;
	
	bool isCoordinator;  	      // True if this is a coordinator node
	bool authentication; 	      // Relevant only for the coordinator
	bool digestEnabled;	      // True if the packet contains the digest, false otherwise
	vector<string> cluster_nodes; // List of nodes in the cluster, used only by coordinator nodes

	simtime_t outOfEnergy;

	double interval;

	int currSampleSN;
	int currentSampleAccumulated;
	int maxSampleAccumulated;
	vector<report_info> report_info_table;

	string reportDestination; // Network level destination
	
	double averageInterval;   // Amount of time between two consecutive average calculations (seconds)
	double clusterSamples;
	int averagesComputations; // DEBUG variable
	int clusterSamplesCount;  // Number of samples per cluster in the current average window
	double driftCorrection;

	/* About metrics */
	int payloadSize;	// In bytes
	double delaySum;
	int bytesReceived ;	// Total number of received bytes
	int packetsReceived;	// Number of packets received correctly
	double simulationTime;  // Used to compute the throughput


	/* Calculate averages every 'averageInterval' seconds and write them to output files */
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

#endif
