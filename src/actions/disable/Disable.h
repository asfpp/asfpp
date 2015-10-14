/**
 * @file Disable.h
 * 
 * @author Francesco Racciatti <racciatti.francesco@gmail.com>
 * 
 * @brief The class Disable destroies the node's communication module.
 */

#ifndef DISABLE_H
#define DISABLE_H


#include "Action.h"
#include <cobject.h>


class Disable : public Action {
private:
    // pointer to the target node (i.e. the node to disable)
    cModule* targetNode;

public:
    /**
     * @brief Constructor.
     * @param targetNode Is the pointer-to the node to disable.
     */
    Disable(cModule* targetNode);
    
    /**
     * @brief Destructor.
     */
    virtual ~Disable();

    /**
     * @brief Disables the node.
     */
    void execute() const;
};

#endif
