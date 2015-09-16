/**
 * @file Send.h
 * @authors Alessandro Pischedda <alessandro.pischedda@gmail.com>
 *          Francesco Racciatti <racciatti.francesco@gmail.com>
 * @brief TODO
 */
 
 /*This action can have differents behaviour, and is meaningful only for conditional attacks, i.e. on LocalFilter modules.
 * 
 * Intercepted packets: delay packet delivery to the next layer in the TX/RX flow (there is
 * no delay by default). Such packets are always either sent to the next layer or discarded.
 * 
 * Created/cloned packets: send the packet to the next layer in the TX/RX flow, possibly specifying a delivery delay.
 *
 */


#ifndef SEND_H
#define SEND_H


#include "Action.h"


class Send: public Action {
    
    private:
        // sending delay (s)
        double delay;
    
    public:
        Send(double delay);
        virtual ~Send();
        
        void execute(cMessage* packet) const;
        double getDelay();	
    
};

#endif
