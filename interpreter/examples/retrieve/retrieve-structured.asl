# This is an example of ASL file that contains a retrieve action.
# It retrieves the content of a field of a structure (of a certain layer) in a packet.
#
# usage: 
#  python ../interpreter/interpreter.py -i retrieve-structured.asl -o retrieve-structured.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# declare and initialize a list of nodes
list targetList = {1}

# conditional attack statement (starts at 100 and it refers nodes in targetList)
from 100 nodes in targetList do {

	# packet filter, it filters all packets having the field 'sourcePort' of the layer 'NET' equals to 1000
	filter("NET.sourcePort" == 1000)

		# declare a variable
		var source
		
		# retrieve the field 'source' of the struct 'appNetInfoExchange' of the layer 'APP' and store it in source
    	retrieve(original, "APP.appNetInfoExchange.source", source)

}
