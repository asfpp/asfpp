#include "Retrieve.h"

Retrieve::Retrieve(const string field_name, const string var_name) : Action(RETRIEVE) {

	vector<string> tokens;

	/* Split layer/field information */
	tokenize(tokens, field_name, '.');
	layer = layertoi(tokens[0]);
	field = tokens[1];
	
	variable_name = var_name;

}

/* 
 * Retrieve the value of the specified packet field.
 * 
 * @param msg		The packet from which the field has to be retrieved
 * @return 		The value of the retrieved field, as a String Variable object
 */
Variable* Retrieve::execute(cMessage* msg) const {

	string value;

	cClassDescriptor* descriptor; 
	cMessage* substitute_pkt = NULL; 
	cMessage* temp_packet = NULL ;

	int msgKind;

	int field_int; // the function setFieldAsString want the field as a integer

	msgKind = (msg)->getKind();

	/* copy the original packet */
	substitute_pkt = (cMessage* )hardCopy( (cPacket*)(msg) );

	temp_packet = substitute_pkt;

	/* Retrieve the encapsulated packet until the right layer is reached */
	while( msgKind < layer ) {

		temp_packet = ((cPacket*)temp_packet)->getEncapsulatedPacket();

		/* avoid the segmentation fault if you try to access to an encapsulated
			packet doesn't exists in this packet. */
		if( temp_packet == NULL){
			string error_message = "\nYou try to access in a layer not contained in this packet,";
			error_message+=" check carefully your filter specification";
			throw cRuntimeError(error_message.c_str());
		}

		msgKind = temp_packet->getKind();
	}

	/* Use the classDescriptor to access the field */
	descriptor = cClassDescriptor::getDescriptorFor(temp_packet);

    //field_int = descriptor->findField(temp_packet, field.c_str());
    field_int = descriptor->findField(field.c_str());
	
	/* The specified field has not been found. This should never happen! */
	if(field_int == -1) {
		string error_message = "RETRIEVE : The packet hasn't a field called "+field;
		throw cRuntimeError(error_message.c_str());
	}
	
	/* Retrieve the value of the specified field (it requires an integer to identify the right field) */
	value = descriptor->getFieldValueAsString(temp_packet, field_int, 0);

	return new Variable(value, getFormat(value) );
	
}

Retrieve::~Retrieve() {
  
	field.clear();

}
