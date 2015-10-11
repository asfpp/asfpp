/* 
 * This class represents an unconditional attack, actually performed by the Global Filter.
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef UNCONDITIONALATTACK_H
#define UNCONDITIONALATTACK_H

#include "Attack.h"
#include "Drop.h"
#include "Change.h"
#include "Put.h"
#include "Retrieve.h"
#include "Clone.h"
#include "Send.h"
#include "Create.h"

#include "utils.h"

#include <sstream>
#include <vector>

class UnconditionalAttack: public Attack {

	double frequency; // Amount of time between two consecutive attack occurrences (s)

	public:

	UnconditionalAttack() {}
	virtual ~UnconditionalAttack() {}

	void execute(vector<cMessage*> &put_messages);
	double getFrequency() { return frequency; }
	void addFrequency(double frequency) { this->frequency = frequency; }
	virtual void addAction(Action* action);
	
};

#endif
