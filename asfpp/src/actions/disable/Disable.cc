/**
 * @file Disable.cc
 * 
 * @author Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "Disable.h"
#include "LocalFilter.h"


Disable::Disable(cModule* targetNode) : Action(DISABLE)
{	
	this->targetNode = targetNode;	
}


Disable::~Disable()
{
}


void Disable::execute() const
{
    // mark the node as 'disabled'
    LocalFilter* localFilter = check_and_cast<LocalFilter*>(targetNode->getSubmodule("LocalFilter"));
    localFilter->isDisabled = true;
    // get radio stats before communication module deleting (will be used to compute energy consumption)
    localFilter->radioStats = localFilter->getRadioStats();
    // retrieve and delete the communication module
    cModule* communicationModule = targetNode->getSubmodule("Communication");
    communicationModule->callFinish();
    communicationModule->deleteModule();
}
