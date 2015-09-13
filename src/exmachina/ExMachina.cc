/**
 * @file	ExMachina.cc
 * @author	Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "ExMachina.h"
#include "Attack.h"
#include "Action.h"
#include "PhysicalAttack.h"
#include "LocalFilter.h"

Define_Module(ExMachina);


void ExMachina::initialize () {

}


void ExMachina::handleMessage (cMessage* msg) {

	bool isSelfMessage = msg->isSelfMessage();
    
    // handles only self messages, i.e. scheduled disable attacks
	if (isSelfMessage) {
        
        // perform the attack stored in the first element of the vector (it's sorted)
        PhysicalAttack* attack = (PhysicalAttack *)(physicalAttacks[0]->getAttack());
        attack->execute();
		// remove the attack from the list of physical attacks
		physicalAttacks.erase(physicalAttacks.begin());
	    
    }
	
	delete msg;

}


void ExMachina::finishSpecific () {

}


ExMachina::ExMachina () {	

}


ExMachina::~ExMachina () {

}


void ExMachina::scheduleDisableAttack (Entry* attack) {

    Enter_Method("scheduleDisableAttack()");
    
    physicalAttacks.push_back(attack);
    cMessage* message = new cMessage("Start physical attack", PHYSICAL_ATTACK);
    scheduleAt(attack->getTime(), message);
    
}



