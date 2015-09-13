/**
 * @file	Disable.cc
 * @author	Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "Disable.h"


Disable::Disable (cModule* targetNode) : Action (DISABLE) {
	
	this->targetNode = targetNode;
	
}


Disable::~Disable () {

}


void Disable::execute () const {
    
    targetNode->callFinish();
    targetNode->deleteModule();
    
}

