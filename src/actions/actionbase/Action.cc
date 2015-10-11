/**
 * @file Action.cc
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 */
 

#include "Action.h"


Action::Action(const ActionName actionName)
{
    // set the action's name
    this->actionName = actionName;
    // physical actions do not deal with packets
    packetName = "";
    layer = NONE;
}


Action::~Action()
{
}


ActionName Action::getName() const
{
    return actionName;
}


void Action::setPacketName(const string packetName)
{
    this->packetName = packetName;
}


string Action::getPacketName() const
{    
    return packetName;
}


int Action::getLayer() const
{    
    return layer;
}

