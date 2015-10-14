/**
 * @file Send.h
 * 
 * @brief The class Send models the action 'send', that is used to send 
 *        to the next layer of the communication stack, with or 
 *        without a forwarding delay, created/cloned or intercepted
 *        packets.
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 */


#ifndef SEND_H
#define SEND_H


#include "Action.h"
#include <omnetpp.h>


class Send : public Action {
private:
    // forwarding delay
    double delay;

public:
    /**
     * @brief Constructor.
     * @param delay Is the forwarding delay.
     */
	Send(double delay);
	
    /**
     * @brief Destructor.
     */
    virtual ~Send();
	
    /**
     * @brief Getter method, gets the delay.
     * @return Returns the delay.
     */
    double getDelay() const;
    
    /**
     * @brief Executes the action.
     * @param packet Is the packet to send to the next layer of the 
     *        communication stack.
     */
	void execute(cMessage* packet) const;
};

#endif
