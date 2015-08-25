/*
 * This class represents a generic action performed during attacks
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef ACTION_H 
#define ACTION_H

#include <string>
#include <iostream>
#include "CastaliaModule.h"

/* This is relevant for actions that do not refer to a specific layer */
#define NONE 100

using namespace std;

enum ActionName{
	DESTROY = 0,
	MOVE = 1,
	CHANGE = 2,
	DROP = 3,
	PUT = 4,
	CLONE = 5,
	RETRIEVE = 6,
	CREATE = 7,
	SEND = 8,
	EXPRESSION = 9,
	FAKEREAD = 10 
};

class Action {

	ActionName name;
	string packetName;
	
	protected:
	
		int layer;

	public:

		Action(const ActionName name_action);
		virtual ~Action() { packetName.clear(); }
	
		ActionName getName() const { return name; }
		virtual void setPacketName(const string name) { packetName = name; }
		virtual string getPacketName() const { return packetName; }
		virtual int getLayer() const { return layer; }
		
};

#endif
