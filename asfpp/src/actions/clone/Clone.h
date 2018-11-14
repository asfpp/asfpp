/**
 * @file Clone.h
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 * 
 * @brief The class Clone models the action clone, which creates a 
 *        perfect copy of a given packet.
 */


#ifndef CLONE_H
#define CLONE_H


#include "Action.h"
#include <omnetpp.h>


class Clone : public Action {
private:
    // name of the clone
    string clonePacketName;

public:
    /**
     * @brief Constructor.
     * @param clonePacketName Is the name of the clone packet.
     * @param sourcePacketName Is the name of the original packet, 
     *        i.e. the packet to clone.
     */
    Clone(string clonePacketName, string sourcePacketName);
    
    /**
     * @brief Destructor.
     */
    virtual ~Clone();
    
    // TODO change in 'getClonePacketName'
    /**
     * @brief Getter method, gets the name of the clone packet.
     * @return Returns the name of the clone packet.
     */
    string getNewPacketName() const;

    /**
     * @brief Execute the action, i.e. creates the clone packet as 
     *        perfect copy of the source packet.
     * @param clonePacket Is the pointer-to-pointer-to the clone packet.
     * @param sourcePacket Is the pointer-to the source packet.
     */
    void execute(cMessage** clonePacket, const cMessage* sourcePacket) const;
};

#endif

