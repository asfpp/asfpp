/*
 * This file provides the two messages used to perform the Put action.
 * 
 * A source node sends a PUT MESSAGE messages to the GlobalFilter, containing:
 *
 *	packet		The packet to be delivered (a copy of the original one)
 *	nodeVector	The list of Put recipient nodes
 *	direction	The packet Put direction, i.e. either RX or TX
 *	statics		Enable/disable statistics update on the recipient nodes (RX mode only)
 * 	delay		Delay after which the packet is actually delivered to recipient nodes (seconds)
 *
 * In case of conditional attacks, the GlobalFilter sends a copy of the packet to each destination node, included into a PUT REQUEST message.
 * In case of unconditional attacks, the GlobalFilter sends PUT MESSAGE messages to intended recipient nodes.
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef PUTMESSAGES_H
#define PUTMESSAGES_H

#include <omnetpp.h>
#include <vector>
#include <string>
#include "utils.h"

using namespace std;

enum PutType {
  
	PUT_MSG = 100,
	PUT_REQ = 101,
};

/* This kind of packet is sent by a node LocalFilter to the GlobalFilter, or by the GlobalFilter to a node LocalFilter (unconditional attacks only) */
class PutMessage : public ::cMessage {

	cMessage* packet;		// The packet to be delivered (a copy of the original one)
	vector<int> nodeVector;		// The list of recipient nodes
	string direction;		// The packet direction, i.e. either RX or TX
	bool statistics;		// Enable/disable statistics update on the recipient nodes (RX mode only)
	double delay;			// Delay after which the packet is actually delivered to recipient nodes (seconds)

	public: 
	  
	PutMessage(cMessage* pkt, const string dir, const bool stats);
	virtual ~PutMessage();

	void setPacket(cMessage *pkt) { packet = pkt; }
	void setDirection(const string dir) { direction = dir; }
	void addNode(const int node) { nodeVector.push_back(node); }
	void setDelay(const double delay_time) { delay = delay_time; }

	cMessage* getPacket() const { return packet; }
	vector<int> getNodeVector() const { return nodeVector; }
	string getDirection() const { return direction; }
	bool getStats() const { return statistics; }
	double getDelay() const { return delay;}

};

/* This kind of packet is sent by the GlobalFilter to the LocalFilter of all destination nodes (conditional attacks only) */
class PutRequest : public ::cMessage {

	cMessage *packet; 
	string direction;
	bool stats;

	public :

	PutRequest(cMessage* pkt, const string dir, const bool stats);
	virtual ~PutRequest();
	
	void setPacket(cMessage *pkt) { packet = pkt; }
	void setDirection(const string dir) { direction = dir; }

	void setStats(const bool s) { stats = s; }
	bool getStats() const { return stats; }
	string getDirection() const { return direction; }
	cMessage* getPacket() const { return packet; }
	
};

#endif
