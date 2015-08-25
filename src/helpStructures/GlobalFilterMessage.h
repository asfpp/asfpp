#ifndef _GLOBAL_FILTER_MESSAGE_H_
#define _GLOBAL_FILTER_MESSAGE_H_

#include <cmessage.h>
#include <string>

using namespace std;

class GlobalFilterMessage {
  
private:
  string arrivalGateName;
  string senderGateName;
  
public:
  GlobalFilterMessage(const string& inGate, const string& outGate);
  GlobalFilterMessage(const GlobalFilterMessage& message);
  GlobalFilterMessage& operator=(const GlobalFilterMessage& message);
  virtual ~GlobalFilterMessage();
  
  string getArrivalGateName() const { return arrivalGateName; }
  string getSenderGateName() const { return senderGateName; }
  
};

#endif
