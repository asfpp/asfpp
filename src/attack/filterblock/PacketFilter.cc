/**
 * @file	PacketFilter.cc
 * @author	Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "PacketFilter.h"
#include "ElementaryBlock.h"
#include "CompoundBlock.h"
#include "seapputils.h"


PacketFilter::PacketFilter (string monolithicPacketFilter) {
    
    // split monolithicPacketFilter in single elements
    vector<string> filterElements = tokenize(monolithicPacketFilter, ':');
    
    // build blocks and logical conditions
    for (size_t i = 0; i < filterElements.size(); i++) {
        
        // block begin
        if (filterElements[i] == "[") {
            // build block
            vector<string> block;
            for (size_t j = i; filterElements[j] != "]"; j++) {
                block.push_back(filterElements[j]);
            } 
            block.push_back("]");
            
            // instantiate elementary block
            if (block.size() == ElementaryBlock::elementaryBlockSize) {
                //filterBlocks.push_back(new ElementaryBlock(std::move(block)));
                filterBlocks.push_back(new ElementaryBlock(block));
            }
            
            // instantiate compound block
            if (block.size() == CompoundBlock::compoundBlockSize) {
                //filterBlocks.push_back(new CompoundBlock(std::move(block)));
                filterBlocks.push_back(new CompoundBlock(block));
            }
            
            // adjust index i before increment
            i += block.size() - 1; 

        }
        
        // logical conditions, insert in reverse order
        if (filterElements[i] == "AND" || filterElements[i] == "OR") {
            filterOperators.insert(filterOperators.begin(), filterElements[i]);
        }
                
    }
    
}


PacketFilter::~PacketFilter () {
    
    // delete blocks composing the filter
    for (size_t i = 0; i < filterBlocks.size(); i++ ) {
        delete filterBlocks[i];
    }
    
}


bool PacketFilter::isMatchingPacketFilter (cPacket* packet) const {

    // solve all filter blocks for the current packet
    vector<bool> solvedBlocks;
    for (size_t i = 0; i < filterBlocks.size(); i++) {
        solvedBlocks.push_back(filterBlocks[i]->solveFilterBlock(packet));
    }
    
    // duplicate filter operators
    vector<string> operators (filterOperators);
    
    // solve ANDs
    for (size_t i = 0; i < operators.size(); ) {
        if (operators[i] == "AND") {
            solvedBlocks[i] = solvedBlocks[i] && solvedBlocks[i+1];
            solvedBlocks.erase(solvedBlocks.begin() + i + 1);
            operators.erase(operators.begin() + i);
        }
        else {
            i++;
        }
    }
    
    // solve the packet filter (remain only ORs)
    bool isMatching = false;
    for (size_t i=0; i < solvedBlocks.size(); i++) {
        isMatching = isMatching || solvedBlocks[i];
    }
    
    return isMatching;
    
}






