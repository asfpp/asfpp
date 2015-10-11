/**
 * @file ConditionalAttack.h
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 * 
 * @brief The class ConditionalAttack models a conditional attack.
 */


#ifndef CONDITIONALATTACK_H
#define CONDITIONALATTACK_H


#include "Attack.h"
#include "PacketFilter.h"

using namespace std;


class ConditionalAttack : public Attack {
private:
    // pointer-to the packet-filter
    PacketFilter* packetFilter;
    // minimum layer in which the attack can be performed
    int minimumLayer;

public:
    /**
     * @brief Constructor.
     */
    ConditionalAttack();
    
    /**
     * @brief Destructor.
     */
    virtual ~ConditionalAttack();
    
    /**
     * @brief Adds (appends) an action to the conditional attack.
     * @param action Is the pointer-to the action to add to the 
     *        conditional attack.
     * 
     */
    virtual void addAction(Action* action);
    
    /**
     * @brief Setter method, sets the packet-filter.
     * @param monolithicPacketFilter Is the packet-filter to add 
     *        to the conditional attack.
     */
    void setPacketFilter(string monolithicPacketFilter);
            
    /**
     * @brief Checks if the the current packet matches the 
     *        packet-filter.
     * @param packet Is the pointer-to the current packet.
     * @return Returns true if the current packet matches the 
     *         packet-filter, false otherwise.
     */
    bool matchFilter(cMessage *packet) const;
    
    // TODO re-design method's signature
    /**
     * @brief Executes (all the actions composing) the conditional 
     *        attack.
     * @param ...
     */
    void execute(cMessage** packet, vector<cMessage*> &new_messages, vector<double> &delays, double& forwarding_delay);
};

#endif
