/* 
 * This class provides the Global Filter module, which is responsible for the execution of 
 * unconditional attacks, and the performance of the PUT action.
 *
 * Author : Alessandro Pischedda
 * e-mail : alessandro.pischedda@gmail.com
 */

#ifndef _GLOBAL_FILTER_H_
#define _GLOBAL_FILTER_H_

#include "CastaliaModule.h"
#include "CastaliaMessages.h"
#include "GlobalFilterMessage.h"
#include "LoggerMessage.h"
#include "PutMessages.h"

#include "UnconditionalAttack.h"
#include "Entry.h"

#include "utils.h"
#include "parser.h"

#include <map>
#include <string>
#include <sstream>

using namespace std;

enum attackTimer {
  UNCONDITIONAL_ATTACK = 12
};

class GlobalFilter: public CastaliaModule {
   
  /* It is TRUE when evaluation of attacks is enabled */
  bool attacksEvaluation;
  
  /* List of unconditional attacks executed by the GlobalFilter */
  vector<Entry*> unconditionalAttacks;

  /* Application name */
  string applicationName;
  
  /* Routing protocol name */
  string routingProtocolName;

  /* MAC protocol name */
  string macProtocolName;

  protected:
   
  virtual void initialize();
  virtual void handleMessage(cMessage* msg);
  virtual void finishSpecific();
  void attackInit();
  
  void handlePutMessage(const cMessage* msg);

  public:
  
  GlobalFilter();
  virtual ~GlobalFilter();
  
};

#endif
