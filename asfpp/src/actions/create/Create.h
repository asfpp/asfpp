/*
 * This action creates a new packet.
 *
 * Author : Marco Tiloca
 * e-mail : marco.tiloca84@gmail.com
 */

#ifndef CREATE_H
#define CREATE_H

#include "utils.h"
#include "Action.h"
#include "PacketTypes.h"
#include <list>
#include <omnetpp.h>
#include <iostream>
#include "CastaliaModule.h"

using namespace std;

/* Information about the packet layer */
struct layerSpec {
  
	int packetLayer;		// The new packet refers to this layer
	string packetLayerType;		// The packet type related to the packetLayer layer
	string packetLayerSubtype;	// The packet subtype related to the packetLayer layer

};

class Create: public Action {

	string applicationName;		// Name of the application
	string RoutingProtocolName;	// Name of the routing protocol
	string MACProtocolName;		// Name of the MAC protocol
	list<layerSpec> layerList;	// Specifications for each involved layer
	
	/* This function creates the part of the new packet related to the specified layer */
	void buildNewPacket(cPacket** packet, const int layer, const string type = "0", const string subtype = "0") const;

	public:

	Create(const string appName, const string routingName, const string MACName, const string appType = "-1", const string netType = "-1", const string macType = "-1");
	virtual ~Create();
	
	void execute(cPacket** packet);

};

#endif
