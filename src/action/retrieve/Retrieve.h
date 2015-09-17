/**
 * @file Retrieve.h
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 * @brief The class Retrieve models the action 'retrieve'.
 *        It retrieves the value of a specified field (even in a structure) of a given packet.
 */


#ifndef RETRIEVE_H
#define RETRIEVE_H


#include "Action.h"
#include <vector>
#include <omnetpp.h>
#include "Variable.h"


class Retrieve: public Action {
    
    private:
        // path to the field
        vector<string> pathOfFields;
        // name of the variable in which store the retrieved value
        string varName;
    
    public:
        Retrieve(const string completePath, const string varName);
        virtual ~Retrieve();
        
        /**
         * @brief Retrieve the value of the specified packet field.
         * @param msg packet from which the field has to be retrieved
         * @return pointer-to the variable that stores the retrieved value
         */
        Variable* execute(cMessage* msg) const;
        
        // TODO change in 'getMonolithicPathOfFields'
        string getField() const;
        string getVarName() const;
    
};

#endif
