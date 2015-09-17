/*
 * This action changes the node's position.
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef MOVE_H
#define MOVE_H

#include "Action.h"
#include "VirtualMobilityManager.h"

using namespace std;

class Move: public Action {

	NodeLocation_type nodeLocation; 	// New coordinates that the node has to assume
	VirtualMobilityManager* mobility; 	// Pointer to the node mobility module

	public:
	  
	Move(VirtualMobilityManager* mob, const NodeLocation_type location);
	virtual ~Move() {}
	
	void execute() const;

};

#endif
