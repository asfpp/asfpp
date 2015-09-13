# This is an example of ASL file that contains two unconditional attacks
# An unconditional attack is a loop statement that contains a set of 
# logical primitives (clone, create, drop, put, change, retrieve, send).
#
# The primitives contained inside the loop are periodically executed. 
# The period of the loop is defined by *period*. The occurrence time of the attack is defined by *time*.
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

# unconditional attack statement (starts at 200 and repeats itself every 0.25 ms)
from 200 every 0.25 do {

    # declare a packet
    packet anotherFakePacket
    
    # initialize a variable (the variable is initialized JUST ONCE)
    var step = 1000

    # expression
    step += 1

    # create a new packet
	create(anotherFakePacket, "APP.type", 0)

	# fill the new packet properly
	change(anotherFakePacket, "APP.data", 1000)
	change(anotherFakePacket, "APP.snNumber", step)
	
	# put the original intercepted packet in the RX buffer of nodes in the dstList without update stats and without delay
	put(anotherFakePacket, dstList, RX, FALSE, 0)
    
}


