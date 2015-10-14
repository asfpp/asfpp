/**
 * @file parser.cc
 * 
 * @todo under revision
 */





#include "Parser.h"


#include "Destroy.h"
#include "Disable.h"
#include "Move.h"
#include "Fakeread.h"




/* Return either the content of an XML Text node (<tag>value</tag>), or an empty string if it is not a Text node 
 * A.P.
 */
string Parser::get_node_value(const xmlpp::Node* node) {

	xmlpp::Node::NodeList values = node->get_children();
	const xmlpp::TextNode* nodeText = dynamic_cast<const xmlpp::TextNode*>(values.front());

	if(nodeText)
		return nodeText->get_content();
	
	return "";

}

/* 
 * Initialize the Parser object. The parameter 'node' is equal to -1 in case the GlobalFilter is performing the parse.
 * In such a case, pointers to the SensorManager and MobilityManager remain set to NULL.
 * This is not an issue, since the GlobalFilter does not perform physical attacks and does not require to access such modules.
 */
Parser::Parser(cModule* targetNode, const string xmlFilename, const string appName, const string netProtocol, const string macProtocol, int node, SensorManager* sensor, VirtualMobilityManager* mobility )
{
    this->targetNode = targetNode;

	xmlFile = xmlFilename;
	applicationName = appName;
	routingProtocolName = netProtocol;
	macProtocolName = macProtocol;

	nodeID = node;

	mobilityModule = mobility;
	sensorModule = sensor;

}

