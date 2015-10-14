package globalfilter;

simple GlobalFilter {

    parameters:
        bool collectTraceInfo = default (false);
        bool evaluateAttacks = default (false);
        string applicationName = default("");
        string routingProtocolName = default("BypassRouting");
        string macProtocolName = default("BypassMac");
    
    gates:
        // to network nodes
        output toNode[];
        
        // to wireless channel module
        output toWirelessChannel;
        
        output toLogger; // to Logger module
        input fromNode[]; // from network nodes 
        input fromWirelessChannel; // from wireless channel
    
}
 
