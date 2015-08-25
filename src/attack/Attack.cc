#include "Attack.h"

/* Add an action to the list of actions composing the attack */
void Attack::addAction(Action* action) {

	actions.push_back(action);
	
}

/* Store the variable table provided as argument */
void Attack::addVarTable(const map<string, Variable*> varTable) {

	this->varTable = varTable;

}

Attack::~Attack() {

	// Delete actions
	for(int i=0; i < actions.size(); i++)
		delete actions[i];

	actions.clear();

	// Delete variables
	std::map<std::string, Variable *>::iterator iter;
	for( iter = varTable.begin(); iter != varTable.end() ; iter++)
		delete iter->second;

	// Clear the variable table
	varTable.clear();

	// Delete the stack
	while( !varStack.empty() )
		varStack.pop();

}

