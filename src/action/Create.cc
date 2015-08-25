#include "Create.h"

void Create::buildNewPacket(cPacket** packet, const int layer, const string type, const string subtype) const {
	

	/* Build the packet portion, according to the specified layer */
	switch (layer) {
	  
	  // Application layer packets
	  case APPLICATION_PACKET:{
	    
	    bool done = false;

	    /* RoomMonitoring application */
	    if(applicationName.compare("RoomMonitoring") == 0){
	      *packet = new RoomMonitoringDataPacket("Room monitoring packet", APPLICATION_PACKET);
	      done = true;
	    }

	    
	    /* Cluster Aggregator application */
	    if(applicationName.compare("ClusterAggregator") == 0){ 
	      *packet = new ClusterAggregatorDataPacket("Cluster report packet", APPLICATION_PACKET);
          done = true;
	    }


	    /* ValueReporting application */
	    if(applicationName.compare("ValueReporting") == 0){
	      *packet = new ValueReportingDataPacket("Value reporting packet", APPLICATION_PACKET);
          done = true;
	    }

	    /* Other applications rely on the standard application packet*/
	    if(!done)
		    *packet = new ApplicationPacket("App generic packet", APPLICATION_PACKET);

	    
	    ApplicationPacket** pkt = (ApplicationPacket**)packet;
	    (*pkt)->setApplicationID(applicationName.c_str());
	    (*pkt)->getAppNetInfoExchange().timestamp = simTime();
		(*pkt)->setByteLength( getPacketLength(applicationName, atoi(type.c_str()) ) );
		(*pkt)->setCompromised(1);

	    break;
	  }
	  
	  // Network layer packets
	  case NETWORK_LAYER_PACKET:
	    
		  /* MultipathRingsRouting protocol */
		  if(RoutingProtocolName.compare("MultipathRingsRouting") == 0) {
		    *packet = new MultipathRingsRoutingPacket("MultipathRingsRouting packet", NETWORK_LAYER_PACKET);
		    ((MultipathRingsRoutingPacket*)(*packet))->setMultipathRingsRoutingPacketKind( atoi(type.c_str()) );
			((RoutingPacket *)(*packet))->setCompromised(1);
			(*packet)->setByteLength( getPacketLength(RoutingProtocolName, atoi(type.c_str()) ) );
		    break;
		  }
	  
		  /* BypassRouting protocol */
		  if(RoutingProtocolName.compare("BypassRouting") == 0) {
		    *packet = new BypassRoutingPacket("BypassRouting packet", NETWORK_LAYER_PACKET);
			((RoutingPacket *)(*packet))->setCompromised(1);
			(*packet)->setByteLength( getPacketLength(RoutingProtocolName, atoi(type.c_str()) ) );
		    break;
		  }

		  /* AODVRouting protocol */
		  if(RoutingProtocolName.compare("AodvRouting") == 0){
			int packetType = atoi(type.c_str());
			switch(packetType){	

				case 1: // RREQ Packet
					*packet = new AodvRREQPacket("AODV routing RREQ packet", NETWORK_LAYER_PACKET);
					// Set some field? 
					break;
				case 2: // RREP Packet
					*packet = new AodvRREPPacket("AODV routing RREP packet", NETWORK_LAYER_PACKET);
					break;
				case 3: // RERR Packet
					*packet = new AodvRERRPacket("AODV routing RERR packet", NETWORK_LAYER_PACKET);
					break;
				case 4: // RREP-ACK Packet
					*packet = new AodvRREPAckPacket("AODV routing RREP ACK packet", NETWORK_LAYER_PACKET);
					break;
				case 5: // HELLO MESSAGE
					*packet = new AodvHelloMessage("AODV hello message packet", NETWORK_LAYER_PACKET);
					break;

				case 6: // DATA Packet
					*packet = new AodvDataPacket("AODV routing data packet", NETWORK_LAYER_PACKET);
					break;
					
				default : break;
			};

			/* The AODV packets derive from PacketId class, that class contains 
			   only the field "id". To recognize and handle correctly the packet 
			   the Aodv's implementation see the field id. Every packet is identified
			   by a unique id value.
			*/
			((PacketId*)(*packet))->setId(packetType);
			((RoutingPacket *)(*packet))->setCompromised(1);
			(*packet)->setByteLength( getPacketLength(RoutingProtocolName, atoi(type.c_str()) ) );

			break;
		  }
	
	  // MAC layer packets
	  case MAC_LAYER_PACKET:
	  
		  /* IEEE 802.15.4 MAC protocol */
		  if(MACProtocolName.compare("Mac802154") == 0) {
		    *packet = new Mac802154Packet("802154 packet", MAC_LAYER_PACKET);
		    ((Mac802154Packet*)(*packet))->setMac802154PacketType( atoi(type.c_str()) );
			((MacPacket *)(*packet))->setCompromised(1);
			(*packet)->setByteLength( getPacketLength(MACProtocolName, atoi(type.c_str()) ) );
		    break;
		  }
		  
		  /* TMAC protocol */
		  if(MACProtocolName.compare("TMAC") == 0) {
		    *packet = new TMacPacket("TMAC packet", MAC_LAYER_PACKET);
		    ((TMacPacket*)(*packet))->setType(atoi(type.c_str()));
			((MacPacket *)(*packet))->setCompromised(1);
			(*packet)->setByteLength( getPacketLength(MACProtocolName, atoi(type.c_str()) ) );
		    break;
		  }
	  
		  /* Tunable MAC protocol */
		  if(MACProtocolName.compare("TunableMAC") == 0) {
		    *packet = new TunableMacPacket("TunableMac packet", MAC_LAYER_PACKET);
		    ((TunableMacPacket*)(*packet))->setFrameType( atoi(type.c_str()) );
			((MacPacket *)(*packet))->setCompromised(1);
			(*packet)->setByteLength( getPacketLength(MACProtocolName, atoi(type.c_str()) ) );
		    break;
		  }
	  
		  /* Baseline BAN MAC protocol */
		  if(MACProtocolName.compare("BaselineBANMac") == 0) {
		    *packet = new BaselineMacPacket("BaselineBANMac packet", MAC_LAYER_PACKET);
		    ((BaselineMacPacket*)(*packet))->setFrameType( atoi(type.c_str()) );
		    ((BaselineMacPacket*)(*packet))->setFrameSubtype( atoi(subtype.c_str()) );
			((MacPacket *)(*packet))->setCompromised(1);
			(*packet)->setByteLength( getPacketLength(MACProtocolName, atoi(type.c_str()) ) );
		    break;
		  }
	  
		  /* Bypass MAC protocol */
		  if(MACProtocolName.compare("BypassMAC") == 0) {
		    *packet = new MacPacket("BypassRouting packet", MAC_LAYER_PACKET);
			((MacPacket *)(*packet))->setCompromised(1);
			(*packet)->setByteLength( getPacketLength(MACProtocolName, atoi(type.c_str()) ) );
		    break;
		  }
	  
	}
  
}

