#include "PacketTypes.h"

using namespace std;


/* This function is used by the action "Create" in order to
   retrieve the lenght of a particular packet identified by 
   the layer name and his type. A.P.
*/
int getPacketLength(string protocolName, int type){


	map<string, map<int, int> > layer_map;


	/* ---------------------- APP ---------------------- */


	map<int, int> clusterAggregator;


	clusterAggregator[0] = 12 + 4; // header + payload 
	layer_map["ClusterAggregator"] = clusterAggregator ;

	/* ---------------------- NET ----------------------- */

	map<int, int> aodv;

	/* AODV 
		AODV_UNKNOWN_PACKET_TYPE = 0,
		AODV_RREQ_PACKET = 1,
		AODV_RREP_PACKET = 2,
		AODV_RERR_PACKET = 3,
		AODV_RREP_ACK_PACKET = 4,
		AODV_HELLO_MESSAGE_PACKET = 5,
		AODV_DATA_PACKET = 6,
	
		every packet has the same dimension... 
	*/
	aodv[1] = 10;
	aodv[2] = 10;
	aodv[3] = 10;
	aodv[4] = 10;
	aodv[5] = 10;
	aodv[6] = 10; // net header
	
	layer_map["AodvRouting"] = aodv;
	
	
	/* ---------------------- MAC --------------------- */
	
	
	/*TMAC 
		SYNC_TMAC_PACKET = 1;
		RTS_TMAC_PACKET = 2;
		CTS_TMAC_PACKET = 3;
		DS_TMAC_PACKET = 4;
		FRTS_TMAC_PACKET = 5;
		DATA_TMAC_PACKET = 6;
		ACK_TMAC_PACKET = 7;
	*/
	
	map<int, int> tmac;
	tmac[SYNC_TMAC_PACKET] = 11;
	tmac[RTS_TMAC_PACKET] = 13;
	tmac[CTS_TMAC_PACKET] = 13;
	tmac[DS_TMAC_PACKET] = 0; // not supported
	tmac[FRTS_TMAC_PACKET] = 0; // not supported
	tmac[DATA_TMAC_PACKET] = 11; // header mac, used to encapsulate
	tmac[ACK_TMAC_PACKET] = 11;
	
	
	layer_map["TMAC"] = tmac;
		
	return (layer_map[protocolName])[type]; //temp[type];
}
