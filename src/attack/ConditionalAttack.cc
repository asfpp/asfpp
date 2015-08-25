#include "ConditionalAttack.h"
#include "RoutingPacket_m.h"

ConditionalAttack::ConditionalAttack():Attack() {

	minimum_layer = NONE;
}

ConditionalAttack::~ConditionalAttack() {
 
	filter.clear();
  
}

/*  <A.P.> This function performs the conditional attack, by sequentially invoking the actions composing it.
 *  The vector 'new_messages' contains pointers to messages created during the attack performance.
*/

void ConditionalAttack::execute(cMessage **packet, vector<cMessage*> &new_messages, vector<double> &delays, double &forwarding_delay){

	/* The key of the 'packetTable' map is the packet name, while the value is the position of such a packet within the 'new_messages' vector. The value -1 means that the original intercepted packet 'packet' must be considered. */
	map<string,int>  packetTable;

	/* New packet created during the attack */
	cMessage* new_pkt = NULL;

	/* New packet created during the attack */
	cPacket* packetCreated = NULL;
	
	/* Actual packet on which a single action will be executed */
	cMessage** workOn = NULL;

	/* Name of the packet considered by the current action */
	string packet_name;

	/* Position of the packet in the vector 'new_messages' */
	int position;
	
	int field_index;

	/* The intercepted packet has name 'original' in the Attack Confguration file */
	packetTable["original"] = -1;

	/* DEBUG INFO */
	cClassDescriptor *descriptor; // general descriptor class
	int ind;
	descriptor = cClassDescriptor::getDescriptorFor(*packet);
	ind = descriptor->findField(*packet, "filtered");

	cGate* arrivalGate;
	arrivalGate = ((cMessage*)(*packet))->getArrivalGate();
				
	/* The field "filtered" is set on this packet, in order to avoid multiple filtering/processing by the same network node */
	setFilteredRecursively(*packet, true);

	try{

	/* Execute all actions composing the attack */
	for(int i=0; i < actions.size(); i++) {
	 
		new_pkt = NULL;
		packetCreated = NULL;

		switch(actions[i]->getName()) {

			case CHANGE:{
				
				Change* change = (Change *)actions[i];
				string new_value;
				string what;

				packet_name = change->getPacketName();
				position = packetTable[packet_name];



				what = change->getValue();

				if(position == -1)
					workOn = packet; // Process the original intercepted packet
				else
					workOn = &new_messages[position]; // Process an already existing packet

				/* Compute a random value */
				if(what == "RANDOM") {
					double fake_value, max , min;
		
					max = double(*(varTable["MAX"]));
					min = double(*(varTable["MIN"]));

					fake_value = min +  ( dblrand() * (max - min) );

					new_value = dtos(fake_value);

				} else // retrieve the value from a stored variable
					new_value = varTable[what]->getValue();
				
				change->execute(workOn, new_value);
				break;
			}

			case DROP:{
				Drop* drop = (Drop*)actions[i];

				packet_name = drop->getPacketName();
				position = packetTable[packet_name];

				if(position == -1)
					workOn = packet; // Process the original intercepted packet
				else
					workOn = &new_messages[position]; // Process an already existing packet

				drop->execute(workOn);
				
				break;
			}

			case PUT:{

				Put* put = (Put*)actions[i];

				packet_name = put->getPacketName();
				position = packetTable[packet_name];

				if(position == -1)
					workOn = packet; // Process the original intercepted packet
				else
					workOn = &new_messages[position]; // Process an already existing packet

				new_pkt = put->execute(*workOn);

				/* Add the PutMessage returned by Put::execute() to the vector 'new_messages'.
				 * It will be delivered at the end of the attack
				 */
				new_messages.push_back(new_pkt);

				/* Add a delivery delay equal to zero referred to this packet. PutMessage messages already include a delay field.
				 * Still, it is necessary to do this, according to the packet delivering scheme adopted at the end of the attack */
				delays.push_back(0.0);

				break;
			}

			case CLONE:{

				Clone* clone = (Clone*)actions[i];

				/* Retrieve the name of the packet to clone and the name of the new packet */
				string new_packet_name = clone->getNewPacketName();
				packet_name = clone->getPacketName();
				position = packetTable[packet_name];

				if(position == -1)
					workOn = packet; // Process the original intercepted packet
				else
					workOn = &new_messages[position]; // Process an already existing packet

				clone->execute(&new_pkt, *workOn);

				/* Add the new packet to the vector 'new_messages' */
				new_messages.push_back(((cMessage*)(new_pkt)));

				/* Add a delivery delay equal to zero referred to this packet */
				delays.push_back(0.0);

				/* Update the 'packetTable' map */
				packetTable[new_packet_name] = new_messages.size() - 1;
				
				break;
								
			}

			case CREATE:{

				Create* create = (Create*)actions[i];
				
				/* Retrieve the name of the packet to be created */
				string new_packet_name = create->getPacketName();

				create->execute(&packetCreated);

				/* Add the new packet to the vector 'new_messages' */
				new_messages.push_back(packetCreated);

				/* Add a delivery delay equal to zero referred to this packet */
				delays.push_back(0.0);

				/* Update the 'packetTable' map */
				packetTable[new_packet_name] = new_messages.size() - 1;
				
				break;
								
			}

			case RETRIEVE:{
				
				Variable* new_value;
				Retrieve* retrieve = (Retrieve*)actions[i];

				packet_name = retrieve->getPacketName();
				position = packetTable[packet_name];

				if(position == -1)
					workOn = packet; // Process the original intercepted packet
				else
					workOn = &new_messages[position]; // Process an already existing packet

				new_value = retrieve->execute(*workOn);
	
				// Delete the old value and update the variable table
				delete varTable[retrieve->getVarName()];
				varTable[retrieve->getVarName()] = new_value;
				
				break;
			}

			case SEND:{
			  
				Send* my_send = (Send*)actions[i];

				packet_name = my_send->getPacketName();
				position = packetTable[packet_name];

				/* If the packet is the original intercepted one, only the delay has to be retrieved */
				if(position == -1){
					forwarding_delay = my_send->getDelay();
					break;
				}
	
				/* The following regards only packets created by CREATE or CLONE */
				workOn = &new_messages[position];

				my_send->execute(*workOn);

				/* Set the delivery delay for this packet */
				delays[position] = my_send->getDelay();
				
				break;

			}
		
			case EXPRESSION:{

				ASFExpression* my_expr = (ASFExpression*)actions[i];
				my_expr->execute(&varTable, &varStack);

				break;

			}


		}// END SWITCH
 
	}// END FOR

	} catch(const char* error){
		opp_error(error);
	}

}

