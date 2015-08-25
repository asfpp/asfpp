#include "Put.h"

Put::Put(const string dir, const double delay_time ,const bool stats) : Action(PUT) {

	direction = dir;
	statics = stats;
	delay = delay_time;
	
}

/* Add the specified node to the list of recipient nodes */
void Put::addNode(const int nodeID) {

	nodeVector.push_back(nodeID);
	
}

/* Return a PutMessage message containing a copy of 'packet' to be delivered to the recipient nodes */
cMessage* Put::execute(cMessage *packet) const {

	PutMessage* msg = NULL;

	/* Create a PutMessage message, including the packet to be delivered */
	msg = new PutMessage(packet, direction, statics);

	msg->setDelay(this->delay);

	for(int i = 0; i < nodeVector.size(); i++)
		msg->addNode(nodeVector[i]);

	/* Return the PutMessage */
	return (cMessage*)(msg);	

}

Put::~Put() {
  
	direction.clear();
	nodeVector.clear();
}
