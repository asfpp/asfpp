/**
 * @file Destroy.h
 * 
 * @author Francesco Racciatti <racciatti.francesco@gmail.com>
 * 
 * @brief The class Destroy destroies a node.
 */

#ifndef DESTROY_H
#define DESTROY_H


#include "Action.h"
#include <cobject.h>


class Destroy : public Action {
private:
    // pointer to the target node (i.e. the node to destroy)
    cModule* targetNode;

public:
    /**
     * @brief Constructor.
     * @param targetNode Is the pointer-to the node to destroy.
     */
    Destroy(cModule* targetNode);
    
    /**
     * @brief Destructor.
     */
    virtual ~Destroy();

    /**
     * @brief Destroyes the node.
     */
    void execute() const;
};

#endif
