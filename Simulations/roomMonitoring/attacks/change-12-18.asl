# Tamper packets of nodes 12 and 18.
#
# authors:
#  + Francesco Racciatti <racciatti.francesco@gmail.com>
#  + Alessandro Pischedda <alessandro.pischedda@gmail.com>

list targetList = {12,18}

# conditional statement
from 200 nodes in targetList do {
    
    # packet filter
	filter("APP.sourceNodeID" == "12|18")
		
    	change(original, "APP.data", 1000)

}
