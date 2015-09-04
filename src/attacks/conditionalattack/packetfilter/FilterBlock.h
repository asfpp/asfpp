/**
 * @file	FilterBlock.h
 * @author	Francesco Racciatti <racciatti.francesco@gmail.com>
 *
 * @brief	FilterBlock models blocks composing the packet filter.
 */
 

#ifndef FILTERBLOCK_H
#define FILTERBLOCK_H


#include <vector>
#include <string>
#include "omnetpp.h"


using namespace std;


class FilterBlock {
    
    protected:
        vector<string> blockElements;
     
    protected:
        FilterBlock(vector<string> blockElements);
        
    public:
        virtual ~FilterBlock();
        
        /**
         * @brief   Pure virtual function. Solve the block by using the infos contained in the current packet.
         * @param   packet Pointer-to the packet to test.
         * @return  true if the packet matches the the block, false otherwise.
         */
        virtual bool solveFilterBlock(cPacket* packet) const = 0;
    
};

#endif
