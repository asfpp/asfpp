package node.localfilter;

simple LocalFilter {
    parameters:
        bool collectTraceInfo = default(false);
        bool evaluateAttacks = default(false);

    gates:
        // LocalFilter between SensorManager and Application
        inout sensormanager_application_sup;
        inout sensormanager_application_inf;

        // LocalFilter between Application and Communication.Routing
        inout application_routing_sup;
        inout application_routing_inf;
        
        // LocalFilter between Communication.Routing and Communication.MAC
        inout routing_mac_sup;
        inout routing_mac_inf;
    
        // LocalFilter between Communication.MAC and Communication.Radio
        inout mac_radio_sup;
        inout mac_radio_inf;
    
        // LocalFilter between Communication.Radio and WirelessChannel
        inout radio_wirelesschannel_sup;
        inout radio_wirelesschannel_inf;
    
        // LocalFilter between ResourceManager and other modules
        inout resourcemanager_sensormanager;
        inout resourcemanager_application;
        inout resourcemanager_routing;
        inout resourcemanager_mac;
        inout resourcemanager_radio;
        
        // to/from GlobalFilter
        output toGlobalFilter;
        input fromGlobalFilter;

        // to Logger
        output toLogger;
        
}
