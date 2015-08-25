// ***********************************************************************************************
// *  Copyright (c) Federal University of Para, brazil - 2011                                    *
// *  Developed at the Research Group on Computer Network and Multimedia Communication (GERCOM)  *
// *  All rights reserved                                                                        *
// *                                                                                             *
// *  Permission to use, copy, modify, and distribute this protocol and its documentation for    *
// *  any purpose, without fee, and without written agreement is hereby granted, provided that   *
// *  the above copyright notice, and the author appear in all copies of this protocol.          *
// *                                                                                             *
// *  Author(s): Kassio Machado <kassio.comp@gmail.com> ,                                        *
// *             Thiago Oliveira <thiagofdso.ufpa@gmail.com>                                     *
// ***********************************************************************************************

package node.communication.routing.aodvRouting;

simple AodvRouting like node.communication.routing.iRouting
//====================================================================================
// Network_GenericFrame has the following real-world
// (non-simulation-specific) fields:
//    unsigned short int frameType; --> 2bytes
//    string source;  ----------------> 2bytes
//    string destinationCtrl; --------> 2bytes
//    string lastHop; ------------> 2bytes
//    string nextHop; ------------> 2bytes
//    unsigned short int ttl; ----> 2bytes
//    string applicationID; ------> 2bytes
// Total bytes = 7*2 = 14 (|*|)
// From these 14bytes, BypassRoutingModule doesn't use everything.
// It doesn't use the ttl and applicationID fields.
// Concluding the calculations, the Network_GenericFrame for
// BypassRoutingModule has a total overhead of:
// 14-(2+2) = 10 bytes
//====================================================================================

//====================================================================================
// RFC Configuration Parameters
//
//   Parameter Name           Value
//   ----------------------   -----
//   ACTIVE_ROUTE_TIMEOUT     3,000 Milliseconds
//   ALLOWED_HELLO_LOSS       2
//   BLACKLIST_TIMEOUT        RREQ_RETRIES * NET_TRAVERSAL_TIME
//   DELETE_PERIOD            see note below
//   HELLO_INTERVAL           1,000 Milliseconds
//   LOCAL_ADD_TTL            2
//   MAX_REPAIR_TTL           0.3 * NET_DIAMETER
//   MIN_REPAIR_TTL           see note below
//   MY_ROUTE_TIMEOUT         2 * ACTIVE_ROUTE_TIMEOUT
//   NET_DIAMETER             35
//   NET_TRAVERSAL_TIME       2 * NODE_TRAVERSAL_TIME * NET_DIAMETER
//   NEXT_HOP_WAIT            NODE_TRAVERSAL_TIME + 10
//   NODE_TRAVERSAL_TIME      40 milliseconds
//   PATH_DISCOVERY_TIME      2 * NET_TRAVERSAL_TIME
//   RERR_RATELIMIT           10
//   RING_TRAVERSAL_TIME      2 * NODE_TRAVERSAL_TIME *
//                            (TTL_VALUE + TIMEOUT_BUFFER)
//   RREQ_RETRIES             2
//   RREQ_RATELIMIT           10
//   TIMEOUT_BUFFER           2
//   TTL_START                1
//   TTL_INCREMENT            2
//   TTL_THRESHOLD            7
//   TTL_VALUE                see note below
//
// NOTE
// 
//  If Hello messages are used, then the
//  ACTIVE_ROUTE_TIMEOUT parameter value MUST be more than the value
//  (ALLOWED_HELLO_LOSS * HELLO_INTERVAL).  For a given
//  ACTIVE_ROUTE_TIMEOUT value, this may require some adjustment to the
//  value of the HELLO_INTERVAL, and consequently use of the Hello
//  Interval Extension in the Hello messages.
//
//  If Hello messages are used to determine the continued availability 
//  of links to next hop nodes, DELETE_PERIOD must be at least 
//  ALLOWED_HELLO_LOSS * HELLO_INTERVAL.  If the link layer feedback is
//  used to detect loss of link, DELETE_PERIOD must be at least 
//  ACTIVE_ROUTE_TIMEOUT.
//
//  TTL_START should be set to at least 2 if Hello messages are used for
//  local connectivity information.
//
//====================================================================================



{
 parameters:
	bool collectTraceInfo = default (false);
	int maxNetFrameSize = default (0);	// bytes
	int netDataFrameOverhead = default (10);	// bytes
	int netBufferSize = default (32);	// number of messages

	int activeRouteTimeout = default(60000); // orig 60000
	int allowedHelloLoss = default(2);  
	int helloInterval = default(25000); 	// orig 25000
	int localAddTTL = default(2);
	int netDiameter = default(5); // orig 35
	int nodeTraversalTime = default(4000);	// orig 4000
	int rerrRatelimit = default(10);
	int rreqRetries = default(2);
	int rreqRatelimit = default(10);
	int timeoutBuffer = default(2);
	int ttlStart = default(2);
	int ttlIncrement = default(2);
	int ttlThreshould = default(7);
	int pathDiscoveryTime = default(560000); 	//ms, 2 * netTrasversalTime orig 8000



 gates:
	output toCommunicationModule;
	output toMacModule;
	input fromCommunicationModule;
	input fromMacModule;
	input fromCommModuleResourceMgr;
}

