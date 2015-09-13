# This is an example of ASL file that contains a drop action.
# It always drops the intercepted (original) packet.
#
# usage: 
#  python ../../interpreter/interpreter.py -i drop-original.asl -o drop-original.xlm
# 
# author: Francesco Racciatti <racciatti.francesco@gmail.com>

# declare and initialize a list of nodes
list targetList = {1}

# conditional attack statement (starts at 100 and it refers nodes in targetList)
from 100 nodes in targetList do {

	# packet filter, it filters all packets having the field 'sourcePort' of the layer 'NET' equals to 1000
	filter("NET.sourcePort" == 1000)

		# drop the original intercepted packet
    	drop(original, 1)

}
