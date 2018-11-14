/**
 * @file GlobalFilter.h
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 * 
 * @brief The class GlobalFilter models the behavior of the module 
 *        GlobalFilter which executes:
 *         + unconditional attacks,
 *         + put actions,
 *         + destroy actions.
 */
 

#ifndef GLOBAL_FILTER_H
#define GLOBAL_FILTER_H


#include "CastaliaModule.h"
#include <vector>
#include <string>

#include "Entry.h"

#include "UnconditionalFireMessage_m.h"
#include "DestroyRequest_m.h"
#include "DestroyFireMessage_m.h"
#include "PutMessages.h"


using namespace std;


enum attackTimer {
  UNCONDITIONAL_ATTACK = 12
};


class GlobalFilter: public CastaliaModule {
private:
    // list of entries wrapping the unconditional attacks handled by the global filter
    vector<Entry*> unconditionalEntries;
    // TODO to remove
    // it is TRUE when evaluation of attacks is enabled
    bool attacksEvaluation;
    // name of the application
    string applicationName;
    // name of the routing protocol
    string routingProtocolName;
    // name of the mac protocol
    string macProtocolName;

private:
    /**
     * @brief Schedules (the first firing of) the unconditional attacks.
     */
    void scheduleUnconditionalAttacks();
    
    /**
     * @brief Handles UnconditionalFireMessage(s) (self-messages), i.e. execute the relative 'unconditional' attack.
     * @param unconditionalFireMessage Is the UnconditionalFireMessage to handle.
     */
    void handleUnconditionalFireMessage(UnconditionalFireMessage* unconditionalFireMessage);

    /**
     * @brief Handles DestroyRequest(s) received by the local-filter(s) and schedule the relative 'destroy' action.
     * @param destroyRequest Is the DestroyRequest to handle.
     */
    void handleDestroyRequest(DestroyRequest* destroyRequest);

    /**
     * @brief Handles DestroyFireMessage(s) (self-message), i.e. executes the relative 'destroy' action.
     * @param destroyFireMessage Is the DestroyFireMessage (self-message) to handle.
     */
    void handleDestroyFireMessage(DestroyFireMessage* destroyFireMessage);

    /**
     * @brief Handles put messages received by the local-filter(s) or creted by the global-filter.
     * @param putMsg Is the put message to handle.
     */
    void handlePutMessage(PutMessage* putMessage);


protected:
    /**
     * @brief Initializes the global-filter module.
     */
    virtual void initialize();

    /**
     * @brief Handles the received messages (both messages and self-messages).
     * @param msg Is the received message to handle.
     */
    virtual void handleMessage(cMessage* msg);

    /**
     * @brief Record statistics.
     */
    virtual void finishSpecific();

public:
    /**
     * @brief Constructor.
     */
    GlobalFilter();
    
    /**
     * @brief Destructor.
     */
    virtual ~GlobalFilter();
};

#endif
