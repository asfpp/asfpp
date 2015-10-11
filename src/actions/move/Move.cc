/**
 * @file Move.cc
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 */


#include "Move.h"


Move::Move(cModule* targetNode, NodeLocation_type targetLocation) : Action(MOVE)
{
    this->targetNode = targetNode;
    this->targetLocation = targetLocation;
}


Move::~Move()
{
}

void Move::execute()
{
    // find the mobility manager
    VirtualMobilityManager* mobilityModule = check_and_cast<VirtualMobilityManager*>(targetNode->getSubmodule("MobilityManager"));
    
    // mobility manager not found
    if (mobilityModule==nullptr) {
        // check if the target node is the global-filter
        if (targetNode->getClassName() == "GlobalFilter") {
            opp_error("[Move::execute()] Error, global-filter can't perform the action 'move'");
        }
        else {
            opp_error("[Move::execute()] Error, mobility module not found, please check the node structure in the .ned file");
        }
    }
    
    // actually ASF++ supports only x, y, z (don't overwrite phy, theta, cell)
    NodeLocation_type actualLocation = mobilityModule->getLocation();
    targetLocation.phi = actualLocation.phi;
    targetLocation.theta = actualLocation.theta;
    targetLocation.cell = actualLocation.cell;
    // set the new location
    mobilityModule->setLocationWrapper(targetLocation);
}
