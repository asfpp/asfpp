#include "LoggerMessage.h"

LoggerMessage::LoggerMessage(const LogType t, const int nodeID, const string info)
{
    
    type = t;
    reqNodeID = nodeID;
    information.assign(info);
    
}

LoggerMessage::LoggerMessage(const LoggerMessage& message)
{
    
    type = message.getLogType();
    reqNodeID = message.getReqNodeID();
    information.assign(message.getInformation());
    
}

LoggerMessage& LoggerMessage::operator=(const LoggerMessage& message)
{
    
    type = message.getLogType();
    reqNodeID = message.getReqNodeID();
    information.assign(message.getInformation());
    
}

LoggerMessage::~LoggerMessage()
{

    information.clear();
    
}
