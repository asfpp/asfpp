# This is an example of ASL file that contains a clone action.
# The packet created by the action 'clone' must be explicitly sended to the next
# layer in the communication stack by using the action 'send' or 'put'.
#
# usage: 
#  python ../interpreter/interpreter.py -i clone.asl -o clone.xlm
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
		
		# clone the original packet, dolly is a perfect copy of original
		clone(original, dolly)

		# the new packets must be explicitly forwarded (in this case by using the send action)
		send(dolly, 0)
		
}
