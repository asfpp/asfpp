#include "PutMessages.h"

PutMessage::PutMessage(cMessage* pkt, const string dir, const bool stats ) : cMessage("PutMessage", PUT_MSG) {
  
  	/* Create a perfect copy of the original packet 'pkt' */
	packet = (cMessage*)hardCopy((cPacket*)pkt);

	take(packet); // Take the ownership on the packet

	/* Set the packet copy as not filtered */
	setFilteredRecursively(packet, false);

	/* Set information related to the Put action execution */
	direction = dir;
	statistics = stats;
	
}

PutMessage::~PutMessage() {

	drop(packet); // Release the ownership on the packet
	delete packet;

	nodeVector.clear();
	direction.clear();
  
}

PutRequest::PutRequest(cMessage* pkt, const string dir, const bool stats) : cMessage("PutRequest", PUT_REQ) {
  
	/* Create a perfect copy of the original packet 'pkt' */
	packet = (cMessage*)hardCopy((cPacket*)pkt);

	take(packet); // Take the ownership on the packet

	direction = dir;
	this->stats = stats;
	
}

PutRequest::~PutRequest() {

	drop(packet); // Release the ownership on the packet
	delete packet;
	direction.clear();
	
}