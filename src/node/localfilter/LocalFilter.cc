#include "LocalFilter.h"
#include "DestroyRequest_m.h"
#include "EntryWrapper.h"
#include "RoomMonitoringPacket_m.h"
#include <time.h>
#include <omnetpp.h>


Define_Module(LocalFilter);

// TODO check
bool entrySort(Entry* a, Entry* b) {

	return (a->getTime()).dbl() < (b->getTime()).dbl();
	
}



// TODO check
void LocalFilter::initialize() {

    // initialize false attack index ?
	falseAttackIndex = 0;
    // node is not disabled
    isDisabled = false;
    // init radio stats
    radioStats.deltaTime = 0.0;
    radioStats.dataRate = 0.0;
    radioStats.rxPower = 0.0;
    // init injected bytes
    injectedBytes = 0;
    
    // initialize sender gates to avoid in case of node disabling
	initializeSenderGatesToAvoid();
	
    // couple arrival and sender gates
	coupleGates();




	attacksEvaluation = getParentModule() -> getParentModule() -> par("attacksEvaluation");

	/* Retrieve protocol names for each layer */
	macProtocolName = ((getParentModule()->getSubmodule("Communication"))->par("MACProtocolName")).stringValue();
	routingProtocolName = ((getParentModule()->getSubmodule("Communication"))->par("RoutingProtocolName")).stringValue();
	
    applicationName = (getParentModule() -> par("ApplicationName")).stringValue();

	nodeID = getParentModule() -> getIndex();

	/* Fill the attack's vectors, if possibile */
	attackInit(nodeID);

	/* Retrieve a pointer to the Radio module */
	radioModule = check_and_cast <Radio*> ((getParentModule()->getSubmodule("Communication"))->getSubmodule("Radio"));
	resourceModule = check_and_cast <ResourceManager*>(getParentModule()->getSubmodule("ResourceManager"));

	/* Retrieve the size of net and mac header */
	mac_header = check_and_cast <VirtualMac*>((getParentModule()->getSubmodule("Communication"))->getSubmodule("MAC"))->getHeaderSize();
	net_header = check_and_cast <VirtualRouting*>((getParentModule()->getSubmodule("Communication"))->getSubmodule("Routing"))->getHeaderSize();

}


void LocalFilter::initializeSenderGatesToAvoid()
{
    // sender gates to avoid if the node is disabled
    senderGatesToAvoid.push_back("application_routing_inf$o");
    senderGatesToAvoid.push_back("routing_mac_inf$o");
    senderGatesToAvoid.push_back("routing_mac_sup$o");
    senderGatesToAvoid.push_back("mac_radio_inf$o");
    senderGatesToAvoid.push_back("mac_radio_sup$o");
    senderGatesToAvoid.push_back("radio_wirelesschannel_sup$o");
    senderGatesToAvoid.push_back("resourcemanager_routing$o");
    senderGatesToAvoid.push_back("resourcemanager_mac$o");
    senderGatesToAvoid.push_back("resourcemanager_radio$o");
}


