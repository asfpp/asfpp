/* 
 * This class provides the Logger module, which is responsible for logging attack related 
 * events, upon conditions from the GlobalFilter or Local Filter modules.
 *
 * Author : Marco Tiloca
 * e-mail : marco.tiloca@iet.unipi.it
 */

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "CastaliaModule.h"
#include "LoggerMessage.h"
#include <set>
#include <map>

using namespace std;

class Logger: public CastaliaModule {
   
  set<LogType> activeLogs; // active logs are related to LogTypes present in this set
  map<LogType,string> LogFiles; // list of log file names, according to the LogType they refer to

  void activateLogs();
  void setLogFileNames();
  
  protected:
   
  virtual void initialize();
  virtual void handleMessage(cMessage* msg);
  virtual void finishSpecific();
  
  public:
  
  Logger() {}
  virtual ~Logger() { activeLogs.clear(); }
  
};

#endif
 
