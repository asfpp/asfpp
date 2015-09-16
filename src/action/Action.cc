/**
 * @file Action.cc
 * @authors Alessandro Pischedda <alessandro.pischedda@gmail.com>
 *          Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "Action.h"


Action::Action (const ActionName actionName) {
    
    this->name = actionName;
	// physical actions do not deal with packets
	this->packetName = "";
    // the execution of some logical actions is triggered by the packet-filter matching
	this->layer = NONE;

}


Action::~Action () {
    
}


ActionName Action::getName () const {
    
    return name;

}


void Action::setPacketName (const string name) {
    
    packetName = name;

}


string Action::getPacketName () const {
    
    return packetName;
    
}


int Action::getLayer () const {
    
    return layer;
    
}
