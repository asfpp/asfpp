#include "DummyApplication.h"

Define_Module(DummyApplication);



void DummyApplication::startup()
{
	
	
}

void DummyApplication::timerFiredCallback(int timer)
{
	
}

void DummyApplication::fromNetworkLayer(ApplicationPacket * rcvPacket,
			const char *source, double rssi, double lqi)
{
	string packetName(rcvPacket->getName());

	trace() << "unknown packet received: [" << packetName << "]";

}

void DummyApplication::handleSensorReading(SensorReadingMessage * sensorMsg)
{
	string sensType(sensorMsg->getSensorType());
	double sensValue = sensorMsg->getSensedValue();

	
}

void DummyApplication::finishSpecific()
{
	
}
