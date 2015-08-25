/* This file includes all header files referred to application and
 * communication messages provided by Castalia. It is included in
 * ./action/Create.h in order to correctly define message objects
 * while performing the Create action.
 * 
 * In case a new application or protocol is defined, the user is
 * required to extend this file, by including the header file of
 * each new user defined message.
 *
 * Author : Marco Tiloca
 * E-mail : marco.tiloca@iet.com
 */
 
#ifndef PACKET_TYPES_H
#define PACKET_TYPES_H

#include <map>
#include <iostream>

 /* Application packets */
#include "ApplicationPacket_m.h"
#include "ClusterAggregatorPacket_m.h"
#include "DistanceTestPacket_m.h"
#include "RoomMonitoringPacket_m.h"
#include "ValueReportingPacket_m.h"

/* Routing protocols packets */
#include "RoutingPacket_m.h"
#include "BypassRoutingPacket_m.h"
#include "MultipathRingsRoutingPacket_m.h"
#include "AodvRoutingDataPacket_m.h"
#include "AodvRoutingPacket_m.h"
#include "AodvRoutingRrepPacket_m.h"

/* MAC protocols packets */
#include "MacPacket_m.h"
#include "BaselineMacPacket_m.h"
#include "Mac802154Packet_m.h"
#include "TMacPacket_m.h"
#include "TunableMacPacket_m.h"

/* This function is used by the action "Create" in order to
   retrieve the lenght of a particular packet identified by 
   the layer name and his type. A.P.
*/
int getPacketLength(std::string protocolName, int type);

#endif
