/*
 * This action destroys a node. 
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef DESTROY_H
#define DESTROY_H

#include "Action.h"

using namespace std;

class Destroy: public Action {

	public:
	  
	Destroy() : Action(DESTROY) {}
	virtual ~Destroy() {}
	
	void execute(bool &destroyed) const;

};

#endif
