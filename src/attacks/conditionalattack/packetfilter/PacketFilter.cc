/**
 * @file	PacketFilter.cc
 * @author	Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "PacketFilter.h"
#include "ElementaryBlock.h"
#include "CompoundBlock.h"
#include "utils.h"
#include <algorithm>


PacketFilter::PacketFilter (string monolithicPacketFilter) {
    
    
    // split monolithicPacketFilter in single elements
    vector<string> filterElements = tokenize(monolithicPacketFilter, ':');
    
    // build blocks and logical conditions (tadily)
    vector<string> reverseLogicalOperators;
    for (size_t i = 0; i < filterElements.size(); i++) {
        
        // build block
        if (filterElements[i] == "[") {
            
            vector<string> block;
            for (size_t j = i; filterElements[j] != "]"; j++) {
                block.push_back(filterElements[j]);
            } 
            block.push_back("]");
            
            // instantiate elementary block
            if (block.size() == ElementaryBlock::elementaryBlockSize) {
                filterBlocks.push_back(new ElementaryBlock(block));
            }
            
            // instantiate compound block
            if (block.size() == CompoundBlock::compoundBlockSize) {
                filterBlocks.push_back(new CompoundBlock(block));
            }
            
            // adjust index i before increment
            i += block.size() - 1; 

        }
        
        // logical conditions (stored in inverse order)
        if (filterElements[i] == "AND" || filterElements[i] == "OR") {
            filterOperators.push_back(filterElements[i]);
        }
    
    }
    
    // reverse filter logical operators
    std::reverse(filterOperators.begin(), filterOperators.end());
    
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
    // append an OR operator for convenience
    operators.push_back("OR");

    // solve ANDs
    for (size_t i = 0; i < operators.size(); i++) {
        
        // solve the chain of ANDs
        if (operators[i] == "AND") {
            
            bool result = solvedBlocks[i];
            for (size_t j = i; j < operators.size(); j++) {
                
                if (operators[j] == "AND") {
                    // solve AND left to right
                    result = result && solvedBlocks[j+1];
                }
                else {
                    // return true if the result is true (it is a logical operand between ORs)
                    if (result == true) {
                        return true;
                    }
                    
                    // update the main index and break the sub-loop
                    i = j;
                    break;
                }
                
            }
            
        }
        else {
            // return true if the result is true (it is a logical operand between ORs)
            if (solvedBlocks[i] == true) {
                return true;
            }
            
        }
        
    }

    return false;
    
}

