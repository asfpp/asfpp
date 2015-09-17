/**
 * @file	ElementaryBlock.cc
 * @author	Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "ElementaryBlock.h"
#include "utils.h"
#include "stdlib.h"


//ElementaryBlock::ElementaryBlock (vector<string> blockElements) : FilterBlock(std::move(blockElements)) {
ElementaryBlock::ElementaryBlock (vector<string> blockElements) : FilterBlock(blockElements) {
    
}


ElementaryBlock::~ElementaryBlock () {
    
}


bool ElementaryBlock::solveFilterBlock (cPacket* packet) const {
    
    // tokenize the fullPath
    vector<string> fullPath = tokenize(blockElements[1], '.');
    
    // clone the original packet
    cPacket* substitutePacket = hardCopy(packet);
    cPacket* encapsulatedPacket = substitutePacket;
    // retrieve the layer name
    string layerName = fullPath[0];
    // retrieve the encapsulated packet which belongs to the same layer of the block 
    int packetLayer = getPacketLayer(encapsulatedPacket);
    while (packetLayer > layertoi(layerName)) {
        
        encapsulatedPacket = encapsulatedPacket->getEncapsulatedPacket();
        // layer not found
        if (encapsulatedPacket == nullptr) {
            return false;
        }
        packetLayer = getPacketLayer(encapsulatedPacket);
    }
    
    // retrieve the path of fields
    vector<string> pathOfFields;
    for (size_t i = 1; i < fullPath.size(); i++) {
        pathOfFields.push_back(fullPath[i]);
    }
    // try to follow the path of fields until the last field is reached
    cClassDescriptor* descriptor = cClassDescriptor::getDescriptorFor(encapsulatedPacket);
    void* compoundField = encapsulatedPacket;
    int fieldIndex = -1;
    for (size_t i = 0; i < pathOfFields.size(); i++) {
        
        // the first entry is packet's top level field
        if (i==0) {
            fieldIndex = descriptor->findField(encapsulatedPacket, pathOfFields[i].c_str());
        }
        else {
            fieldIndex = descriptor->findField(compoundField, pathOfFields[i].c_str());
        }
        
        // field not found in the current packet
        if (fieldIndex==-1) {
            return false;
        }
        
        // all entries (except the last) refer compound fields
        if (i != pathOfFields.size()-1) {
        
            string structName;
            // get the pointer-to the compound field
            if (i==0) {
                structName = descriptor->getFieldStructName(encapsulatedPacket, fieldIndex);
                compoundField = descriptor->getFieldStructPointer(encapsulatedPacket, fieldIndex, 0);
            }
            else {
                structName = descriptor->getFieldStructName(compoundField, fieldIndex);
                compoundField = descriptor->getFieldStructPointer(compoundField, fieldIndex, 0);
            }
            
            // get the descriptor of the compound field
            descriptor = cClassDescriptor::getDescriptorFor(structName.c_str());
        
        }
        
    }
        
    // use the descriptor to get the last field's content
    string actualValue = descriptor->getFieldAsString((cObject*)compoundField, fieldIndex, 0);
    // retrieve the comparison operator from the block
    string comparisonOperator = blockElements[2];
    // retrieve the accepted values for the comparison operation from the block
    vector<string> acceptedValues = tokenize(blockElements[3], '|');
    // perform the comparison operation
    bool comparisonResult = false;
    for (size_t i = 0; i < acceptedValues.size(); i++) {
        comparisonResult = evaluate( stod(actualValue.c_str()), stod(acceptedValues[i].c_str()), comparisonOperator );
        if (comparisonResult == true) {
            return true;
        } 
    }
    
    return false;
    
}
