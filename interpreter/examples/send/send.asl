# This is an example of ASL file that contains a send action.
# The new packets, created by the actions 'create' or 'clone', must be explicitly sended to the
# next layer in the communication stack by using the action 'send'.
#
# usage: 
#  python ../interpreter/interpreter.py -i change.asl -o change.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# declare and initialize a list of nodes
list targetList = {1}

# conditional attack statement (starts at 100 and it refers nodes in targetList)
from 100 nodes in targetList do {

	# packet filter, it filters all packets having the field 'sourcePort' of the layer 'NET' equals to 1000
	filter("NET.sourcePort" == 1000)
		
		# declare a packet
		packet dolly
    
		# clone the original packet
		clone(original, dolly)
		
    	# send dolly to the following layer in the communication stack with no delay
    	send(dolly, 0)
 
}
