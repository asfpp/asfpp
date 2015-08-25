/*
 * This action drops (i.e. deletes) a packet.
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef DROP_H
#define DROP_H

#include "Action.h"
#include <cobject.h>

class Drop: public Action {

	public:
	  
	Drop() : Action(DROP) {}
	virtual ~Drop() {}
	
	void execute(cMessage** packet) const;

};

#endif