// TODO check
void LocalFilter::coupleGates() {

	int gateID;
	string gateName;
	cGate* arrivalGate;
	string inputGateName, outputGateName;
	list<string>::iterator it1, it2;
	list<string> arrivalGatesList; 		// Names of the arrival gates from Routing/MAC/Radio modules
	list<string> senderGatesList; 		// Names of the sender gates to Routing/MAC/Radio modules
	
	trace() << "LocalFilter::initialize() started";
	
    arrivalGatesList.push_back("sensormanager_application_sup$i");
    arrivalGatesList.push_back("sensormanager_application_inf$i");
    arrivalGatesList.push_back("application_routing_sup$i");
    arrivalGatesList.push_back("application_routing_inf$i");
    arrivalGatesList.push_back("routing_mac_sup$i");
    arrivalGatesList.push_back("routing_mac_inf$i");
    arrivalGatesList.push_back("mac_radio_sup$i");
    arrivalGatesList.push_back("mac_radio_inf$i");
    arrivalGatesList.push_back("radio_wirelesschannel_sup$i");
    arrivalGatesList.push_back("radio_wirelesschannel_inf$i");
    arrivalGatesList.push_back("resourcemanager_sensormanager$i");
    arrivalGatesList.push_back("resourcemanager_application$i");
    arrivalGatesList.push_back("resourcemanager_routing$i");
    arrivalGatesList.push_back("resourcemanager_mac$i");
    arrivalGatesList.push_back("resourcemanager_radio$i");
    
    senderGatesList.push_back("sensormanager_application_inf$o");
    senderGatesList.push_back("sensormanager_application_sup$o");
    senderGatesList.push_back("application_routing_inf$o");
    senderGatesList.push_back("application_routing_sup$o");
    senderGatesList.push_back("routing_mac_inf$o");
    senderGatesList.push_back("routing_mac_sup$o");
    senderGatesList.push_back("mac_radio_inf$o");
    senderGatesList.push_back("mac_radio_sup$o");
    senderGatesList.push_back("radio_wirelesschannel_inf$o");
    senderGatesList.push_back("radio_wirelesschannel_sup$o");    
    senderGatesList.push_back("resourcemanager_sensormanager$o");
    senderGatesList.push_back("resourcemanager_application$o");
    senderGatesList.push_back("resourcemanager_routing$o");
    senderGatesList.push_back("resourcemanager_mac$o");
    senderGatesList.push_back("resourcemanager_radio$o");

	it1 = arrivalGatesList.begin();
	it2 = senderGatesList.begin();
	
	while (it1 != arrivalGatesList.end()) {
	  inputGateName = *it1;
	  outputGateName = *it2;
	  arrivalGate = gate(inputGateName.c_str());
	  gateID = arrivalGate -> getId();
	  arrivalGatesMap.insert(pair<int,string> (gateID, inputGateName));
	  gatesLinksMap.insert(pair<string,string> (inputGateName, outputGateName));
	  it1++;
	  it2++;
	}

}


// TODO check
// TODO rename in 'initializeAttacks'
void LocalFilter::attackInit(int nodeID) {
	
	VirtualMobilityManager* mobilityModule;
	SensorManager* sensorModule;

	sensorModule = check_and_cast <SensorManager*>(getParentModule()->getSubmodule("SensorManager"));
	mobilityModule = check_and_cast <VirtualMobilityManager*> (getParentModule() -> getSubmodule("MobilityManager"));

	/* Retrieve the XML file name from the .ini file */
	string configurationFile = (getParentModule() -> getParentModule() -> par("configurationFile")).stringValue();

	trace() << "-> XML : "<< configurationFile;
	
	/* There is no configuration attack file */
	if(configurationFile == "none")
		return;

    cModule* targetNode = getParentModule();

	Parser parser(targetNode, configurationFile, applicationName, routingProtocolName, macProtocolName, nodeID, sensorModule, mobilityModule );

	/* Fill the physicalAttacks vector */
	parser.parse("Physical", physicalAttacks);

	/* Fill the condictionalAttacks vector*/
	parser.parse("Conditional", logicalAttacks);
	
	/* Sort physical attacks and logical attacks according to their starting time */
	if( physicalAttacks.size() > 0 )
		sort(physicalAttacks.begin(), physicalAttacks.end(), entrySort);

	if( logicalAttacks.size() > 0 )
		sort(logicalAttacks.begin(), logicalAttacks.end(), entrySort);

	// schedule self messages according to the occurrence time and attach to it the physical attacks, except destroy attack
    for (int i=0; i<physicalAttacks.size(); i++) {
    
        // get the attack
        Attack* attack = physicalAttacks[i]->getAttack();
        
        // recognize the physical action 'destroy' (physical attacks consists of a single physical action)
        Action* action = attack->getAction(0);
        
        if (action->getName() == DESTROY) {
            // build an EntryWrapper for the current physical attack (i.e. the action destroy)
            EntryWrapper entryWrapper = EntryWrapper(physicalAttacks[i]);
            // send a destroyRequest to the global-filter
            DestroyRequest* destroyRequest = new DestroyRequest("DestroyRequest");
            destroyRequest->setEntryWrapper(entryWrapper);
            send(destroyRequest, "toGlobalFilter");
            
            // adjust vector of physical attacks and index
            physicalAttacks.erase(physicalAttacks.begin()+i);
            i--;
            
        }
        
        // schedule other physical actions: disable, move, fakeread
        else {
            cMessage* message = new cMessage("Start physical attack", PHYSICAL_ATTACK);
            scheduleAt(physicalAttacks[i]->getTime(), message);
        }
    }
    
    

	/* Set timers of logical attacks */
	for(int i = 0; i < logicalAttacks.size(); i++) {
	  	
		cMessage* message = new cMessage("Start logical attack", LOGICAL_ATTACK);
		scheduleAt(logicalAttacks[i]->getTime(), message);

		/* Add an entry in the activeLogicattack and set it as false (not active yet) */
		activeLogicAttack.push_back(false);

	}


}


