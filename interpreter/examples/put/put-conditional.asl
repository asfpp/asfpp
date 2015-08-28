# This is an example of ASL file that contains a put action used in a conditional attack.
# It puts a packet (either an original or a packet created by the actions 'create' or 'clone')
# in the reception or transmission buffer of a set of nodes.
#
# usage: 
#  python ../interpreter/interpreter.py -i put-conditional.asl -o put-conditional.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# declare and initialize a list of nodes
list targetList = {1}
list dstList = {2,3,4,5}

# conditional attack statement (starts at 100 and it refers nodes in targetList)
from 100 nodes in targetList do {

	# packet filter, it filters all packets having the field 'sourcePort' of the layer 'NET' equals to 1000
	filter("NET.sourcePort" == "1000")
		
		# put the original intercepted packet in the RX buffer of nodes in the dstList without update stats and with delay 0.5 ms
		put(original, dstList, RX, FALSE, 0.5)
 
}
