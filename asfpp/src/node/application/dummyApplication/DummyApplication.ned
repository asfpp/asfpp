//****************************************************************************
//*  Copyright: Università di Pisa - 2013     			                    *
//*  Author(s): Alessandro Pischedda                                         *
//*                                                                          *
//****************************************************************************/

package castalia.node.application.dummyApplication;

// The sensor node module. Connects to the wireless channel in order to communicate 
// with other nodes. Connects to psysical processes so it can sample them.

simple DummyApplication like castalia.node.application.iApplication {
 parameters: 
 	string applicationID = default ("DummyApplication");
	bool collectTraceInfo = default (false);
	int priority = default (1);
	int packetHeaderOverhead = default(0);	// in bytes
	int constantDataPayload = default(0);	// in bytes

 gates:
 	output toCommunicationModule;
	output toSensorDeviceManager;
	input fromCommunicationModule;
	input fromSensorDeviceManager;
	input fromResourceManager;
}

