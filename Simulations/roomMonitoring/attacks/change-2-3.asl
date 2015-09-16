# Tamper packets of nodes 2 and 3.
#
# authors:
#  + Francesco Racciatti <racciatti.francesco@gmail.com>
#  + Alessandro Pischedda <alessandro.pischedda@gmail.com>

list targetList = {2,3}

# conditional statement
from 200 nodes in targetList do {
    
    # packet filter
	filter("APP.sourceNodeID" == "2|3")
		
    	change(original, "APP.data", 1000)

}
