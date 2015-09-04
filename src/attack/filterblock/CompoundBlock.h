/**
 * @file    CompoundBlock.h
 * @author  Francesco Racciatti <racciatti.francesco@gmail.com>
 *
 * @brief   CompoundBlock models compound blocks composing the packet filter.
 * 
 * @details A compound block has the following form:
 *          [ : ( : layerName.fieldName : arithmeticOperator : operand : ) : comparisonOperator: operand : ]
 *          ^   ^           ^                       ^             ^      ^             ^            ^      ^
 *          0   1           2                       3             4      5             6            7      8 
 */
 

#ifndef COMPOUNDBLOCK_H
#define COMPOUNDBLOCK_H


#include <FilterBlock.h>
#include "omnetpp.h"


using namespace std;


class CompoundBlock : public FilterBlock {
    
    public:
        static const size_t compoundBlockSize = 9;
     
    public:
        CompoundBlock(vector<string> blockElements);
        ~CompoundBlock();
        
        /**
         * @brief   Solve the compound block by using the infos contained in the current packet.
         * @param   packet Pointer-to the packet to test.
         * @return  true if the packet matches the compound block, false otherwise.
         */
        bool solveFilterBlock(cPacket* packet) const;
    
};

#endif
