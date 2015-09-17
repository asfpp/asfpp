/**
 * @file	Disable.h
 * @author	Francesco Racciatti <racciatti.francesco@gmail.com>
 *
 * @brief	Disables the communication module of a node (actually removes the node).
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
		 * @brief   Constructor.
		 * @param   targetNode, is the pointer-to the node to disable.
		 */
        Disable(cModule* targetNode);
		virtual ~Disable();

		/**
		 * @brief   Disables the (communication module of the) node.
		 */
		void execute() const;
    
};

#endif
