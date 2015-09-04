/**
 * @file	CompoundBlock.cc
 * @author	Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "CompoundBlock.h"
#include <seapputils.h>


CompoundBlock::CompoundBlock (vector<string> blockElements) : FilterBlock(blockElements) {

}

CompoundBlock::~CompoundBlock () {
    
}

/**
 @details A compound block has the following form:
 *          [ : ( : layerName.fieldName : arithmeticOperator : operand : ) : comparisonOperator : operand : ]
 *          ^   ^           ^                       ^             ^      ^             ^             ^      ^
 *          0   1           2                       3             4      5             6             7      8 
 */
bool CompoundBlock::solveFilterBlock (cPacket* packet) const {
    
    // retrieve the layer name from the block
    string layerName = vector<string>(tokenize(blockElements[2], '.'))[0];
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
    string fieldName = vector<string>(tokenize(blockElements[2], '.'))[1];
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
        string arithmeticOperator = blockElements[3];
        // retrieve values for the comparison operation from the block
        string operand = blockElements[4];
        // perform the arithmetic operation
        string valuePacket = descriptor->getFieldAsString(encapsulatedPacket, fieldIndex, 0);
        float result = evaluateArithmetic( atoi(valuePacket.c_str()), atoi(operand.c_str()), arithmeticOperator );
        
        // retrieve the comparison operator from the block
        string comparisonOperator = blockElements[6];
        // retrieve values for the comparison operation from the block
        vector<string> values = tokenize(blockElements[7], '|');
        // perform the comparison operation
        bool comparisonResult = false;
        for (size_t i = 0; i < values.size(); i++) {
            comparisonResult = evaluate( (int)result, atoi(values[i].c_str()), comparisonOperator );
            if (comparisonResult == true) {
                return true;
            } 
        }
        
    }
    
    return false;
    
}


