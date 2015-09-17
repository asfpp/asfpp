/**
 * @file Action.h
 * @authors Alessandro Pischedda <alessandro.pischedda@gmail.com>
 *          Francesco Racciatti <racciatti.francesco@gmail.com>
 * @brief Base class for actions. It represents a generic action performed during attacks.
 */


#ifndef ACTION_H 
#define ACTION_H


#include <string>
#include "CastaliaModule.h"

// relevant for actions that do not refer a specific layer to be executed
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
    FAKEREAD = 10,
    DISABLE = 11
};


class Action {

    private:
        // name of the action
        ActionName name;
        // name of the packet
        string packetName;
    
    protected:
        // specific layer in which execute the action
        int layer;
    
    public:
        Action(const ActionName actionName);
        virtual ~Action();
        
        ActionName getName() const;
        virtual void setPacketName(const string name);
        virtual string getPacketName() const;
        virtual int getLayer() const;
    
};

#endif
