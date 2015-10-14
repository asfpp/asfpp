/* 
 * This class provides the Local Filter module.
 * The Local Filter, is a module in the node architecture which, let the 
 * Communication Stack layers to communicate each other passing by him.
 * So it intercepts every packet which pass through the communication stack,
 * thanks to it is possible to perform Conditional and Physical attacks. 
 *
 *
 * Author : Alessandro Pischedda
 * E-mail : alessandro.pischedda@gmail.com
 */

#ifndef _LOCAL_FILTER_H_
#define _LOCAL_FILTER_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <libxml++/libxml++.h>
#include <algorithm>
#include <sstream>

#include "utils.h"

#include "Action.h"

#include "Radio.h"


#include "CastaliaMessages.h"
#include "GlobalFilterMessage.h"
#include "LoggerMessage.h"
#include "SensorManager.h"

#include "VirtualMac.h"
#include "VirtualRouting.h"

#include "Entry.h"
#include "PhysicalAttack.h"
#include "ConditionalAttack.h"


#include "Parser.h"
#include "Fakeread.h"

#include "Disable.h"


enum attackTimer {
	PHYSICAL_ATTACK = 10,
	LOGICAL_ATTACK = 11
};


struct RadioStats_type {
    double deltaTime;
    double dataRate;
    double rxPower;    
};


class LocalFilter : public CastaliaModule {
// Disable is a friend class
friend class Disable;

private:
    // true if the node is disabled
    bool isDisabled;
    // gates to avoid if the node is disabled
    vector<string> senderGatesToAvoid;
    // enabled fakeread actions
    vector<Fakeread*> enabledFakereads;
    // radio stats
    RadioStats_type radioStats;   
    // byte received by injection
    int injectedBytes;

   
   
   
  /* Evaluation of attacks is enabled if TRUE */
  bool attacksEvaluation;

  /* TRUE means that the LF must send a message to Logger for
	these kind of events. */
  bool logCompromisedPacket;

  int nodeID;

  /* Lists of attacks performed on this node */
  vector<Entry*> physicalAttacks;
  vector<Entry*> logicalAttacks;

  /* If the i-th boolean is TRUE, the i-th attack has been triggered */
  vector<bool> activeLogicAttack;

  /* The index of the next logical attack to be triggered by a timer */
  int falseAttackIndex;
  
  /* Names and IDs of the arrival gates from Routing/MAC/Radio modules */
  // arrival gates
  map <int,string> arrivalGatesMap;
  
  /* Pair of gates names, linked with each other */
  map <string,string> gatesLinksMap;
 
  /* Application name */
  string applicationName;
  
  /* Routing protocol name */
  string routingProtocolName;

  /* MAC protocol name */
  string macProtocolName;
  
  /* Radio module used to update his statistics */
  Radio* radioModule;
  
  /* It is used to retrieve the energy consumed */
  ResourceManager* resourceModule;

  /* mac and net header size */
  int net_header, mac_header;  

  
  
  
  

private:
    /**
     * @brief Gets radio stats from the node's Radio module.
     * @return Returns stats from the node's Radio module.
     */
    RadioStats_type getRadioStats();

    /**
     * @brief Initializes the sender gates to avoid if the module is
     *        disabled. These gates wire the local filter with the 
     *        communication module. If the node is disabled, it no  
     *        longer has the communication module. In this case, 
     *        the local filter must not use these (sender) gates
     *        because the node's communication module does not exist
     *        anymore.
     */
    void initializeSenderGatesToAvoid();

    



protected:
    virtual void initialize();
    void attackInit(int nodeID);
    
    virtual void handleMessage(cMessage* msg);
    virtual void finishSpecific();
    bool testAndSet(cMessage* packet);

    void coupleGates();

public:
    /**
     * @brief Constructor.
     */
    LocalFilter();
    
    /**
     * @brief Destructor.
     */
    virtual ~LocalFilter();  
};

#endif