/* Populate the layer list, according to the specific application/protocols involved, and packet subtypes
* The lowest layer will be the last entry of the layer list
*/
// TODO Complete with a comprehensive management of the BaselineBANMac (subtype has to be considered as well)
Create::Create(const string appName, const string routingName, const string MACName, const string appType, const string netType, const string macType) : Action(CREATE) {
	
	applicationName = appName;
	RoutingProtocolName = routingName;
	MACProtocolName = MACName;
	layerSpec spec;

	/* Application level information */
	if(appType != "-1") {
	    spec.packetLayer = APPLICATION_PACKET;
	    spec.packetLayerType = appType;
	    layerList.push_back(spec);
	}
  
	/* Network level information */
	if(netType != "-1") {
	    spec.packetLayer = NETWORK_LAYER_PACKET;
	    spec.packetLayerType = netType;
	    layerList.push_back(spec);
	}
	
	/* MAC level information */
	if(macType != "-1") {
	    spec.packetLayer = MAC_LAYER_PACKET;
	    spec.packetLayerType = macType;
	    spec.packetLayerSubtype = "0";
	    layerList.push_back(spec);
	}
	    
}

// TODO Complete with a comprehensive management of the BaselineBANMac (subtype has to be considered as well)
/* Starting from the application layer, create a new packet, considering each layer separately */
void Create::execute(cPacket** packet){

	cPacket* auxPacket;

	int layer;
	string type, subtype;
	
	list<layerSpec>::iterator it = layerList.begin();

	for( it ; it != layerList.end(); it++) {

	    layer = it->packetLayer;
	    type = it->packetLayerType;
	    subtype = it->packetLayerSubtype;

	    buildNewPacket(&auxPacket, layer, type);

	    /* No encapsulation is needed at the (top) application layer */
	    if(it != layerList.begin() ){
			int enc_packet_size = (*packet)->getByteLength();
			int packet_size = auxPacket->getByteLength();
			auxPacket->encapsulate(*packet);
			auxPacket->setByteLength( enc_packet_size + packet_size );
		}  

	    *packet = auxPacket;
	}

	/* Hereafter, this packet will not be involved in another attack on the same node */
	setFilteredRecursively( *packet, true);

}

Create::~Create() {
  
	applicationName.clear();
	RoutingProtocolName.clear();
	MACProtocolName.clear();
	layerList.clear();
	
}
