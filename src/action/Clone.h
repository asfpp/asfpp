/*
 *  This action creates a perfect copy of a given packet. In order to do that,
 *  it relies on the hardCopy() function (see utils.h)
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef CLONE_H
#define CLONE_H

#include "Action.h"
#include "utils.h"

class Clone: public Action {

	string packetCloneName; // Name of the clone packet

	public:
	  
	Clone(const string cloneName, const string originalPacketName);
	virtual ~Clone();

	void execute(cMessage** newPacket, const cMessage* oldPacket) const;
	string getNewPacketName() const { return packetCloneName; }

};

#endif

