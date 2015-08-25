package logger;

simple Logger {

 parameters:
    bool collectTraceInfo = default (false);	// M.T.

    // List of available logs (set to true to activate)
    bool logPacketDrop = default (false);
    bool logCompromisedPacket = default (false);

  gates:
    input fromNode[]; // from network nodes (local filters)	// M.T.
    input fromGlobalFilter; // from the Global Filter module	// M.T.

}
