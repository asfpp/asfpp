/* 
 * This class represents a generic attack, defined as a sequence of actions. 
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef ATTACK_H
#define ATTACK_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include "CastaliaModule.h"
#include "Action.h"
#include "ASFExpression.h"

using namespace std;

class Attack {

	protected:
	
	/* Sequence of actions performed during the attack */
	vector<Action*> actions;
	
	/* This table stores variables used during the attack. Entry format is <Variable_Name ; Variable_Object> */
	map<string, Variable*> varTable;
	
	/* This stack is used to support expression evaluation */
	stack<Variable> varStack;

	public:
	  
	Attack() {}
	virtual ~Attack();

	cMessage* execute() {};
	virtual void addAction(Action* action);
	void addVarTable(const map<string, Variable*> varTable);
		
};

#endif
