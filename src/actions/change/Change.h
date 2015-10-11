/*
 * This action modifies the value contained in a specified packet field.
 * The adopted format is LAYER.FIELD_NAME (e.g. APP.sourceNodeID)
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef CHANGE_H
#define CHANGE_H

#include "Action.h"
#include "SensorManager.h"
#include "utils.h"
#include <omnetpp.h>
#include <iostream>
#include "CastaliaModule.h"

class Change: public Action {
  
	string field;	// Name of the field
	string value;	// New value for the field content
		
	public:
	
	Change(const string field_name, const string new_value);
	virtual ~Change();
	
	void execute(cMessage** packet, string new_value);
	string getField() const { return field; }
	string getValue() const { return value; }
		
};

#endif
