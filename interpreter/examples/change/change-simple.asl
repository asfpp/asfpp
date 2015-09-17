# This is an example of ASL file that contains a change action.
# It changes the content of a field (of a certain layer) in a packet.
# It is also useful to write contents in new packets (see create).
#
# usage: 
#  python ../interpreter/interpreter.py -i change-simple.asl -o change-simple.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# declare and initialize a list of nodes
list targetList = {1}

# conditional attack statement (starts at 100 and it refers nodes in targetList)
from 100 nodes in targetList do {

	# packet filter, it filters all packets having the field 'sourcePort' of the layer 'NET' equals to 1000
	filter((("APP.source"==2) or ("NET.may"==3)) and ("APP.sousou" == 2))
		
		# declare a packet
		packet dolly
		
		# declare and initialize a variable
		var value = -1234
		
		# clone the original packet
		clone(original, dolly)
		
		# change the field 'appName' of the layer 'APP' with the value "myapp" (STRING)
    	change(original, "APP.appName", "myapp")
    	
		# change the field 'destPort' of the layer 'NET' with the value 5000 (NUMBER)
    	change(original, "NET.destPort", 5000.1)
        
    	# change the field 'destPort' of the layer 'NET' with the value contained in the variable value
    	change(dolly, "NET.destPort", value)

}