// TODO check
void LocalFilter::handleMessage(cMessage* msg)
{
	int msgKind;
	cGate* arrivalGate;
	int arrivalGateID;
	string arrivalGateName, senderGateName;
	double forwarding_delay = 0.0; // This delay affects only intercepted packets
	int packet_size = 0;

	msgKind = (int)msg->getKind();


	// handle self message
	if (msg->isSelfMessage()) {

		// handle attacks
		switch(msgKind) {

            // enable or execute physical attacks
			case PHYSICAL_ATTACK: {
				trace()<<"-> Enable/execute physical attack";
                // the attack to be performed or enabled is in the first position
				PhysicalAttack* attack = (PhysicalAttack*)(physicalAttacks[0]->getAttack());
                // physical attacks are made by one node action
                Action* action = ((Attack*)attack)->getAction(0);
                ActionName actionName = action->getName();
                switch (actionName) {
                    case FAKEREAD: {
                        // enable the actual fakeread action
                        enabledFakereads.push_back((Fakeread*)action);
                        break;
                    }
                    default: {
                        attack->execute();
                    }
                }
                // remove the entry
				physicalAttacks.erase(physicalAttacks.begin());
				break;
            }

            // enable conditional attacks
			case LOGICAL_ATTACK: {
                trace()<<"-> Enable logical attack";
                // enable the logical attack
                activeLogicAttack[falseAttackIndex] = true;
                // move to the next attack to enable
                falseAttackIndex++;
                break;
            }
            
            default: {
                opp_error("[void LocalFilter::handleMessage(cMessage*)] Error, kind of self-message not recognized");
            }
			
		}

		delete msg;
		return;	

	}

	/* Retrieve information about packet source and destination */
	arrivalGate = msg->getArrivalGate();
	arrivalGateID = arrivalGate -> getId();
	arrivalGateName = arrivalGate -> getFullName();

    // handle enabled fakeread actions
    if (arrivalGateName == "sensormanager_application_sup$i") {
        for (size_t i = 0; i < enabledFakereads.size(); i++) {
            enabledFakereads[i]->execute(msg);
        }
        send(msg, "sensormanager_application_inf$o");
        return;
    }


	/* Message received from the Global Filter */
	if (!arrivalGateName.compare("fromGlobalFilter")) {
		
		trace()<<"-> PUT_REQ from the GlobalFilter";

		switch(msgKind) {
		  
			/* Put Request message */
			case PUT_REQ: {
			  
				PutRequest* request = NULL;
				cMessage* packet = NULL;	
				string direction = "";
				int msgKind;
				bool stats = false;

				request = (PutRequest*)(msg);

				/* Make a copy of the packet carried by the Put Request message */
				packet = hardCopy( (cPacket*)(request->getPacket()) );

				/* Retrieve information about the packet to be delivered */
				direction = request->getDirection();
				stats = request->getStats();
				msgKind = packet->getKind();
				
				/* DEBUG INFO */
				cClassDescriptor *descriptor; // general class descriptor
				int ind;
				descriptor = cClassDescriptor::getDescriptorFor(packet);
				ind = descriptor->findField(packet, "filtered");

				//trace()<<" Filtered : "<<descriptor->getFieldAsString(packet, ind, 0);

				trace()<<"-> I've received a PUT REQUEST message, direction "<<direction;

				/* Determine the gate where the packet must be sent to */
				
				/* Application packets are sent to the network layer.
				 * Packets of different kinds are sent to the MAC layer.
				 */
				if(direction == "TX") {
						
						if(msgKind == APPLICATION_PACKET) {
						  
							trace()<<"-> send the packet to gate toRoutingFromCommunication";
							if (isDisabled == false) { 
                                send(packet,"application_routing_inf$o");
							}
                            else {
                                delete packet;
                            }
						}
						
						else {
						  
							trace()<<"-> send the packet to gate toMacFromRouting";
							if (isDisabled == false) {
                                send(packet, "routing_mac_inf$o");
							}
                            else {
                                delete packet;
                            }
						}
						
				}
				
				/* Direction is RX. Application packets are sent to the application layer.
				 * Packets of different kinds are sent to the MAC layer.
				 * Here we store the bytes received in order to compute the extra energy
				 * consumption. Obviously we must considerate a complete packet so if
				 * we receive an application packet we must considerate even NET and MAC
				 * header. This bytes are considerate only if the throughtWC in PUT is true.
				 */
				else {
					
					if( msgKind == APPLICATION_PACKET) {
					  
						packet_size = ((cPacket*)packet)->getByteLength();			
						packet_size += net_header + mac_header;
						send(packet,"application_routing_sup$o");
						
					}
					
					else if(msgKind == NETWORK_LAYER_PACKET) {
					  
						packet_size = ((cPacket*)packet)->getByteLength();
						packet_size += mac_header;
						if (isDisabled == false) {
                            send(packet, "routing_mac_sup$o");
						}
                        else {
                            delete packet;
                        }
					}
					
					else {
					  
						packet_size = ((cPacket*)packet)->getByteLength();
						
                        if (isDisabled == false) {
                            send(packet, "mac_radio_sup$o");
						}
                        else {
                            delete packet;
                        }
					}
					
				}

				/* Update node statistics.
				 * Store the injected bytes for, extra, energy consuption reason.
				*/
				if(stats) {

					/* packet_size is initialized as 0 so if we have stat ON and
					 * TX direction injected bytes still remain the same, avoiding
					 * direction control ( if(RX) injectedBytes += .... ; ).					
					*/
					injectedBytes += packet_size;

					/* Update statistics at the Radio Layer */

					/* TODO provide statistics update at the Network and MAC layers as well (it is strongly layer dependent) */

					trace()<< "-> UPDATE THE RADIO STATS";
					radioModule->forceUpdateStatsWrapper();
					
				}
				
				break;
				
			}
			
		}

		/* Delete the PutRequest message. This will automatically destroy the received copy of the packet */
		delete msg;
		return;
		
	} // end of message received from GlobalFilter

	/* Conditional Attack */
	if(activeLogicAttack.size() != 0) {

		if( (activeLogicAttack[0] == true) && ( 0 < logicalAttacks.size()) ) {

			/* Perform all active logical attacks */
			for(int i = 0; (activeLogicAttack[i] == true) && (i < logicalAttacks.size()); i++ ) {

				ConditionalAttack *logic_attack;
				
				vector<cMessage*> new_messages;
				vector<double> delays;
				new_messages.clear();
				delays.clear();
				

				// we are interested only in Application, Network or MAC Packet 
				if(msgKind == APPLICATION_PACKET || msgKind == NETWORK_LAYER_PACKET || msgKind == MAC_LAYER_PACKET ){

					if(testAndSet(msg) == TRUE){

						// return the highest packet layer contained in this packet
						int packetLayer = highestPacketLayer(msg);
	
						/* Request the Logger module to log the drop event */
						string logInfo;
						switch(packetLayer) {
							case APPLICATION_PACKET:
								logInfo.assign("APPLICATION_PACKET");
								break;
							case NETWORK_LAYER_PACKET:
								logInfo.assign("NETWORK_LAYER_PACKET");
								break;
							case MAC_LAYER_PACKET:
								logInfo.assign("MAC_LAYER_PACKET");
								break;
						}
						  
						LoggerMessage* logReq = new LoggerMessage(COMPROMISED_PACKET, nodeID, logInfo);
						logReq -> setKind(LOGGER_MESSAGE);
						logReq -> setTimestamp(simTime().dbl());
						send(logReq, "toLogger");
					}

				}

				logic_attack = (ConditionalAttack *)(logicalAttacks[i]->getAttack());

				/* Check whether the intercepted packet match with the packet filter */
				if(logic_attack->matchFilter(msg)) {
				  
					/* Positive match: the attack is executed */

					trace()<<"-> Filter Matched";

					new_messages.clear();
					delays.clear();

					logic_attack->execute(&msg, new_messages, delays, forwarding_delay);	

					/* The packet has not been dropped during the attack */
					if(msg != NULL) {

					  /* Retrieve the output gate */
					  senderGateName.assign(gatesLinksMap[arrivalGateName]);

					  /* Send the packet to the right gate, i.e. it continues its original path through the stack */
					  sendDelayed(msg,  forwarding_delay, senderGateName.c_str());		
		  
					}

					if(msg == NULL) {
					  
					  trace()<<"-> Packet dropped";
					  
					  string logInfo;
					  switch(msgKind) {
					    case APPLICATION_PACKET:
					      logInfo.assign("APPLICATION_PACKET");
					      break;
					    case NETWORK_LAYER_PACKET:
					      logInfo.assign("NETWORK_LAYER_PACKET");
					      break;
					    case MAC_LAYER_PACKET:
					      logInfo.assign("MAC_LAYER_PACKET");
					      break;
					  }
					  
					  	LoggerMessage* logReq = new LoggerMessage(PACKET_DROP, nodeID, logInfo);
					  	logReq -> setKind(LOGGER_MESSAGE);
					  	logReq -> setTimestamp(simTime().dbl());
					  	send(logReq, "toLogger");
					  
					}

					/* Send packets created during the attacks */
					if(new_messages.size() != 0) {
					  for(int i=0 ; i< new_messages.size(); i++) {

						/* The new packet has been destroyed after being created */
						if(new_messages[i] == NULL) {
						  
						  trace()<<"-> the new message was deleted by drop action, thus IGNORE it";
						  continue;

						}

						trace()<<" -> The new message is "<<new_messages[i];
							  
						switch(new_messages[i]->getKind()) {

						  /* It is a Put_MSG message to the Global Filter */
						  case PUT_MSG: {			    
						  
						    //trace()<<"-> Send "<<new_messages[i];
					    
						    /* The GlobalFilter will send it to the intended recipient nodes */
						    send(new_messages[i], "toGlobalFilter");
						    break;
						  
						  }
						
						  /* A "real" packet aimed to be sent to the right layer of the communication stack */
						  default:{

						    trace()<<" -> Clone/Create Packet";

						    cClassDescriptor* descriptor; 
						    int field_int, packetKind;
						    string sended; 
						    descriptor = cClassDescriptor::getDescriptorFor(new_messages[i]);

						    /* Check if the packet actually has to be sent */
						    field_int = descriptor->findField(new_messages[i], "sended");
						    
						    if( field_int == -1 ) {
						      
							string error_message = "This packet hasn't a field called sended";
							opp_error(error_message.c_str());

						    }

						    sended = descriptor->getFieldAsString(new_messages[i], field_int, 0);

						    /* This packet must not be sent */
						    if( sended == "0") {
						      
							trace()<<" -> someone has forgotten to send the new packet";
							continue;
							
						    }

						    /* The packet is sent to the layer below the current one */

						    /* Set the field 'sended' to 0 */
						    descriptor->setFieldAsString(new_messages[i], field_int, 0, "0");

						    /* Packets are directly sent to the lower layer, without being stored
						     * in any transmission buffer. This is consistent with the assumption
						     * according to which every attack is always successfully performed.
						     */
						    switch(new_messages[i]->getKind()) {

							/* Application packets are sent to the routing layer */
							case APPLICATION_PACKET:{

								trace()<<" -> send to application_routing_inf$o";
								//sendDelayed(new_messages[i], delays[i], "toRoutingFromCommunication");
								if (isDisabled == false) {
                                    sendDelayed(new_messages[i], delays[i], "application_routing_inf$o");
                                }
                                else {
                                    delete new_messages[i];
                                }
                                break;

							}

							/* Routing packets are sento to the MAC layer */
							case NETWORK_LAYER_PACKET:{
							  
								trace()<<" -> send to routing_mac_inf$o";
								//sendDelayed(new_messages[i], delays[i], "toMacFromRouting");
                                if (isDisabled == false) {
                                    sendDelayed(new_messages[i], delays[i], "routing_mac_inf$o");
								}
                                else {
                                    delete new_messages[i];
                                }
                                break;
								
							}
							
							/* MAC packets are sent to the radio layer */
							case MAC_LAYER_PACKET:{
							  
								trace()<<" -> send to mac_radio_inf$o";
								
                                if (isDisabled == false) {
                                    sendDelayed(new_messages[i], delays[i], "mac_radio_inf$o");
                                }
                                else {
                                    delete new_messages[i];
                                }
                                
                                break;
								
							}

						    } // END switch(new_messages[i]->getKind())	

						  } // END default case
								
						}// END SWITCH

					  }// END FOR

				        }// END if new_messages.size()
			
					/* The packet has been set as filtered. Thus, it will not be further processed by this node */
					return;

				} // END IF logic_attack->matchFilter(msg)

			} // END FOR
		
		} //END IF

	}// END IF
	
    // check if the communication module exists 
    senderGateName.assign(gatesLinksMap[arrivalGateName]);
    if (isDisabled == true) {
        for (size_t i = 0; i < senderGatesToAvoid.size(); i++) {
            if (senderGateName == senderGatesToAvoid[i]) {
                delete msg;
                return;
            }
        }
    }
    send(msg, senderGateName.c_str());
}





