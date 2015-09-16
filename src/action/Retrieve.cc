/**
 * @file Retrieve.cc
 * @authors Francesco Racciatti <racciatti.francesco@gmail.com>
 *          Alessandro Pischedda <alessandro.pischedda@gmail.com>
 */


#include "Retrieve.h"
#include "utils.h"


Retrieve::Retrieve (const string completePath, const string varName) : Action (RETRIEVE) {

    // split layer from the path of fields
    vector<string> tokens = tokenize(completePath, '.');
    // store the target layer
    layer = layertoi(tokens[0]);
    // store the target path of fields
    for (size_t i = 1; i < tokens.size(); i++) {
        this->pathOfFields.push_back(tokens[i]);
    }
    // store the name of the variable that contains the value
    this->varName = varName;

}


Retrieve::~Retrieve() {
  
}


Variable* Retrieve::execute (cMessage* msg) const {

    // clone the original packet
    cMessage* substituteMsg = (cMessage*)hardCopy((cPacket*)msg);
    cMessage* encapsulatedMsg = substituteMsg;
    
    // get packet kind (usefull to determine its layer)
    int msgKind = msg->getKind();
    
    // de-caspulate packets until the right layer is reached 
    while (msgKind < layer) {
        
        encapsulatedMsg = ((cPacket*)encapsulatedMsg)->getEncapsulatedPacket();
        // check if the encapsulated packet exists
        if (encapsulatedMsg==nullptr) {
            opp_error("[Variable* Retrieve::execute(cMessage*)] The layer at which you tried to access does not exist in the current packet, please check the packet-filter");
        }
        msgKind = encapsulatedMsg->getKind();
	
    }
    
    
    // try to follow the path of fields until the last field is reached
    cClassDescriptor* descriptor = cClassDescriptor::getDescriptorFor(encapsulatedMsg);
    void* compoundField = encapsulatedMsg;
    int fieldIndex = -1;
    for (size_t i = 0; i < pathOfFields.size(); i++) {
        
        // the first entry is message's top field (if exists)
        if (i==0) {
            fieldIndex = descriptor->findField(encapsulatedMsg, pathOfFields[i].c_str());
        }
        else {
            fieldIndex = descriptor->findField(compoundField, pathOfFields[i].c_str());
        }
        
        // check if the searched field exists
        if (fieldIndex==-1) {
            string msgErr = "[Variable* Retrieve::execute(cMessage*)] The field '" + pathOfFields[i];
            msgErr += "' in the indicated layer does not exist, please check the path of fields or the packet-filter";
            opp_error(msgErr.c_str());
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
    string value = descriptor->getFieldAsString((cObject*)compoundField, fieldIndex, 0);
    
    // instantiate a variable which stores the retrieved value
    Variable* variable = new Variable(value, getFormat(value) );
    
	return variable;

}


string Retrieve::getField () const { 
    
    string monolithicPathOfFields;
    for (size_t i = 0; i < pathOfFields.size(); i++) {
        monolithicPathOfFields.append(pathOfFields[i]);
        if (i != pathOfFields.size()-1) {
            monolithicPathOfFields.append(".");
        }
    }
    
    return monolithicPathOfFields;
    
}


string Retrieve::getVarName () const {
    
    return varName;
    
}























