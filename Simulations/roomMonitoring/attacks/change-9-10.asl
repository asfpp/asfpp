# Tamper packets of nodes 9 and 10.
#
# authors:
#  + Francesco Racciatti <racciatti.francesco@gmail.com>
#  + Alessandro Pischedda <alessandro.pischedda@gmail.com>

list targetList = {9,10}

# conditional statement
from 200 nodes in targetList do {
    
    # packet filter
	filter("APP.sourceNodeID" == "9|10")
		
    	change(original, "APP.data", 1000)

}
