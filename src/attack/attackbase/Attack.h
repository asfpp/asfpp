/**
 * @file Attack.h
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 * 
 * @brief The class Attack models a generic attack. An attack is made 
 *        by a set of actions.
 */


#ifndef ATTACK_H
#define ATTACK_H


#include <vector>
#include <string>
#include <map>
#include <stack>
#include <omnetpp.h>

#include "Action.h"
#include "Variable.h"


using namespace std;

// TODO make it an abstract class
// TODO change name in "AttackBase"
class Attack {
protected:
    // ordered set of actions composing the attack
    vector<Action*> actions;
    // variables used to perform the attack
    map<string, Variable*> varTable;
    // support for the evaluation of the expressions
    stack<Variable> varStack;
    
public:
    /**
     * @brief Constructor.
     */
    Attack();

    /**
     * @brief Destructor. Deletes actions and variables pointed by 
     *        the pointers contained in actions and varTable. 
     */
    virtual ~Attack();
    
    /**
     * @brief Adds (appends) an action to the attack.
     * @param action Is the pointer-to the action to append to the 
     *        vector actions.
     */
    virtual void addAction(Action* action);
    
    /**
     * @brief Getter method, gets the pointer-to action having 
     *        the specified index, if exists.
     * @param index Is the index of the pointer-to action to return.
     * @return Returns the pointer-to action at the poisition 
     *         index.
     */
    virtual Action* getAction(int index);
    
    /**
     * @brief Adds a table of variables to the attack.
     * @param varTable Is the table of variables that will be used 
     *        to perform the attack.
     */
    void addVarTable(const map<string, Variable*> varTable);
    
    // TODO make pure virtual
    /**
     * @brief ...
     * @return ...
     */
    cMessage* execute();

};

#endif
