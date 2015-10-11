/*
 * This action delivers a packet to a set of specified nodes. The following three modes are available.
 *
 *	TX			the packet is put in the TX buffer of the specified layer
 *	RX stats OFF		the packet is put in the RX buffer of the specified layer, as it has NOT come not from the wireless channel
 *
 *	RX stats ON		the packet is put in the RX buffer of the specified layer, as it has come from the wireless channel
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef PUT_H
#define PUT_H

#include "Action.h"
#include "PutMessages.h"
#include "utils.h"

#include <omnetpp.h>
#include "CastaliaModule.h"
#include "CastaliaMessages.h"
#include "WirelessChannelMessages_m.h"
#include <iostream>


class Put: public Action {

	string direction;		// Either RX or TX
	bool statics;			// If TRUE, statistics at the Radio Level must be updated on the recipient nodes
	vector<int> nodeVector;		// List of recipient nodes that will receive the packet
	double delay;			// Delay after which the packet is actually delivered to recipient nodes (seconds)

	public:
	  
	Put(const string dir, const double delay_time, const bool stats = false);
	virtual ~Put();
	
	void addNode(const int nodeID);
	double getDelay() const { return delay; }
	cMessage* execute(cMessage* packet) const;
	
};

#endif
