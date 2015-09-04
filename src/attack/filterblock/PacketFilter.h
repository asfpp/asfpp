/**
 * @file	PacketFilter.h
 * @author	Francesco Racciatti <racciatti.francesco@gmail.com>
 *
 * @brief	PacketFilter class models the packet filter.
 */
 

#ifndef PACKETFILTER_H
#define PACKETFILTER_H


#include <FilterBlock.h>


using namespace std;


class PacketFilter {
    
    private:
        // store blocks (tadily) that build the packet filter
        vector<FilterBlock*> filterBlocks;
        // store operators (tadily) between blocks
        vector<string> filterOperators;
    
    public:
        PacketFilter(string monolithicPacketFilter);
        ~PacketFilter();
        
        /**
         * @brief   Check if a packet matches the packet filter.
         * @param   packet Pointer-to the packet to test.
         * @return  true if the packet matches the packet filter, false otherwise.
         */
        bool isMatchingPacketFilter(cPacket* packet) const;
    
};

#endif
