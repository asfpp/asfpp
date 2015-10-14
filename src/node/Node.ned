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

package node;

import node.mobilityManager;
import node.localfilter;

// The sensor node module. Connects to the wireless channel in order to communicate 
// with other nodes. Connects to psysical processes so it can sample them.

module Node {
 parameters:
 	//node location is defined by five parameters below
	double xCoor = default (0);
	double yCoor = default (0);
	double zCoor = default (0);
	double phi = default (0);
	double theta = default (0);
	
	double startupOffset = default (0);							//node startup offset (i.e. delay), in seconds 
	double startupRandomization = default (0.05);				//node startup randomisation, in seconds
	// Node will become active startupOffset + random(startupRandomization) 
	// seconds after the start of simulation

	string ApplicationName;										//the name of the implemented Application Module
	string MobilityManagerName = default ("NoMobilityManager");	//the name of the implemented Mobility Module

    gates:
        input fromWirelessChannel;
        output toWirelessChannel;
        
        input fromPhysicalProcess[];
        output toPhysicalProcess[];
        
        input fromGlobalFilter;
        output toGlobalFilter;
        
        output toLogger;

    submodules:
        MobilityManager: <MobilityManagerName> like node.mobilityManager.iMobilityManager;
        ResourceManager: node.resourceManager.ResourceManager;
        SensorManager: node.sensorManager.SensorManager {
         gates:
            fromNodeContainerModule[sizeof(toPhysicalProcess)];
            toNodeContainerModule[sizeof(toPhysicalProcess)];
        } 
        Communication: node.communication.CommunicationModule;
        Application: <ApplicationName> like node.application.iApplication;
        LocalFilter: node.localfilter.LocalFilter;

    connections allowunconnected:
        // LocalFilter between SensorManager and Application
        SensorManager.toApplicationModule --> LocalFilter.sensormanager_application_sup$i;
        LocalFilter.sensormanager_application_inf$o --> Application.fromSensorDeviceManager;
        Application.toSensorDeviceManager --> LocalFilter.sensormanager_application_inf$i;
        LocalFilter.sensormanager_application_sup$o --> SensorManager.fromApplicationModule;

        // LocalFilter between Application and Communication.Routing
        Application.toCommunicationModule --> LocalFilter.application_routing_sup$i;
        LocalFilter.application_routing_inf$o --> Communication.fromApplicationModule;
        Communication.toApplicationModule --> LocalFilter.application_routing_inf$i;
        LocalFilter.application_routing_sup$o --> Application.fromCommunicationModule;

        // LocalFilter between Communication.Routing and Communication.MAC
        Communication.routing_inf$o --> LocalFilter.routing_mac_sup$i;
        LocalFilter.routing_mac_inf$o --> Communication.mac_sup$i;
        Communication.mac_sup$o --> LocalFilter.routing_mac_inf$i;
        LocalFilter.routing_mac_sup$o --> Communication.routing_inf$i;

        // LocalFilter between Communication.MAC and Communication.Radio
        Communication.mac_inf$o --> LocalFilter.mac_radio_sup$i;
        LocalFilter.mac_radio_inf$o --> Communication.radio_sup$i;
        Communication.radio_sup$o --> LocalFilter.mac_radio_inf$i;
        LocalFilter.mac_radio_sup$o --> Communication.mac_inf$i;

        // LocalFilter between Communication.Radio and WirelessChannel
        Communication.toNodeContainerModule --> LocalFilter.radio_wirelesschannel_sup$i;
        LocalFilter.radio_wirelesschannel_inf$o --> toWirelessChannel;
        fromWirelessChannel --> LocalFilter.radio_wirelesschannel_inf$i;
        LocalFilter.radio_wirelesschannel_sup$o --> Communication.fromNodeContainerModule;


        // LocalFilter between ResourceManager and SensorManager
        ResourceManager.toSensorDevManager --> LocalFilter.resourcemanager_sensormanager$i;
        LocalFilter.resourcemanager_sensormanager$o --> SensorManager.fromResourceManager;

        // LocalFilter between ResourceManager and Application
        ResourceManager.toApplication --> LocalFilter.resourcemanager_application$i;
        LocalFilter.resourcemanager_application$o --> Application.fromResourceManager;

        // LocalFilter between ResourceManager and Communication.Routing
        ResourceManager.toNetwork --> LocalFilter.resourcemanager_routing$i;
        LocalFilter.resourcemanager_routing$o --> Communication.fromResourceManager2Net;

        // LocalFilter between ResourceManager and Communication.MAC
        ResourceManager.toMac --> LocalFilter.resourcemanager_mac$i;
        LocalFilter.resourcemanager_mac$o --> Communication.fromResourceManager2Mac;

        // LocalFilter between ResourceManager and Communication.Radio
        ResourceManager.toRadio --> LocalFilter.resourcemanager_radio$i;
        LocalFilter.resourcemanager_radio$o --> Communication.fromResourceManager2Radio;

        // wire physical processes with sensormanager
        for i = 0..sizeof(toPhysicalProcess) - 1 {
            fromPhysicalProcess[i] --> SensorManager.fromNodeContainerModule[i];
            SensorManager.toNodeContainerModule[i] --> toPhysicalProcess[i];
        }

        // LocalFilter and GlobalFilter
        LocalFilter.toGlobalFilter --> toGlobalFilter;
        fromGlobalFilter --> LocalFilter.fromGlobalFilter;

        // LocalFilter and Logger
        LocalFilter.toLogger --> toLogger;
	
}

