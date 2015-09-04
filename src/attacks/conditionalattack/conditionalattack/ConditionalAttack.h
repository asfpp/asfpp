/** 
 *  @brief      This class models a conditional attack.
 *
 *  @authors    Alessandro Pischedda <alessandro.pischedda@gmail.com>
 *              Francesco Racciatti <racciatti.francesco@gmail.com>
 */

#ifndef CONDITIONALATTACK_H
#define CONDITIONALATTACK_H

#include "PacketFilter.h"

#include "Attack.h"
#include "Drop.h"
#include "Change.h"
#include "Put.h"
#include "Retrieve.h"
#include "Clone.h"
#include "Send.h"
#include "Create.h"

#include "utils.h"

#include <sstream>
#include <vector>

class ConditionalAttack: public Attack {
    
    private:
        PacketFilter* packetFilter;
    
        string filter; // Applied to intercepted packets, in order to determine whether the attack has to be executed
        
        /* The minimum layer where the attack can take place (the higher layer providing all necessary information) */
        int minimum_layer; 

    public:
        ConditionalAttack();
        virtual ~ConditionalAttack();

        void execute(cMessage** packet, vector<cMessage*> &new_messages, vector<double> &delays, double& forwarding_delay);
        void addFilter(const std::string f);
        string getFilter() const { return filter; }
        bool matchFilter(cMessage *packet) const;
        virtual void addAction(Action* action);
};

#endif
