/**
 * @file Drop.h
 * 
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 * 
 * @brief The class Drop models the action drop, which is used to 
 *        delete packets according to the setted threshold.
 */


#ifndef DROP_H
#define DROP_H


#include "Action.h"
#include <omnetpp.h>


class Drop: public Action {
private:
    // drop threshold 
    double threshold;

public:
    /**
     * @brief Constructor.
     * @param threshold Is the threshold that will be used to decide
     *        if a packet will be deleted. If left empty, it is setted 
     *        the max threshold (i.e. all packets will be dropped).
     */
    Drop(double threshold = 1.0);
    
    /**
     * @brief Setter method, sets the threshold.
     * @param threshold Is the threshold that will be used to decide
     *        if a packet will be deleted.
     */
    void setThreshold(double threshold);
    
    /**
     * @brief Getter method, get the threshold.
     * @return Returns the threshold.
     */
    double getThreshold() const;

    /**
     * @brief Destructor.
     */
    virtual ~Drop();

    /**
     * @brief Drops the current packet according to the setted
     *        threshold.
     * @param packet Is the pointer-to the pointer-to the packet 
     *        that will be dropped according to the setted 
     *        threshold.
     */
    void execute(cMessage** packet) const;
};

#endif
