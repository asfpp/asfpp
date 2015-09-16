# Tamper cluster-1's packets.
#
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# cluster 1
list targetList = {1,2,7,8,13,14}

# conditional statement
from 50 nodes in targetList do {
    
    # packet filter
	filter("APP.sequenceNumber" > 11)
		
        var myvalue = 50        		
    	change(original, "APP.data", myvalue)

}
