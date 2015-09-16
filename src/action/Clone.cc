/**
 * @file Clone.cc
 * @authors Alessandro Pischedda <alessandro.pischedda@gmail.com>
 *          Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "Clone.h"
#include "utils.h"


Clone::Clone (const string clonedPacketName, const string originalPacketName) : Action (CLONE) {
    
    setPacketName(originalPacketName);
    this->clonedPacketName = clonedPacketName;
    
}


Clone::~Clone () {

}


void Clone::execute (cMessage** clonedPacket, const cMessage* originalPacket) const {
    
	// create a perfect copy of the original packet
	*clonedPacket = (cMessage*)hardCopy((cPacket*)originalPacket);
    
}


// TODO change method name in 'getClonedPacketName'
string Clone::getNewPacketName () const {
    
    return clonedPacketName;
    
}
