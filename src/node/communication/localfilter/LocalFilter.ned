package node.communication.localfilter;

simple LocalFilter {
    parameters:
        bool collectTraceInfo = default(false);
        bool evaluateAttacks = default(false);

    gates:
        // gates to/from the Communication module
    output toCommunicationFromRouting;
    input fromCommunicationToRouting;
  
    // gates to/from the Routing module
    output toRoutingFromCommunication;
    output toRoutingFromMac;
    input fromRoutingToMac;
    input fromRoutingToCommunication;

    // gates to/from the MAC module
    output toMacFromRouting;
    output toMacFromRadio;
    input fromMacToRouting;
    input fromMacToRadio;

    // gates to/from the Radio module
    output toRadioFromMac;
    output toRadioFromCommunication;
    input fromRadioToMac;
    input fromRadioToCommunication;

    // gates to/from the Communication module
    output toCommunicationFromRadio;
    input fromCommunicationToRadio;

    // gates to/from the local filter module
    output toGlobalFilter;
    input fromGlobalFilter;

    // gate to the Logger module
    output toLogger; // to Logger module
        
        input fromSensorDeviceManagerToApplicationIn;
        output fromSensorDeviceManagerToApplicationOut;
        input fromApplicationToSensorDeviceManagerIn;
        output fromApplicationToSensorDeviceManagerOut;
}
