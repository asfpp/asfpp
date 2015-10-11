/**
 * @file Attack.cc
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 */
 
 
#include "Attack.h"
#include <stdexcept>


Attack::Attack()
{
}


Attack::~Attack()
{
    // delete actions
    for (size_t i = 0; i < actions.size(); i++) {
        delete actions[i];
    }
    // delete variables
    map<string, Variable*>::iterator iter;
    for (iter = varTable.begin(); iter != varTable.end() ; iter++) {
        delete iter->second;
    }
}


void Attack::addAction(Action* action)
{
    actions.push_back(action);
}


Action* Attack::getAction(int index)
{    
    Action* action;
    try {
        action = actions.at(index);
    }
    catch(const std::out_of_range& oor) {
        opp_error("[Action* Attack::getAction(int)] Out of range exception raised");
    }
    return action;
}


void Attack::addVarTable(const map<string, Variable*> varTable)
{
    this->varTable = varTable;
}


cMessage* Attack::execute()
{    
}
