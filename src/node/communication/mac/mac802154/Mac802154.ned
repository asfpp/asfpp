//****************************************************************************
//*  Copyright: National ICT Australia,  2007 - 2010                         *
//*  Developed at the ATP lab, Networked Systems research theme              *
//*  Author(s): Athanassios Boulis, Yuriy Tselishchev                        *
//*  This file is distributed under the terms in the attached LICENSE file.  *
//*  If you do not find this file, copies can be found by writing to:        *
//*                                                                          *
//*      NICTA, Locked Bag 9013, Alexandria, NSW 1435, Australia             *
//*      Attention:  License Inquiry.                                        *
//*                                                                          *  
//****************************************************************************/

package node.communication.mac.mac802154;

simple Mac802154 like node.communication.mac.iMac {
 parameters:
    //debug parameters
	bool collectTraceInfo = default (false);
	bool printStateTransitions = default (false);

	//mac layer parameters
	//non colpevoli
	int macMaxPacketSize = default (121);// O(0) R(121); considering the standard maxphypacketsize --> 127 - 6 <-- phy hdr
	int macPacketOverhead = default (9); //O(14) R(9); assuming to use 2 bytes addresses and PAN ID compression.
	int macBufferSize = default (32); //<R.D.> not so sure about this

	bool enableSlottedCSMA = default (true); // if true it's a beacon enabled network
	bool enableCAP = default (true);
	bool isFFD = default (false);
	bool isPANCoordinator = default (false);
	bool batteryLifeExtention = default (false);

	int frameOrder = default (4);
	int beaconOrder = default (6);
	int unitBackoffPeriod = default (20);
	int baseSlotDuration = default (60);

	int numSuperframeSlots = default (16);
	// <R.D.> changing the following values to stay standard compliant (old values commented out)
	int macMinBE = default(5); //originale(5) R(3); opzione colpevole nel senso che è troppo piccolo
	int macMaxBE = default(7); //originale(7) R(5); (come sopra)
	int macMaxCSMABackoffs = default (4);
	int macMaxFrameRetries = default (3);
	int maxLostBeacons = default (4);
	int minCAPLength = default (440);
	int requestGTS = default (0);

	// parameters dependent on physical layer
	// some are essential and are not defined as default
	double phyDelayForValidCS = default (0.128);
	double phyDataRate;
	//non colpevoli
	double phyDelaySleep2Tx = default (0.006); //originale(0.2) R(0.006); //in ms, considering a tmote sky mote
	double phyDelayRx2Tx = default (0.192); //originale (0.02) R(0.192);	//in ms 15.4 Turnaroundtime is 192us
	int phyFrameOverhead = default (6);
	int phyBitsPerSymbol; 

	//reception guard time, in ms
	double guardTime = default (1);

 gates:
	output toNetworkModule;
	output toRadioModule;
	input fromNetworkModule;
	input fromRadioModule;
	input fromCommModuleResourceMgr;
}

