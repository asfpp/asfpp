# This is an example of ASL file that contains a create action used in a conditional attack.
# It creates a new packet. The action 'change' must be used to fill the fields of the new packet.
# The new packet must be explicitly sended to the next layer in the communication stack
# by using the action 'send' or 'put'.
#
# usage: 
#  python ../interpreter/interpreter.py -i create-conditional.asl -o create-conditional.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# declare and initialize a list of nodes
list targetList = {1}

# conditional attack statement (starts at 100 and it refers nodes in targetList)
from 100 nodes in targetList do {

	# packet filter, it filters all packets having the field 'source' of the layer 'APP' equals to 1000
	filter("APP.source" == "1000")
		
		# declare a packet
		packet fakePacket
		
		# drop the original intercepted packet
		drop(original, 1)

		# create a new packet
		create(fakePacket, "APP.type", 0)

		# fill the new packet properly
		change(fakePacket, "APP.data", 1000)
		change(fakePacket, "APP.source", 1234)
		
		# send the new packet to the next layer in the communication stack with no delay
		send(fakePacket, 0)

}
