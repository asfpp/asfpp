# Deep test.
#
# authors: 
#  + Francesco Racciatti <racciatti.francesco@gmail.com>

# cluster 2
list targetList = {3, 4, 9, 10, 15, 16}

# conditional statement
from 50 nodes in targetList do{

    filter("APP.sourceNodeID" == "3|4|9|10|15|16" )
        
        packet fakePacket
    
        var applicationID = 0
        var sequenceNumber = 0
        var sourceNodeID = 0
        var data = 110
        
        var source = 0
        var destination = 0
        var timestamp = 0
        
        retrieve(original, "APP.applicationID", applicationID)
        retrieve(original, "APP.sequenceNumber", sequenceNumber)
        retrieve(original, "APP.sourceNodeID", sourceNodeID)
        
        # retrieve in struct appNetInfoExchange
        retrieve(original, "APP.appNetInfoExchange.source", source)
        retrieve(original, "APP.appNetInfoExchange.destination", destination)
        retrieve(original, "APP.appNetInfoExchange.timestamp", timestamp)
        
        drop(original, 1)
        
        create(fakePacket, "APP.type", 0)
        change(fakePacket, "APP.applicationID", applicationID)
        change(fakePacket, "APP.sequenceNumber", sequenceNumber)
        change(fakePacket, "APP.sourceNodeID", sourceNodeID)
        change(fakePacket, "APP.data", data)
        
        # change in struct appNetInfoExchange
        #change(fakePacket, "APP.appNetInfoExchange.source", source)
        #change(fakePacket, "APP.appNetInfoExchange.destination", destination)
        #change(fakePacket, "APP.appNetInfoExchange.timestamp", timestamp)
        
        send(fakePacket, 0)
        
}
