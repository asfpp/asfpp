/**
 * @file Action.h
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 *
 * @brief The class Action models a generic action performed during 
 *        attacks.
 */


#ifndef ACTION_H 
#define ACTION_H


#include <string>
#include "CastaliaModule.h"


#define NONE 100


using namespace std;


// TODO use enum class
enum ActionName {
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
    ActionName actionName;
    // name of the target packet
    string packetName;
    
protected:
    // layer in which the action must be performed
    int layer;

public:
    /**
     * @brief Constructor.
     * @param name Is the name of the action.
     */
    Action(const ActionName actionName);
    
    /**
     * @brief Destructor.
     */
    virtual ~Action();

    /**
     * @brief Getter method, gets the name of the action.
     * @return Returns the name of the action.
     */
    ActionName getName() const;
    
    /**
     * @brief Setter method, sets the packet name.
     * @param packetName Is the name of the target packet.
     */
    virtual void setPacketName(const string packetName);
    
    /**
     * @brief Getter method, gets the packet name.
     * @return Returns the name of the target packet.
     */      
    virtual string getPacketName() const;
    
    /**
     * @brief Getter method, gets the target layer.
     * @return Returns the layer in which the action must be 
     *         performed.
     */
    virtual int getLayer() const;
};

#endif
