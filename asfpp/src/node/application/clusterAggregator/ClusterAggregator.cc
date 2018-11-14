/***************************************************************************
 *  Author(s): Alessandro Pischedda                                        *
 *                                                                         *
 ***************************************************************************/

#include "ClusterAggregator.h"

Define_Module(ClusterAggregator);

void ClusterAggregator::calculateAverages()
{
	double avgReport = 0;

	/* Compute the average */
	if (clusterSamples != 0)
		avgReport = clusterSamples/clusterSamplesCount;

	if(isCoordinator){ // On a coordinator node
	  
		/* Create the average packet */
		ClusterAggregatorDataPacket *newPkt = new ClusterAggregatorDataPacket("Cluster report packet", APPLICATION_PACKET);
		newPkt->setData(avgReport);
		newPkt->setSourceNodeID((unsigned short)self);
		newPkt->setSequenceNumber(currSampleSN);
		newPkt->setByteLength( 	payloadSize );

		if( digestEnabled)
			newPkt->setDigest(1);

		/* Send the packet to the Sink node */
		toNetworkLayer(newPkt, reportDestination.c_str());

		/* Update the sequence number */
		currSampleSN++;

	}

	/* Data cleaning */
	clusterSamples = 0;
	clusterSamplesCount = 0;


}

/* Initialize the application */
void ClusterAggregator::startup()
{
	string simtime;

	sampleInterval = (double)par("sampleInterval") / 1000;
	reportDestination = par("reportDestination").stringValue();
	isCoordinator = (bool)par("isCoordinator");	
	isSink = (bool)par("isSink");
	digestEnabled = (bool)par("digest");
	payloadSize = (int)par("constantDataPayload");
	driftCorrection = par("driftCorrection");

	/* Retrieve the simulation duration */
	simtime = string(ev.getConfig()->getConfigValue("sim-time-limit"));
	simtime = simtime.replace(simtime.size()-1, 1, ""); // Relete the 's' character
	
	simulationTime = atof( simtime.c_str() );
	
	delaySum = 0;
	packetsReceived = 0;
	bytesReceived = 0;
	authentication = false;

	/* Check if report packets are authenticated.
	 * In such a case, they include a digest, and
	 * result in an additional overhead.
	 */
	if (digestEnabled)
		packetHeaderOverhead += (int)par("digestOverhead");

	// To auth or not to auth, that is the question.	
	if( isCoordinator ){

		authentication = (bool)par("authentication");
		string nodes = par("cluster_nodes");

		tokenize(cluster_nodes ,nodes , ' ');

	}
	
	currSampleSN = 1;
	outOfEnergy = 0;
	averagesComputations = 0;
	clusterSamples = 0;
	clusterSamplesCount = 0;
	interval = 0;

	report_info_table.clear();

	/* Simple sensor node */
	if (!isSink && !isCoordinator)
		setTimer(REQUEST_SAMPLE, sampleInterval);
	

	averageInterval = par("averageInterval");
	trace() << "AverageInterval "<< averageInterval;

	// you should calculate the average
	if ( isCoordinator ){
		averagesComputations++;
		setTimer(CALCULATE_AVERAGE, averageInterval);
	}	

}

void ClusterAggregator::timerFiredCallback(int timer)
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
			setTimer(CALCULATE_AVERAGE, averageInterval);
			break;
		}
		
	}
}

