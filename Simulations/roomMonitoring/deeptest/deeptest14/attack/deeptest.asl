# Deep test.
#
# authors: 
#  + Francesco Racciatti <racciatti.francesco@gmail.com>

# cluster 2
list targetList = {3, 4, 9, 10, 15, 16}

list targetList3 = {3}
list targetList4 = {4}
list targetList9 = {9}
list targetList10 = {10}
list targetList15 = {15}
list targetList16 = {16}



# conditional statement
from 200 nodes in targetList do {

    filter("APP.appNetInfoExchange.source" == "3|4|9|10|15|16")
   
        drop(original, 1)

}


# unconditional statement
from 50 every 0.1 do {

        var seqNumb = 10000

        packet fakePacket3
        packet fakePacket4
        packet fakePacket9
        packet fakePacket10
        packet fakePacket15
        packet fakePacket16
        
        create(fakePacket3, "APP.type", 0)
        create(fakePacket4, "APP.type", 0)
        create(fakePacket9, "APP.type", 0)
        create(fakePacket10, "APP.type", 0)
        create(fakePacket15, "APP.type", 0)
        create(fakePacket16, "APP.type", 0)
        
        #change(fakePacket3, "APP.applicationID", applicationID)
        #change(fakePacket4, "APP.applicationID", applicationID)
        #change(fakePacket9, "APP.applicationID", applicationID)
        #change(fakePacket10, "APP.applicationID", applicationID)
        #change(fakePacket15, "APP.applicationID", applicationID)
        #change(fakePacket16, "APP.applicationID", applicationID)
        
        change(fakePacket3, "APP.sequenceNumber", seqNumb)
        change(fakePacket4, "APP.sequenceNumber", seqNumb)
        change(fakePacket9, "APP.sequenceNumber", seqNumb)
        change(fakePacket10, "APP.sequenceNumber", seqNumb)
        change(fakePacket15, "APP.sequenceNumber", seqNumb)
        change(fakePacket16, "APP.sequenceNumber", seqNumb)
                
        change(fakePacket3, "APP.sourceNodeID", 3)
        change(fakePacket4, "APP.sourceNodeID", 4)
        change(fakePacket9, "APP.sourceNodeID", 9)
        change(fakePacket10, "APP.sourceNodeID", 10)
        change(fakePacket15, "APP.sourceNodeID", 15)
        change(fakePacket16, "APP.sourceNodeID", 16)
        
        change(fakePacket3, "APP.data", 80)
        change(fakePacket4, "APP.data", 80)
        change(fakePacket9, "APP.data", 80)
        change(fakePacket10, "APP.data", 80)
        change(fakePacket15, "APP.data", 80)
        change(fakePacket16, "APP.data", 80)
        
        # change in struct appNetInfoExchange
        change(fakePacket3, "APP.appNetInfoExchange.source", 3)
        change(fakePacket4, "APP.appNetInfoExchange.source", 4)
        change(fakePacket9, "APP.appNetInfoExchange.source", 9)
        change(fakePacket10, "APP.appNetInfoExchange.source", 10)
        change(fakePacket15, "APP.appNetInfoExchange.source", 15)
        change(fakePacket16, "APP.appNetInfoExchange.source", 16)
        
        change(fakePacket3, "APP.appNetInfoExchange.destination", 0)
        change(fakePacket4, "APP.appNetInfoExchange.destination", 0)
        change(fakePacket9, "APP.appNetInfoExchange.destination", 0)
        change(fakePacket10, "APP.appNetInfoExchange.destination", 0)
        change(fakePacket15, "APP.appNetInfoExchange.destination", 0)
        change(fakePacket16, "APP.appNetInfoExchange.destination", 0)
        
        #change(fakePacket, "APP.appNetInfoExchange.timestamp", timestamp)
                
        put(fakePacket3, targetList3, TX, FALSE, 0)
        put(fakePacket4, targetList4, TX, FALSE, 0)
        put(fakePacket9, targetList9, TX, FALSE, 0)
        put(fakePacket10, targetList10, TX, FALSE, 0)
        put(fakePacket15, targetList15, TX, FALSE, 0)
        put(fakePacket16, targetList16, TX, FALSE, 0)
        
        seqNumb += 1
        
}

