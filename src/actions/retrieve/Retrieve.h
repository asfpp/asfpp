/*
 * This action retrieves the value of a specified packet field of a given packet
 * The adopted format is LAYER.FIELD_NAME (e.g. APP.sourceNodeID)
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef RETRIEVE_H
#define RETRIEVE_H

#include <map>

#include "Action.h"
#include "Variable.h"
#include "utils.h"
#include <omnetpp.h>
#include <iostream>
#include "CastaliaModule.h"

class Retrieve: public Action {

	string field;		// Name of the field to be accessed
	string variable_name;	// Variable where the retrieved value will be stored after being retrieved
	
	public:
	  
	Retrieve(const string field_name, const string var_name);
	virtual ~Retrieve();
	
	Variable* execute(cMessage* packet) const;
	string getField() const { return field; }
	string getVarName() const { return variable_name; }
		
};

#endif
