/**
 * @file Change.h
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 * @brief The class 'Change' models the action 'change'. 
 *        It modifies the value contained in a specified packet field.
 */


#ifndef CHANGE_H
#define CHANGE_H


#include "Action.h"
#include <vector>
#include <omnetpp.h>


class Change: public Action {

    private:
        // path to the field
        vector<string> pathOfFields;
        // name of the variable that contains the value to write in the target field
        string varName;
    
    public:
        Change(const string completePath, const string varName);
        virtual ~Change();
        
        /**
         * @brief Modify the value of a certain field.
         * @details To access to the correct field, it is used the class 'cClassDescriptor'.
         * @param msg is the packet to modify
         * @param value is the value to write in the field
         */
        void execute(cMessage** msg, string value);
        
        // TODO change in 'getMonolithicPathOfFields()'
        string getField() const;
        // TODO change in getVarName()
        string getValue() const;
    
};

#endif
