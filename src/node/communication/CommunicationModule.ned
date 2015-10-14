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
        input fromApplicationModule;
        
        inout routing_inf;
        inout mac_sup;
        inout mac_inf;
        inout radio_sup;
        
        output toNodeContainerModule;
        input fromNodeContainerModule;
        
        input fromResourceManager2Net;
        input fromResourceManager2Mac;
        input fromResourceManager2Radio;

    submodules:
        Radio: node.communication.radio.Radio;
        MAC: <MACProtocolName> like node.communication.mac.iMac;
        Routing: <RoutingProtocolName> like node.communication.routing.iRouting;

    connections allowunconnected:
        // LocalFilter between Application (inf) and Communication.Routing (sup)
        fromApplicationModule --> Routing.fromCommunicationModule;
        Routing.toCommunicationModule --> toApplicationModule;
        
        // LocalFilter between Communication.Routing (inf) and Communication.MAC (sup)
        Routing.toMacModule --> routing_inf$o;
        routing_inf$i --> Routing.fromMacModule;
        MAC.toNetworkModule --> mac_sup$o;
        mac_sup$i --> MAC.fromNetworkModule;
        
        // LocalFilter between Communication.MAC (inf) and Communication.Radio (sup)
        MAC.toRadioModule --> mac_inf$o;
        mac_inf$i --> MAC.fromRadioModule;
        Radio.toMacModule --> radio_sup$o;
        radio_sup$i --> Radio.fromMacModule;
        
        // LocalFilter between Communication.Radio (inf) and WirelessChannel (sup)
        Radio.toCommunicationModule --> toNodeContainerModule;
        fromNodeContainerModule --> Radio.fromCommunicationModule;

        
        // LocalFilter between ResourceManager and Communication.Routing
        fromResourceManager2Net --> Routing.fromCommModuleResourceMgr;
        
        // LocalFilter between ResourceManager and Communication.MAC
        fromResourceManager2Mac --> MAC.fromCommModuleResourceMgr;
        
        // LocalFilter between ResourceManager and Communication.Radio
        fromResourceManager2Radio --> Radio.fromCommModuleResourceMgr;
	
}