bool LocalFilter::testAndSet(cMessage* packet){

	cClassDescriptor *descriptor; 	// General class descriptor
	int field_index;

	// Check if the packet has the flag out_of_reality setted
	descriptor = cClassDescriptor::getDescriptorFor(packet);
	field_index = descriptor->findField(packet, "compromised");

	// out_of_reality == 1 stop the procedure
	if( atoi( descriptor->getFieldAsString(packet, field_index, 0).c_str() ) == 1 )
		return FALSE;

	// set the flag in every packet layer
	setCompromisedRecursively(packet);

	return TRUE;
}



void LocalFilter::finishSpecific()
{
    // if node is not disabled get radio stats, else they have been already collected
    if (isDisabled == false) {
        getRadioStats();
    }
    
    // retrieve the resource module
    ResourceManager* resource = check_and_cast<ResourceManager*>(getParentModule()->getSubmodule("ResourceManager"));
    if (resource == nullptr) {
        opp_error("[void LocalFilter::finishSpecific()] Error, ResourceManager not found");
    }
    
    // compute the energy consumption
    double energyConsumption = resource->getSpentEnergy();
    // add the extra consumption due to radio's RX mode (during injections)
    double injectionTime = ((double)injectedBytes)/(radioStats.dataRate/8.0);
    if (injectionTime > radioStats.deltaTime) {
        energyConsumption += (injectionTime - radioStats.deltaTime) * radioStats.rxPower;
    }
    
    // collect output by using Castalia's primitives
    declareOutput("Energy consumption");
    collectOutput("Energy consumption", "mJ", energyConsumption);
}


