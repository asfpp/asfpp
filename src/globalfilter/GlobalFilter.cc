#include "GlobalFilter.h"

Define_Module(GlobalFilter);

GlobalFilter::GlobalFilter() {
  
  /* Attack evaluation is disabled by default */
  attacksEvaluation = false;

}

GlobalFilter::~GlobalFilter(){

	applicationName.clear();
	routingProtocolName.clear();
	macProtocolName.clear();
	unconditionalAttacks.clear();

}

void GlobalFilter::attackInit() {
	
	/* Retrieve the XML file name */
	string configurationFile = ( getParentModule() -> par("configurationFile")).stringValue();

	/* There is no attack configuration file */
	if(configurationFile == "none")
		return;

	Parser parser( configurationFile, applicationName, routingProtocolName, macProtocolName );

	/* Parse the attack configuration file, and fill the unconditionalAttacks vector */
	parser.parse("Unconditional", unconditionalAttacks);

	/* Schedule self messages in order to trigger the execution of uncondition attacks.
	 * Each message name is the index of the attack in the unconditionalAttacks vector.
	 */
	for(int i = 0; i < unconditionalAttacks.size(); i++) {

	  	string index = itos(i);
		
		cMessage* message = new cMessage(index.c_str(), UNCONDITIONAL_ATTACK);
		scheduleAt(unconditionalAttacks[i]->getTime(), message);
	}

}

void GlobalFilter::initialize() {
	
	/* Retrieve protocol names and the application name */
	macProtocolName = (par("macProtocolName")).stringValue();
	routingProtocolName = (par("routingProtocolName")).stringValue();
	applicationName = (par("applicationName")).stringValue();

	/* Initialize data structures related to uncondition attacks */
	attackInit();

}

void GlobalFilter::handleMessage(cMessage* msg) {

	int msgKind;

	msgKind = msg->getKind();

	/* This is a self (internal) message */
	if (msg->isSelfMessage()) {
	
		switch( msgKind ) {

			case UNCONDITIONAL_ATTACK : { // An unconditional attack timer is elapsed

				int attack_index;
				double new_time;  // Next time the attack will be performed (current time + attack frequency)

				UnconditionalAttack* attack = NULL;
				
				/* List of messages created during the attack and aimed to be sent through a PUT action */
				vector<cMessage*> new_messages;

				/* Retrieve the attack index from the message */
				attack_index = atoi( msg->getName() );

				attack = (UnconditionalAttack *)( unconditionalAttacks[attack_index]->getAttack() );

				/* Execute the unconditional attack. The function Uncoditional::execute()
				 * fills the 'new_messages' vector with PUT_MSG messages to be sent afterwards
				 */
				attack->execute(new_messages);

				/* Deliver PUT_MSG messages to the intended recipient nodes */
				for(int i=0; i < new_messages.size(); i++)
					handlePutMessage( new_messages[i] );
				
				/* if the frequency is 0 means that this attack can
				   be executed just once time.
				   Otherwise set the new time to re-schedule the attack.
				*/
				if( attack->getFrequency() == 0)
					break;

				/* Compute the next time the attack will be performed */
				new_time = attack->getFrequency() + simTime().dbl();

				/* Schedule next occurrance of the attack. Each message name is the index of the attack in the unconditionalAttacks vector. */
				cMessage* message = new cMessage( msg->getName(), UNCONDITIONAL_ATTACK);
				scheduleAt( new_time, message );

				break; 
			}
		}

	} 
	
	else { // It is a message from another network node

		switch( msgKind ) {

			/* PUT_MSG is the only possible external message type */
			case PUT_MSG: {
			  
				handlePutMessage(msg);
				break;
			}

		} /* END SWITCH */

	} /* END ELSE STATEMENT */

	/* Delete the internal message or the PUT_MSG message. 
	In the latter case, the packet stored inside it will be deleted by the PutMessage destructor. */
	delete msg;

}

void GlobalFilter::finishSpecific() {
	
	cout<<"finishSpecific\n";
  
}

/**
 * This message encapsulates a Put_MSG message, into different Put_REQ messages,
 * in order to deliver them to the recipient nodes specified in the Put_MSG message.
 *
 * @param msg , the Put_MSG to be encapsulated into a number of Put_REQ messages
 *
 */
void GlobalFilter::handlePutMessage(const cMessage* msg){

	cMessage* packet = NULL;
	cMessage* enc_pkt = NULL;
	PutMessage * putMsg = (PutMessage*)(msg);
	vector<int> nodes;
	string direction;
	double delay;
	bool stats;

	/* Retrieve the list of recipient nodes */
	nodes = putMsg->getNodeVector();
	
	/* Retrieve other PUT parameters */
	direction = putMsg->getDirection();
	stats = putMsg->getStats();	
	delay = putMsg->getDelay();		

	/* Create a copy of Put_MSG message to be sent */
	enc_pkt = putMsg->getPacket();

	/* For each recipient node, create a Put_REQ message, including the copy of the original Put_MSG message */
	for(int i = 0; i < nodes.size(); i++ ){

		/* This message as well as the encapsulated packet will be deleted by the LocalFilter of each recipient node */
		PutRequest* request = new PutRequest(enc_pkt, direction, stats);

		/* Send the Put_REQ message with the specified delivery delay*/
		sendDelayed(request, delay,"toNode", nodes[i]);

	}

}
