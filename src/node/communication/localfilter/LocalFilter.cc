#include "LocalFilter.h"

Define_Module(LocalFilter);

/* This function is used by the std::sort to sort the physicalAttacks and logicalAttacks vectors */
bool entrySort(Entry* a, Entry* b) {

	return (a->getTime()).dbl() < (b->getTime()).dbl();
	
}


LocalFilter::LocalFilter() {

    falseAttackIndex = 0;
	
}

LocalFilter::~LocalFilter() {

	physicalAttacks.clear();
	logicalAttacks.clear();
	activeLogicAttack.clear();
	arrivalGatesMap.clear();
	gatesLinksMap.clear();
	applicationName.clear();
	routingProtocolName.clear();
	macProtocolName.clear();

}

/* This function fills arrivalGatesMap and gatesLinksMap in order to connect node gates to the LocalFilter module */
void LocalFilter::initializeGates() {

	int gateID;
	string gateName;
	cGate* arrivalGate;
	string inputGateName, outputGateName;
	list<string>::iterator it1, it2;
	list<string> arrivalGatesList; 		// Names of the arrival gates from Routing/MAC/Radio modules
	list<string> senderGatesList; 		// Names of the sender gates to Routing/MAC/Radio modules
	
	trace() << "LocalFilter::initialize() started";
	
	arrivalGatesList.push_back("fromRoutingToMac");	
	arrivalGatesList.push_back("fromMacToRouting");
	arrivalGatesList.push_back("fromMacToRadio");
	arrivalGatesList.push_back("fromRadioToMac");
	arrivalGatesList.push_back("fromRadioToCommunication");
	arrivalGatesList.push_back("fromCommunicationToRadio");
	arrivalGatesList.push_back("fromCommunicationToRouting");
	arrivalGatesList.push_back("fromRoutingToCommunication");
	
	senderGatesList.push_back("toMacFromRouting");
	senderGatesList.push_back("toRoutingFromMac");
	senderGatesList.push_back("toRadioFromMac");
	senderGatesList.push_back("toMacFromRadio");
	senderGatesList.push_back("toCommunicationFromRadio");
	senderGatesList.push_back("toRadioFromCommunication");
	senderGatesList.push_back("toRoutingFromCommunication");
	senderGatesList.push_back("toCommunicationFromRouting");	

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


/* Initialize the attack vectors */
void LocalFilter::attackInit(int nodeID) {
	
	VirtualMobilityManager* mobilityModule;
	SensorManager* sensorModule;

	sensorModule = check_and_cast <SensorManager*>(getParentModule() -> getParentModule() -> getSubmodule("SensorManager"));
	mobilityModule = check_and_cast <VirtualMobilityManager*> (getParentModule() -> getParentModule() -> getSubmodule("MobilityManager"));

	/* Retrieve the XML file name from the .ini file */
	string configurationFile = ( getParentModule() -> getParentModule() -> getParentModule() -> par("configurationFile")).stringValue();

	trace() << "-> XML : "<< configurationFile;
	
	/* There is no configuration attack file */
	if(configurationFile == "none"){
		trace() <<" -> no configuration file";	// <F.R.>
		return;
	}
	Parser parser( configurationFile, applicationName, routingProtocolName, macProtocolName, nodeID, sensorModule, mobilityModule );

	/* Fill the physicalAttacks vector */
	parser.parse("Physical", physicalAttacks);

	/* Fill the condictionalAttacks vector*/
	parser.parse("Conditional", logicalAttacks);
	
	/* Sort physical attacks and logical attacks according to their starting time */
	if( physicalAttacks.size() > 0 )
		sort(physicalAttacks.begin(), physicalAttacks.end(), entrySort);

	if( logicalAttacks.size() > 0 )
		sort(logicalAttacks.begin(), logicalAttacks.end(), entrySort);

	/* Set timers of physical attacks */
	for(int i = 0; i < physicalAttacks.size(); i++) {
		cMessage* message = new cMessage("Start physical attack", PHYSICAL_ATTACK);
		scheduleAt(physicalAttacks[i]->getTime(), message);
	}

	/* Set timers of logical attacks */
	for(int i = 0; i < logicalAttacks.size(); i++) {
	  	
		cMessage* message = new cMessage("Start logical attack", LOGICAL_ATTACK);
		scheduleAt(logicalAttacks[i]->getTime(), message);

		/* Add an entry in the activeLogicattack and set it as false (not active yet) */
		activeLogicAttack.push_back(false);

	}
	injected_bytes = 0;

}

/* Initialize the LocalFilter module */
void LocalFilter::initialize() {
	
	destroyed = false;
	
	/* Retrieve information about gates and connect them */
	initializeGates();

	attacksEvaluation = getParentModule() -> getParentModule() -> getParentModule() -> par("attacksEvaluation");

	/* Retrieve protocol names for each layer */
	macProtocolName = (getParentModule() -> par("MACProtocolName")).stringValue();
	routingProtocolName = (getParentModule() -> par("RoutingProtocolName")).stringValue();
	applicationName = (getParentModule() -> getParentModule() -> par("ApplicationName")).stringValue();

	nodeID = getParentModule() -> getParentModule() -> getIndex();

	/* Fill the attack's vectors, if possibile */
	attackInit(nodeID);

	/* Retrieve a pointer to the Radio module */
	radioModule = check_and_cast <Radio*>(getParentModule()->getSubmodule("Radio"));

	resourceModule = check_and_cast <ResourceManager*>(getParentModule()->getParentModule()->getSubmodule("ResourceManager"));

	/* Retrieve the size of net and mac header */
	mac_header = check_and_cast <VirtualMac*>(getParentModule() -> getSubmodule("MAC"))->getHeaderSize();
	net_header = check_and_cast <VirtualRouting*>(getParentModule() -> getSubmodule("Routing"))->getHeaderSize();

	injected_bytes = 0;

	// <F.R.>
	// Retrieve the number of sensors and build the fakeread data structures
	sensorManager = check_and_cast <SensorManager*>(getParentModule()->getParentModule()->getSubmodule("SensorManager"));
	int numberOfSensors = sensorManager->getNumSensingDevices();
	
	for( int i=0; i<numberOfSensors; i++){
		
		// build the first layer of noises vector
		noises.push_back( vector<Noise>() );
		
		// build the first layer of noisesParams vector
		noisesParams.push_back( vector< vector<double> >() );
		
		// build the first layer of noisesParams vector
		noisesValues.push_back( vector<double>() );
		
		// build the first and second layers of sensorsValues vector
		sensorsValues.push_back( vector<double>(numbSensorsValues, 0.0) );
		// sensorsValues[i][0] is the last sensed value
		// sensorsValues[i][1] is the counter
		// sensorsValues[i][2] is the sensitivity
		// sensorsValues[i][3] is the saturation
		// sensorsValues[i][4] is the minimum sensed value
		// sensorsValues[i][5] is the maximum sensed value
		// sensorsValues[i][6] is the average of sensed value
		sensorsValues[i][2] = sensorManager -> getSensorDeviceSensitivity(i); // set sensitivity
		sensorsValues[i][3] = sensorManager -> getSensorDeviceSaturation(i); // set saturation

	}

	srand((unsigned)time(NULL));

}


/* Handle packets and actually reproduce attacks */
void LocalFilter::handleMessage(cMessage* msg)
{	
	int msgKind;
	cGate* arrivalGate;
	int arrivalGateID;
	string arrivalGateName, senderGateName;
	double forwarding_delay = 0.0; // This delay affects only intercepted packets
	int packet_size = 0;

	msgKind = (int)msg->getKind();

	/* In case the node is destroyed, it ignores all packets, even if internal messages */
	if(destroyed) {
	  
		trace()<<"-> Due destroy action I'm going to delete the packets";
		delete msg;
		return;
		
	}

	/* This is an internal message. */
	if (msg->isSelfMessage()) {

		/* Check if the message either requires to perform a Physical attack, or enables a Conditional attack */
		switch(msgKind) {

			case PHYSICAL_ATTACK:
			  
				trace()<<"-> Active Physical Attack";
				PhysicalAttack *attack;	

				/* The first element of physicalAttacks is the attack to be performed */
				attack = (PhysicalAttack *)(physicalAttacks[0]->getAttack());
				attack->execute(destroyed, noises, noisesParams, noisesValues, sensorsValues); // <F.R.>	
				/* Remove the attack from the list of physical attacks */
				physicalAttacks.erase(physicalAttacks.begin());
				break;

			case LOGICAL_ATTACK:

				trace()<<"-> Active Logical Attack";

				/* Enable the attack occurrence */
				activeLogicAttack[falseAttackIndex] = true;

				/* Move to the next attack to be enabled */
				falseAttackIndex++;

				break;
			
		}

		delete msg;
		return;	

	}

	/* Retrieve information about packet source and destination */
	arrivalGate = msg->getArrivalGate();
	arrivalGateID = arrivalGate -> getId();
	arrivalGateName = arrivalGate -> getFullName();

	// <F.R.>
	/* perform fakeread attack */
	if (arrivalGateName.compare("fromSensorDeviceModuleToLocalFilterModule") == 0){
	
		if(msg->getKind() == SENSOR_READING_MESSAGE){
			
			trace()<<"-> received SENSOR_READING_MESSAGE";
			
			SensorReadingMessage *sMsg = check_and_cast <SensorReadingMessage*>(msg);			
			int sensorID = sMsg->getSensorIndex();
			
			// init sensorsValues vector at first sensor reading
			if( sensorsValues[sensorID][1] == 0 ){
				
				// sensorsValues[sensorID][2] already initialized in LocalFilter::Initialize()
				// sensorsValues[sensorID][3] already initialized in LocalFilter::Initialize()
				sensorsValues[sensorID][4] = sMsg->getSensedValue(); // init min sensed value with first sensor reading
				sensorsValues[sensorID][5] = sMsg->getSensedValue(); // init max sensed value with first sensor reading
				sensorsValues[sensorID][6] = sMsg->getSensedValue(); // init avg sensed value with first sensor reading
				
			}

			sensorsValues[sensorID][0] = sMsg->getSensedValue(); // update last sensed value
			sensorsValues[sensorID][1]++;  // update counter
			
			// update the minimum sensed value
			if(sensorsValues[sensorID][0] < sensorsValues[sensorID][4]){
				sensorsValues[sensorID][4] = sensorsValues[sensorID][0];
			}

			// update maximum sensed value
			if(sensorsValues[sensorID][0] > sensorsValues[sensorID][5]){
				sensorsValues[sensorID][5] = sensorsValues[sensorID][0];
			}
			
			// update the average of the sensed values
			sensorsValues[sensorID][6] = ( sensorsValues[sensorID][6] * (sensorsValues[sensorID][1]-1) + sensorsValues[sensorID][0] ) / sensorsValues[sensorID][1];


			// fakeread attack engine
			double fValue = 0;
			for(int i=0; i<(int)noises[sensorID].size(); i++){
				
				switch( noises[sensorID][i] ){
				
					case CON:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						noisesValues[sensorID][i] = 1;
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i];
						break;
					}
					
					case SEN:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						double gamma = noisesParams[sensorID][i][2];
						noisesValues[sensorID][i] = sensorsValues[sensorID][2]; // sensitivity
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i] + gamma;
						break;
					}
					
					case SAT:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						double gamma = noisesParams[sensorID][i][2];
						noisesValues[sensorID][i] = sensorsValues[sensorID][3]; // saturation
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i] + gamma;
						break;		
					}	
				
					case FIX:
					case MIN:
					case MAX:
					case AVG:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						double gamma = noisesParams[sensorID][i][2];
						// noisesValues[sensorID][i] already setted by Fakeread::execute
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i] + gamma;
						break;	
					}
					
					case INF:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						double gamma = noisesParams[sensorID][i][2];
						noisesValues[sensorID][i] = sensorsValues[sensorID][4]; // minimum sensed value
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i] + gamma;
						break;
					}
						
					case SUP:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						double gamma = noisesParams[sensorID][i][2];
						noisesValues[sensorID][i] = sensorsValues[sensorID][5]; // maximum sensed value
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i] + gamma;
						break;	
					}
										
					case MED:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						double gamma = noisesParams[sensorID][i][2];
						noisesValues[sensorID][i] = sensorsValues[sensorID][6]; // average of the sensed values
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i] + gamma;
						break;	
					}
					
					case SGN:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						double gamma = noisesParams[sensorID][i][2];
						if(sensorsValues[sensorID][0] == 0.0){
							noisesValues[sensorID][i] = 0.0;
						}
						else{
							if(sensorsValues[sensorID][0] > 0.0){
								noisesValues[sensorID][i] = 1.0;
							}
							else{
								noisesValues[sensorID][i] = -1.0;
							}
						}
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i] + gamma;
						break;
					}
								
					case RND:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						double gamma = noisesParams[sensorID][i][2];
						noisesValues[sensorID][i] = (double)rand()/((double)RAND_MAX);
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i] + gamma;
						break;
					}
											
					case LIN:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						double gamma = noisesParams[sensorID][i][2];
						noisesValues[sensorID][i] = simTime().dbl();									
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i] + gamma;
						break;
					}
					
					case SYM:{
						double alpha = noisesParams[sensorID][i][0];
						double gamma = noisesParams[sensorID][i][1];
						double deltaH = noisesParams[sensorID][i][2];
						double deltaL =  noisesParams[sensorID][i][3];
						double upperBound = gamma + deltaH;
						double lowerBound = gamma - deltaL;
						double argValue = alpha * sensorsValues[sensorID][0] + gamma;
						if( (argValue >= lowerBound) && (argValue <= upperBound) ){
							noisesValues[sensorID][i] = 0.0;	
						}
						else{
							
							do{
								double exceed;
								
								if(argValue > upperBound){
									exceed = argValue - upperBound;
									argValue = upperBound - exceed;								
								}
								
								if(argValue < lowerBound){
									exceed = lowerBound - argValue;
									argValue = lowerBound + exceed;
								}
								
							}
							while( (argValue > upperBound) || (argValue < lowerBound) );
							
							noisesValues[sensorID][i] = argValue - sensorsValues[sensorID][0];					

						}
						
						//fValue = fValue + alpha * sensorsValues[sensorID][0] + noisesValues[sensorID][i];
						fValue = fValue + argValue;
						
						break;
					
					}
					
					case SHP:{
						double alpha = noisesParams[sensorID][i][0];
						double gamma = noisesParams[sensorID][i][1];
						double deltaH = noisesParams[sensorID][i][2];
						double deltaL = noisesParams[sensorID][i][3];
						double upperBound = gamma + deltaH;
						double lowerBound = gamma - deltaL;				
						double argValue = alpha * sensorsValues[sensorID][0] + gamma;
						if( (argValue >= lowerBound) && (argValue <= upperBound) ){
							noisesValues[sensorID][i] = 0.0;	
						}
						else{
							
							if(argValue > upperBound){
								noisesValues[sensorID][i] = upperBound - argValue;
								argValue = upperBound;
							}
							else{
								noisesValues[sensorID][i] = lowerBound - argValue;
								argValue = lowerBound;
							}							
						}
						//fValue = fValue + alpha * sensorsValues[sensorID][0] + noisesValues[sensorID][i] + gamma;
						fValue = fValue + argValue;
						break;
					}
					
					case SIN:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						double tau = noisesParams[sensorID][i][2];
						double phi = noisesParams[sensorID][i][3];
						double gamma = noisesParams[sensorID][i][4];			
						noisesValues[sensorID][i] = sin( ((2*M_PI)/tau) * simTime().dbl() + phi );
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i] + gamma;
						break;
					}
											
					case SQR:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						double tau = noisesParams[sensorID][i][2];
						double phi = noisesParams[sensorID][i][3];
						double gamma = noisesParams[sensorID][i][4];			
						double sinValue = sin( ((2*M_PI)/tau) * simTime().dbl() + phi );
						if(sinValue == 0){
							noisesValues[sensorID][i] = 0.0;
						}
						else{
							if(sinValue > 0){
								noisesValues[sensorID][i] = 1.0;
							}
							else{
								noisesValues[sensorID][i] = -1.0;
							}
						}
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i] + gamma;
						break;
					}
						
					case SAW:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						double tau = noisesParams[sensorID][i][2];
						double phi = noisesParams[sensorID][i][3];
						double gamma = noisesParams[sensorID][i][4];			
						double argValue = (simTime().dbl() + phi) / tau;
						noisesValues[sensorID][i] = 2 * ( argValue - floor(0.5 + argValue) );
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i] + gamma;
						break;
					}
											
					case TRI:{
						double alpha = noisesParams[sensorID][i][0];
						double beta = noisesParams[sensorID][i][1];
						double tau = noisesParams[sensorID][i][2];
						double phi = noisesParams[sensorID][i][3];
						double gamma = noisesParams[sensorID][i][4];			
						double argValue = (simTime().dbl() + phi) / tau;
						noisesValues[sensorID][i] = 2 * fabs( argValue - floor(0.5 + argValue) );
						fValue = fValue + alpha * sensorsValues[sensorID][0] + beta * noisesValues[sensorID][i] + gamma;
						break;
					}
				};
						
				sMsg->setSensedValue(fValue);
				
				//trace()<<"fValue: "<<fValue;
			
			} // end for (fake read engine)
			
			send(sMsg, "toApplicationModuleFromLocalFilterModule");

		} // end if

		else{
			send(msg, "toApplicationModuleFromLocalFilterModule");
		}
		
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
							send(packet,"toRoutingFromCommunication");
							
						}
						
						else {
						  
							trace()<<"-> send the packet to gate toMacFromRouting";
							send(packet, "toMacFromRouting");
							
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
						send(packet,"toCommunicationFromRouting");
						
					}
					
					else if(msgKind == NETWORK_LAYER_PACKET) {
					  
						packet_size = ((cPacket*)packet)->getByteLength();
						packet_size += mac_header;
						send(packet, "toRoutingFromMac");
						
					}
					
					else {
					  
						packet_size = ((cPacket*)packet)->getByteLength();
						send(packet, "toMacFromRadio");
						
					}
					
				}

				/* Update node statistics.
				 * Store the injected bytes for, extra, energy consuption reason.
				*/
				if(stats) {

					/* packet_size is initialized as 0 so if we have stat ON and
					 * TX direction injected bytes still remain the same, avoiding
					 * direction control ( if(RX) injected_bytes += .... ; ).					
					*/
					injected_bytes += packet_size;

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

								trace()<<" -> send to toRoutingFromCommunication";
								sendDelayed(new_messages[i], delays[i], "toRoutingFromCommunication");
								break;

							}

							/* Routing packets are sento to the MAC layer */
							case NETWORK_LAYER_PACKET:{
							  
								trace()<<" -> send toMacFromRouting";
								sendDelayed(new_messages[i], delays[i], "toMacFromRouting");
								break;
								
							}
							
							/* MAC packets are sent to the radio layer */
							case MAC_LAYER_PACKET:{
							  
								trace()<<" -> send toRadioFromMac";
								sendDelayed(new_messages[i], delays[i], "toRadioFromMac");
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

	/* No attack occurs, and the intercepted packet simply follows its original flow */
	senderGateName.assign(gatesLinksMap[arrivalGateName]);
	send(msg, senderGateName.c_str());

	
	return;

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

void LocalFilter::finishSpecific() {

	double timeInj, rxTimeRemaining, extraTime;
	double dataRate = 0.0; // kbps
	double energyExtra = 0.0;
	double realEnergy = 0.0;
	double rxPower = 0.0; // mW
	
	/* compute the energy consuption using even the injected packet */

	radioModule->getRxInfoWrapper(rxTimeRemaining, dataRate, rxPower);
	realEnergy = resourceModule->getSpentEnergy();	
	timeInj = injected_bytes / (dataRate / 8);

	/* if the time needed to receive the injected packet is contained in
		rxTimeRemaining than do nothing, otherwise compute the extra time 
		in which the Radio would have to be in RX mode.	
	*/
	if(timeInj > rxTimeRemaining){
  		extraTime = timeInj - rxTimeRemaining;
		energyExtra = extraTime * rxPower;

	}

	declareOutput("Real Energy Consumed");

	realEnergy += energyExtra;

    collectOutput("Real Energy Consumed", "Energy (mJ)", realEnergy);

  	dataRate = 0.0; // kbps
	energyExtra = 0.0;
	realEnergy = 0.0;
	rxPower = 0.0; // mW
	injected_bytes = 0;
	
}
