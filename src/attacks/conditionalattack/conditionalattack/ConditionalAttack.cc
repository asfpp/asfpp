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

void ConditionalAttack::addFilter (const std::string f) {
    
    this->filter = f;
    packetFilter = new PacketFilter(f);
    
}


/* Return true if the intercepted packet produces a positive match with the attack packet filter. Return false otherwise. */
bool ConditionalAttack::matchFilter(cMessage* packet) const {

	// check the arrival gate (packet filter does not support radio packets)
    cGate* arrivalGate = packet->getArrivalGate();
    string direction = arrivalGate->getFullName();
    if ( (direction == "fromCommunicationToRadio") || (direction == "fromRadioToCommunication") ) {
        return false;
    }

    // check packet kind (supported layers: 5,3,2)
	int msgKind = packet->getKind();
    if ( msgKind != APPLICATION_PACKET && msgKind != NETWORK_LAYER_PACKET && msgKind != MAC_LAYER_PACKET ) {
        return false;
    }
    
    // do not process packets that has been already filtered before
    cClassDescriptor* descriptor = cClassDescriptor::getDescriptorFor(packet);
    int fieldIndex = descriptor->findField(packet, "filtered");
    string filtered = descriptor->getFieldAsString(packet, fieldIndex, 0);
    if ( atoi(filtered.c_str()) == 1 ) {
        return false;
    }

    return (packetFilter->isMatchingPacketFilter((cPacket*)packet));
   
}
