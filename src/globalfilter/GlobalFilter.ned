package globalfilter;

simple GlobalFilter {

 parameters:
    bool collectTraceInfo = default (false);
    bool evaluateAttacks = default (false);
    
    string applicationName = default("");	// A.P.
    string routingProtocolName = default("BypassRouting"); // A.P.
    string macProtocolName = default("BypassMac");	// A.P.
    

  gates:
    output toNode[]; // to network nodes
    output toAdversary; // to the external adversary
    output toWirelessChannel; // to wireless channel
    output toLogger; // to Logger module
    input fromNode[]; // from network nodes 
    input fromAdversary; // from the external adversary
    input fromWirelessChannel; // from wireless channel

}
 