void ClusterAggregator::fromNetworkLayer(ApplicationPacket * rcvPacket,	const char *source, double rssi, double lqi){

	string packetName(rcvPacket->getName());

	double delay;

	double data = rcvPacket->getData();
	int sequenceNumber = rcvPacket->getSequenceNumber();

	ClusterAggregatorDataPacket* datapkt = check_and_cast<ClusterAggregatorDataPacket*>(rcvPacket);
	int sourceNodeID = datapkt->getSourceNodeID();
	int digestValue = datapkt->getDigest();

	/* Simple sensor node: ignore the packet. */
	if(!isSink && !isCoordinator)
		return;

	/* A coordinator node has received an authenticated packet */
	if( isCoordinator && authentication){

		bool found = false;		
		string s_sourceNodeID = itos(sourceNodeID);

		for(int i = 0; i < cluster_nodes.size(); i++ ){
			if ( s_sourceNodeID == cluster_nodes[i] ){
				found = true;
				break;
			}
		}

		if( !found )
			return;

	}

	if( digestEnabled && digestValue != 1)
		return;

	/* Proceed only if this packet has not been previously received */
	if (updateReportTable(sourceNodeID, sequenceNumber)) {
				  
		/* Report received by a coordinator node */
		if( isCoordinator ){
			/* Add this sample to the sample set */
			clusterSamples += data;

			/* Update the number of collected samples */
			clusterSamplesCount++;

		}
		
		/* Aggregated report received by the Sink node */
		if (isSink) {
			ofstream outputFile;
			string filename;
			double packetTimestamp;
			double timeDiff;

			/* compute the current window [ left, right ]*/
			int leftTemp  = floor( (simTime()).dbl() ); 	 
			int leftEdge  = leftTemp - (leftTemp % int(averageInterval) );
			int rightEdge = leftEdge + int(averageInterval);

		
			/*cause if it is 489.999 it store as 490 but see like 489.999 */
			packetTimestamp = (rcvPacket->getAppNetInfoExchange().timestamp).dbl();

			timeDiff = leftEdge - packetTimestamp;

			trace()<<" --------------------------------------------- "<<endl;

			trace()<<"SourcenodeID "<<sourceNodeID<<" timestamp "<< packetTimestamp << " data "<<data;
			trace()<<"[ "<<leftEdge<<" , "<<rightEdge<<" ]";

			if( ( packetTimestamp >= leftEdge ) && ( packetTimestamp < rightEdge) ){
				clusterSamples += data;
				clusterSamplesCount++;

				trace () <<"[ "<< sourceNodeID << "] Sensed value is " << data;

				filename = "cluster" + itos(sourceNodeID) + ".txt";
	  			outputFile.open(filename.c_str(), ios::app);
  				outputFile << leftEdge << " " << data << '\n';
				outputFile.close();

			}else if ( (packetTimestamp < leftEdge) && (timeDiff < driftCorrection )){
				clusterSamples += data;
				clusterSamplesCount++;

				trace() <<" Correction done ";
				trace() <<"[ "<< sourceNodeID << "] Sensed value is " << data;

				filename = "cluster" + itos(sourceNodeID) + ".txt";
	  			outputFile.open(filename.c_str(), ios::app);
  				outputFile << leftEdge << " " << data << '\n';
				outputFile.close();
			}
			else{
							
				trace() << "PACKET DROPPED, origin time "<<packetTimestamp ;
			}

			trace()<<" --------------------------------------------- "<< endl;					

		}

		/* Compute and store delay and throughput */
		bytesReceived += payloadSize;

		//trace() << "Received "<<payloadSize<< " byte, new total bytes received are "<<bytesReceived;
		delaySum += (simTime()).dbl() - (rcvPacket->getAppNetInfoExchange().timestamp).dbl();

		packetsReceived++;
	}
}

void ClusterAggregator::handleSensorReading(SensorReadingMessage * sensorMsg)
{
	string sensType(sensorMsg->getSensorType());
	double sensValue = sensorMsg->getSensedValue();

	/* they shouldnt receive some Sensor reading, if it happen send a message */
	if (isSink || isCoordinator ) {
		//trace() << "WARNING: Sink or Coordinator received SENSOR_READING (while it shouldnt) "    << sensValue << " (int)" << (int)sensValue;
		return;
	}

	/* Cluster node behaviour */

	int x = mobilityModule->getLocation().x;
	int y = mobilityModule->getLocation().y;
	
	ClusterAggregatorDataPacket *newPkt = new ClusterAggregatorDataPacket("Cluster report packet", APPLICATION_PACKET);
	newPkt->setData(sensValue);
	newPkt->setSourceNodeID((unsigned short)self);
	newPkt->setSequenceNumber(currSampleSN);
	newPkt->setByteLength(payloadSize);

	if (digestEnabled)
		newPkt->setDigest(1);

	toNetworkLayer(newPkt, reportDestination.c_str());
	currSampleSN++;
}

void ClusterAggregator::finishSpecific()
{
	double delay = 0;

	if (isCoordinator || isSink) {
		declareOutput("Report reception");
		for (int i = 0; i < (int)report_info_table.size(); i++) {
			collectOutput("Report reception", report_info_table[i].source,
					"Success", report_info_table[i].parts.size());
			collectOutput("Report reception", report_info_table[i].source,
					"Fail", report_info_table[i].seq - report_info_table[i].parts.size());

			declareOutput("Throughput");
			collectOutput("Throughput","bytes/s", bytesReceived / simulationTime);

			delay = delaySum / packetsReceived;

			declareOutput("Average Delay");
			collectOutput("Average Delay","sec", delay );

		}

	}

}

int ClusterAggregator::updateReportTable(int src, int seq)
{
	int pos = -1;
	for (int i = 0; i < (int)report_info_table.size(); i++) {
		if (report_info_table[i].source == src)
			pos = i;
	}

	/* if you not find an entry for that source
		create one
	*/	
	if (pos == -1) {
		report_info newInfo;
		newInfo.source = src;
		newInfo.parts.clear();
		newInfo.parts.push_back(seq);
		newInfo.seq = seq;
		report_info_table.push_back(newInfo);
	} else {

		// ok you found an entry, check if the seq number is already used

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
