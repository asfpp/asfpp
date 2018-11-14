#include "GlobalFilterMessage.h"

GlobalFilterMessage::GlobalFilterMessage(const string& inGate, const string& outGate)
{
    
    arrivalGateName = inGate;
    senderGateName = outGate;
    
}

GlobalFilterMessage::GlobalFilterMessage(const GlobalFilterMessage& message)
{
    
    arrivalGateName = message.getArrivalGateName();
    senderGateName = message.getSenderGateName();
    
}

GlobalFilterMessage& GlobalFilterMessage::operator=(const GlobalFilterMessage& message)
{
    
    arrivalGateName.clear();
    senderGateName.clear();
    arrivalGateName = message.getArrivalGateName();
    senderGateName = message.getSenderGateName();
    
}

GlobalFilterMessage::~GlobalFilterMessage()
{

    arrivalGateName.clear();
    senderGateName.clear();
    
}
