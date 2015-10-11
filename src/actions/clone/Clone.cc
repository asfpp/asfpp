/**
 * @file Clone.cc
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 */
 

#include "Clone.h"
#include "utils.h"


Clone::Clone(string clonePacketName, string sourcePacketName) : Action(CLONE)
{
    this->clonePacketName = clonePacketName;
    // set packet name in the base class
    setPacketName(sourcePacketName);
}


Clone::~Clone()
{
}


string Clone::getNewPacketName() const
{
    return clonePacketName;
}


void Clone::execute(cMessage** clonePacket, const cMessage* sourcePacket) const
{
    // create a perfect copy of the source packet
	*clonePacket = (cMessage*)hardCopy((cPacket*)sourcePacket);
}
