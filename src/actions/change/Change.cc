#include "Change.h"

Change::Change(const string field_name, const string new_value) : Action(CHANGE) {

	vector<string> tokens;
	
	/* Split layer/field information */
	tokenize(tokens, field_name, '.');

	layer = layertoi (tokens[0]);
	field = tokens[1];

	value = new_value;

}

/* 
 * Modify the value of a certain filed (the name of the field is a private class information).
 * To access the correct field, and have a generic method, it uses the packet descriptor class. 
 * 
 * @param msg	is the packet to modify
 */
void Change::execute(cMessage** msg, string new_value) {

	cClassDescriptor* descriptor; 
	cMessage* substitute_pkt = NULL; 
	cMessage* temp_packet = NULL ;

	int msgKind;

	int field_int; // Integer associated to the field to be edited

	msgKind = (*msg)->getKind();

	/* Create a full copy of the original packet */
	substitute_pkt = (cMessage* )hardCopy( (cPacket*)(*msg) );

	temp_packet = substitute_pkt;

	/* Retrieve the encapsulated packet until the right layer is reached */
	while( msgKind < layer ) {

		temp_packet = ((cPacket*)temp_packet)->getEncapsulatedPacket();

		/* avoid the segmentation fault if you try to access to an encapsulated
			packet doesn't exists in this packet. */
		if( temp_packet == NULL){
			string error_message = "\nYou try to access in a layer not contained in this packet,";
			error_message+=" check carefully your filter specification";
			opp_error(error_message.c_str());
		}

		msgKind = temp_packet->getKind();
	}

	/* Use the classDescriptor to access the field */
	descriptor = cClassDescriptor::getDescriptorFor(temp_packet);

	field_int = descriptor->findField(temp_packet, field.c_str());
	
	/* The specified field has not been found. This should never happen! */
	if(field_int == -1){
		string error_message = "\nCHANGE : The packet hasn't a field called "+field;
		opp_error(error_message.c_str());
	}

	/* Edit the value of the specified field (it requires an integer to identify the right field) */
	descriptor->setFieldAsString(temp_packet, field_int, 0, new_value.c_str());

	/* Delete the original packet and replace it with the copy */
	delete *msg;
	*msg = substitute_pkt;
	
}

Change::~Change() {

	field.clear();
	value.clear();
  
}