/* Build and fill the 'attack' object, by parsing the XML tags <Attack></Attack> of the 'xml_attack' XML node. 
   If the parsing is performed by the GlobalFilter, then nodeID == -1 in che Parser class.
*/
bool Parser::attackInit(const xmlpp::Node* xml_attack, Attack* attack, SimTime& time){

	bool node_found = false; // If TRUE, the current node takes part in the attack, as victim and/or performer
	string start_time;
	string action_parameters;
	string action_name;
	vector<string> tokens;
	vector<string> items;	// used for the "Expression" actions

	/* MAX and MIN values must be manually specified in the XML attack configuration file */
	map<string, Variable*> varTable;

	/* Add SELF (nodeID of the current node) to the Variable Table */
	varTable["SELF"] = new Variable(itos(nodeID), NUMBER);
	varTable["MAX"] = new Variable("100", NUMBER);
	varTable["MIN"] = new Variable("0", NUMBER);
	
	/* The "details" section contains the following information
		- attack first occurrence time
		- packet filter, for conditional attacks only
		- list of involved nodes
		- list of variables declared by the user
		- attack frequency, for unconditional attacks only
		- list of actions to be performed during the attack
	*/
	xmlpp::Node::NodeList details = xml_attack->get_children();
	
	//ofstream debug;
	//debug.open("Parser_AttackInit.txt", ios::app);

	/* Retrieve attack details */
	for(xmlpp::Node::NodeList::iterator k = details.begin(); k != details.end(); ++k) {
			
		xmlpp::Node *detail = *k;
		
		/* First occurrence time */
		if(detail->get_name() == "start_time")
			start_time = get_node_value(detail);
			
		/* Packet filter (condictional attacks only) */
		if(detail->get_name() == "filter") {
		  
			((ConditionalAttack *)(attack))->setPacketFilter(get_node_value(detail));
			//debug<<"\nfilter "<<get_node_value(detail)<<endl;
			
		}	

		/* Attack frequency (uncondictional attacks only) */
		if(detail->get_name() == "frequency") {
		  	double frequency = atof(get_node_value(detail).c_str());
			((UnconditionalAttack *)(attack))->addFrequency( frequency );
			//debug<<"\nfrequency "<<frequency<<endl;
			
		}
		
		/* Node involved in the attack as victim and/or performer (not relevant for unconditional attacks) */
		/*TODO This check should be moved to the top */
		if(detail->get_name() == "node") {
		  
			vector<string> nodes;
			tokenize(nodes, string(get_node_value(detail)), ':');
			
 			/* Check if the current node is a "target" of this attack */
			for(int i=0; i < nodes.size(); i++) {
			  
				if(itos(nodeID) == nodes[i])
					node_found = true;
			
			}

			if(!node_found)
				break; // Skip the rest of this attack and continue to parse other attacks
		}

		/* Declaration and initialization of a variable object */
		if(detail->get_name() == "var") {
			xmlpp::Node::NodeList parameters = detail->get_children(); 
			string variable_name, variable_value;
			varType variable_type;

			/* Retrieve name, value, and type of the specified variable */
			for(xmlpp::Node::NodeList::iterator jter = parameters.begin(); jter != parameters.end(); ++jter) {
			  
				xmlpp::Node *param = *jter;
				
				if( param->get_name() == "name")
					variable_name = get_node_value(param);

				if( param->get_name() == "value")
					variable_value = get_node_value(param);
				
				if( param->get_name() == "type"){
					if (get_node_value(param) == "STRING")
						variable_type = STRING;
					else if (get_node_value(param) == "NUMBER")
						variable_type = NUMBER;
					else	
						variable_type = NOTYPE;	
				}
			}

			/* Add the retrieved variable to the variableTable */
			//debug<<"\nVAR "<<variable_name<<" "<<variable_value<<endl;
			varTable[variable_name] = new Variable(variable_value, variable_type);
			
		}

		/* Retrieve action details from the XML tags <action></action>. Action details consist of
			- name
			- parameters
			- item (for Expression Evaluation only)
		*/
		if(detail->get_name() == "action") {
			
			xmlpp::Node::NodeList parameters = detail->get_children(); 

			action_name="";
			action_parameters = "";
			tokens.clear();
			items.clear();
			
			/* Retrieve action details */
			for(xmlpp::Node::NodeList::iterator jter = parameters.begin(); jter != parameters.end(); ++jter) {
			  
				xmlpp::Node *param = *jter;
				
				if( param->get_name() == "name")
					action_name = get_node_value(param);

				if( param->get_name() == "parameters")
					action_parameters = get_node_value(param);

				if( param->get_name() == "item")
					items.push_back(get_node_value(param));

			}
			
			tokenize(tokens, action_parameters, ':');

			/* Retrieve action specific parameters */
			
			// action 'destroy' found
			if(action_name == "Destroy") {
				Destroy* destroy = new Destroy(targetNode);
				attack->addAction(destroy);
			}
            
            // action 'disable' found
			if(action_name == "Disable") {
				Disable* disable = new Disable(targetNode);
				attack->addAction(disable);
			}
		
			// action 'move' found
            if (action_name == "Move") {
                // retrieve the action's parameters
                NodeLocation_type targetLocation;
                targetLocation.x = stod(tokens[0]);
                targetLocation.y = stod(tokens[1]);
                targetLocation.z = stod(tokens[2]);
                // build the action
                Move *move = new Move(targetNode, targetLocation);
                // add the action to the attack
                attack->addAction(move);
            }
            
            // action 'fakeread' found
            if (action_name == "Fakeread") {
                // retrieve the index of the target sensor
                int targetSensorIndex = stoi(tokens[1]);
                // retrieve the expression
                string expression = tokens[3];
                // build the action
                Fakeread *fakeread = new Fakeread(targetSensorIndex, expression);
                // add the action to the attack
                attack->addAction(fakeread);
            }
			
			/* "Change" requires the following parameters
				- name of the packet to be altered
				- layer and field to be altered (retrieved from 'fied_name')
				- new value to written in the specified field
			*/
			if(action_name == "Change") {

				string protocol, field_name, new_value;
				string packetName;

				//debug<<"-> CHANGE ACTION"<<endl;

				for(int i=0; i < tokens.size() ; i++) {
				  
					if(tokens[i] == "field_name")
						field_name = tokens[i+1];
					
					if(tokens[i] == "value")
						new_value = tokens[i+1];
					
					if(tokens[i] == "packetName")
						packetName = tokens[i+1];
					
				}
					
				//debug<<"\t-> Packet Name "<<packetName<<endl;
				//debug<<"\t-> field_name "<<field_name<<endl;
				//debug<<"\t-> new_value "<<new_value<<endl;

				Change *change = new Change(field_name, new_value);
				
				change->setPacketName(packetName);

				attack->addAction(change);
				//debug<< "\t-> Add Change Action"<<endl;
				
			}

			// action 'drop' found
            if (action_name == "Drop") {
                // retrieve the action's parameters
                string packetName = tokens[1];
                double threshold = stod(tokens[3]);
                // build the action
                Drop* drop = new Drop(threshold);
                drop->setPacketName(packetName);
                // add the action to the attack
                attack->addAction(drop);
			}

			/* "Send" requires the following parameters
				- name of the packet to be delivered
				- delivery delay (seconds)
			*/
			if(action_name == "Send") {

				double delay;
				string packetName;

				//debug<<"\n-> PUT"<<endl;

				for(int i=0; i < tokens.size() ; i++) {
				  
			
					if(tokens[i] == "delay")
						delay = atof( (tokens[i+1]).c_str() );
						
					if(tokens[i] == "packetName")
						packetName = tokens[i+1];
				
				}

				//debug<<"-> SEND ACTION"<<endl;

				Send* my_send = new Send(delay);

				my_send->setPacketName( packetName );

				//debug<<"\t-> Packet Name "<<my_send->getPacketName()<<endl;

				attack->addAction(my_send);
				//debug<<"\t-> Add Send Action"<<endl;
				
			}

			/* "Put" requires the following parameters
				- name of the packet to be delivered
				- direction (either TX or RX)
				- list of recipient nodes
				- dlivery delay (seconds)
				- throughWC (either update radio statistics on recient nodes or not)
			*/
			if(action_name == "Put") {
			  
				string direction;
				vector<string> nodeList;
				bool stats = false;
				double delay;
				string packetName;

				//debug<<"\n-> PUT"<<endl;

				for(int i=0; i < tokens.size() ; i++) {
				  
					if(tokens[i] == "direction")
						direction = tokens[i+1];
					
					if(tokens[i] == "nodes")
						tokenize(nodeList, tokens[i+1], '|');
					
					if(tokens[i] == "delay")
						delay = atof( (tokens[i+1]).c_str() );

					if(tokens[i] == "throughWC")
						if(tokens[i+1] == "true" || tokens[i+1] == "TRUE")
							stats = true;
						
					if(tokens[i] == "packetName")
						packetName = tokens[i+1];
				
				}

				//debug<<"\t-> DELAY "<<delay<<endl;

				Put* put = new Put(direction, delay, stats);
				put->setPacketName( packetName );

				/* Populate the list of recipient nodes for the Put action */
				for(int i = 0; i < nodeList.size() ; i++)
					put->addNode(atoi(nodeList[i].c_str()));

				attack->addAction(put);
				//debug<<"\t-> Add Put Action"<<endl;

			}
				
			/* "Retrieve" requires the following parameters
				- name of the packet
				- field_name, i.e. names of the layer and field to be inspected
				- varName, i.e. the variable where the retrieved value has to be stored
			*/
			if(action_name == "Retrieve") {

				//debug<<"-> RETRIEVE ACTION"<<endl;

				string protocol, fieldName;
				string packetName, varName;

				for(int i=0; i < tokens.size() ; i++) {
				  
					if(tokens[i] == "field_name")
						fieldName = tokens[i+1];
					
					else if(tokens[i] == "packetName")
						packetName = tokens[i+1];
					
					else if(tokens[i] == "varName")
						varName = tokens[i+1];
					
				}
				
				//debug<<"\t-> Packet Name "<<packetName<<endl;

				Retrieve *retrieve = new Retrieve(fieldName, varName);
				
				retrieve->setPacketName(packetName);

				attack->addAction(retrieve);
				//debug<< "\t-> Add Retrieve Action"<<endl;
				
			}

			/* "Clone" requires the following parameters
				- packetName, i.e. the source packet name
				- newPacketName, i.e. the clone packet name
			*/
			if(action_name == "Clone") {

				string packetName;
				string newPacketName;

				//debug<<"-> CLONE ACTION"<<endl;

				for(int i=0; i < tokens.size() ; i++) {
				
					if(tokens[i] == "packetName")
						packetName = tokens[i+1];

					else if(tokens[i] == "newPacketName")
						newPacketName = tokens[i+1];
					
				}

				//debug<<"\t-> Work on "<<packetName<<" generate "<<newPacketName<<endl;
				
				Clone* clone = new Clone(newPacketName, packetName);

				attack->addAction(clone);
				//debug<<"\t-> Add Clone Action"<<endl;
				
			}

			/* "Create" requires the following parameters
				- packetName, i.e. the name of the packet to be created
				- APP.type, i.e. the name of the considered application
				- NET.type, i.e. the name of the considered network level protocol
				- MAC.type, i.e. the name of the considered MAC level protocol
			*/
			if(action_name == "Create") {

				string packetName;
				string appType, netType, macType;
				
				appType = netType = macType = "-1";
				
				//debug<<"-> CREATE ACTION"<<endl;

				for(int i=0; i < tokens.size() ; i++) {
				
					if(tokens[i] == "packetName")
						packetName = tokens[i+1];
					
					if(tokens[i] == "APP.type")
						appType = tokens[i+1];
					
					if(tokens[i] == "NET.type")
						netType = tokens[i+1];
					
					if(tokens[i] == "MAC.type")
						macType = tokens[i+1];
	
				}

				//debug<<"\t-> Generate "<<packetName<<endl;
				
				//debug<<"\t-> APP.type "<<appType<<endl;
				//debug<<"\t-> NET.type "<<netType<<endl;
				//debug<<"\t-> MAC.type "<<macType<<endl;

				Create* create = new Create(applicationName, routingProtocolName, macProtocolName, appType, netType, macType);

				create->setPacketName(packetName);
				attack->addAction(create);
				//debug<<"\t-> Add Create Action"<<endl;
			}
			
			/* The "Expression" action is a sequence of items.
			 * Every item can be an operand or an operator.
			 */
			if(action_name == "Expression") {

				ASFExpression* expr = new ASFExpression(items);
				//cout<<"\nAdd Expression "<<endl;
				attack->addAction(expr);
			}
			

		} // end action paring

	} // end attack details parsing

	/* Add the Variable Table to the attack object */
	attack->addVarTable(varTable);

	if(node_found || nodeID == -1 ) {
		time = atol( start_time.c_str());
		return true;
	}
	
	//debug.close();
	return false;

}

