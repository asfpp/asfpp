#include "utils.h"

void tokenize(vector<string>& tokens, const string str, const char delim) {
    
    string word;
    stringstream stream(str);
    while (getline(stream, word, delim))
        tokens.push_back(word);

}

vector<string> tokenize (const string stringToTokenize, const char delimiter) {
	
	// vector of tokenized strings
	vector<string> tokens;
	
	string word;
	stringstream stream(stringToTokenize);
	
	while (getline(stream, word, delimiter)) {
		tokens.push_back(word);
	}
	
	return tokens;
}



string itos(const int i) { 
  
 	stringstream s; 
 	s << i; 
 	return s.str(); 

}

string dtos(const double number){

	std::ostringstream strs;
	strs << number;
	return strs.str();

}

int layertoi(const string layer) {

	if(layer == "MAC")
		return 30;
	if(layer == "NET")
		return 40;
	if(layer == "APP")
		return 50;
    
    string message = "ERROR : in the XML file -> the layer "+layer+" doesn't exist\n";
	opp_error(message.c_str());
}


int getPacketLayer(cPacket* packet) {
    
    switch (packet->getKind()) {
    
        case(NODE_STARTUP):{return 0;}
        case(TIMER_SERVICE):{return 0;}
        case(OUT_OF_ENERGY):{return 0;}
        case(DESTROY_NODE):{return 0;}
        case(SENSOR_READING_MESSAGE):{return 0;}
        case(RESOURCE_MANAGER_DRAW_POWER):{return 0;}
        case(PHYSICAL_PROCESS_SAMPLING):{return 0;}
        case(WC_SIGNAL_START):{return 0;}
        case(WC_SIGNAL_END):{return 0;}
        case(WC_NODE_MOVEMENT):{return 0;}
        case(RADIO_CONTROL_MESSAGE):{return 20;}
        case(RADIO_CONTROL_COMMAND):{return 20;}
        case(RADIO_ENTER_STATE):{return 20;}
        case(RADIO_CONTINUE_TX):{return 20;}
        case(MAC_LAYER_PACKET):{return 30;}
        case(MAC_CONTROL_MESSAGE):{return 30;}
        case(MAC_CONTROL_COMMAND):{return 30;}
        case(NETWORK_LAYER_PACKET):{return 40;}
        case(NETWORK_CONTROL_MESSAGE):{return 40;}
        case(NETWORK_CONTROL_COMMAND):{return 40;}
        case(APPLICATION_PACKET):{return 50;}
        default:{opp_error("Cannot recognize the packet kind");}
    }
}

void setFilteredRecursively(cMessage* packet, const int value) {

	int field_index;

	cMessage* temp_packet;
	cClassDescriptor *descriptor; // Generic class descriptor

	temp_packet = packet;

	/* Set the packet at filters at each one of its parts */
	while(temp_packet->getKind() <= APPLICATION_PACKET) {
	
		// Retrieve the packet descriptor
		descriptor = cClassDescriptor::getDescriptorFor(temp_packet);
		field_index = descriptor->findField(temp_packet, "filtered");

		// Set the packet as filtered
		if(value)
			descriptor->setFieldAsString(temp_packet, field_index, 0, "1");
		else
			descriptor->setFieldAsString(temp_packet, field_index, 0, "0");

		// Rretrieve the encapsulated packet
		temp_packet = ((cPacket*)temp_packet)->getEncapsulatedPacket();

		/* If 'temp_packet' is NULL we are done */
		if(temp_packet == NULL)
			break;
	
	}

	return;
	
}


void setCompromisedRecursively(cMessage* packet) {

	int field_index;

	cMessage* temp_packet;
	cClassDescriptor *descriptor; // Generic class descriptor

	temp_packet = packet;

	/* Set the packet at filters at each one of its parts */
	while(temp_packet->getKind() <= APPLICATION_PACKET) {
	
		// Retrieve the packet descriptor
		descriptor = cClassDescriptor::getDescriptorFor(temp_packet);
		field_index = descriptor->findField(temp_packet, "compromised");

		// Set the flag
		descriptor->setFieldAsString(temp_packet, field_index, 0, "1");

		// Retrieve the encapsulated packet
		temp_packet = ((cPacket*)temp_packet)->getEncapsulatedPacket();

		/* If 'temp_packet' is NULL we are done */
		if(temp_packet == NULL)
			break;
	
	}

	return;
	
}


int highestPacketLayer(cMessage* packet) {

	cPacket* temp_packet;
	int packetLayer;

	temp_packet = (cPacket*)packet;

	while( temp_packet != NULL) {
		packetLayer = temp_packet->getKind();

		// Retrieve the encapsulated packet
		temp_packet = temp_packet->getEncapsulatedPacket();
	
	}

	return packetLayer;
	
}


/*
	The cPacket::dup() method copy only the outer packet , instead for the inner packets use 
	 a reference counter mechanisms. We need a copy of the packet and his encapsulated packet.

	NOTE: the cPacket::decapsulate() method return a copy of the encapsulated packet 
	and clean the pointer to the encapsulated packet from the outer packet and others information like the length. 
	In this way it's simple to make a correct encapsulate action.

	A.P.
*/
cPacket* hardCopy(cPacket* packet){

	cPacket* macPacket = NULL;
	cPacket* netPacket = NULL;
	cPacket* appPacket = NULL;

	if( packet == NULL )
		return NULL;

	switch( packet->getKind() ){

		case MAC_LAYER_PACKET :

				// make a copy of the packet (the outer)
				macPacket = packet->dup();
				
				// create a copy of the network packet (if exist) and clean others information like the length 
				netPacket = macPacket->decapsulate();

				// this mac Packet hasn't an encapsulated packet
				if( netPacket == NULL )
						return macPacket;

		case NETWORK_LAYER_PACKET : 

				// if is it null means that the outer packet is a network packet 
				if( netPacket == NULL)
					netPacket = packet->dup();

				// create a copy of the application packet (if exist) and clean others information like the length 
				appPacket = netPacket->decapsulate();

				/* encapsulate the application packet in the network packet. 
				   The encapsulate() method update correctly the length of the network packet.
				*/
				if( appPacket != NULL )
					netPacket->encapsulate(appPacket);

				break;

		case APPLICATION_PACKET :
				// The application packet hasn't an encapsulated packet so simply return the copy
				return packet->dup();


	}

	/* if we're here means that we've a network packet (with encapsulated packet or not )
	   but we must check if there is some mac packet to be completed encapsulating the network packet.
	   Otherwise we return the network packet.
	*/

	if( macPacket == NULL )
		return netPacket;

	macPacket->encapsulate(netPacket);

	return macPacket;

}
