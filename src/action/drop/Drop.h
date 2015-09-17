/**
 * @file	Drop.h
 * @authors Alessandro Pischedda <alessandro.pischedda@gmail.com>
 *      	Francesco Racciatti <racciatti.francesco@gmail.com>
 *
 * @brief	The class Drop is used to drop packets.
 */


#ifndef DROP_H
#define DROP_H


#include "Action.h"
#include <cobject.h>


class Drop : public Action {
    
    private:
        double threshold;

	public:
        Drop(double threshold);
        virtual ~Drop();

		/**
		 * @brief   Drops the packet (depending on the threshold).
         * @param   packet is the packet to drop.
		 */
		void execute(cMessage** packet) const;
    
};

#endif
