#include "Clone.h"

Clone::Clone(const string cloneName, const string originalPacketName) : Action(CLONE) {

	setPacketName(originalPacketName);
	packetCloneName = cloneName;
	
}

void Clone::execute(cMessage** newPacket, const cMessage* oldPacket) const {

	/* Create a perfect copy of the original packet */
	*newPacket = (cMessage*)hardCopy((cPacket*)oldPacket);

}

Clone::~Clone() {
  
	packetCloneName.clear();
  
}
