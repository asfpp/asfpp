/**
 * @file Destroy.cc
 * 
 * @author Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "Destroy.h"


Destroy::Destroy(cModule* targetNode) : Action(DESTROY)
{	
	this->targetNode = targetNode;	
}


Destroy::~Destroy()
{
}


void Destroy::execute() const
{
    targetNode->callFinish();
    targetNode->deleteModule();
}
