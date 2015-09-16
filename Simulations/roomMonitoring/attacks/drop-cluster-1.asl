# Drop cluster-1's packets.
#
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# cluster 1
list targetList = {1,2,7,8,13,14}

# conditional statement
from 100 nodes in targetList do {

	filter("APP.sequenceNumber" > 10)
				
		# always drop the original intercepted packet (likelyhood 1)
    	drop(original, 1)

}
