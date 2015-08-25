# This is an example of ASL file that contains a put action used in an unconditional attack.
# It puts a packet (either an original or a packet created by the actions 'create' or 'clone')
# in the reception or transmission buffer of a set of nodes.
#
# usage: 
#  python ../interpreter/interpreter.py -i put-unconditional.asl -o put-unconditional.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# declare and initialize a list of nodes
list dstList = {2,3,4,5}

# unconditional attack statement (starts at 100 and repeats itself every 0.1 ms)
from 100 every 0.1 do {

		# declare a packet
		packet fakePacket
		
		# create a new packet
		create(fakePacket, "APP.type", 0)

		# fill the new packet properly
		change(fakePacket, "APP.data", 1000)
		change(fakePacket, "APP.source", 1234)
		
		# put the original intercepted packet in the RX buffer of nodes in the dstList without update stats and with delay 0.5 ms
		put(fakePacket, dstList, RX, FALSE, 0.5)

}
