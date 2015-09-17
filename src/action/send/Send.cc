/**
 * @file Send.cc
 * @authors Alessandro Pischedda <alessandro.pischedda@gmail.com>
 *          Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "Send.h"
#include <omnetpp.h>

Send::Send (double delay) : Action (SEND) {
    
    this->delay = delay;
     
}

Send::~Send () {
    
}


void Send::execute(cMessage* msg) const {

    cClassDescriptor* descriptor = cClassDescriptor::getDescriptorFor(msg);
    
    // TODO change 'sended' in 'toSend'
    int fieldIndex = descriptor->findField(msg, "sended");
    
    // the field 'sended' cannot be found (this should never happen)
    if (fieldIndex==-1) {
        opp_error("[void Send::execute(cMessage*)] Error: the field 'sended' in the message does not exist");
    }
    
    // the packet will be sent to the next layer
    descriptor->setFieldAsString(msg, fieldIndex, 0, "1");

}


double Send::getDelay () {
	
    return delay;
    
}
