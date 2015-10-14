//********************************************************************************
//*  Copyright: National ICT Australia,  2007 - 2010                             *
//*  Developed at the ATP lab, Networked Systems research theme                  *
//*  Author(s): Athanassios Boulis, Dimosthenis Pediaditakis, Yuriy Tselishchev  *
//*  This file is distributed under the terms in the attached LICENSE file.      *
//*  If you do not find this file, copies can be found by writing to:            *
//*                                                                              *
//*      NICTA, Locked Bag 9013, Alexandria, NSW 1435, Australia                 *
//*      Attention:  License Inquiry.                                            *
//*                                                                              *
//*******************************************************************************/

import wirelessChannel;
import physicalProcess;
import node;
import globalfilter; // <M.T.> Import the Global Filter module
import logger;

network SN {
	
 parameters:
	int field_x = default (30);			// the length of the deployment field
	int field_y = default (30);			// the width of the deployment field
	int field_z = default (0);			// the height of the deployment field (2-D field by default)

	int numNodes;					// the number of nodes

	string deployment = default ("");

	int numPhysicalProcesses = default (1);
	string physicalProcessName = default ("CustomizablePhysicalProcess");
	string debugInfoFileName = default ("Castalia-Trace.txt");
	
	bool attacksEvaluation = default (true);

	string configurationFile = default("none");
	
 submodules:
	wirelessChannel:wirelessChannel.WirelessChannel {
	 gates:
		toNode[numNodes];
		fromNode[numNodes];
	} 

	physicalProcess[numPhysicalProcesses]: <physicalProcessName> 
				like physicalProcess.iPhysicalProcess {
	 gates:
		toNode[numNodes];
		fromNode[numNodes];
	}

	node[numNodes]:node.Node {
	 gates:
		toPhysicalProcess[numPhysicalProcesses];
		fromPhysicalProcess[numPhysicalProcesses];
	}
	
	// <M.T.> The Global Filter communicates with the Local Filter of every node
	globalFilter:globalfilter.GlobalFilter {
	 gates:
		toNode[numNodes];
		fromNode[numNodes];
	}
	
	// <M.T.> The Logger receives log messages from the Global Filter and Local Filter modules
	logger:logger.Logger {
	 gates:
		fromNode[numNodes];
		fromGlobalFilter;
	}

 connections:
	for i = 0..numNodes - 1 {
		node[i].toWirelessChannel --> wirelessChannel.fromNode[i];
		node[i].fromWirelessChannel <-- wirelessChannel.toNode[i];
		node[i].toGlobalFilter --> globalFilter.fromNode[i]; // M.T.
		node[i].fromGlobalFilter <-- globalFilter.toNode[i]; // M.T.
		node[i].toLogger --> logger.fromNode[i]; // M.T.
	}

	for i = 0..numNodes - 1, for j = 0..numPhysicalProcesses - 1 {
		node[i].toPhysicalProcess[j] -->  physicalProcess[j].fromNode[i];
		node[i].fromPhysicalProcess[j] <-- physicalProcess[j].toNode[i];
	}
	
	// <M.T.> Global Filter wiring with the Wireless Channel and the Logger
	globalFilter.toWirelessChannel --> wirelessChannel.fromGlobalFilter;
	wirelessChannel.toGlobalFilter --> globalFilter.fromWirelessChannel;
	globalFilter.toLogger --> logger.fromGlobalFilter;
	
}