void Parser::parse( const string attackTypeName, vector<Entry*>& attacksVector ) {
	
	//ofstream debug;
	//debug.open("Parser_parse.txt", ios::app);
   
	try {

    	xmlpp::DomParser parser;

		/* There is no configuration attack file */
		if(xmlFile == "none")
			return;

		if( attackTypeName != "Physical" && attackTypeName != "Conditional" && attackTypeName != "Unconditional" ){
			string error_message = "ERROR: doesn't exist no one attack type called "+attackTypeName;
			opp_error(error_message.c_str());
		}
		
		//debug<<"File XML : "<<xmlFile<<endl;

		parser.parse_file(xmlFile);

		/* Retrieve the root node */
		xmlpp::Node* rootNode = parser.get_document()->get_root_node();

		/* Retrieve root node children */
		xmlpp::Node::NodeList list = rootNode->get_children();
		
		for(xmlpp::Node::NodeList::iterator iter = list.begin(); iter != list.end(); ++iter) {
			xmlpp::Node *attack_type = *iter;
			Glib::ustring name = attack_type->get_name();


			/* If the attack type is the one we are looking for, then parse this entry. Otherwise, ignore it. */
			if(attack_type->get_name() == attackTypeName) {
	
				xmlpp::Node::NodeList attacks = attack_type->get_children(); 
				for(xmlpp::Node::NodeList::iterator iter = attacks.begin(); iter != attacks.end(); ++iter) {
			  
					SimTime time;
					Attack* attack = NULL;

					xmlpp::Node *attack_xml = *iter;
					Glib::ustring name = attack_xml->get_name();

					if(name == "text") // Skip this kind of XML nodes
						continue;

					/* Create an attack object */
					if (attackTypeName == "Physical")
						attack = new PhysicalAttack();
					if (attackTypeName == "Conditional")
						attack = new ConditionalAttack();
					if (attackTypeName == "Unconditional")
						attack = new UnconditionalAttack();

					/* Initialize the attack object */
					if( attackInit(attack_xml, attack, time) ) {
				  
						/* Build an attack entry object and add it to the attacksVector list */
						Entry* entry = new Entry(attack,time);
						attacksVector.push_back(entry);
						//debug<<"-> Add a "+attackTypeName+" Attack"<<endl;
					
					}
				
					else 
						delete attack;
					
				} // END FOR
			
			} // END 

		
        }// END MAIN FOR

   }
   
   catch(const std::exception& ex) {

    	string error_message = "Exception caught: "+string(ex.what());
    	opp_error(error_message.c_str());

   }

	//debug<< attackTypeName<<" Attack : "<<attacksVector.size()<<endl;
	//debug.close();

}

Parser::~Parser(){

	xmlFile.clear();
	routingProtocolName.clear();
	macProtocolName.clear();
	applicationName.clear();

}
