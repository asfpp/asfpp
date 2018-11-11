/**
 * @file	ElementaryBlock.cc
 * 
 * @author	Francesco Racciatti <racciatti.francesco@gmail.com>
 */


#include "ElementaryBlock.h"
#include "utils.h"
#include "stdlib.h"


ElementaryBlock::ElementaryBlock(vector<string> blockElements) : FilterBlock(block_t::ELEMENTARY, blockElements)
{
}


ElementaryBlock::~ElementaryBlock()
{
}


int ElementaryBlock::getLayer() const
{
    // get the layer's name
    vector<string> fullPath = tokenize(blockElements[1], '.');
    return layertoi(fullPath[0]);
}



bool ElementaryBlock::solveFilterBlock(cMessage* msg) const
{
    // tokenize the full path to access to names of layer and fields
    vector<string> fullPath = tokenize(blockElements[1], '.');    
    
    // retrieve the encapsulated message belonging to the block's layer
    int blockLayer = layertoi(fullPath[0]);
    int msgLayer = msg->getKind();
    cMessage* encapsulatedMsg = msg;
    while (msgLayer < blockLayer) {
        encapsulatedMsg = (cMessage*)(((cPacket*)encapsulatedMsg)->getEncapsulatedPacket());
        if (encapsulatedMsg == nullptr) {
            return false;
        }
        msgLayer = encapsulatedMsg->getKind();
    }
    
    // retrieve the path of fields
    vector<string> pathOfFields;
    for (size_t i = 1; i < fullPath.size(); i++) {
        pathOfFields.push_back(fullPath[i]);
    }
    
    // try to follow the path of fields until the last field is reached
    cClassDescriptor* descriptor = cClassDescriptor::getDescriptorFor(encapsulatedMsg);
    void* compoundField = encapsulatedMsg;
    int fieldIndex = -1;
    for (size_t i = 0; i < pathOfFields.size(); i++) {
        
        // the first entry is packet's top level field
        if (i==0) {
            fieldIndex = descriptor->findField(encapsulatedMsg, pathOfFields[i].c_str());
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
                structName = descriptor->getFieldStructName(encapsulatedMsg, fieldIndex);
                compoundField = descriptor->getFieldStructPointer(encapsulatedMsg, fieldIndex, 0);
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
    // retrieve the accepted values from the block
    vector<string> acceptedValues = tokenize(blockElements[3], '|');
    // perform the comparison operation
    bool comparisonResult = false;
    for (size_t i = 0; i < acceptedValues.size(); i++) {
        comparisonResult = evaluate(stod(actualValue), stod(acceptedValues[i]), comparisonOperator);
        if (comparisonResult == true) {
            return true;
        }
    }
    
    return false;
}


/*
// TODO remove, it can't access to structured fields
bool ElementaryBlock::solveFilterBlock (cMessage* msg) const
{
    // tokenize the full path to access to names of layer and fields
    vector<string> fullPath = tokenize(blockElements[1], '.');    
    
    // retrieve the encapsulated message belonging to the block's layer
    int blockLayer = layertoi(fullPath[0]);
    int msgLayer = msg->getKind();
    cMessage* encapsulatedMsg = msg;
    while (msgLayer < blockLayer) {
        encapsulatedMsg = (cMessage*)(((cPacket*)encapsulatedMsg)->getEncapsulatedPacket());
        if (encapsulatedMsg == nullptr) {
            return false;
        }
        msgLayer = encapsulatedMsg->getKind();
    }
    
    string field = fullPath[1];
    cClassDescriptor* descriptor = cClassDescriptor::getDescriptorFor(encapsulatedMsg);
    int fieldIndex = descriptor->findField(encapsulatedMsg, field.c_str());
    if (fieldIndex==-1) {
        return false;
    }
    
    // use the descriptor to get the last field's content
    string actualValue = descriptor->getFieldAsString(encapsulatedMsg, fieldIndex, 0);
    
    // retrieve the comparison operator from the block
    string comparisonOperator = blockElements[2];
    // retrieve the accepted values from the block
    vector<string> acceptedValues = tokenize(blockElements[3], '|');
    // perform the comparison operation
    bool comparisonResult = false;
    for (size_t i = 0; i < acceptedValues.size(); i++) {
        comparisonResult = evaluate(stod(actualValue), stod(acceptedValues[i]), comparisonOperator);
        if (comparisonResult == true) {
            return true;
        }
    }
    return false;
    
}
*/
