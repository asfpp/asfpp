/**
 * @file Move.h
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 * 
 * @brief The class Move models the action move (i.e. misplaces nodes).
 */


#ifndef MOVE_H
#define MOVE_H


#include "Action.h"
#include <omnetpp.h>
#include "VirtualMobilityManager.h"


using namespace std;


class Move : public Action {
private:
    // pointer-to the target node (i.e. the node to misplace)
    cModule* targetNode;
    // target location
	NodeLocation_type targetLocation;

public:
    /**
     * @brief Constructor.
     * @param targetNode Is the pointer-to the node to misplace.
     * @param targetLocation Is the new location that the node must 
     *        take.
     */
    Move(cModule* targetNode, NodeLocation_type targetLocation);
    
    /**
     * @brief Destructor.
     */
    virtual ~Move();
	
    /**
     * @brief Executes the move action, i.e. misplaces the node.
     */
	void execute();
};

#endif
