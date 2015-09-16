/**
 * @file    Clone.h
 * @authors Alessandro Pischedda <alessandro.pischedda@gmail.com>
 *          Francesco Racciatti <racciatti.francesco@gmail.com>
 * @brief   The class Clone models the action 'clone'. 
 *          It creates a perfect copy of a given packet. 
 *          
 * @details It relies on the utility funcion 'cMessage* hardCopy(cPacket*)'. 
 */


#ifndef CLONE_H
#define CLONE_H


#include "Action.h"


class Clone: public Action {

    private:
        // name of the cloned packet
        string clonedPacketName; 
    
    public:	  
        Clone(const string clonedPacketName, const string originalPacketName);
        virtual ~Clone();
        
        void execute(cMessage** clonedPacket, const cMessage* originalPacket) const;
        string getNewPacketName() const;
    
};

#endif

