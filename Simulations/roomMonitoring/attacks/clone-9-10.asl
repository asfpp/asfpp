# Clone packets of nodes 9 and 10.
#
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

list targetList = {9, 10}

# conditional statement
from 200 nodes in targetList do {
    
    # packet filter
	filter("APP.sourceNodeID" == "9|10")
		
        packet dolly
    	clone(original, dolly)
        send(dolly, 0)

}
