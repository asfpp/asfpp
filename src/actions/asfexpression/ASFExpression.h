/*
 * This class is used to represent arithmetic or boolean expressions.
 * It makes use of the Reverse Polish Notation (RPN) described below.
 *
 * RPN is a postfix notation in which every operator follows all its operands, thus being parentethis-free.
 *
 * EXAMPLE 
 *
 *    Prefix notation  5 + 6
 *    Postfix notation 5 6 + 
 * 
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <stack>
#include <vector>
#include <map>
#include "Variable.h"
#include "utils.h"
#include "Action.h"
#include <omnetpp.h>
#include <iostream>
#include "CastaliaModule.h"

using namespace std;

class ASFExpression : public Action{

	// The expression is represented as a sequence of token
	vector<string> tokens;

	bool operatorModifier(const string op );

	public:
	
	ASFExpression(const vector<string> items);
	void execute(map<string, Variable*> *varTable, stack<Variable> *stack_ );

	virtual ~ASFExpression(){ tokens.clear(); };
	
};

#endif
