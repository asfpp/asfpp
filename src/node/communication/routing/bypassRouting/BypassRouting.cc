/*******************************************************************************
 *  Copyright: National ICT Australia,  2007 - 2011                            *
 *  Developed at the ATP lab, Networked Systems research theme                 *
 *  Author(s): Athanassios Boulis, Yuriy Tselishchev                           *
 *  This file is distributed under the terms in the attached LICENSE file.     *
 *  If you do not find this file, copies can be found by writing to:           *
 *                                                                             *
 *      NICTA, Locked Bag 9013, Alexandria, NSW 1435, Australia                *
 *      Attention:  License Inquiry.                                           *
 *                                                                             *
 *******************************************************************************/

#include "BypassRouting.h"

Define_Module(BypassRouting);

/* Application layer sends a packet together with a dest network layer address.
 * Network layer is responsible to route that packet by selecting an appropriate
 * MAC address. With BypassRouting we do not perform any routing function. We
 * just encapsulate the app packet and translate the net address to a MAC address
 * (e.g. "3" becomes 3, or a BROADCAST_NETWORK_ADDRESS becomes BROADCAST_MAC_ADDRESS)
 * If the destination is a 1-hop neighbor it will receive the packet.
 */
void BypassRouting::fromApplicationLayer(cPacket * pkt, const char *destination)
{
	BypassRoutingPacket *netPacket = new BypassRoutingPacket("BypassRouting packet", NETWORK_LAYER_PACKET);
	netPacket->setSource(SELF_NETWORK_ADDRESS);
	netPacket->setDestination(destination);
	encapsulatePacket(netPacket, pkt);
	trace() << "-> Pass a packet destined to "<< destination <<" ( Node: "<< resolveNetworkAddress(destination) <<" ) at MAC Layer";
	
	toMacLayer(netPacket, resolveNetworkAddress(destination));
}

/* MAC layer sends a packet together with the source MAC address and other info.
 * With BypassMAC we just filter the packet by the NET address. If this
 * node is the right destination decapsulatePacket will extract the APP packet.
 * If not, there is no need to do anything. The whole net packet (including
 * the encapsulated apppacket will be deleted by the virtual routing code
 */
void BypassRouting::fromMacLayer(cPacket * pkt, int srcMacAddress, double rssi, double lqi)
{
	RoutingPacket *netPacket = dynamic_cast <RoutingPacket*>(pkt);
	
	if (netPacket) {
		string destination(netPacket->getDestination());
		trace () << "-> Arrived a packet for node "<< destination<< "from node" << srcMacAddress;
		if (destination.compare(SELF_NETWORK_ADDRESS) == 0 ||
		    destination.compare(BROADCAST_NETWORK_ADDRESS) == 0 || destination.compare("0") == 0){
			trace() << "-> Send Packet to Application Layer";
			toApplicationLayer(decapsulatePacket(pkt));
		}
	}
}

