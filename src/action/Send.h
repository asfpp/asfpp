/*
 * This action can have differents behaviour, and is meaningful only for conditional attacks, i.e. on LocalFilter modules.
 * 
 * Intercepted packets: delay packet delivery to the next layer in the TX/RX flow (there is
 * no delay by default). Such packets are always either sent to the next layer or discarded.
 * 
 * Created/cloned packets: send the packet to the next layer in the TX/RX flow, possibly specifying a delivery delay.
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef SEND_H
#define SEND_H

#include "Action.h"
#include "SensorManager.h"
#include "utils.h"

class Send: public Action {

	double delay; // Actually used only for created/clones packets (seconds)

	public:
	  
	Send(double time_delay) : Action(SEND) { delay = time_delay; }
	virtual ~Send() {}
	
	void execute(cMessage* packet) const;
	double getDelay();	

};

#endif
