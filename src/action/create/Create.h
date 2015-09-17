/**
 * @file Create.h
 * @authors Marco Tiloca <marco.tiloca84@gmail.com>
 *          Francesco Racciatti <racciatti.francesco@gmail.com>
 * @brief This action creates a new packet.
 */

#ifndef CREATE_H
#define CREATE_H

#include "utils.h"
#include "Action.h"
#include "PacketTypes.h"
#include <list>
#include <omnetpp.h>

using namespace std;

/* Information about the packet layer */
/*
struct layerSpec {
  
	int packetLayer;		// The new packet refers to this layer
	string packetLayerType;		// The packet type related to the packetLayer layer
	string packetLayerSubtype;	// The packet subtype related to the packetLayer layer

};
*/

class LayerSpec {
    
    public:
        int packetLayer;
        string packetLayerType;
        string packetLayerSubtype;
    
    public:
        LayerSpec(){};
        ~LayerSpec(){};
};

class Create: public Action {

	string applicationName;		// Name of the application
	string RoutingProtocolName;	// Name of the routing protocol
	string MACProtocolName;		// Name of the MAC protocol
	list<LayerSpec*> layerList;	// Specifications for each involved layer
    cModule* module;
    
	/* This function creates the part of the new packet related to the specified layer */
	void buildNewPacket(cPacket** packet, const int layer, const string type = "0", const string subtype = "0") const;

	public:

	Create(cModule* module, const string appName, const string routingName, const string MACName, const string appType = "-1", const string netType = "-1", const string macType = "-1");
	virtual ~Create();
	
	void execute(cPacket** packet);

};

#endif