/* Add an action to the list of actions that compose the attack */
void ConditionalAttack::addAction(Action* action) {

	actions.push_back(action);
	if(minimum_layer > action->getLayer())
		minimum_layer = action->getLayer();

}

/* Return true if the intercepted packet produces a positive match with the attack packet filter. Return false otherwise. */
bool ConditionalAttack::matchFilter(cMessage *packet) const {

	cClassDescriptor *descriptor; 	// General descriptor class
	vector<string> tokens; 		// Vector of entries <packet_field_name,operator,value>
	string layer;
	string field_name;
	string filter_value;
	string field_value;

	vector<string> temp;
	cMessage* temp_packet; 		// Used to retrieve incapulated packets

	int msgKind;
	int field_index;
	
	string logic_operator;		// AND (&&), OR (||)
	string comparison_operator;	// ==, !=, <, >, <=, >=

	string direction;

	cGate* arrivalGate;
	
	/* The gate where the packet has arrived */
	arrivalGate = packet->getArrivalGate();

	/* Direction coincides with the full name of the arrival gate */
	direction = arrivalGate -> getFullName();

	/* Check the arrival gate. Note that the packet filter does not support radio packet */
	if( (direction == "fromCommunicationToRadio") || (direction == "fromRadioToCommunication") ) 
		return false;

	msgKind = packet->getKind();

	/* Only Application, Network and MAC Packet are supported */
	if(msgKind != APPLICATION_PACKET && msgKind != NETWORK_LAYER_PACKET && msgKind != MAC_LAYER_PACKET )
		return false;
	
	/* Check if the packet has been already filtered before */
	descriptor = cClassDescriptor::getDescriptorFor(packet);
	field_index = descriptor->findField(packet, "filtered");
	
	/* The packet has been already filtered, and must not be further processed */
	if( atoi(descriptor->getFieldAsString(packet, field_index, 0).c_str()) == 1 )
		return false;

	/* Not all needed information is available at the current layer. Filtering is postponed to a lower layer */
	if(msgKind > minimum_layer)
		return false;

	/* Split logic operator and conditions */
	tokenize(tokens, filter, ':');

	logic_operator = "||";

	/* Retrieve the logic operator, in case at least two conditions are present */
	if(tokens.size() != 3) {

		// The logic operator is at the end of the filter
		logic_operator = tokens.back();
		
		// Remove the logic operator from the tokens
		tokens.pop_back();

		if(logic_operator == "AND")
			logic_operator = "&&";
		else
			logic_operator = "||";

	}

	/* There are three steps, since each condition is composed by a triplet <field:comparison_operator:value> */
	for(int i = 0; i< tokens.size(); i+=3) {

		temp.clear();

		temp_packet = NULL;	

		/* Parse the 'field' entry, composed by the couple <layer_name.field_name> */
		tokenize(temp, tokens[i], '.');

		layer = temp[0];
		field_name = temp[1];

		/* Retrieve logical operator and value for the current condition */
		comparison_operator = tokens[i+1];
		filter_value = tokens[i+2];
	
		temp_packet = packet;
		msgKind = temp_packet->getKind();
		
		/* Retrieve the encapsulated packet until the right layer is reached */
		while( msgKind < layertoi(layer) ) {

			temp_packet = ((cPacket*)temp_packet)->getEncapsulatedPacket();

			/* The packet cannot be filtered at the current layer */
			if(temp_packet == NULL)
				return false;

			msgKind = temp_packet->getKind();
		}

		/* Retrieve a descriptor for the packet to be filtered */
		descriptor = cClassDescriptor::getDescriptorFor(temp_packet);
	
		bool result = false;

		vector<string> values;
		tokenize(values, filter_value, '|');
		
		/* In order to satisfy the filter, it is sufficient that one value is present */
		for(int j = 0; j < values.size(); j++) {

			field_index = descriptor->findField(temp_packet, field_name.c_str());

			/* This field does not exist in the packet */
			if( field_index == -1)
				return false;
			
			/* Retrieve the field value */
			field_value = descriptor->getFieldAsString(temp_packet, field_index, 0);

			/* Apply the comparison operator to the field value and the filter value
			   Note that field values are converted to integer before being compared */
			if(evaluate(atoi(field_value.c_str()), atoi(values[j].c_str()), comparison_operator) == true) {
				result = true;
				break;
			}	

		}

		/* The conditions are kept together by the same logic operator, i.e. either AND or OR. This simplifies the overall evaluation */
		if(result == false && logic_operator == "&&") 
			return false;	
		
		if(result == true && logic_operator == "||") 
			return true;

	} // END FOR

	/* All conditions are TRUE */
	if( logic_operator == "&&") {
		return true;
	}
	
	/* All conditions are FALSE (the logic operator is OR) */
	else {
		return false;
	}
	
}
