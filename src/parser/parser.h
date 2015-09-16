
/*  This class is responsible for parsing the XML file containing the attack description. It relies on the XML++ library.
 *  It is used by LocalFilter modules and the GlobalFilter module, for physical/conditional and unconditional attacks, respectively.
 *
 *  Author : Alessandro Pischedda
 *  e-mail : alessandro.pischedda@gmail.com
 */

#ifndef PARSE_H
#define PARSE_H

#include <omnetpp.h>

#include <libxml++/libxml++.h>
#include <vector>
#include "SensorManager.h"
#include "Entry.h"
#include "PhysicalAttack.h"
#include "ConditionalAttack.h"
#include "UnconditionalAttack.h"
#include "Variable.h"
#include "ASFExpression.h"
#include "utils.h"
#include "Fakeread.h" // <F.R.>
#include "Disable.h" // <F.R.>

class Parser{

	private:

        // actually used only by disable
        cModule* callerNode;

		string xmlFile;
		int nodeID; // It is -1 in case the parsing is performed by the GlobalFilter module
		
		/* Names of adopted protocols are necessary, in order to correctly perform the "Create" action */
		string routingProtocolName;
		string macProtocolName;
		string applicationName;

		VirtualMobilityManager* mobilityModule; // Required to perform the "Move" action
		SensorManager* sensorModule;		// Required to perform the "Change" action 

		bool attackInit(const xmlpp::Node* xml_attack, Attack* attack, SimTime& time);
		string get_node_value(const xmlpp::Node* node);

	public:
		Parser(cModule* callerNode, const string xmlFilename, const string appName,  const string netProtocol, const string macProtocol, int nodeID = -1, SensorManager* sensorModule = NULL, VirtualMobilityManager* mobModule = NULL);
		~Parser();

		void parse(const string attackTypeName, vector<Entry*>& attacksVector);

};

#endif
