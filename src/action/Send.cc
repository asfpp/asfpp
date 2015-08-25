#include "Send.h"

void Send::execute(cMessage* msg) const {

	int field_int;
	cClassDescriptor* descriptor;
	descriptor = cClassDescriptor::getDescriptorFor(msg);

	field_int = descriptor->findField(msg, "sended");
	
	/* The 'sended' field cannot be found. This should never happen! */
	if( field_int == -1){
		string error_message = " ERROR in Retrieve Action : the object field 'sended' does not exist!!!";
		opp_error(error_message.c_str());
	}
	
	/* The packet will be sent to the next layer in the TX/RX flow */
	descriptor->setFieldAsString(msg, field_int, 0, "1");
		
}

double Send::getDelay(){
	return delay;
}
