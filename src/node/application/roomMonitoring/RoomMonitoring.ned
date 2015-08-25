//********************************************************************************
//*  Copyright: National ICT Australia,  2007 - 2010                             *
//*  Developed at the ATP lab, Networked Systems research theme                  *
//*  Author(s): Yuriy Tselishchev                                                *
//*  This file is distributed under the terms in the attached LICENSE file.      *
//*  If you do not find this file, copies can be found by writing to:            *
//*                                                                              *
//*      NICTA, Locked Bag 9013, Alexandria, NSW 1435, Australia                 *
//*      Attention:  License Inquiry.                                            *
//*                                                                              *
//*******************************************************************************/

package node.application.roomMonitoring;

// The sensor node module. Connects to the wireless channel in order to communicate 
// with other nodes. Connects to psysical processes so it can sample them.

simple RoomMonitoring like node.application.iApplication {
 parameters: 
 	string applicationID = default ("RoomMonitoring");
	bool collectTraceInfo = default (false);
	int priority = default (1);
	// 4 bytes sourceNodeID, 4 bytes timestamp , 4 bytes sequence number = 12 bytes
	int packetHeaderOverhead = default (12); // in bytes
	int constantDataPayload = default (0);

	bool isSink = default (false);

	string reportDestination = default ("0");	//this can also be set to "-1" for broadcast
												// or to a specific node's address (e.g "0")

	double reportTreshold = default (10);
	double sampleInterval = default (100);	// in ms
	
	double averageInterval = default (10); // in seconds

 gates:
 	output toCommunicationModule;
	output toSensorDeviceManager;
	input fromCommunicationModule;
	input fromSensorDeviceManager;
	input fromResourceManager;
}

