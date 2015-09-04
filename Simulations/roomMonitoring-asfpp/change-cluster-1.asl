
# cluster 1
list targetList = {1,2,7,8,13,14}

from 50 nodes in targetList do {

	filter("APP.sequenceNumber" > 11)
		
        var myvalue = 50
        		
    	change(original, "APP.value", myvalue)

}
