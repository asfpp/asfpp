//********************************************************************************
//*  Author(s): Alessandro Pischedda                                             *
//*                                                                              *
//*******************************************************************************/

package node.application.clusterAggregator;

// The sensor node module. Connects to the wireless channel in order to communicate 
// with other nodes. Connects to psysical processes so it can sample them.

simple ClusterAggregator like node.application.iApplication {
 parameters: 
 	string applicationID = default ("ClusterAggregator");
	bool collectTraceInfo = default (false);
	int priority = default (1);
	// 4 bytes sourceNodeID, 4 bytes timestamp , 4 bytes sequence number = 12 bytes
	int packetHeaderOverhead = default (12); // in bytes
	int digestOverhead = default(4);	// the size (in bytes) of the digest
	int constantDataPayload = default (4);  // payload 4 byte

	bool isSink = default (false);
	bool isCoordinator = default(false);
	// if is True then the coordinators accepts only the packets from their cluster nodes 
	bool authentication = default(false);
	bool digest = default(false);


	string reportDestination = default ("0");	//this can also be set to "-1" for broadcast
							// or to a specific node's address (e.g "0")
	double sampleInterval = default (100);	// in ms
	double averageInterval = default (10); // in seconds
	double driftCorrection = default(0.1); 

	// format nodeID nodeID nodeID: ... :nodeID
	string cluster_nodes = default("");


 gates:
 	output toCommunicationModule;
	output toSensorDeviceManager;
	input fromCommunicationModule;
	input fromSensorDeviceManager;
	input fromResourceManager;
}
