#include "UnconditionalAttack.h"
#include "RoutingPacket_m.h"
#include "ASFExpression.h"


/*  <A.P.> This function performs the unconditional attack, by sequentially invoking the actions composing it.
 *  The vector 'put_messages' contains pointers to the PUT_MESSAGE messages created during the attack performance.
 *  Every message created during the attack will be either delivered through a PUT action, or deleted.
*/

void UnconditionalAttack::execute(vector<cMessage*> &put_messages){

	/* The key of the 'packetTable' map is the packet name, while the value is the position of such a packet within the 'new_messages' vector */
	map<string,int>  packetTable;

	/* It contains all packets created or cloned during the attack */
	vector<cMessage*> new_messages;

	/* New packet created during the attack */
	cMessage* new_pkt = NULL;

	/* New packet created during the attack */
	cPacket* packetCreated = NULL;
	
	/* Actual packet on which a single action is executed */
	cMessage** workOn = NULL;

	/* Name of the packet considered by the current action */
	string packet_name;

	/* Position of the packet in the vector 'new_messages' */
	int position;
	
	int field_index;

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

				/* Retrieve the value to be written */
				what = change->getValue();

				/* Process an already existing packet */
				workOn = &new_messages[position];

				/* Compute a random value */
				if(what == "RANDOM") {
					double fake_value, max , min;
		
					max = double(*(varTable["MAX"]));
					min = double(*(varTable["MIN"]));

					fake_value = min +  ( dblrand() * (max - min) );

					new_value = dtos(fake_value);

				} else{
					// retrieve the value from a stored variable
					new_value = varTable[what]->getValue();
				}

				change->execute(workOn, new_value);
				
				break;
			}

			case DROP:{
			  
				Drop* drop = (Drop*)actions[i];

				packet_name = drop->getPacketName();
				position = packetTable[packet_name];

				// Process an already existing packet
				workOn = &new_messages[position];

				drop->execute(workOn);
				
				break;
			}

			case PUT:{

				Put* put = (Put*)actions[i];

				packet_name = put->getPacketName();
				position = packetTable[packet_name];

				// Process an already existing packet
				workOn = &new_messages[position];

				new_pkt = put->execute(*workOn);

				/* Add the PutMessage returned by Put::execute() to the vector 'put_messages'.
				 * It will be delivered at the end of the attack
				 */
				put_messages.push_back(new_pkt);
				break;
			}

			case CLONE:{

				Clone* clone = (Clone*)actions[i];

				/* Retrieve the name of the packet to be cloned and the name of the new packet */
				string new_packet_name = clone->getNewPacketName();
				packet_name = clone->getPacketName();
				position = packetTable[packet_name];
				
				// Process an already existing packet
				workOn = &new_messages[position]; 

				clone->execute(&new_pkt, *workOn);

				/* Add the new packet to the vector 'new_messages' */
				new_messages.push_back(((cMessage*)(new_pkt)));

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

				/* Update the 'packetTable' map */
				packetTable[new_packet_name] = new_messages.size() - 1;
				
				break;
								
			}

			case RETRIEVE:{
				
				Variable* new_value;
			  
				Retrieve* retrieve = (Retrieve*)actions[i];

				packet_name = retrieve->getPacketName();
				position = packetTable[packet_name];
				
				// Process an already existing packet
				workOn = &new_messages[position]; 
				new_value = retrieve->execute(*workOn);
	
				// Delete the old value and update the variable table
				delete varTable[retrieve->getVarName()];
				varTable[retrieve->getVarName()] = new_value;

				break;
			}

			case EXPRESSION:{

				ASFExpression* my_expr = (ASFExpression*)actions[i];
				my_expr->execute(&varTable, &varStack);
				break;
			}

			default:{

				opp_error("Unconditional attacks doesn't recognize the action. Check the manual to the compability.");

			}


		}// END SWITCH
 
	}// END FOR

}

/* Add an action to the list of actions that compose the attack */
void UnconditionalAttack::addAction(Action* action) {

	actions.push_back(action);
}
