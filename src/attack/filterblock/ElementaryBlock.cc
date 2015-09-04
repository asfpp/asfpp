/**
 * @file	ElementaryBlock.cc
 * @author	Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "ElementaryBlock.h"
#include "seapputils.h"


//ElementaryBlock::ElementaryBlock (vector<string> blockElements) : FilterBlock(std::move(blockElements)) {
ElementaryBlock::ElementaryBlock (vector<string> blockElements) : FilterBlock(blockElements) {
    
}


ElementaryBlock::~ElementaryBlock () {
    
}


bool ElementaryBlock::solveFilterBlock (cPacket* packet) const {
        
    // retrieve the layer name from the block
    string layerName = vector<string>(tokenize(blockElements[1], '.'))[0];    
    // retrieve the encapsulated packet which belongs to the same layer of the block 
    cPacket* encapsulatedPacket = packet;
    while (getPacketLayer(encapsulatedPacket) > layertoi(layerName)) {
        encapsulatedPacket = encapsulatedPacket->getEncapsulatedPacket();
        // layer not found
        if (encapsulatedPacket == nullptr) {
            return false;
        }
    }

    // retrieve the field name from the block
    string fieldName = vector<string>(tokenize(blockElements[1], '.'))[1];
    // retrieve the descriptor of the encapsulated packet
    cClassDescriptor* descriptor = cClassDescriptor::getDescriptorFor(encapsulatedPacket);
    // retrieve the index of the field of the packet from its descriptor
    int fieldIndex = descriptor->findField(encapsulatedPacket, fieldName.c_str());
    // field not found in the packet
    if (fieldIndex == -1) {
            return false;
    }
    else {
        // retrieve the comparison operator from the block
        string comparisonOperator = blockElements[2];
        // retrieve values for the comparison operation from the block
        vector<string> values = tokenize(blockElements[3], '|');
        // perform the comparison operation
        string valuePacket = descriptor->getFieldAsString(encapsulatedPacket, fieldIndex, 0);
        bool comparisonResult = false;
        for (size_t i = 0; i < values.size(); i++) {
            comparisonResult = evaluate( atoi(valuePacket.c_str()), atoi(values[i].c_str()), comparisonOperator );
            if (comparisonResult == true) {
                return true;
            } 
        }
    }
    
    return false;
        
}
