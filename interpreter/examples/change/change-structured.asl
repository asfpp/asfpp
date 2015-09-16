# This is an example of ASL file that contains a change action.
# It changes the content of a structured field (of a certain layer) in a packet.
# It is also useful to write contents in new packets (see create).
#
# usage: 
#  python ../interpreter/interpreter.py -i change-structured.asl -o change-structured.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# declare and initialize a list of nodes
list targetList = {1}

# conditional attack statement (starts at 100 and it refers nodes in targetList)
from 100 nodes in targetList do {

	# packet filter, it filters all packets having the field 'sourcePort' of the layer 'NET' equals to 1000
	filter("NET.sourcePort" == 1000)
				
		# change the field 'appName' of the layer 'APP' with the value "myapp" (STRING)
    	change(original, "APP.appName", "myapp")
    	
		# change the field 'source' of the structure 'appNetInfoExchange' of the layer 'APP' with the value 1 (NUMBER)
    	change(original, "APP.appNetInfoExchange.source", 1)
        
        # change the field 'destination' of the structure 'appNetInfoExchange' of the layer 'APP' with the value 5 (NUMBER)
    	change(original, "APP.appNetInfoExchange.destination", 5)

}
