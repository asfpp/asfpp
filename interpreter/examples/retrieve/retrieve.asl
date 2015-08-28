# This is an example of ASL file that contains a retrieve action.
# It retrieves the content of a field (of a certain layer) in a packet.
#
# usage: 
#  python ../interpreter/interpreter.py -i retrieve.asl -o retrieve.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# declare and initialize a list of nodes
list targetList = {1}

# conditional attack statement (starts at 100 and it refers nodes in targetList)
from 100 nodes in targetList do {

	# packet filter, it filters all packets having the field 'sourcePort' of the layer 'NET' equals to 1000
	filter("NET.sourcePort" == "1000")

		# declare a variable
		var value
		
		# retrieve the field 'destPort' of the layer 'NET' and store it in value
    	retrieve(original, "NET.destPort", value)

}
