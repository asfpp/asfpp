# Deep test.
#
# authors: 
#  + Francesco Racciatti <racciatti.francesco@gmail.com>

# cluster 2
list targetList = {3, 4, 9, 10, 15, 16}

# conditional statement
from 50 nodes in targetList do{

    filter("APP.sourceNodeID" == "3|4|9|10|15|16" )
    
        var data = 0
        packet fakePacket
        
        retrieve(original, "APP.data", data)
        data -= 50
        
        clone(original, fakePacket)
        drop(original, 1)
        
        change(fakePacket, "APP.data", data)
        send(fakePacket, 0)
        
        
}