RadioStats_type LocalFilter::getRadioStats()
{
    // retrieve the communication module
    cModule* communication = getParentModule()->getSubmodule("Communication");
    if (communication == nullptr) {
        opp_error("[RadioStats_type LocalFilter::getRadioStats()] Error, node's Communication module not found");
    }
    
    // retrieve the radio module
    Radio* radio = check_and_cast<Radio*>(communication->getSubmodule("Radio"));
    if (radio == nullptr) {
        opp_error("[RadioStats_type LocalFilter::getRadioStats()] Error, node's Radio module not found");
    }
    
    RadioStats_type retrievedRadioStats;
    retrievedRadioStats.deltaTime = radio->getDeltaTimeWrapper();
    retrievedRadioStats.dataRate = radio->getDataRateWrapper();
    retrievedRadioStats.rxPower = radio->getRxPowerWrapper();
    
    return retrievedRadioStats;
}


LocalFilter::LocalFilter()
{
}

// TODO check
LocalFilter::~LocalFilter() {

    // delete enabled fakeread actions
    for (size_t i = 0; i < enabledFakereads.size(); i++) {
        delete enabledFakereads[i];
    }
    
    // delete entries and relative physicalattacks
    //for (size_t i = 0; i < physicalAttacks.size(); i++) {
    //    delete physicalAttacks[i]->getAttack();
    //   delete physicalAttacks[i];
    //}
    
    // delete entries and relative physicalattacks
    //for (size_t i = 0; i < logicalAttacks.size(); i++) {
    //    delete logicalAttacks[i]->getAttack();
    //    delete logicalAttacks[i];
    //}
 
}




