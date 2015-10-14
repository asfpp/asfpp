/**
 * @file Send.cc
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 */


#include "Send.h"


Send::Send(double delay) : Action(SEND)
{
    // set the delay
    if (delay < 0.0) {
        opp_error("[Send::Send(double)] Error, delay can't be a negative number");
    }
    this->delay = delay;
}


Send::~Send()
{
}


double Send::getDelay() const
{
    return delay;
}

// TODO rename 'sended' to 'tosend'
void Send::execute(cMessage* packet) const
{
    // find the content of the field 'sended' (if exists)
    cClassDescriptor* descriptor = cClassDescriptor::getDescriptorFor(packet);
    int fieldIndex = descriptor->findField(packet, "sended");
    // can't found the field 'sended'
    if (fieldIndex == -1) {
        opp_error("[void Send::execute(cMessage*)] Error, field 'sended' not found in the current packet");
    }
	// set the field 'sended', in this way the packet will be sent by the local-filter
	descriptor->setFieldAsString(packet, fieldIndex, 0, "1");
}
