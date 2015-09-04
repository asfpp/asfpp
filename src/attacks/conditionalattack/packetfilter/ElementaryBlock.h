/**
 * @file    ElementaryBlock.h
 * @author  Francesco Racciatti <racciatti.francesco@gmail.com>
 *
 * @brief   ElementaryBlock models elementary blocks composing the packet filter.
 * 
 * @details An elementary block has the following form:
 *          [ : layerName.fieldName. : comparisonOperator : operand : ]
 */
 

#ifndef ELEMENTARYBLOCK_H
#define ELEMENTARYBLOCK_H


#include "FilterBlock.h"
#include "omnetpp.h"


using namespace std;


class ElementaryBlock : public FilterBlock {
    
    public:
        static const size_t elementaryBlockSize = 5;
     
    public:
        ElementaryBlock(vector<string> blockElements);
        ~ElementaryBlock();
        
        /**
         * @brief   Solve the elementary block by using the infos contained in the current packet.
         * @param   packet Pointer-to the packet to test.
         * @return  true if the packet matches the elementary block, false otherwise.
         */
        bool solveFilterBlock(cPacket* packet) const;
    
};

#endif
