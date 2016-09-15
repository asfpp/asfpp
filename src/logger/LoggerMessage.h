#ifndef _LOGGER_MESSAGE_H_
#define _LOGGER_MESSAGE_H_

#include <cmessage.h>
#include <string>

using namespace std;

/* Type of messages used by the Global Filter and Local Filter modules to ask the Logger module for logging */
enum LogMessage {
  LOGGER_MESSAGE = 13
};

/* Possible log requests */
enum LogType {

        PACKET_DROP = 0,
        COMPROMISED_PACKET = 1,
};

class LoggerMessage : public ::cMessage {
  
private:
  LogType type; // Type of log request
  int reqNodeID; // Either the node ID requesting for logging, or -1 for the Global Filter
  string information; // The information to be logged by the Logger module (it can vary according to the specific log type)
  
public:
  LoggerMessage(const LogType t, const int nodeID, const string info);
  LoggerMessage(const LoggerMessage& message);
  LoggerMessage& operator=(const LoggerMessage& message);
  virtual ~LoggerMessage();
  
  LogType getLogType() const { return type; }
  int getReqNodeID() const { return reqNodeID; }
  string getInformation() const { return information; }
  
};

#endif
