#include "Logger.h"

Define_Module(Logger);

/* This function populates the list containing the names of log files */
void Logger::setLogFileNames() {
  
      LogFiles.insert(pair<LogType,string>(PACKET_DROP,"LogPacketDrop.txt"));
      LogFiles.insert(pair<LogType,string>(COMPROMISED_PACKET,"LogCompromisedPacket.txt"));
  
}

/* This function retrieves which logs are active, and populates the activeLogs set accordingly */
void Logger::activateLogs() {
      
      if (par("logPacketDrop"))
	activeLogs.insert(PACKET_DROP);
      
      if (par("logCompromisedPacket"))
	activeLogs.insert(COMPROMISED_PACKET);
  
}

void Logger::initialize() {
  
      /* Populate the list containing the names of log files */
      setLogFileNames(); 
      
      /* Retrieve which logs are active, and populate the activeLogs set accordingly */
      activateLogs();
      
      
      /* Debug output */
      
      set<LogType>::iterator it;
      
      trace() << "List of active logs";
      for (it=activeLogs.begin(); it!=activeLogs.end(); ++it)
	trace() << ' ' << *it;
      
}

void Logger::handleMessage(cMessage* msg) {
  
      int msgKind;

      msgKind = msg->getKind();
	
      if (msgKind != LOGGER_MESSAGE) {
	  trace() << "Wrong type of message received by the Logger module. Abort...";
	  exit(1);
      }
      
      /* A log request has been received */
      LoggerMessage* logMsg = (LoggerMessage*)(msg);
      LogType type = logMsg -> getLogType();
      set<LogType>::iterator it = activeLogs.find(type);
      
      /* This type of log is active */
      if (it != activeLogs.end()){
	  ofstream outputFile;
	  double timestamp = (msg -> getTimestamp()).dbl();
	  int nodeID = logMsg -> getReqNodeID();
	  string text = logMsg -> getInformation();
	  string filename(LogFiles[type]); // retrieve the output file name
	  
	  outputFile.open(filename.c_str(), ios::app);
	  outputFile << timestamp << " " << nodeID << " " << text << '\n';
	  outputFile.close();
      }
      
}

void Logger::finishSpecific() {
  
}