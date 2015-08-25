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

package node.communication;

module CommunicationModule {
 parameters:
 	string MACProtocolName = default ("BypassMAC");
	string RoutingProtocolName = default ("BypassRouting");

 gates:
 	output toApplicationModule;
	output toNodeContainerModule;
	output toGlobalFilterModule; // <M.T.>
	output toLoggerModule; // <M.T.>
	output toApplicationModuleFromSensorDeviceModule; // <F.R.>
	input fromApplicationModule;
	input fromNodeContainerModule;
	input fromResourceManager2Net;
	input fromResourceManager2Mac;
	input fromResourceManager2Radio;
	input fromGlobalFilterModule; // <M.T.>
	input fromSensorDeviceModuleToApplicationModule; // <F.R.>


 submodules:
 	Radio: node.communication.radio.Radio;
	MAC: <MACProtocolName> like node.communication.mac.iMac;
	Routing: <RoutingProtocolName> like node.communication.routing.iRouting;
	LocalFilter: node.communication.localfilter.LocalFilter; // <M.T.>

 connections:
	
	fromResourceManager2Net --> Routing.fromCommModuleResourceMgr;
	fromResourceManager2Mac --> MAC.fromCommModuleResourceMgr;
	fromResourceManager2Radio --> Radio.fromCommModuleResourceMgr;
	
	// <M.T.> Local Filter wiring with the application
	fromApplicationModule --> LocalFilter.fromCommunicationToRouting;
	LocalFilter.toCommunicationFromRouting --> toApplicationModule;
	
	// <M.T.> Local Filter wiring with the Routing layer
	Routing.toCommunicationModule --> LocalFilter.fromRoutingToCommunication;
	LocalFilter.toRoutingFromCommunication --> Routing.fromCommunicationModule;
	Routing.toMacModule --> LocalFilter.fromRoutingToMac;
	LocalFilter.toRoutingFromMac --> Routing.fromMacModule;

	// <M.T.> Local Filter wiring with the MAC layer
	MAC.toNetworkModule --> LocalFilter.fromMacToRouting;
	LocalFilter.toMacFromRouting --> MAC.fromNetworkModule;
	LocalFilter.toMacFromRadio --> MAC.fromRadioModule;
	MAC.toRadioModule --> LocalFilter.fromMacToRadio;

	// <M.T.> Local Filter wiring with the Radio module
	LocalFilter.toRadioFromMac --> Radio.fromMacModule;
	Radio.toMacModule --> LocalFilter.fromRadioToMac;
	LocalFilter.toRadioFromCommunication --> Radio.fromCommunicationModule;
	Radio.toCommunicationModule --> LocalFilter.fromRadioToCommunication;

	// <M.T.> Local Filter wiring with the Communication module (to/from the Wireless Channel)
	LocalFilter.toCommunicationFromRadio --> toNodeContainerModule;
	fromNodeContainerModule --> LocalFilter.fromCommunicationToRadio;
	
	// <M.T.> Local Filter wiring with the Communication module (to/from the Global filter)
	LocalFilter.toGlobalFilter --> toGlobalFilterModule;
	fromGlobalFilterModule --> LocalFilter.fromGlobalFilter;
	
	// <M.T.> Local Filter wiring with the Communication module (to the Logger)
	LocalFilter.toLogger --> toLoggerModule;

	// <F.R.> Local Filter wiring with the Communication module (from the SensorDeviceModule)
	fromSensorDeviceModuleToApplicationModule --> LocalFilter.fromSensorDeviceModuleToLocalFilterModule;

	// <F.R.> Local Filter wiring with the Communication module (to the ApplicationModule)
	LocalFilter.toApplicationModuleFromLocalFilterModule --> toApplicationModuleFromSensorDeviceModule;
	
}

