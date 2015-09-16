# Conditional attacks.
#
# authors: 
#  + Francesco Racciatti <racciatti.francesco@gmail.com>

# recipient list
list targetList = {3, 4, 9, 10, 15, 16}
list dstList = {3, 4, 9, 10, 15, 16}

# conditional statement
from 50 nodes in targetList do{

    filter("APP.sourceNodeID" == "3|4|9|10|15|16" )
    
    # declare a fake packet
	packet fakePacket
    
    # declare variables
    #var seqNum = 0
    #var id = 0
        var evalue = 0
    
    #retrieve(original, "APP.sequenceNumber", seqNum)
    #retrieve(original, "APP.applicationID", id)
        retrieve(original, "APP.value", evalue)
    
        evalue += 1500
    
        clone(original, fakePacket)
    
        change(fakePacket, "APP.value", evalue)
        drop(original,1)
    
    #create and fill the fake packet
	#create(fakePacket, "APP.type", 0)
    #change(fakePacket, "APP.data", 110)
    #change(fakePacket, "APP.sequenceNumber", seqNum)
    #change(fakePacket, "APP.applicationID", id)
    
    #drop(original, 1)
        send(fakePacket, 0)
    
    # send the fake packet to the recipients's TX buffer
	#put(fakePacket, dstList, TX, FALSE, 0)

}
